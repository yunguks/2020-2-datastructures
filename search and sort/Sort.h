#include <stdio.h>
#include <stdlib.h>

void selectionSort(int list[],int n){
    int i,j;
    int small;
    int temp;
    
    for(i=0;i<n-1;i++){
        small=i;
        for(j=i+1;j<n;j++){
            if(list[j]<list[small]) small=j;
        }
        
        temp=list[i];
        list[i]=list[small];
        list[small]=temp;
    }
}

void insertionSort(int list[],int n){
    int i,j;
    int temp;
    int hold;
    
    for(i=1;i<n;i++){
        hold=list[i];
        for(j=i;j>0&&hold<list[j-1];j--){
            temp=list[j];
            list[j]=list[j-1];
            list[j-1]=temp;
        }
    }
}

void bubbleSort(int list[], int n){
    int i,j;
    int temp;
    int sorted=0;
    
    for(i=0;i<n&&sorted==0;i++){
        for(j=0,sorted=1;j<n-1;j++){
            if(list[j]>list[j+1]){
                sorted=0;
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
}

void quickSort(int list[], int left, int right){
    int L,R;
    int temp;
    int pivot;
    
    L=left;
    R=right;
    pivot=list[(L+R)/2];
    
    while(L<=R){
        while(list[L]<pivot) L++;
        while(list[R]>pivot) R--;
        
        if(L<=R){
            if(L!=R){
                temp=list[L];
                list[L]=list[R];
                list[R]=temp;
            }
            L++;
            R--;
        }
        /*for(int i=0;i<100;i++){
            printf("%d ",list[i]);
        }
        printf("\n");//데이터확인*/
    }
    if(left < R) quickSort(list,left,R);
    if(L < right) quickSort(list,L,right);
}

int sorted[100]={};

void merge(int list[], int left, int mid, int right){
    int j,k,i,t;
    i=left;
    j=mid+1;
    k=left;
    
    while(i<=mid && j<=right){
        if(list[i]<list[j]) sorted[k++] = list[i++];
        else sorted[k++] = list[j++];
    }
    
    if(i>mid){
        for(t=j;t<=right;t++) sorted[k+t-j] = list[t];
    }
    else{
        for(t=i;t<=mid;t++) sorted[k+t-i] = list[t];
    }
    //배열 sorted 를 list로 
    for(t=left; t<=right; t++){
        list[t]=sorted[t];
    }
}

void mergeSort(int list[],int left, int right){
    int mid;
    
    if(left<right){
        mid =(left+right)/2;
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}
