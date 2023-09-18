// 判斷閏年
#include <stdio.h>
/*
  1.西元年份除以4可整除，且除以100不可整除
  2.西元年份除以400可整除
*/
  int main(void) {
  int year;
  printf("請輸入一個西元年分：\n");
  scanf("%d", &year);
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    printf("%d年為閏年", year);
  } else {
    printf("%d年為平年", year);
  }
  return 0;
}

int main(void) {
  int m[5][5], i, j;
  for (i = 0; i < 5; i++) {
    scanf("%d", &j);
    m[i][0] = j;
    m[0][i] = j;
  }
  for (i = 1; i < 5; i++) {
    for (j = 1; j < 5; j++) {
      m[i][j] = m[i-1][j] + m[i][j-1] + m[i-1][j-1];
    }
  }
  
  //輸出最後陣列
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("%4d", m[i][j]);
      
    }
    printf("\n");
  }
  return 0;
}
