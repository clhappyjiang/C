#include <stdio.h>
#define N 1000 
 #include"stdafx.h"
#include <stdio.h>
#include<string.h> 
# include <stdlib.h>
typedef struct student  //����ṹ��
{
	char number[30];   //�ֻ���
	char name[30]; //����
	char chengji[30];      //����
	char zhiye[30];      //ְҵ
	char shenfenzheng[40];      //���֤��
	char sex[15];      //�Ա�
	char address[15];      //��ס��
	char status[15];      //״̬
}STUDENT;
STUDENT student[N]; 
int renshu = 0 ;


void jiaoshi () ; //  ��ʦ�������  0
void shanchu () ; //  ɾ��ѧ����Ϣ
void xiugai  () ; //  �޸�ѧ����Ϣ  
void denglu  () ; //  ��¼����  0  
void dengji  () ; //  �Ǽ�ѧ����Ϣ 0
void tuichu  () ; //  �˳�ϵͳ  0
void chaxun  () ; //  ��ѯѧ����Ϣ
void xianshi () ; //  ��ʾȫ��ѧ����Ϣ 0
void zhanghao() ; //  �˺������¼  0
void paixu   () ; //  ѧ���ɼ�����


void dengji()                                      //�ɼ���¼������Ӻ���
 {
	FILE *fp;
	int i = 0 , n = 0 ;
	char sign='y';                              //���ȶ���sing='y'
	system( "cls ");                             //��������  ϵͳ�е���
d : if(sign =='y')                    //��ʵֻ�е�����N��nʱ������ѭ��
    {
	    printf(" ----�û���¼���----\n");
 	    printf("\t\t\t�ֻ��ţ�");
	    scanf("%s",student[i].number);
	    printf("\t\t\t����: ");
	    scanf("%s",student[i].name); 
	    printf("\t\t\t���䣺");
		scanf("%s",&student[i].chengji);
		printf("\t\t\tְҵ��");
		scanf("%s",&student[i].zhiye);
		printf("\t\t\t���֤�ţ�");
		scanf("%s",&student[i].shenfenzheng);
		printf("\t\t\t�Ա�");
		scanf("%s",&student[i].sex);
		printf("\t\t\t��ס�أ�");
		scanf("%s",&student[i].address);
		printf("\t\t\t״̬��");
		scanf("%s",&student[i].status);


e :     printf("\t\t\t�Ƿ������ӣ�y/n��");
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
		printf("\t\t\t�������.") ;
		goto e ;
	}

 }


