#include <stdio.h>
#include <string.h>
int main()
{
    char key1[6]="Dian";
    char key2[6]="Quit";
    char entry[32]={'\0'};
    int sign=-1;
    while(1)
    {
        printf("please enter:");
        fgets(entry,128,stdin);
        entry[strlen(entry)-1]='\0';
        //scanf("%s",&entry);
        if (strcmp(key1,entry)==0)
        {
            printf("2002\n");
            continue;
        }
        if (strcmp(key2,entry)==0)
        {
            return 0;
        }
        else
        {
            printf("Error\n");
            continue;
        }
    }
    return 0;
}