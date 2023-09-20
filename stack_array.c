#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* DS Stack(Array) */

#define SIZE 5
#define EMPTY (-1)
#define INT_MIN (-2147483648)
#define STACK_EMPTY INT_MIN

int stack[SIZE];    // stack[5]
int top = EMPTY;    // top = -1

// push() -- add element
bool push(int value) {
    if (top >= SIZE - 1) {
        return false;
    }
    // 每次push元素的時候，將top＋1，並放入index＝top＋1這個位置
    top ++;
    stack[top] = value;
    return true;
}

// pop() -- remove element
int pop() {
    if (top == EMPTY) {     // stack見底
        return STACK_EMPTY;
    }
    int reuslt = stack[top];
    top--;
    return reuslt;
}

int main() {
    push(56);   // add 56
    push(78);   // add 78
    push(13);   // add 13

    int t;
    while ((t = pop()) != STACK_EMPTY) {
        printf("t = %d\n", t);
    }
    system("pause");
    return 0;
}
