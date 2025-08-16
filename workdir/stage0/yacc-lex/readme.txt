how to run

1 lex e1.l
2 yacc ex1.y -d
3 gcc lex.yy.c y.tab.c -o ex1.exe
4 ./ex1.exe