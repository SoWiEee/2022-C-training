#include <stdio.h>
#include <string.h>
int main(){
  char s[100];
  char *p;
  scanf("%[^\n]%*c",s);
  do{
    p=strchr(s,' ');
    if(p) *p='_';
  } while(p);
  printf("%s\n",s);
  return 0;
}

int main(){
  // abc => cba（前面往後移）
  char *p;
  int i;
  char s[100];
  scanf("%s",s);
  // 單字字母數＝s~下一個空格
  strcat(s, s[0]);
  //p=strchr(s,'\0');
  printf("%s",s);

  return 0;
}
