#!/bin/bash

echo '[+] Assembling with Nasm | -f elf32 -g -o *.o -->'
nasm -f elf32 -g -o $1.o $1.asm

echo '[+] Linking -->'
ld -o $1 $1.o

echo '[+] Done!'



