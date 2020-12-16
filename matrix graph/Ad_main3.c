#include "Ad_Matrix3.h"

int main()
{
    FILE *fp=NULL;
    char name[100];
    char a,b;
    char line[100];
    char real[100]={};
    Queue *q=createQueue(100);
    Graph *g;
    int i,m,l,w;
    
    
    printf("FIle name of a graph : ");
    scanf("%s",name);
    
    fp=fopen(name,"r");
    
    if(fp==NULL){
        printf("파일 열기에 실패했습니다.\n");
        exit(1);
    }
    while(fgets(line,100,fp)){
        a=line[0];
        b=line[2];
        if(checkQueue(q,a)==-1) enQueue(q,a);
        if(checkQueue(q,b)==-1) enQueue(q,b);
    }

    sortQueue(q);
    g=createGraph(q->count);
    
    rewind(fp);//파일 포인터 처음부터
    
    while(fgets(line,100,fp)){
        a=line[0];
        b=line[2];
        w=(int)line[4]-(int)'0';
        newEdge(g,checkQueue(q,a),checkQueue(q,b),w);
    }
    i=0;//배열에 abcd 삽입
    while(q->count){
        real[i]=deQueue(q);
        i++;
    }
    printf("\nThe graph is :\n");
    for(m=0;m<g->vertex;m++){
        printf("%c :",real[m]);
        for(l=0;l<g->vertex;l++){
            if(g->Node[m][l]==1) printf(" %c (%d)",real[l],g->weight[m][l]);
        }
        printf("\n");
    }
    
    fclose(fp);
    
    destroyQueue(q);
    destroyGraph(g);
    return 0;
}
