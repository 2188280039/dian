#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Login "Login"
#define Exit "Exit"
#define Quit "Quit"

char Loginf();//登录函数
int decide(char s[]);//判定操作函数
int search(char m[],int n,char day[]);//查询函数
int reserve(char m[128],int n,char user[]);//预约函数
void search_reservation(char m[],int n,char user[]);//查询预约函数
void clear();//清除函数

int main()
{
    //FILE *fpUser;
    char sign='\0';
    char User[10];
    while(1)
    {
        //输入指令
        char entry[128]={'\0'};
        scanf("%s",&entry);
        getchar();
        if((strcmp(entry,"Login"))==0)
        {
           sign=Loginf();
            if(sign=='k')
            {
                printf("已退出登录\n");
                break;
            }
            sprintf(User,"%c.txt",sign);
            
            while(1)
            {
                char Operation[128]={'\0'};
                char save[128]={'\0'};
                int check=-1;

                fgets(Operation,sizeof(Operation),stdin);
                
                if((strcmp(Operation,"Quit\n"))==0)
                {
                    return 0;
                }
                if((strcmp(Operation,"Exit\n"))==0)
                {
                    printf("已退出该操作\n");
                    break;
                }

                
                int c=0;
                for(;Operation[c]!=' '&&Operation[c]!='\n';c++)
                {
                    save[c]=Operation[c];
                }//获取首个单词

                check = decide(save);//判断何种操作
                switch(check)
                {
                   case 0:
                        search(Operation,c,save);//调用查询函数
                        break;
                    case 1:
                        reserve(Operation,c,User);//调用预约操作
                        break;
                    case 2:
                        search_reservation(Operation,c,User);//调用预约查询操作
                        break;
                    case 3:
                        clear(User);
                        break;
                    default:
                        printf("非任何操作");
                        break;      
                }
            }
        }
        if((strcmp(entry,"Quit"))==0)
        {
            return 0;
        }
        if((strcmp(entry,"Exit"))==0)
        {
            printf("当前已在最初始页\n");
        }
    }
    //fclose(fpUser);
    return 0;
}

char Loginf()//登录
{
    int i=0;
    char entryUser[20];
    printf("请输入用户名：");
    scanf("%s",&entryUser);
    getchar();
    if((strcmp(entryUser,"Quit"))==0)
    {
        return 0;
    }
    if((strcmp(entryUser,"Exit"))==0)
    {
        printf("已退出");
        return 'k';
    }

    for(i=65;i<=90;i++)
    {
        if(entryUser[0]==(char)i)
        {
            printf("登陆成功\n");
            return entryUser[0];
        }
    }
    printf("无该用户!\n");
}

