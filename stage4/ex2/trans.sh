#!/bin/bash
lex label.l
gcc lex.yy.c 
./a.out temp.txt out1.txt

