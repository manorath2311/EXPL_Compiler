# Makefile for lex + yacc + gcc build

CC = gcc
LEX = lex
YACC = yacc
CFLAGS = -Wall -g

TARGET = task1.exe
LEX_SRC = task1.l
YACC_SRC = task1.y
LEX_OUT = lex.yy.c
YACC_OUT = y.tab.c
YACC_HDR = y.tab.h
INPUT = text1.txt   # change this if your input file has a different name

all: $(TARGET)

$(TARGET): $(LEX_OUT) $(YACC_OUT)
	$(CC) $(CFLAGS) $(LEX_OUT) $(YACC_OUT) -o $(TARGET)

$(LEX_OUT): $(LEX_SRC) $(YACC_HDR)
	$(LEX) $(LEX_SRC)

$(YACC_OUT) $(YACC_HDR): $(YACC_SRC)
	$(YACC) -d $(YACC_SRC)

run: $(TARGET)
	./$(TARGET) < $(INPUT)

clean:
	rm -f $(LEX_OUT) $(YACC_OUT) $(YACC_HDR) $(TARGET)
