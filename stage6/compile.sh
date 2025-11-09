#!/bin/bash

INPUT_FILE="$1"
lex ex2.l
yacc -d ex2.y
gcc lex.yy.c y.tab.c -o ex2.exe

./ex2.exe $INPUT_FILE