void duqu() //��ȡ�û���Ϣ��Ϣ
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
	struct student temp;                               //������ʱ�������ڽ���ʱ���������Ϣ���ں���Ľ���//
	int sum;                                         //�ܷ�
	int s[100];
    int i=0 ;
	int j,k,t;
	int m;
	duqu() ;
	system("cls");
	printf("\t\t\tѡ������ʽ:\n");
    printf("\t\t\t����������������\n");
    printf("\t\t\t��1------�ֻ���\n");
    printf("\t\t\t��2------���� ��\n");
	printf("\t\t\t��3------���� ��\n");
    printf("\t\t\t��            ��\n");
    printf("\t\t\t����������������\n");
	printf("\t\t\t��������Ҫ����ķ�ʽ\n");
	scanf("%d",&m);
	system("cls");
	while(m!=1&&m!=2&&m!=3)
		{
			printf("\t\t\t�����������������\n");
	        scanf("%d",&m);
	    }
   
   if(m==1)
	  {
	  for(i=0;i<renshu-1;i++)                           //����ð�ݷ���������//
	  {
		 k=i;
	    for(j=i+1;j<renshu;j++)
	    if(student[j].number>student[k].number)                              //����//�Ƚϴ�С//
	    k=j;
		temp=student[k];student[k]=student[i];student[i]=temp;                  //����������ʱ�������ݽ���//
		}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("\t\tѧ��\t\t����\t\t�ɼ�              \n");
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
            printf("\t\tѧ��\t\t����\t\t�ɼ�              \n");
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

void chaxun() /*��ѯ�û���Ϣ*/
{
	int i, t , flag;
	char s1[21];
	duqu() ;
	printf("\t\t\t\n��ѡ���ѯ��ʽ:\n");
    printf("\t\t\t����������������\n");
	printf("\t\t\t��1------���� ��\n");
    printf("\t\t\t��2------�ֻ���\n");
    printf("\t\t\t��3------���� ��\n");
    printf("\t\t\t��            ��\n");
    printf("\t\t\t����������������\n");
	while(1)
	{
		printf("\t\t\t��ѡ���Ӳ˵���ţ�");
		scanf("%d",&t);
		flag=0;
		switch(t)
		{
		case 1:
			printf("\n\t\t\t������Ҫ��ѯ���û���������");
			scanf("%s",s1);
			for(i=0;i<renshu;i++)
				if(strcmp(student[i].number,s1)==0)
				{
					flag=1;
     	            printf("\t\t�ֻ���: %s\n",student[i].number);
	                printf("\t\t����: %s\n",student[i].name);
	                printf("\t\t����: %s\n",student[i].chengji);
					printf("\t\tְҵ: %s\n",student[i].zhiye);
					printf("\t\t���֤��: %s\n",student[i].shenfenzheng);
					printf("\t\t�Ա�: %s\n",student[i].sex);
					printf("\t\t��ס��: %s\n",student[i].address);
					printf("\t\t״̬: %s\n",student[i].status);
				}
			if(flag==0)
				printf("\t\t������������!\n\n");
			break;
		case 2:
			printf("\n\t\t\t������Ҫ��ѯ���û����ֻ��ţ�");
			scanf("%s",s1);
			for(i=0;i<renshu;i++)
				if(strcmp(student[i].name,s1)==0)
				{
					flag=1;
				   	printf("\t\t�ֻ���: %s\n",student[i].number);
	                printf("\t\t����: %s\n",student[i].name);
	                printf("\t\t����: %s\n",student[i].chengji);
					printf("\t\tְҵ: %s\n",student[i].zhiye);
					printf("\t\t���֤��: %s\n",student[i].shenfenzheng);
					printf("\t\t�Ա�: %s\n",student[i].sex);
					printf("\t\t��ס��: %s\n",student[i].address);
					printf("\t\t״̬: %s\n",student[i].status);
				}
			if(flag==0)
				printf("\t\t��ѧ�Ų�����!\n\n");
			break;
		case 3:jiaoshi();break ;
		default:printf("\t\t\t����1-3֮��ѡ��\n");
		}
	}
}

void zhanghao()  // �˺ŵ�¼����
{
	int n;	
	printf("\t\t\t\t����0�����ϲ˵�\n") ;
b :	printf("\t\t\t\t���������Ա��¼����: ") ;
    scanf ("%d",&n) ;
	switch(n)
	{
	    case 123 : jiaoshi() ; break ;
		case 0   : denglu()  ; break ;
		default : 
			{
				printf("\t\t�������\n") ;
				goto b ;
			}
	}
}

void shanchu()/*ɾ����Ϣ*/
{
	FILE *fp;
	int i,j,flag=0;
	char s1[20];
	duqu() ;
	printf("\t\t\t������Ҫɾ���û����ֻ��ţ�");
	scanf("%s",s1);
	for(i=0;i<renshu;i++)
		if(strcmp(student[i].number,s1)==0)
		{
			flag=1;
			for(j=i;j<renshu-1;j++)
				student[j]=student[j+1];
		}
		if(flag==0)
			printf("\t\t\t���ֻ��Ų����ڣ�\n");
	    else
		{
			printf("\t\t\tɾ���ɹ�.\n");
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

void tuichu()  // �˳�����
{
     int a;
     char ch;
     printf("\t\t\t\t�Ƿ�ȷ���˳�����ѡ�� y or n:  ");
     getchar();
     ch=getchar();
     if(ch=='y'||ch=='Y') 
	 {
		 exit(0);
	 }
	
     else
     denglu();
     
}

void xiugai()/*�޸���Ϣ*/
{
	FILE *fp;
	int i , t , num ;
	char s1[10] ,s2[20];
	printf("\t\t\t������Ҫ�޸ĵ��û����ֻ��ţ�\n");
	scanf("%s",s1);
	duqu () ;
	for(i=0;i<renshu;i++)
	if(strcmp(student[i].number,s1)==0)
		num = i;
	printf("\n\t\t\t��ѡ���ѯ��ʽ:\n");
    printf("\t\t\t����������������\n");
	printf("\t\t\t��1--�޸����� ��\n");
    printf("\t\t\t��2--�޸����� ��\n");
	printf("\t\t\t��3--ע��     ��\n");
    printf("\t\t\t��4------���� ��\n");
    printf("\t\t\t��            ��\n");
    printf("\t\t\t����������������\n");
	while(1)
	{
		printf("\t\t\t��ѡ���Ӳ˵��ı�ţ�");
		scanf("%d",&t);
		switch(t)
		{
		case 1:
			printf("\t\t\t�������µ�������");
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
			printf("\t\t\t�������µ����䣺");
			scanf("%s",&student[num].chengji );	
			fp=fopen("student.txt","w");
	        for(i=0;i<renshu;i++)
			{
		        fprintf(fp,"%s %s %s %s %s %s %s %s \n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status);
			}
	        fclose(fp);
		    break;
		case 3:
			printf("\t\t\t������ע��״̬��");
			scanf("%s",&student[num].status );	
			fp=fopen("student.txt","w");
	        for(i=0;i<renshu;i++)
			{
		        fprintf(fp,"%s %s %s %s %s %s %s %s \n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status);
			}
	        fclose(fp);
		    break;
		case 4:jiaoshi();break ;
		default:printf("\t\t\t����1-3֮��ѡ��\n");
		}

	}

    jiaoshi() ;
}

void xianshi()//��ʾ��ǰ�û���Ϣ
{
	int i , t ;
	system( "cls ");
	duqu() ;
	printf("\t\t�����û�����ϢΪ��\n");
 	printf("\t\t\t�ֻ���\t����\t����\tְҵ\t���\t�Ա�\t��ס��\t״̬ \n") ;
	for(i=0;i<renshu;i++)
	{
	    printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",student[i].number,student[i].name , student[i].chengji,student[i].zhiye,student[i].shenfenzheng,student[i].sex,student[i].address,student[i].status) ;
	}
	printf("\n\n\n\t\t\t��ѡ���ѯ��ʽ:\n");
    printf("\t\t\t����������������\n");
	printf("\t\t\t��1------ɾ�� ��\n");
    printf("\t\t\t��2------�޸� ��\n");
    printf("\t\t\t��3------���� ��\n");
    printf("\t\t\t��            ��\n");
    printf("\t\t\t����������������\n");
	while(1)
	{
		printf("\t\t\t��ѡ���Ӳ˵���ţ�");
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
		default:printf("\t\t\t����1-3֮��ѡ��\n");
		}
	}
    system("pause");
	jiaoshi() ;

}

void jiaoshi()  // ��ʦ����
{
	int n;
	system("cls");
	printf("\t\t\t\t �q-----------------------�r \n") ;
	printf("\t\t\t\t��Ӫҵ����Ϣ����ϵͳ(����Ա)��\n") ;
    printf("\t\t\t\t�t-------------------------�s\n") ;
	printf("\t\t\t\t��������������������������\n") ;
	printf("\t\t\t\t�� 1.����               ��\n") ;
	printf("\t\t\t\t�� 2.��ѯ               ��\n") ;
	printf("\t\t\t\t�� 3.��ʾȫ����Ϣ       ��\n") ;
	printf("\t\t\t\t�� 4.ɾ���û�           ��\n") ;
	printf("\t\t\t\t�� 5.�޸��û���Ϣ       ��\n") ;
	printf("\t\t\t\t�� 7.�˳�ϵͳ           ��\n") ;
    printf("\t\t\t\t�� 0.���ص�¼����       ��\n") ;
	printf("\t\t\t\t��                      ��\n") ;
	printf("\t\t\t\t��                      ��\n") ;
	printf("\t\t\t\t��������������������������\n") ;
b:	printf("\t\t\t\t��ѡ�������ѡ��:") ;
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
				printf("\t\t�������\n") ;
				goto b ;
			}
	}
}

   
void denglu()   // ��ʦ�˺ŵ�¼
 { 	 
	 
     int a ;
	 char r ;
     system("cls"); 
	 printf("\t\t\t\t��ӭ����Ӫҵ������ϵͳ��¼����\n") ;
	 printf("********************************************************************************\n") ;
	 printf("\t\t\t\t1.����Ա��¼\n") ;
	 printf("\t\t\t\t2.�˳�ϵͳ\n")  ;
b :  printf("\t\t\t\t��ѡ�������ѡ��:") ;
     scanf ("%d",&a) ;
     switch(a)
	 {
	    case 1 : zhanghao() ; break ;
		case 2 : tuichu()   ; break ;
		default : 
			{
				printf("\t\t\t\t�������\n") ;
				goto b ;
			}
	 }	

}

int main()  //������
{ 	 
	 FILE *fp;
	 int ji = 3 ;
	 printf("******************************************\n");
	 printf("***       Ӫҵ����Ϣ����ϵͳ           ***\n");
	 printf("******************************************");
 	 printf("\n");
l:   printf("1.��һ��ʹ��\n") ;
	 printf("0.���ʹ��\n") ;
	 printf("��ѡ�������ѡ��:\n ") ;
	 
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