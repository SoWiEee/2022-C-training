#include <stdio.h>

int main(void) {
	char line[100],stk[100];
	int i,top;
  
	scanf("%s",line);
  top=0;
  for(i=0; line[i]!='\0'; i++){
    if(line[i]=='(' || line[i]=='['){
      stk[top]=line[i];
      top++;
    }else if(top>0){
      if(line[i]==')' && stk[top-1]=='(') top--;
      else if(line[i]==']' && stk[top-1]=='[') top--;
      else break;
    }
  }
	if(line[i]!='\0' || top>0) printf("NO");
	else printf("YES");
  
	return 0;
}
