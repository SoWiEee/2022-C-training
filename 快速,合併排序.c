#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *data,size;
void swap(int *a, int *b) {
	int c=*a;*a=*b;*b=c;
}
void shuffleData(){
	int i;
	srand(time(0));
	data=calloc(size,sizeof(int));
	for(i=0;i<size;i++) data[i]=i+1;
	for(i=0;i<size;i++) {
		swap(&data[i],&data[rand()%size]);
	}	
}
void showData(const char *str) {
	printf("%s",str);
	for(int i=0;i<size;i++) printf("%d ",data[i]);
	printf("\n");
}
void bubbleSort(int N) { //這是氣泡排序的範例
	int i,j;
	for(i=1;i<N;i++) {        //外迴圈：決定幾回合，決定回合終點
		for(j=0;j<N-i;j++) {  //內迴圈：每一回合的交換次數
			if(data[j]>data[j+1]) {
				swap(&data[j],&data[j+1]);
			}
		}
	}
}

void mergeSort(int L,int R) { //注意：包含L，不包含R
	/*  提示：先分割再合併。  */
  if(L >= R) return;
  int M = (L+R)/2;
  int i, j, k, sorted[R-L+1];
  for(i = L,j = M+1, k=0; i<=M && j<=R; k++)
}

void quickSort(int L,int R) { //注意：包含L，不包含R
	/*  提示：找一個基準值，把比較小的往前丟。
			 最後把基準值丟在小堆的最後一個，基準值後就是大堆。
			 再各別排序大小兩堆。
	*/
  if(L >= R) return;
  int i,j;
  for(i = L,j = L; i < R; i++){
    if(data[i] < data[R]) swap(&data[i], &data[j++]);
  }
  swap(&data[j], &data[R]);
  quickSort(L, j-1);
  quickSort(j+1, R);
}

int main(void) {
	int opt;
	scanf("%d %d",&opt,&size);
	shuffleData();
	if(opt==1) {
		showData("合併排序前：");
		mergeSort(0,size); //注意：包含L，不包含R
		showData("合併排序後：");
	} else if(opt==2) {
		showData("快速排序前：");
		quickSort(0,size); //注意：包含L，不包含R
		showData("快速排序後：");
	} else if(opt==3) {
		showData("氣泡排序前：");
		bubbleSort(size); //這是氣泡排序的範例
		showData("氣泡排序後：");
	}
	free(data);
	return 0;
}
