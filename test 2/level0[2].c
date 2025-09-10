#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int m,char result[],char wait[]);

int main()
{
    FILE *fp;
    char entry[20]={'\0'};
    char value[20]={'\0'};
    int x=-1;
    scanf("%s",entry);
    if((fp=fopen("Data.txt","r"))==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    while(!feof(fp))
    {
        char search[20]={'\0'};
        fgets(search,20,fp);
        for(int i=0;search[i]!='\0';i++)
        {
            if(search[i]==':')
            {
                x=check(i,search,entry);
            }
           if(x==0)
            {
                break;
            }
            if(x==1)
            {
                for(int j=i+1,p=0;search[j]!='\0';j++,p++)
                {
                    value[p]=search[j];
                }
                printf("%s",value);
                return 0;
            }
        }
         
    }
    if(x==0)
    {
        printf("there is no relative key!\n");
    }

    return 0;
}

int check(int m,char result[],char wait[])
{
    int sign=1;
    for (int k=0;k<m;k++)
    {
        if(result[k]!=wait[k])
        {
            sign=0;
            break;
        }
    }
    return sign;
}