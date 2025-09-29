#include <stdio.h>
#include <errno.h>
#include <string.h>
char *day[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

char Loginf()//登录函数
{
    char username[20]={'\0'};
    printf("please type your name(If you are the administrator, please enter 0):");
    scanf("%s",&username);
    if(strcmp(username,"Exit")==0)
    {
        return '1';
    }
    if(strcmp(username,"Quit")==0)
    {
        return '2';
    }
    getchar();
    return username[0];
}

int decide(char operation[],char User)//判定操作函数
{
    int sign_ = -1;
    char first_word[128] = {'\0'};
    for( int i=0; (operation[i] != ' ') && ( operation[i] != '\n' ); i++ )
    {
        first_word[i]=operation[i];
    }

    if(strcmp(first_word,"Reserve")==0)//判断预约操作
    {
        sign_=0;
        return sign_;
    }
    for(int j=0;j<7;j++)//判断查询日期函数
    {
        if(strcmp(first_word,day[j])==0)
        {
            sign_=1;
            return sign_;
        }
    }
    if(strcmp(first_word,"Reservation")==0)//判断查询用户预约函数
    {
        sign_=2;
        return sign_;
    }
    if(strcmp(first_word,"clear")==0)//判断清除函数
    {
        sign_=3;
        if(User!='0')
        {
            printf("you can't do this operation!");
            sign_=-1;
        }
        return sign_;
    }
    if(strcmp(first_word,"Quit")==0)//判断清除函数
    {
        sign_=4;
        return sign_;
    }
    if(strcmp(first_word,"Exit")==0)//判断清除函数
    {
        sign_=5;
        return sign_;
    }
}

int search(char operation[],char User)//查询函数
{
    
    FILE *DayFile;
    char Day[10]={'\0'};
    char Dayf[20]={'\0'};
    char floor;
    char seat[4][5];

    sscanf(operation,"%s Floor %c\n",&Day,&floor);//获取日期及楼层

    sprintf(Dayf,"%s.txt",Day);
    DayFile=fopen(Dayf,"r");
    if(DayFile==NULL)
    {
        printf("error\n%s\n",strerror(errno));
        return 1;
    }//打开该日文件

    for(;!feof(DayFile);)
    {
        fgets(seat[0],5,DayFile);
        if(seat[0][0]==floor)//定位至该层
        {
            for(int j=0;j<4;j++)
            {
                fgets(seat[j],6,DayFile);
                printf("%s",seat[j]);//获取座位并输出
            }
            break;
        }
    }
}

int reserve(char operation[],char userf)//预约函数
{
    if(userf=='0')
    {
        printf("which user do you want to help reserve:");
        scanf("%c",&userf);
    }
    FILE *openday;
    char Day[20]={'\0'};
    char day[20]={'\0'};
    char userfile[10]={'\0'};
    int floor;
    int row;
    int column;
    sscanf(operation,"Reserve %s Floor %d Seat %d %d",&day,&floor,&row,&column);//获取日期，楼层，座位

    sprintf(userfile,"%c.txt",userf);
    sprintf(Day,"%s.txt",day);
    openday=fopen(Day,"r");
    if(openday==NULL)
    {
        printf("error\n%s\n",strerror(errno));
        return 1;
    }//打开文件

    char seat[5][4][5]={{'0'},{'0'},{'0'},{'0'},{'0'}};//声明座位
    char sign1[10]={'\0'};//用于判断是否到达该层次
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            fgets(seat[i][j],10,openday);
            if(strlen(seat[i][j])==2)
            {
                j--;
            }
        }
    }
    seat[floor-1][row-1][column-1]='2';//将位置信息录入座位数组
    fclose(openday);


    char l='1';
    openday=fopen(Day,"w");
    if(openday==NULL)
    {
        printf("error\n%s\n",strerror(errno));
        return 1;
    }//打开文件
   
        
    for(int i=0;i<5;i++)
    {
        fputc(l,openday);
        fputc('\n',openday);
        for(int j=0;j<4;j++)
        {
            
            for(int m=0;m<5;m++)
            {
                fputc(seat[i][j][m],openday);
            }
        }
        l=(char)((int)l+1);//在日期文件中写入
    }
        
    fclose(openday);

    FILE *User;
    User=fopen(userfile,"a+");
    if(User==NULL)
    {
        printf("error\n%s\n",strerror(errno));
        return 1;
    }//打开文件
    fprintf(User,"%s %d %d %d\n",day,floor,row,column);
    fclose(User);
    printf("reserve successfully!\n");
}

int check(char User)//查询预约函数
{
    if(User=='0')
    {
        printf("which user do you want to search:");
        scanf("%c",&User);
    }
    FILE *userf;
    char UserFile[20]={'\0'};
    char record[20][128];
    sprintf(UserFile,"%c.txt",User);
    userf=fopen(UserFile,"r");
     if(userf==NULL)
    {
        printf("error\n%s\n",strerror(errno));
        return 1;
    }//打开文件
    for(int i=0;!feof(userf);i++)
    {
        fgets(record[i],128,userf);
        printf("%s",record[i]);
    }
}

int clear()//清除函数
{
    char User;
    printf("please enter the user you want to clear:");
    scanf("%c",&User);
    FILE *UserF;
    FILE *DAY;
    char UserFile[20]={'\0'};
    char seat[5][4][6];
    char record[128];
    char day[20]={'\0'};
    int floor;
    int row;
    int column;
    char Dayf[20];
    sprintf(UserFile,"%c.txt",User);
    UserF=fopen(UserFile,"r");
    if(UserF==NULL)
    {
        printf("error\n%s\n",strerror(errno));
        return 1;
    }//打开文件
    for(;!feof(UserF);)
    {
        fgets(record,128,UserF);
        sscanf(record,"%s %d %d %d",&day,&floor,&row,&column);
        sprintf(Dayf,"%s.txt",day);
        DAY=fopen(Dayf,"r");
        if(DAY==NULL)
        {
            printf("error\n%s\n",strerror(errno));
            return 1;
        }//打开文件
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<4;j++)
            {
                fgets(seat[i][j],10,DAY);
                if(strlen(seat[i][j])==2)
                {
                    j--;
                }
            }
        }
        seat[floor-1][row-1][column-1]='0';
        fclose(DAY);
    }//取得数据
    fclose(UserF);
    
    DAY=fopen(Dayf,"w");
    if(DAY==NULL)
    {
        printf("error %s or no record\n",strerror(errno));
        return 1;
    }//打开文件
     char l='1';
    for(int i=0;i<5;i++)
    {
        fputc(l,DAY);
        fputc('\n',DAY);
        for(int j=0;j<4;j++)
        {
            
            for(int m=0;m<5;m++)
            {
                fputc(seat[i][j][m],DAY);
            }
        }
        l=(char)((int)l+1);//在日期文件中写入
    }
    fclose(DAY);//写入数据

    UserF=fopen(UserFile,"w");
    if(UserF==NULL)
    {
        printf("error\n%s\n",strerror(errno));
        return 1;
    }//打开文件
    fclose(UserF);
    printf("done!");
}