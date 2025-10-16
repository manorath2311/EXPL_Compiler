lex ex1.l
yacc -d ex1.y 
gcc lex.yy.c y.tab.c -o ex1.exe
./ex1.exe 