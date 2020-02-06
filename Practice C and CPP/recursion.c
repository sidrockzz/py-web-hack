#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int main()
{
    char nt,a[]={'\0','\0','\0','\0','\0'},b;
    int num,i,index=3,j=0,k=4;
    char p[10][SIZE];
    printf("Enter the number of productions:");
    scanf("%d",&num);
    printf("Enter the grammar as E->E|A:\n");
    for(i=0;i<num;i++){
        scanf("%s",p[i]);
    }
    for(i=0;i<num;i++){
        printf("\n GRAMMAR ::: %s",p[i]);
        nt = p[i][0];
        if(nt == p[i][index]){
            for(j=1;p[i][k]!='|';j++){
                a[j]=p[i][k];
                k++;
            }
            printf("is left recursive");
            while(p[i][index]!=0 && p[i][index]!='|')
            index++;
            if(p[i][index]!=0){
                b=p[i][index+1];
                printf("grammar without left recursion\n");
                printf("%c->%c%c\`",nt,b,nt);
                printf("\n%c\`",nt);
                for(j=1;a[j]!='\0';j++)
                printf("%c",a[j]);
                printf("%c\`|999",nt);
            }
            else
        
                printf("Cant be reduced\n");
            
        }
         else
            
                printf("is not left recursive\n");
    }
    return 0;
}