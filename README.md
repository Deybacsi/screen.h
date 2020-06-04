# screen.h

Simple C++ terminal screen manipulation with layer handling and transparency.

## How to use

Create your screen object:
```
Cscreen screen;
screen.init();
```

### Draw to screen buffers:

Write out a string: `screen.stringXy(layerno, x, y, style, string)`

Write out a character: `screen.charXy(layerno, x, y, style, char)`

Draw a line: `screen.lineXy(layerno, x1, y1, x2,y2, style)`

Fill a layer with char: `clearLayer(layerno, style)`
Fill all layers with char: `clearAllLayer(style)`

### Finally draw everything to the screen:
```
screen.mergeLayers();
screen.printScreen();
```
### Style definition

```
struct s_simplechar {
    std::string chr;            // the char to print out, it's a string because it's easier to use unicode chars ;)
    unsigned short int col ;    // caracter color
    unsigned short int bcol ;   // background color
    bool transpchr;             // character is transparent? (true=if a bottom layer has something below this, that will appear instead of this char)
    bool transpcol;             // color is transparent?
    bool transpbcol;            // background color transparent?
};
```

You can use for example: `screen.stringXy(0, 5, 10, { "1", C_BLACK, C_BLUE, false, false, false}, "Hello world!")`

### Other useful stuff

Clear screen: `clearScreen()`
Move cursor: `gotoXy(x,y)`
Hide cursor: `hideCursor()`
Show cursor: `showCursor()`
Reset text color to defaults: `textReset()`

Number of layers can be changed by modifying `MAXLAYERS`

Color code constants:

```
// color code constants
// only the first 8 can be used as background colors!!
const int   C_BLACK   = 0,
            C_RED     = 1,
            C_GREEN   = 2,
            C_YELLOW  = 3,
            C_BLUE    = 4,
            C_MAGENTA = 5,
            C_CYAN    = 6,
            C_GRAY    = 7,

            C_DGRAY   = 8,
            C_LRED    = 9,
            C_LGREEN  = 10,
            C_LYELLOW = 11,
            C_LBLUE   = 12,
            C_LMAGENTA= 13,
            C_LCYAN   = 14,
            C_WHITE   = 15,

            C_BGTRANS = 8;  // default transparent bg color -> ANSI 49m
```