int decide(char s[])//判断操作函数
{
    int sign1=-1;
    char *p[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    for(int w=0;w<7;w++)
    {
        if((strcmp(s,p[w]))==0)
        {
            sign1=0;
            
        }
    }//判定为查询操作
    if(strcmp(s,"Reserve")==0)
    {
        sign1=1;
       
    }//判定为预约操作
    if(strcmp(s,"Reservation")==0)
    {
        sign1=2;
        
    }//判定为查询预约操作
    if(strcmp(s,"clear")==0)
    {
        sign1=3;
    }
    return sign1;
}

int search(char m[],int n,char day[])//查询某一日某层的函数
{
    FILE *search_Date_floor;
    char Day[20];

    sprintf(Day,"%s.txt",day);
    if((search_Date_floor=fopen(Day,"r"))==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    //打开该日文件

    char floor[5]="floor";//判断命令正确与否
    char day_seats[4][4];
    int sign2=-1;
    char ground='\0';
    int t=n+1;
    for(int s=0;m[t]!=' ';t++,s++)
    {
        if(floor[s]=m[t])
        {
            sign2=1;
        }
        else
        {
            sign2=-1;
        }
    }//判断是否为floor
    if(sign2==1)
    {
        ground=m[t+1];
    }//若的确是则获取楼层
    else
    {
        printf("错误操作");
        return 0;
    }//若不是，则结束该函数

    char x[16]={'\0'};
    for(int q=1;;q++)
    {
        fgets(x,16,search_Date_floor);
        if(x[0]==ground);
        {
            break;
        }
    }//定位到该楼层

    for(int q=1;q<=4;q++)
    {
        fgets(x,16,search_Date_floor);
        printf("%s",x);
    }//获取该楼层座位情况
    fclose(search_Date_floor);
}


int reserve(char m[128],int n,char user[])//预约函数
{
    FILE *Reserve_date;
    FILE *fpuser;
    char day[10]={'\0'};
    char tem_day[10]={'\0'};
    char Day[14]={'\0'};
    char seat[5][4][5]={{'0'},{'0'},{'0'},{'0'},{'0'}};
   
    for(int j=n+1,i=0;m[j]!=' ';j++,i++)
    {
        day[i]=m[j];
        tem_day[i]=m[j];
    }//获取该日

    snprintf(Day,15,"%s.txt",day);
    if((Reserve_date=fopen(Day,"r"))==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }//打开该日文件

    char x[20];
    for(int j=1;;j++)
    {
        fgets(x,20,Reserve_date);
        if(x[0]==m[n+14])
        {
            break;
        }
    }//定位到该楼层
    fclose(Reserve_date);

    if((Reserve_date=fopen(Day,"r"))==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }//打开该日文件
    char detect[128];
    int g=0;
    while(g<5)
    {
            for(;;)
            {
            fgets(detect,20,Reserve_date);
            if(strlen(detect)==2)
            {
                break;
            }
            }
            for(int j=0;j<4;j++)
            {
                fgets(seat[g][j],5,Reserve_date);
                getc(Reserve_date);
            }
            g++;
    }
    fclose(Reserve_date);

    //获取座位情况

    int q=0,w=0,r=0;
    q=(int)(m[n+14])-49;
    w=(int)(m[n+21])-49;
    r=(int)(m[n+23])-49;
    seat[q][w][r]='2';//更改

    if((Reserve_date=fopen(Day,"w"))==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }//打开该日文件

    char l[1]="1";
    for(int j=0;j<5;j++)
    {
        fputc(l[0],Reserve_date);
        fputs("\n",Reserve_date);
        for(int i=0;i<4;i++)
        {
            fprintf(Reserve_date,seat[j][i]);
            fputs("\n",Reserve_date);
        }
        l[0]=(char)((int)l[0]+1);
    }    //在该日文件中写入
    fclose(Reserve_date);
 
    if((fpuser=fopen(user,"a+"))==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    //登陆后输入操作
    fputs(tem_day,fpuser);
    fprintf(fpuser," %d %d %d",(int)(m[n+14])-48,(int)(m[n+21])-48,(int)(m[n+23])-48);
    fclose(fpuser);

    printf("done\n");
}

void search_reservation(char m[],int n,char user[])//查询用户函数
{
    FILE *fpuser;
    int i=0;
    char result[128][96];
    fpuser=fopen(user,"r");
    if((fpuser=fopen(user,"a+"))==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    while(!feof(fpuser))
    {
        fgets(result[i],40,fpuser);
        int j=0;
        for(;result[i][j]!=' ';j++)
        {
            printf("%c",result[i][j]);
        }
        printf(" floor %c seat %c %c\n",result[i][j+1],result[i][j+3],result[i][j+5]);
        i++;
    }
    fclose(fpuser);
}

void clear(char user[])//清除函数
{
    FILE *Ouser;
    Ouser=fopen(user,"r");
    if(Ouser==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    FILE *ODay;

    char record[20][128]={'\0'};
    char day[20]={'\0'};
    char seat[5][4][5]={{'0'},{'0'},{'0'},{'0'},{'0'}};
    for(int i=0;!feof(Ouser);i++)
    {
        char Day[20]={'\0'};
        fgets(record[i],128,Ouser);
        int j;
        for(j=0;record[i][j]!=' ';j++)
        {
            day[j]=record[i][j];
        }//获取用户该行预约情况
        snprintf(Day,20,"%s.txt",day);
        ODay=fopen(Day,"r");
        if(ODay==NULL)
        {
            printf("Error\n");
            exit(EXIT_FAILURE);
        }
        for(int p=0;!feof(ODay);p++)
        {
            for(int h=0;h<4;h++)
            {
                char m[6];
                fgets(m,6,ODay);
                if(strlen(m)==2)
                {
                    p--;
                    break;
                }
                else
                {
                    for(int s=0;s<4;s++)
                    {
                        seat[p][h][s]=m[s];
                    }
                    
                }
            }

        }//获取座位情况
        int u=(int)(record[i][j+1])-49;
        int v=(int)(record[i][j+3])-49;
        int w=(int)(record[i][j+5])-49;
        seat[u][v][w]='0';//取消该预约
        fclose(ODay);


        ODay=fopen(Day,"w");
        if(ODay==NULL)
        {
            printf("Error\n");
            exit(EXIT_FAILURE);
        }
        char l[1]="1";
        for(int a=0;a<5;a++)
        {
            fputc(l[0],ODay);
            fputs("\n",ODay);
            for(int b=0;b<4;b++)
            {
                fprintf(ODay,seat[a][b]);
                printf("%s",seat[a][b]);
                fputs("\n",ODay);
                printf("\n");
            }
            l[0]=(char)((int)l[0]+1);
        }    //在该日文件中写入
            fclose(ODay);
    }//完成对用户预约取消


   


    fclose(Ouser);
    Ouser=fopen(user,"w");
    if(Ouser==NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
   
    fclose(Ouser);
    printf("已完成清除");
}