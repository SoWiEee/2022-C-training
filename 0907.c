#include <stdio.h>
#include <string.h>
int strrep(dst[], str[], times){
  for(i=1; i<times; i++){
    strncat(dst, str[]);
  }
}
  
int main(void) {
  //int times;
  //scanf("%d", &times);
  const char str[4] = "abc";
  char dst[];
  scanf("%s %d", &str, &times);
  strrep();
  printf("%s\n", dst);
  return 0;
}
