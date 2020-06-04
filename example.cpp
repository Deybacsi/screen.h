/*

Screen.h simple examples

https://github.com/Deybacsi/screen.h

*/

#include "screen.h"

using namespace std;

int main() {

    int i,j;

    // hide the cursor
    // it will be handy for continuous animations and regular screen redrawing
    hideCursor();

    // initiate our screen object, and initialize everything
    Cscreen screen;
    screen.init();

    

    /*
        The screen consists of 5 layers, each one can have its own content (0=bottom)
        They can have transparent characters, fore- or background colors too
        Image will not displayed until the layers were merged
    */

    // first, clear all of the layers with transparent characters
    screen.clearAllLayer(CLEARCHAR);

    // write out something to layer 0 at 10x2 coordinates (x,y) 
    screen.stringXy(0, 10, 2, WRITECHAR, "Something");

    // write out the screen size with a custom style
    // using screen.getScreenWidth() and screen.getScreenHeight()
    s_simplechar MYSTYLE={
        " ",                    // it can be anything, not used for strings
        C_RED,                  // text color
        C_GRAY,                 // background color
        false, false, false     // lower layers will not be seen above this character (false=not transparent)
    };
    screen.stringXy(0, 10, 5, MYSTYLE, "Screen size: "+to_string(screen.getScreenWidth()) + "x" + to_string(screen.getScreenHeight()));  

    // let's draw a blue and a red rectangle to layer 0 and 1
    // drawing order is not important
    for (i=7; i<=10; i++) {
        for (j=0; j<=25; j++) {
            screen.charXy(0,j,i,{ "0", C_BLACK, C_RED, false, false, false});
        }
    }
    for (i=8; i<=12; i++) {
        for (j=10; j<=32; j++) {
            screen.charXy(1,j,i,{ "1", C_BLACK, C_BLUE, false, false, false});
        }
    }

    // finally draw a line to layer 3 with some transparency
    // note that the "3" will not appear anywhere, because it's transparent
    // the bottom layer's chars will be drawn there, which are mostly " " because of the previous clearAllLayer
    screen.lineXy(3, 10,0, 35, 14, {"3", C_BLACK, C_GREEN, true, false, false});

    // finally merge all layers to one picture, and print the whole thing out to terminal
    screen.mergeLayers();
    screen.printScreen();

    // show the cursor again
    showCursor();
    return 0;
}