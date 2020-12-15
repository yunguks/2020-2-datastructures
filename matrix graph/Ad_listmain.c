#include "Ad_List.h"

int main()
{
    FILE *fp=NULL;
    char name[100];
    char c,a,b;
    char line[100];
    char real[100]={};
    Queue *q=createQueue(30);
    Graph *g;
    int i,m,l;
    
    
    printf("FIle name of a graph : ");
    scanf("%s",name);
    
    fp=fopen(name,"r");
    
    if(fp==NULL){
        printf("파일 열기에 실패했습니다.\n");
        exit(1);
    }
    
    while((c=fgetc(fp))!=EOF){
        if(c!='\n'&&c!=' '&&c!='\0'&&c!=EOF){
            if(checkQueue(q,c)==-1) enQueue(q,c);
        }
    }
    sortQueue(q);
    deQueue(q);//'\0'를 빼지못해 dequeue로 뺏음
    printQueue(q);
    
    g=createGraph(0);
    
    i=0;//배열에 abcd 삽입
    while(q->count){
        real[i]=deQueue(q);
        c=real[i];
        insertVertex(g,&c);
        i++;
    }
    
    rewind(fp);//파일 포인터 처음부터
    
    while(fgets(line,100,fp)){
        a=line[0];
        b=line[2];
        insertArc(g,&a,&b);
    }

    printf("\nThe graph is :\n");
    for(m=0;m<g->count;m++){
        printf("%c :",real[m]);
        //printVertex(g->first);
        printf("\n");
    }
    printf("\n");
    printf("Depth First Traversal :");
    depthTraversal(g->first);
    printf("\n");
    printf("Breadth First Traversal :");
    //breadthTraversal(g,0,real);
    
    fclose(fp);
    
   
    destroyGraph(g);
    destroyQueue(q);
    return 0;
}
