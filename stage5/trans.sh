#!/bin/bash
lex label.l
gcc lex.yy.c 
./a.out machinecode.xsm out1.txt

