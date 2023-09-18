#include <stdio.h>

int main(void) {
  char op[100], c;
  int i, stk[100], top, x, y;
  scanf("%[^\n]%*c", op);
  top = 0;
  for(i=0; op[i], i++){
    c =op[i];
    if(c>='0' && c<='9'){
      stk[top++] = c-'0';
    }
  }
}
