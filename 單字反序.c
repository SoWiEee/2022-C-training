#include <stdio.h>
#include <string.h>
void reverse(char str[], int start, int end){
    char temp;
    while(start < end){
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start ++;
        end --;
    }
}
int main(){
    int i;
    char str[100];
    scanf("%[^\n]%*c",str);
    int start, end;
    end=0;
    start=0;
    while(str[end]){
        for(end = start; str[end] && str[end]!=' '; end++);
        reverse(str, start, end-1);
        start = end+1;
    }
    for(i=strlen(str)-1; i>=0; i--){
      printf("%c", str[i]);
    }
    return 0;
}
