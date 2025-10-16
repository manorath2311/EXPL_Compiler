# Makefile for ex2 compiler project
# This compiles a yacc/lex based compiler

# Compiler settings
CC = gcc
CFLAGS = -Wall -g
YACC = yacc
LEX = lex

# Target executable
TARGET = ex2

# Source files
YACC_SRC = ex2.y
LEX_SRC = ex2.l
HEADER = ex2.h
C_SRC = ex2.c

# Generated files
YACC_OUT = y.tab.c y.tab.h
LEX_OUT = lex.yy.c

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(YACC_OUT) $(LEX_OUT)
	$(CC)  y.tab.c lex.yy.c -o $(TARGET)

# Generate yacc parser
y.tab.c y.tab.h: $(YACC_SRC) $(HEADER) $(C_SRC)
	$(YACC) -d $(YACC_SRC)

# Generate lex analyzer
lex.yy.c: $(LEX_SRC) $(HEADER)
	$(LEX) $(LEX_SRC)

# Clean generated files
clean:
	rm -f $(TARGET) $(YACC_OUT) $(LEX_OUT) temp.txt *.xsm

# Clean everything including output files
distclean: clean
	rm -f *.out *.o core

# Test with sample input
test: $(TARGET)
	./$(TARGET) input1.txt

# Run the generated code in XSM simulator
run-xsm: $(TARGET)
	@echo "Compiling input program..."
	./$(TARGET) input1.txt
	@echo "Converting labels to line numbers..."
	@if [ -f temp.txt ]; then \
		cp temp.txt program.xsm; \
		echo "Running in XSM simulator..."; \
		echo "Note: You may need to provide input when prompted"; \
		cd ../../xsm_expl && ./xsm -l library.lib -e ../stage4/ex2/program.xsm; \
	else \
		echo "Error: temp.txt not found. Compilation may have failed."; \
	fi

# Convert temp.txt labels to line numbers (like out1.txt)
convert-labels: temp.txt
	@echo "Converting labels to line numbers..."
	@python3 -c "\
import re; \
content = open('temp.txt').read(); \
lines = content.strip().split('\n'); \
labels = {}; \
code_lines = []; \
line_num = 0; \
for line in lines: \
    if line.strip().endswith(':'): \
        labels[line.strip()[:-1]] = line_num; \
    else: \
        code_lines.append(line); \
        line_num += 1; \
for i, line in enumerate(code_lines): \
    for label, num in labels.items(): \
        line = re.sub(r'\b' + label + r'\b', str(num), line); \
    code_lines[i] = line; \
print('\n'.join(code_lines));" > out1.txt
	@echo "Labels converted and saved to out1.txt"

# Remove debug printf statements from ex2.c
clean-debug:
	@echo "Creating clean version without debug prints..."
	@cp ex2.c ex2.c.backup
	@sed -e 's/printf("reached[^"]*");//g' \
	     -e 's/printf("reached[^"]*\\n");//g' \
	     ex2.c.backup > ex2.c.clean
	@echo "Clean version saved as ex2.c.clean"
	@echo "Original backed up as ex2.c.backup"

# Install dependencies (for Ubuntu/Debian)
install-deps:
	sudo apt-get update
	sudo apt-get install -y build-essential yacc flex

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build the compiler (default)"
	@echo "  clean      - Remove generated files"
	@echo "  distclean  - Remove all generated and output files"
	@echo "  test       - Build and test with input1.txt"
	@echo "  run-xsm    - Compile and run the program in XSM simulator"
	@echo "  convert-labels - Convert temp.txt labels to line numbers (creates out1.txt)"
	@echo "  install-deps - Install required dependencies"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "To run XSM programs manually:"
	@echo "  1. Build: make"
	@echo "  2. Compile your source: ./ex2 your_program.txt"
	@echo "  3. Copy temp.txt to XSM directory: cp temp.txt ../../xsm_expl/program.xsm"
	@echo "  4. Run: cd ../../xsm_expl && ./xsm -l library.lib -e program.xsm"

# Declare phony targets
.PHONY: all clean distclean test run-xsm convert-labels clean-debug install-deps help

# Dependencies
$(LEX_OUT): $(YACC_OUT)  # lex needs y.tab.h from yacc