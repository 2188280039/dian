#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    FILE *fp;
    char entry[20]={'\0'};//输入的键值
    char keyvalue[40]={'\0'};
    int x=-1;//核验键的标志

    

    for(;1;)
    {
        if((fp=fopen("data.txt","r"))==NULL)
        {
            printf("Error\n");
            exit(EXIT_FAILURE);
        }
        int x=0;
        printf("please enter key:");
        fgets(entry,20,stdin);
        entry[strlen(entry)-1]='\0';
        if(strcmp(entry,"Quit")==0)
        {
            return 0;
        }
        while(!feof(fp))
        {
            char key[10]={'\0'};
            char value[10]={'\0'};

            fgets(keyvalue,40,fp);
            sscanf(keyvalue,"%[^:]:%s",key,value);

            if((strcmp(entry,key))==0)
            {
                x=0;
                printf("the corresponding value is:%s\n",value);
                break;
            }
            else
            {
                x=1;
                continue;
            }
        }
        if(x==1)
        {
            printf("Error\n");
        }
    }
    
    fclose(fp);
    return 0;
}

