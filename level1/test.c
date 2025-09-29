#include <stdio.h>
#include <string.h>
#include "test3.h"
int main()
{
    while(1)                
    {
        m:;
        char entry[128]={'\0'};
        printf("please type your command:");
        scanf("%s",&entry);
        getchar();
        if(strcmp(entry,"Login")==0)                //输入登录时
        {
            char user[1]={'\0'};
            int result=-1;
            op: ;                        //用于判断是否登陆成功 
            user[0]=Loginf(entry);
            if(user[0]=='1')
            {
                printf("already exit\n");
                goto m;
            }
            if(user[0]=='2')
            {
                printf("already quit\n");
                return 0;
            }
            if(((int)user[0]<=90&&(int)user[0]>=45)||(user[0]=='0'))
            {
                int sign=-1;                        //判断何种操作
                printf("successfully!\n");
                char Operation[128]; 
                 printf("please type your operation:");                
                fgets(Operation,sizeof(Operation),stdin);
                switch(sign=decide(Operation,user[0]))
                {
                    case 0:
                        reserve(Operation,user[0]);
                        break;
                    case 1:
                        search(Operation,user[0]);
                        break;
                    case 2:
                        check(user[0]);
                        break;
                    case 3:
                        clear();
                        break;
                    case 4:
                        printf("alredy Quit\n");
                        return 0;
                    case 5:
                        printf("already exit\n");
                        goto op;
                    default:
                        printf("no such operation\n");
                        break;
                }                                   //进入判断
            } 
            else
            {
                printf("we can't find this name\n");
                continue;
            } 
        }
        else if(strcmp(entry,"Exit")==0)                 //输入离开时
        {
            printf("it is already the initial page!\n");
        }
        else if(strcmp(entry,"Quit")==0)
        {
            break;
        }
        else                                        //非可识别操作
        {
            printf("invalid operation\n");
        }
    }
    return 0;
}