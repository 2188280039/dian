#include <stdio.h>
#include <string.h>
int main()
{
    char key1[5]="Dian";
    char key2[5]="Quit";
    char entry[32]={'\0'};
    int sign=-1;
    while(1)
    {
        printf("请输入：");
        for(int i=0;i<32;i++)
            {
                scanf("%c",&entry[i]);
                if(entry[i]=='\n')
                {
                    entry[i]='\0';
                    break;
                }
            }
        
        if (strcmp(key1,entry)==0)
        {
            printf("2002\n");
        }
        if (strcmp(key2,entry)==0)
        {
            return 0;
        }
        else
        {
            printf("Error\n");
        }
    }
    return 0;
}