#include <stdio.h>

int main(void) {
    FILE *filepointer;
    char dataToBeWritten[50]="Akash is such a dickhead";
    filepointer = fopen("GFGTest.c","w");
    if(filepointer == NULL){
        printf("GFGTest.c file failed to open");
    }
    else{
        printf("The file is no opened");
        if(strlen(dataToBeWritten)>0){
            fputs(dataToBeWritten,filepointer);
            fputs("\n",filepointer);
        }
        fclose(filepointer);
        printf("Data succesfully written in gfgtext.c\n");
        printf("The file is now closed");
    }
	return 0;
}

