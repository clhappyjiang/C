#include <stdio.h>
#define N 1000 
 #include"stdafx.h"
#include <stdio.h>
#include<string.h> 
# include <stdlib.h>
typedef struct student  //定义结构体
{
	char number[30];   //手机号
	char name[30]; //姓名
	char chengji[30];      //年龄
	char zhiye[30];      //职业
	char shenfenzheng[40];      //身份证号
	char sex[15];      //性别
	char address[15];      //居住地
	char status[15];      //状态
}STUDENT;
STUDENT student[N]; 
int renshu = 0 ;


void jiaoshi () ; //  教师管理界面  0
void shanchu () ; //  删除学生信息
void xiugai  () ; //  修改学生信息  
void denglu  () ; //  登录界面  0  
void dengji  () ; //  登记学生信息 0
void tuichu  () ; //  退出系统  0
void chaxun  () ; //  查询学生信息
void xianshi () ; //  显示全部学生信息 0
void zhanghao() ; //  账号密码登录  0
void paixu   () ; //  学生成绩排序


void dengji()                                      //成绩的录入与添加函数
 {
	FILE *fp;
	int i = 0 , n = 0 ;
	char sign='y';                              //首先定义sing='y'
	system( "cls ");                             //清屏函数  系统中调用
d : if(sign =='y')                    //其实只有当输入N或n时才跳出循环
    {
	    printf(" ----用户纪录添加----\n");
 	    printf("\t\t\t手机号：");
	    scanf("%s",student[i].number);
	    printf("\t\t\t姓名: ");
	    scanf("%s",student[i].name); 
	    printf("\t\t\t年龄：");
		scanf("%s",&student[i].chengji);
		printf("\t\t\t职业：");
		scanf("%s",&student[i].zhiye);
		printf("\t\t\t身份证号：");
		scanf("%s",&student[i].shenfenzheng);
		printf("\t\t\t性别：");
		scanf("%s",&student[i].sex);
		printf("\t\t\t居住地：");
		scanf("%s",&student[i].address);
		printf("\t\t\t状态：");
		scanf("%s",&student[i].status);


e :     printf("\t\t\t是否继续添加（y/n）");
	    scanf("\t%c",&sign);
	    i++;
		n++ ;
		goto d ;
	}
	
	else if(sign == 'n') 
	{
		FILE *fp;
	    fp=fopen("student.txt","a");
	    for(i=0;i<n;i++)
		{
		    fprintf(fp,"%s %s %s %s %s %s %s %s \n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status);
		}
	    fclose(fp);
		jiaoshi() ;
		
	}
	
	else 
	{
		printf("\t\t\t输入错误.") ;
		goto e ;
	}

 }


void duqu() //读取用户信息信息
{
	char *p="student.txt";
	FILE *fp;
	int i=0;
	if((fp=fopen("student.txt","r"))==NULL)
	{
		printf("Open file %s error! Strike any key to exit!",p);
		system("pause");
		exit(0);
	}
	while(fscanf(fp,"%s %s %s %s %s %s %s %s \n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status)==8)
	{
		i++;
	}
	fclose(fp);
	renshu = i;
}
void paixu()
 {
	FILE *fp;
	struct student temp;                               //定义临时数组用于交换时存放数组信息用于后面的交换//
	int sum;                                         //总分
	int s[100];
    int i=0 ;
	int j,k,t;
	int m;
	duqu() ;
	system("cls");
	printf("\t\t\t选择排序方式:\n");
    printf("\t\t\t┌──────┐\n");
    printf("\t\t\t│1------手机号\n");
    printf("\t\t\t│2------年龄 │\n");
	printf("\t\t\t│3------返回 │\n");
    printf("\t\t\t│            │\n");
    printf("\t\t\t└──────┘\n");
	printf("\t\t\t请输入你要排序的方式\n");
	scanf("%d",&m);
	system("cls");
	while(m!=1&&m!=2&&m!=3)
		{
			printf("\t\t\t输入错误请重新输入\n");
	        scanf("%d",&m);
	    }
   
   if(m==1)
	  {
	  for(i=0;i<renshu-1;i++)                           //采用冒泡法进行排序//
	  {
		 k=i;
	    for(j=i+1;j<renshu;j++)
	    if(student[j].number>student[k].number)                              //排序//比较大小//
	    k=j;
		temp=student[k];student[k]=student[i];student[i]=temp;                  //当符合条件时进行数据交换//
		}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("\t\t学号\t\t姓名\t\t成绩              \n");
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	    for(i=0;i<renshu;i++)
	        printf("\t\t%s\t\t%s\t\t%d \n",student[i].number,student[i].name,student[i].chengji);
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			system("pause");
			jiaoshi() ;
		}

	if(m==2)
	  {
		for(i=0;i<renshu-1;i++)
		 {
			k=i;
	        for(j=i+1;j<renshu;j++)
			if(student[j].chengji>student[k].chengji)
			     k=j;
		    temp=student[k];student[k]=student[i];student[i]=temp;
		  }
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("\t\t学号\t\t姓名\t\t成绩              \n");
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	    for(i=0;i<renshu;i++)
	        printf("\t\t%s\t\t%s\t\t%d \n",student[i].number,student[i].name,student[i].chengji);
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			system("pause");
			jiaoshi() ;
	    }
	if(m==3)
	  {
		jiaoshi() ;
      }
      system("pause");
}

void chaxun() /*查询用户信息*/
{
	int i, t , flag;
	char s1[21];
	duqu() ;
	printf("\t\t\t\n请选择查询方式:\n");
    printf("\t\t\t┌──────┐\n");
	printf("\t\t\t│1------姓名 │\n");
    printf("\t\t\t│2------手机号\n");
    printf("\t\t\t│3------返回 │\n");
    printf("\t\t\t│            │\n");
    printf("\t\t\t└──────┘\n");
	while(1)
	{
		printf("\t\t\t请选择子菜单编号：");
		scanf("%d",&t);
		flag=0;
		switch(t)
		{
		case 1:
			printf("\n\t\t\t请输入要查询的用户的姓名：");
			scanf("%s",s1);
			for(i=0;i<renshu;i++)
				if(strcmp(student[i].number,s1)==0)
				{
					flag=1;
     	            printf("\t\t手机号: %s\n",student[i].number);
	                printf("\t\t姓名: %s\n",student[i].name);
	                printf("\t\t年龄: %s\n",student[i].chengji);
					printf("\t\t职业: %s\n",student[i].zhiye);
					printf("\t\t身份证号: %s\n",student[i].shenfenzheng);
					printf("\t\t性别: %s\n",student[i].sex);
					printf("\t\t居住地: %s\n",student[i].address);
					printf("\t\t状态: %s\n",student[i].status);
				}
			if(flag==0)
				printf("\t\t该姓名不存在!\n\n");
			break;
		case 2:
			printf("\n\t\t\t请输入要查询的用户的手机号：");
			scanf("%s",s1);
			for(i=0;i<renshu;i++)
				if(strcmp(student[i].name,s1)==0)
				{
					flag=1;
				   	printf("\t\t手机号: %s\n",student[i].number);
	                printf("\t\t姓名: %s\n",student[i].name);
	                printf("\t\t年龄: %s\n",student[i].chengji);
					printf("\t\t职业: %s\n",student[i].zhiye);
					printf("\t\t身份证号: %s\n",student[i].shenfenzheng);
					printf("\t\t性别: %s\n",student[i].sex);
					printf("\t\t居住地: %s\n",student[i].address);
					printf("\t\t状态: %s\n",student[i].status);
				}
			if(flag==0)
				printf("\t\t该学号不存在!\n\n");
			break;
		case 3:jiaoshi();break ;
		default:printf("\t\t\t请在1-3之间选择\n");
		}
	}
}

void zhanghao()  // 账号登录界面
{
	int n;	
	printf("\t\t\t\t输入0返回上菜单\n") ;
b :	printf("\t\t\t\t请输入管理员登录密码: ") ;
    scanf ("%d",&n) ;
	switch(n)
	{
	    case 123 : jiaoshi() ; break ;
		case 0   : denglu()  ; break ;
		default : 
			{
				printf("\t\t密码错误。\n") ;
				goto b ;
			}
	}
}

void shanchu()/*删除信息*/
{
	FILE *fp;
	int i,j,flag=0;
	char s1[20];
	duqu() ;
	printf("\t\t\t请输入要删除用户的手机号：");
	scanf("%s",s1);
	for(i=0;i<renshu;i++)
		if(strcmp(student[i].number,s1)==0)
		{
			flag=1;
			for(j=i;j<renshu-1;j++)
				student[j]=student[j+1];
		}
		if(flag==0)
			printf("\t\t\t该手机号不存在！\n");
	    else
		{
			printf("\t\t\t删除成功.\n");
			renshu-- ;
		}
		system("pause");
	    fp=fopen("student.txt","w");
	    for(i=0;i<renshu;i++)
		{
		    fprintf(fp,"%s %s %s %s %s %s %s %s \n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status);
		}
	    fclose(fp);
		jiaoshi() ;
}

void tuichu()  // 退出程序
{
     int a;
     char ch;
     printf("\t\t\t\t是否确定退出？请选择 y or n:  ");
     getchar();
     ch=getchar();
     if(ch=='y'||ch=='Y') 
	 {
		 exit(0);
	 }
	
     else
     denglu();
     
}

void xiugai()/*修改信息*/
{
	FILE *fp;
	int i , t , num ;
	char s1[10] ,s2[20];
	printf("\t\t\t请输入要修改的用户的手机号：\n");
	scanf("%s",s1);
	duqu () ;
	for(i=0;i<renshu;i++)
	if(strcmp(student[i].number,s1)==0)
		num = i;
	printf("\n\t\t\t请选择查询方式:\n");
    printf("\t\t\t┌──────┐\n");
	printf("\t\t\t│1--修改姓名 │\n");
    printf("\t\t\t│2--修改年龄 │\n");
	printf("\t\t\t│3--注销     │\n");
    printf("\t\t\t│4------返回 │\n");
    printf("\t\t\t│            │\n");
    printf("\t\t\t└──────┘\n");
	while(1)
	{
		printf("\t\t\t请选择子菜单的编号：");
		scanf("%d",&t);
		switch(t)
		{
		case 1:
			printf("\t\t\t请输入新的姓名：");
			scanf("%s",s2);
            strcpy(student[num].name,s2);
			fp=fopen("student.txt","w");
	        for(i=0;i<renshu;i++)
			{
		        fprintf(fp,"%s %s %s %s %s %s %s %s \n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status);
			}
	        fclose(fp);
			break ;
		case 2:
			printf("\t\t\t请输入新的年龄：");
			scanf("%s",&student[num].chengji );	
			fp=fopen("student.txt","w");
	        for(i=0;i<renshu;i++)
			{
		        fprintf(fp,"%s %s %s %s %s %s %s %s \n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status);
			}
	        fclose(fp);
		    break;
		case 3:
			printf("\t\t\t请输入注销状态：");
			scanf("%s",&student[num].status );	
			fp=fopen("student.txt","w");
	        for(i=0;i<renshu;i++)
			{
		        fprintf(fp,"%s %s %s %s %s %s %s %s \n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status);
			}
	        fclose(fp);
		    break;
		case 4:jiaoshi();break ;
		default:printf("\t\t\t请在1-3之间选择\n");
		}

	}

    jiaoshi() ;
}

void xianshi()//显示当前用户信息
{
	int i , t ;
	system( "cls ");
	duqu() ;
	printf("\t\t所有用户的信息为：\n");
 	printf("\t\t\t手机号\t姓名\t年龄\t职业\t身份\t性别\t居住地\t状态 \n") ;
	for(i=0;i<renshu;i++)
	{
	    printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status) ;
	}
	printf("\n\n\n\t\t\t请选择查询方式:\n");
    printf("\t\t\t┌──────┐\n");
	printf("\t\t\t│1------删除 │\n");
    printf("\t\t\t│2------修改 │\n");
    printf("\t\t\t│3------返回 │\n");
    printf("\t\t\t│            │\n");
    printf("\t\t\t└──────┘\n");
	while(1)
	{
		printf("\t\t\t请选择子菜单编号：");
		scanf("%d",&t);
		switch(t)
		{
		case 1:
			shanchu() ;
			break;
		case 2:
			xiugai() ;
			break;
		case 3:jiaoshi();break ;
		default:printf("\t\t\t请在1-3之间选择\n");
		}
	}
    system("pause");
	jiaoshi() ;

}

void jiaoshi()  // 教师界面
{
	int n;
	system("cls");
	printf("\t\t\t\t ╭-----------------------╮ \n") ;
	printf("\t\t\t\t│营业厅信息管理系统(管理员)│\n") ;
    printf("\t\t\t\t╰-------------------------╯\n") ;
	printf("\t\t\t\t┌────────——─┐\n") ;
	printf("\t\t\t\t│ 1.开户               │\n") ;
	printf("\t\t\t\t│ 2.查询               │\n") ;
	printf("\t\t\t\t│ 3.显示全部信息       │\n") ;
	printf("\t\t\t\t│ 4.删除用户           │\n") ;
	printf("\t\t\t\t│ 5.修改用户信息       │\n") ;
	printf("\t\t\t\t│ 7.退出系统           │\n") ;
    printf("\t\t\t\t│ 0.返回登录界面       │\n") ;
	printf("\t\t\t\t│                      │\n") ;
	printf("\t\t\t\t│                      │\n") ;
	printf("\t\t\t\t└─────────——┘\n") ;
b:	printf("\t\t\t\t请选择想操作选项:") ;
    scanf ("%d",&n) ;
	switch(n)
	{
	    case 0 : denglu() ; break ;
		case 1 : dengji() ; break ;
		case 2 : chaxun() ; break ;
	    case 3 : xianshi(); break ;
		case 4 : shanchu(); break ;
        case 5 : xiugai (); break ;
		case 7 : tuichu() ; break ;
		default : 
			{
				printf("\t\t输入错误。\n") ;
				goto b ;
			}
	}
}

   
void denglu()   // 教师账号登录
 { 	 
	 
     int a ;
	 char r ;
     system("cls"); 
	 printf("\t\t\t\t欢迎进入营业厅管理系统登录界面\n") ;
	 printf("********************************************************************************\n") ;
	 printf("\t\t\t\t1.管理员登录\n") ;
	 printf("\t\t\t\t2.退出系统\n")  ;
b :  printf("\t\t\t\t请选择想操作选项:") ;
     scanf ("%d",&a) ;
     switch(a)
	 {
	    case 1 : zhanghao() ; break ;
		case 2 : tuichu()   ; break ;
		default : 
			{
				printf("\t\t\t\t输入错误。\n") ;
				goto b ;
			}
	 }	

}

int main()  //主函数
{ 	 
	 FILE *fp;
	 int ji = 3 ;
	 printf("******************************************\n");
	 printf("***       营业厅信息管理系统           ***\n");
	 printf("******************************************");
 	 printf("\n");
l:   printf("1.第一次使用\n") ;
	 printf("0.多次使用\n") ;
	 printf("请选择想操作选项:\n ") ;
	 
	 scanf("%d",&ji) ;
	 if(ji == 1)
	 {
	    fp=fopen("student.txt","w");
	    duqu() ;
	 }
	 else if(ji == 0)
	   duqu() ;
	 else goto l ;
		 

     system("pause");
     denglu();
     return 0 ;
}