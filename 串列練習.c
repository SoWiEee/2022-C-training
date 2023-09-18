#include <stdio.h>
#include <stdlib.h>

typedef struct X Node;
struct X {
	int value;
	Node *next;
};
/* ［0:end; +:insert; -:delete］
  1. "0" -> 結束
  2. "正整數" -> 遞增序插入正確的位置 （ps:若已存在，則不插入）
  3. "負整數" -> 刪除該節點 （ps:若不存在，則不刪除）
    （ex: -1刪除節點1）
  4. 刪除全串列
*/

int main(void) {
	Node *head = NULL, *node, *p;
	int num;
  do{
    scanf("%d",&num);
    if(num == 0) break;
    if(num > 0){
      node = malloc(sizeof(Node));
      node->value = num;
      node->next = NULL;
      
      if(head == NULL){
        head = node;
      }else if(head->value > node->value){
        node->next = head;
        head = node;
      }else {
        p = head;
        while(p->next){
          if(p->next->value > node->value)break;
          p = p->next;
        }
        if(p->next == NULL || p->value < node -> value){
        node->next = p->next;
        p->next = node;
        }
      }
    }else{
        num*=-1;
        if(head == NULL) continue;
        if(head->value == num){
          node = head;
          head = head->next;
          free(node);
        }else{
          p = head;
          while(p->next){
            if(p->next->value == num){
              node = p->next;
              p->next = node->next;
              free(node);
              
            }else{
              p = p->next;
            }
          }  
        }
      }
    }while(1);
  p = head;
  while(p){
    printf("%d->", p->value);
    p = p->next;
  }
  printf("NULL\n");
	return 0;
}
