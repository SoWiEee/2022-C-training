#include <stdio.h>
#include <stdlib.h>

typedef struct X Node;
struct X {
	int value;
	Node *next;
};
/* 
  1. "0" -> 結束
  2. "正整數" -> 遞增序插入正確的位置 （ps:若已存在，則不插入）
  3. "負整數" -> 刪除該節點 （ps:若不存在，則不刪除）
    （ex: -1刪除節點1）
  4. 刪除全串列
*/

int main(void) {
	Node *head=NULL, *node, *p;
	int num;
  do{
    scanf("%d",&num);
    node = malloc(sizeof(Node));
    node->value = num;
    node->next = NULL;
    p = head;
    // "0" -> 結束，輸出全串列
    if(num == 0) {
      while(p->next != NULL){
        printf("%d->", p->value);
        p = p->next;
      }
      printf("%d", p->value);
      break;
    }

    // "正整數" -> 遞增序插入正確的位置
    if(num > 0){
        if(head == NULL){
          head->value = num;
        } else if(p->next == NULL){
            p->next = node;
            break;
        }
        if(node->value > p->next->value || node->value < p->value){
          p = p->next;  // 區間往後移(p++)
        }
        if(node->value <= p->next->value && node->value >= p->value){
          // 插入node
          node->next = p->next;
          p->next = node;
          break;
        }
      break;
    }
      
    // "負整數" -> 遍歷，刪除該節點
    if(num < 0){ 
      p=head;
      while(p->next != NULL){
            if(p->next->value == -1*num){
                p->next = p->next->next;
            }else{
                p = p->next;  // 下一個
            }
      }
      printf("不存在\n");
    }
  }while(num!=0);
  
	return 0;
}
