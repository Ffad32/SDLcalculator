#include "funkce.h"

// addition
void add(int a, int b,int *result) {
    *result= a + b;
    printf("add\n");
    return;
}

// subtraction
void sub(int a, int b,int *result) {
    *result= a - b;
    printf("sub\n");
}

// multiplication
void mul(int a, int b,int *result) {
    *result= a * b;
    printf("mul\n");
}

// division
void div(int a, int b,int *result) {
    *result= a / b;
    printf("div\n");
}

