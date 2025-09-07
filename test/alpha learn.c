
/*素数
#include <stdio.h>
int main()
{
    int num;
    int sign=1;
    scanf("%d",&num);
    for(int i=1;i<num/2;i++)
    {
        if(num%i==0)
        {
            sign=0;
            break;
        }
    }
    if(sign!=0)
    {
        printf("y");
 
    }
    else
    {
        printf("n");
    }
    return 0;
}



{
    int num;
    int sign=1;
    int i=2;
    scanf("%d",&num);
    while(i<num/2)
    {
        if(num%i==0)
        {
            sign=0;
            break;
        }
        i++;
    }
    if(sign==1)
    {
        printf("y");
    }
    else
    {
        printf("n");
    }
    return 0;
}*/


/*ASCII码
#include <stdio.h>
int main()
{
    char a;
    for(int i=32;i<=126;i++)
    {
        a=(char)i;
        printf("%d %-2c",i,a);
        if(i%2==0)
        {
            printf("\n");
        }
    }
    return 0;
}*/


/*i++和++i
#include <stdio.h>
int main()
{
    int i=5;
    int j;
    j=i++;
    printf("%d\n",j);
    j=++i;
    printf("%d\n",j);
    return 0;
}*/
//i++ : 先赋值再自增
//++i ：先自增再赋值

//条件运算符
/*#include <stdio.h>

int main()
{
    int i=1;
    int j;
    j=i>1?1:0;
    printf("%d",j);
    return 0;
}*/

//类型大小
/*#include <stdio.h>
int main()
{
    printf("%d %d %d %d",sizeof(int),sizeof(float),sizeof(double),sizeof(char));
    return 0;
}*/


//字符串处理
//#include <stdio.h>
//#include <string.h>
//int main()
//{
    /*
        strlen()  获取字符串长度：字符个数
    
    char str[]="sp tq";
    printf("%d %d %d", strlen(str),sizeof(str));//字符串尺寸包含\0
    */

    //拷贝字符串 strcpy strncpy
    //char str1[]="my";//3
    //char str2[]="spumpp";//5
    //int result;

   /*strncpy(str2,str1,8);
   printf("%s\n%s\n",str1,str2);

   strncpy(str1,str2,8);
   printf("%s\n%s\n",str1,str2);
    return 0;*/

    //连接字符串strcat strncat
   /* strcat(str1,str2);
    printf("%s",str1);
    //strncat(限制连接的字符数)
    */
    //比较字符串strccmp strncmp
    /*result=strcmp(str1,str2);
    printf("%d",result);//前小于后则为-1；前大于后则为1；相等为0（采用求和比较）
    */
//}

//二维数组
/*#include <stdio.h>
int main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int i,j=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%-2d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/

//指针
#include <stdio.h>
int main()
{
    
   /*
    char a=9,m='r';
    char *p=a,*i=&m;//此处*为定义式符号，获取变量地址，变量地址存储在p和i中
    printf("%d %d",p,*i);//此处的*代表取地址运算，将i储存的地址的相应变量取出
    */

    
    /*
    char a[2];
    printf("%p\n%p",a,&a[0]);//数组名为指向第一个元素的地址
    */

    //关于各种类型数组地址，相邻的数组之间的地址相差一个该类型所差的字节（一个地址占一个字节）
    //数组名只是一个地址，而指针则是一个左值（可变）

    char *f='u';
   char *p[5]={
        "mm",
        "pp",
        "oo",
        "qq",
        "tt"
    };//指针数组，p[1],p[2]……均存放地址
    //int (*p)[5];//数组指针
    for(int i=0;i<5;i++)
    {
        printf("%s",p[i]);//此处需注意，字符串的输出用的是数组名（地址），则可用p[i]代替（地址）
    }
    printf("%c",f);
    return 0;
}