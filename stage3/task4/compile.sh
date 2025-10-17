#!/bin/bash

INPUT_FILE="$1"
lex task4.l
yacc -d task4.y
gcc lex.yy.c y.tab.c -o task4.exe

./task4.exe $INPUT_FILE

