#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int m,char result[],char wait[]);

int main()
{
    FILE *fp;
    char entry[20]={'\0'};//输入的键值
    char value[20]={'\0'};
    int x=-1;//核验键的标志

    if((fp=fopen("Data.txt","r"))==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    while(!feof(fp))
    {
        printf("please input your keywords：");
        scanf("%s",entry);//输入键

        if((strcmp("Quit",entry))==0)
        {
            return 0;
        }

        char search[20]={'\0'};
        fgets(search,20,fp);//获取每行字符串

        for(int i=0;search[i]!='\n';i++)
        {
            if(search[i]==':')//检测是否有键
            {
                x=check(i,search,entry);//核验该键符合与否
            }
           if(x==0)//该行非该键或无键
            {
                break;
            }
            if(x==1)//与该行键相同，输出对应值
            {
                for(int j=i+1,p=0;search[j]!='\0';j++,p++)
                {
                    value[p]=search[j];
                }
                printf("the corresponding value is :%s",value);
                break;
            }
        }
        if(x==0)//文档中无该键
        {
            printf("there is no relative key!\n");
        }
         
    }
    fclose(fp);
    return 0;
}

int check(int m,char result[],char wait[])//核验键函数
{
    int sign=1;
    for (int k=0;k<m;k++)
    {
        if(result[k]!=wait[k])//若有不同，则输入键非该键
        {
            sign=0;
            break;
        }
    }
    return sign;
}