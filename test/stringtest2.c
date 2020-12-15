#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char num1[100], num2[100];
  int  num[100];
  char* token;
  const char s[2]=",";
  int k=0, a=0;
  int tmp;

  printf("input : \n");
  scanf(" %[^\n]s", num1);
  scanf(" %[^\n]s", num2);

  token = strtok(num1, s);
  while(token != NULL){
    num[k] = atoi(token);
    token = strtok(NULL, s);
    k++;
  }
  
   token = strtok(num2, s);
   while(token != NULL){
    num[k] = atoi(token);
    token = strtok(NULL, s);
    k++;
  }

  if(k!=20) {
    printf("You should input 20 numbers in total.\n");
    exit(1);
  }

  for(int i=0;i<19;i++){
    for(int j=i+1;j<20;j++){
      if(num[i]>num[j]){
        tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
        a++;
      }
    }
  }

  if(a>0) printf("The input numbers are not in ascending order.\n");
  printf("Output :\n");
  for(int i=0;i<k;i++){
    printf("%d",num[i]);
    if(i<19) printf(", ");
  }
  return 0;
}