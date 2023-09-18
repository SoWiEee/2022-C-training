#include <stdio.h>

int main(void) {
	char line[100], op[20], c;
	int num[20], tn, to, i, n, m;
	tn = 0; to = 0; n = 0; m = 0;
  // (1+2*3)*4-5
  // op: (+*) *-
  // out:(123*+) 4*5-
  /* 算法：
  1. *,/ 可壓 +,-
  2. *,/ 上面有 +,- => 先算(*,/)在壓(+,-)

  */ 
	scanf("%[^\n]%*c", line);
	for(i = 0; line[i]; i++) {
		c = line[i];
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'){  // 提取運算子
      op[n] = c;
      n++;
    }else{  // 提取運算元
      num[m] = c;
      m++;
    }
    
  }
	printf("%d", num[0]);
	return 0;
}
