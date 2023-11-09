#!/bin/bash
gcc -c -Wall -g -o init.o init.c
gcc -c -Wall -g -o main.o main.c
gcc -Wall -g -o a.out.1 main.o init.o
./a.out.1
