#include <stdio.h>
#include <stdlib.h>

// 指定這個陣列的長度
#define size 100

// 宣告一個長度為 size 的全域變數 stack
int stack[size];

// top 設為 -1 : 代表 stack 裡面沒有資料
// 如果 stack[0] 有資料但再上面就沒有 top 就是 0
// 如果 stack[1] 有資料但再上面就沒有 top 就是 1
// 如果 stack[2] 有資料但再上面就沒有 top 就是 2
// ...依此類推，所以一開始設成 -1 代表空的

int top = -1;

void push(int value) {
    // 因為最大只到 stack[size-1]
    // 所以當 top == size-1 時
    if (top == size - 1) {
        fprintf(stderr, "Stack is full.");
        exit(EXIT_FAILURE);
    }
    stack[top + 1] = value;
    top = top + 1;
}

int pop() {
    // 當 top == -1 時還要再抓東西出來，一定是抓不出來啊
    if (top == -1) {
        fprintf(stderr, "Stack is empty.");
        exit(EXIT_FAILURE);
    }
    top -= 1;
    return stack[top + 1];
}

// 方便我們觀察 stack 變化
void printStackLn() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    printStackLn();
    push(20);
    printStackLn();
    push(30);
    printStackLn();
    pop();
    printStackLn();
    pop();
    printStackLn();
    push(40);
    printStackLn();

    return 0;
}
