#include <stdio.h>
#include <stdbool.h>
#define HASH_SIZE 100

bool binarySearch (int list[ ], int n, int target)
{
    int begin = 0;
    int mid = 0;
    int end = n - 1;
    
    while (begin <= end){
        mid = (begin + end) / 2;
        if (target > list[mid]) begin = mid + 1; // 반보다 큰
        else if (target < list[mid]) end = mid - 1; // 반보다 작은
        else begin = end + 1; // 예외로 입력된 수이면 탈출
    }//mid를 찾기
    
    return (target == list[mid]);
} // binary

int hashFunc1(int x){
    return x%HASH_SIZE;
}

/*int hashFunc2(int x,int size){
    return (x+1)%HASH_SIZE;
}

int doubleHash(int x,int size){
    return (hashFunc1(x,size)+hashFunc2(x,size))%HASH_SIZE;
}*/
int collusion(int key){
    return hashFunc1(key);
}

void insertHash(int list[], int hash[], int n){
    int i;
    int key;
    
    for(i=0;i<HASH_SIZE;i++){
        hash[i]=-1;
    }
    
    i=0;
    while(i<n){
        key=hashFunc1(list[i]);
        if(hash[key]==-1) {
            hash[key]=list[i];
            //printf("key=%d %d\n",key,list[i]);
        }
        else {
            hash[collusion(key)]=list[i];
            printf("%d에서 충돌 key=%d\n",list[i],key);// 충돌일 경우 한번더 
        }
        i++;
    }
}

int searchHash(int hash[],int search){
    int key;
    key=hashFunc1(search);
    if(search==hash[key]) return 1;
    else {
        key=hashFunc1(key);
        if(search==hash[key]) return 1;
        else return 0;
    }
    return 0;
}