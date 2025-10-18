#!/bin/bash

# Script to compile and run programs with XSM simulator
# Usage: ./run-xsm.sh input_file.txt

if [ $# -eq 0 ]; then
    echo "Usage: $0 <input_file.txt>"
    echo "Example: $0 input1.txt"
    exit 1
fi

INPUT_FILE="$1"
XSM_DIR="../../xsm_expl"

echo "=== Compiling $INPUT_FILE ==="
./ex2 "$INPUT_FILE"

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

if [ ! -f temp.txt ]; then
    echo "Error: temp.txt not generated!"
    exit 1
fi

echo ""
echo "=== Generated XSM code (temp.txt) ==="
echo "First 10 lines:"
head -10 temp.txt

echo ""
echo "=== Copying to XSM directory ==="
cp temp.txt "$XSM_DIR/program.xsm"

echo ""
echo "=== Running in XSM simulator ==="
echo "Note: The program may ask for input. Type numbers and press Enter."
echo "The program will halt when complete."
echo ""

cd "$XSM_DIR"
./xsm -l library.lib -e program.xsm