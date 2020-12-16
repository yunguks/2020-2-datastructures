#include <stdio.h>
#include <string.h>

int main()
{
    char name[50];
    int age;
    char sex;
    char *namep;
    char s[2] = " ";
    
    while(1){
        printf("Provide your personal information :\n");
        
        printf("Name : ");
        scanf(" %[^\n]s", name);
        if(strcmp(name, "stop")==0) break;
        fflush(stdin);
        
        printf("Age : ");
        scanf(" %d",&age);
        
        printf("Sex(M/F) : ");
        scanf(" %c",&sex);
        
        printf("Your name is ");
        
        namep = strtok(name,s);

        while(namep != NULL){
            printf("%s ",namep);
            
            namep = strtok(NULL,s);
        }
    
        printf(",your age is %d, your sex is %c.\n",age,sex);
    }
    
    return 0;
}