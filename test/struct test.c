#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info{
  int age, mth, eng, his;
  char name[100];
};

int main(void) {

  FILE *fp;
  int m,s,a1=0, a2=0,n2,n3,n4,n5; //a는 메뉴 1을 몇번 연것이가, m=메뉴선택 s=정렬선택
  char fname[100],n1[100];
  int i=0,j=0,k;
  struct info *p,*q;//q는 바꾸기
  p=(struct info *)malloc(10*sizeof(struct info));
  if(p==NULL){
    printf("동적 메모리 할당에 실패하였습니다.\n");
    exit(1);
  }

  while(1){
    printf("1)Insert\n2)Sort\n3)Quit\nSelect a menu :");
    scanf("%d",&m);

    if(m==1) {
      printf("File name :");
      scanf("%s", fname);
    
      if((fp=fopen(fname,"r"))==NULL){
       fprintf(fp,"파일 %s를 열 수 없습니다.\n",  fname);
       return 0;
      }

      if(strcmp(fname,"input1.txt")==0){
        while(!feof(fp)){
          fscanf(fp,"%s %d %d %d %d",n1,&n2,&n3,&n4,&n5);
          if((n2<0)||(n3<0)||(n4<0)||(n5<0)){
            printf("Result : The age cannot be a negative number. Program terminates.\n");
            a1--;//a1이 음수이면 밑에 if문 출력 x
            break;
          }
          else{
            strcpy((p+i)->name,n1);
            (p+i)->age=n2;
            (p+i)->mth=n3;
            (p+i)->eng=n4;
            (p+i)->his=n5;
            i++;
          }
        }

        if(a1==0){
          printf("No Name Age Math English History\n");

          for(j=0;j<i;j++){
            printf("%2d %s %d %d %d %d\n", j+1, (p+j)->name,(p+j)->age,(p+j)->mth,(p+j)->eng,(p+j)->his);
          }
        }        
        a1++;
      }
      else if(strcmp(fname,"input2.txt")==0){
        i=2;
        while(!feof(fp)){
          fscanf(fp,"%s %d %d %d %d",n1,&n2,&n3,&n4,&n5);
          
          if((n2<0)||(n3<0)||(n4<0)||(n5<0)){
            printf("Result : The age cannot be a negative number. Program terminates.\n");
            a2--;
            break;
          }
          else{
            strcpy((p+i)->name,n1);
            (p+i)->age=n2;
            (p+i)->mth=n3;
            (p+i)->eng=n4;
            (p+i)->his=n5;
            i++;
          }
        }

        if(a2==0){
          printf("No Name Age Math English History\n");

          for(j=2;j<i;j++){
            printf("%2d %s %d %d %d %d\n", j-1, (p+j)->name,(p+j)->age,(p+j)->mth,(p+j)->eng,(p+j)->his);
          }
        }  
        a2++;
        
      }
      fclose(fp);
    }        
  
    else if(m==2){
      if(a2==0){
        printf("Result : There is no data to be sorted. Program terminates.\n");
        break;
      }
      else{
        printf("1)Name\n2)Age\n3)Math\n4)English\n5)History\nChoose the field to sort by: ");
        scanf("%d",&s);
        if(s==1){
          for(j=2;j<i-1;j++){
            for(k=j+1;k<i;k++){
              if(strcmp((p+j)->name,(p+k)->name)==1){
                *q=*(p+j);
                *(p+j)=*(p+k);
                *(p+k)=*q;
              }
            }
          }
          printf("No Name Age Math English History\n");
          for(j=2;j<i;j++){
            printf("%2d %s %d %d %d %d\n", j-1, (p+j)->name,(p+j)->age,(p+j)->mth,(p+j)->eng,(p+j)->his);
          }
        }
        else if(s==2){
          for(j=2;j<i-1;j++){
            for(k=j+1;k<i;k++){
              if((p+j)->age > (p+k)->age){
                *q=*(p+j);
                *(p+j)=*(p+k);
                *(p+k)=*q;
              }
            }
          }
          printf("No Age Name Math English History\n");
          for(j=2;j<i;j++){
            printf("%2d %d %s %d %d %d\n", j-1, (p+j)->age,(p+j)->name,(p+j)->mth,(p+j)->eng,(p+j)->his);
          }
        }
        else if(s==3){
          for(j=2;j<i-1;j++){
            for(k=j+1;k<i;k++){
              if((p+j)->mth > (p+k)->mth){
                *q=*(p+j);
                *(p+j)=*(p+k);
                *(p+k)=*q;
              }
            }
          }
          printf("No Math Name Age English History\n");
          for(j=2;j<i;j++){
            printf("%2d %d %s %d %d %d\n", j-1, (p+j)->mth,(p+j)->name,(p+j)->age,(p+j)->eng,(p+j)->his);
          }
        }
        else if(s==4){
          for(j=2;j<i-1;j++){
            for(k=j+1;k<i;k++){
              if((p+j)->eng > (p+k)->eng){
                *q=*(p+j);
                *(p+j)=*(p+k);
                *(p+k)=*q;
              }
            }
          }
          printf("No English Name Age Math History\n");
          for(j=2;j<i;j++){
            printf("%2d %d %s %d %d %d\n", j-1, (p+j)->eng,(p+j)->name,(p+j)->age,(p+j)->mth,(p+j)->his);
          }
        }
        else if(s==5){
          for(j=2;j<i-1;j++){
            for(k=j+1;k<i;k++){
              if((p+j)->his > (p+k)->his){
                *q=*(p+j);
                *(p+j)=*(p+k);
                *(p+k)=*q;
              }
            }
          }
          printf("No History Name Age Math English\n");
          for(j=2;j<i;j++){
            printf("%2d %d %s %d %d %d\n", j-1, (p+j)->his,(p+j)->name,(p+j)->age,(p+j)->mth,(p+j)->eng);
          }
        }
      }
    }    

    else if(m==3){
      free(p);
      exit(1);
    }
  }
    return 0;
}