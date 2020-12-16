#include "Ad_Matrix.h"

int main()
{
    FILE *fp=NULL;
    char name[100];
    char c,a,b;
    char line[100];
    char real[100]={};
    Queue *q=createQueue(100);
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
    g=createGraph(q->count);
    
    rewind(fp);//파일 포인터 처음부터
    
    while(fgets(line,100,fp)){
        a=line[0];
        b=line[2];
        newEdge(g,checkQueue(q,a),checkQueue(q,b));
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
            if(g->Node[m][l]==1) printf(" %c",real[l]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Depth First Traversal :");
    depthTraversal(g,0,real);
    printf("\n");
    printf("Breadth First Traversal :");
    breadthTraversal(g,0,real);
    
    fclose(fp);
    
    destroyQueue(q);
    destroyGraph(g);
    return 0;
}
