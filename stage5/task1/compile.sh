#!/bin/bash

INPUT_FILE="$1"
lex task1.l
yacc -d task1.y
gcc lex.yy.c y.tab.c -o task1.exe

./task1.exe $INPUT_FILE

