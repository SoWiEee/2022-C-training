#include <stdio.h>
#include <string.h>

int main(void) {  
  char words[1000][30];
  int count[1000], max = 0, n = 0, i;

  //開始讀文章，比較單字出現的次數
  while (EOF != scanf("%s", words[n])) {
    // EOF:End of File: Ctrl+D
    for (i = 0; i < n; i++) {
      if (0 == strcmp(words[n], words[i])) {
        count[i]++;
        break;
      }
    }
    if (i == n) {
      count[n] = 1;
      n++;
    }
    if (count[i] > max) {
      max = count[i];
    }
  }

  printf("單字重複最多的是%d次，如下：\n", max);
  for (i = 0; i < n; i++) {
    if (max == count[i]) {
      //以出現的順序列印，可能有不只一個單字
      printf("%s\n", words[i]);
    }
  }
  return 0;
}
