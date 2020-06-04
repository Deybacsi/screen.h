#!/bin/bash

g++ example.cpp -o example

if [ $? -eq 0 ];then
   ./example 
else
   echo "There are compilation errors!"
fi
