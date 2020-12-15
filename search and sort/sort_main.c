#include "Sort.h"
#include "Search.h"

int main(){
    FILE *fp;
    char name[30];
    int num,fpnum,n=0;
    int data[100];
    int target,method;
    int find;
    int hash[HASH_SIZE]={};
    
    printf("Input file name : ");
    scanf("%s",name);
    
    fp=fopen(name,"r");
    
    if(fp==NULL){
        printf("파일 열기에 실패했습니다\n");
        exit(1);
    }
    
    while(fscanf(fp,"%d",&fpnum)!=EOF){
        data[n++]=fpnum;
        //printf(" %d",data[n-1]); 읽는지 확인
    }
    
    //printf("n = %d\n",n);//n이 얼마인가
    while(1){
        printf("Choose a sorting method to use\n");
        printf("(Selection : 0, Insertion : 1, Bubble : 2, Quick : 3, Merge : 4 ) : ");
        scanf(" %d",&method);
    
        if(method==0) {
            selectionSort(data,n);
            break;
        }
        else if(method==1) {
            insertionSort(data,n);
            break;
        }
        else if(method==2) {
            bubbleSort(data,n);
            break;
        }
        else if(method==3) {
            quickSort(data,0,n);
            break;
        }
        else if(method==4) {
            mergeSort(data,0,n-1);
            break;
        }
        else printf("0~4사이 수를 입력하시오.\n");
    }
    
    printf("The numbers sorted : ");
    for(int k=0;k<n;k++){
        printf(" %d,",data[k]);
    }

    //--------searching------------------------
    printf("\n\nTarget integer : ");
    scanf(" %d",&target);
    
    while(1){
        printf("Choose a searching method (Binary : 1 , Hash : 2) : ");
        scanf(" %d",&method);
    
        if(method==1){
            if(binarySearch(data,n,target)) printf("%d is find !",target);
            else printf("%d is not find !",target);
            break;
        }
        else if(method==2){
            insertHash(data,hash,n);
            if(searchHash(hash,target)==1) printf("%d is find !",target);
            else printf("%d is not find !",target);
            break;
        }
        else printf("1 또는 2를 입력하여주세요.\n");
    }
    fclose(fp);
    
    return 0;
   
}