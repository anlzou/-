//#include "LibraryClerk.h"
//#include "SystemBasicFun.cpp"
#define ww 10
int dath[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},//ƽ��//
{31,29,31,30,31,30,31,31,30,31,30,31}};//����//
//char Pass[20];


void InPutData(Book *&head)//¼����Ϣ�Ż�¼����鱾����
{
	   if(head->next==NULL)
	   		head=new(Book);
	   Book *pre=head;
	   int i=0;
	   while(pre->next!=NULL)//�ҵ�����ĩβ����ڵ�
	   {
	   		i++;
	   		pre=pre->next;
	   }
	   pre->next=NULL;
       Book *p,*s;
	   s=pre;
	   int flag=1;
	   int err=0;
	   char ch;
	   while(flag)
	   {
	   		char text[]={"��¼�롿"};
	   		windows(40,60,text);
	       p=new(Book);
	       gotoxy(PageRetraction+1+40-ww,PageRetraction-1+6);
	       printf("������� %d ���������",i+1);
	       gotoxy(PageRetraction+1+40-ww,PageRetraction-1+7);
	       scanf("%s",p->BookName);
	       getchar();
	       gotoxy(PageRetraction+1+40-ww,PageRetraction-1+9);
		   printf("��������������");
		   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+10);
	       scanf("%s",p->AutherName);
	       getchar();
	       gotoxy(PageRetraction+1+40-ww,PageRetraction-1+12);
		   printf("�������鱾�ķ����(1-20)");
	   err=0;
	   while(err==0)
	   {
	   		gotoxy(PageRetraction+1+40-ww,PageRetraction-1+13);
	   		printf("                     ");
	   		gotoxy(PageRetraction+1+40-ww,PageRetraction-1+13);
	       scanf("%d",&p->ClassNumber);
	       	getchar();
		   if(p->ClassNumber<1 || p->ClassNumber>20)
		   {
		   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+12);
		   	printf("�����˴�����鱾����ţ�����������(1-20)");
		   }		       
		   else
			   err=1;  
	   }
	   err=0;
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+15);
	   printf("��������浥λ");
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+16);
	   scanf("%s",p->PublishUnit);
	   getchar();
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+18);
	   printf("������������");
	   while(err==0)
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+19);
	   	printf("                     ");
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+19);
	   scanf("%d",&p->PublishTime.year);
	   getchar();
	   if(p->PublishTime.year<=2100&&p->PublishTime.year>=1900)
		   err=1;
	   else
	   {
	   		gotoxy(PageRetraction+1+40-ww,PageRetraction-1+18);
		   printf("��������ȷ�����");
		}
	   }
	   err=0;
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+21);
	   printf("����������·�");
	   while(err==0)
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+22);
	   	printf("                     ");
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+22);
	   scanf("%d",&p->PublishTime.month);
	   getchar();
	   if(p->PublishTime.month<=12&&p->PublishTime.month>=1)
		   err=1;
	   else
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+21);
		   printf("��������ȷ���·�");
		}
	   }
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+24);
		   printf("�����������");
	   err=0;
	   	   while(err==0)
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+25);
	   	printf("                     ");
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+25);
	   scanf("%d",&p->PublishTime.day);
	   getchar();
	   if((p->PublishTime.year%4==0&&p->PublishTime.year%100!=0)||p->PublishTime.year%400==0)//����
	   {
		   if(p->PublishTime.day>=0&&p->PublishTime.day<=dath[1][p->PublishTime.month-1])
			   err=1;
		   else
		   {
		   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+24);
		   printf("��������ȷ����");
			}
	   }
	   else
	   {
	   if(p->PublishTime.day>0&&p->PublishTime.day<=dath[0][p->PublishTime.month-1])
			   err=1;
		   else
		   {
		   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+24);
		   printf("��������ȷ����");
			}
	   }
	   
	   
	   }
		
	   err=0;
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+27);
	   printf("��������ļ۸�");
	   while(err==0)
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+28);
	   	printf("                     ");
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+28);
	       scanf("%f",&p->Price);
	       getchar();
		   if(p->Price<=0)
		   {
		   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+27);
              printf("�۸��������,��������ȷ�ļ۸�");
          }
		   else
			   err=1;	   
	   }
	   err=0;
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+30);
	   printf("����������޸����");
	    while(err==0)
	   {
		gotoxy(PageRetraction+1+40-ww,PageRetraction-1+31);
	   	printf("                     ");
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+31);
	   scanf("%d",&p->ReviseTime.year);
	   if(p->ReviseTime.year<=2100&&p->ReviseTime.year>=1900)
		   err=1;
	   else
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+30);
		 printf("��������ȷ�����");
		}
	   }
	   err=0;
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+33);
	   printf("�������޸��·�");
	   	   while(err==0)
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+34);
	   	printf("                     ");
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+34);
	   scanf("%d",&p->ReviseTime.month);
	   getchar();
	   if(p->ReviseTime.month<=12&&p->ReviseTime.month>=1)
		   err=1;
	   else
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+33);
		   printf("��������ȷ���·�");
		}
	   }
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+36);
		   printf("�����������");
	   err=0;
	   	   while(err==0)
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+37);
	   	printf("                     ");
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+37);
	   scanf("%d",&p->ReviseTime.day);
	   getchar();
	   if((p->ReviseTime.year%4==0&&p->ReviseTime.year%100!=0)||p->ReviseTime.year%400==0)//����
	   {
		   if(p->ReviseTime.day>0&&p->ReviseTime.day<=dath[1][p->ReviseTime.month-1])
			   err=1;
		   else
		   {
		   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+36);
		   printf("��������ȷ����");
			}
	   }
	   else
	   {
	   if(p->ReviseTime.day>0&&p->ReviseTime.day<=dath[0][p->ReviseTime.month-1])
			   err=1;
		   else
		   {
		   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+36);
		   printf("��������ȷ������");
			}	   
	   }	   
	   }

		err=0;
		gotoxy(PageRetraction+1+40-ww,PageRetraction-1+39);
	   printf("���Ƿ񱻽裨�ǣ�1����0��");
	   	   while(err==0)
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+40);
	   	printf("                     ");
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+40);
	   scanf("%d",&p->Borrow);
	   getchar();
	   if(p->Borrow>=0 && p->Borrow<=1)
		   err=1;
	   else
	   {
	   	gotoxy(PageRetraction+1+40-ww,PageRetraction-1+39);
		   printf("��������ȷ��ֵ�����Ƿ񱻽裨�ǣ�1����0��");
		}
	   }
	   i++;
	   CensusAll=i;
	   s->next=p;
	   s=p;
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+42);
	   printf("�Ƿ��������Y����N");
	   gotoxy(PageRetraction+1+40-ww,PageRetraction-1+43);
	   scanf("%c",&ch);
	   getchar();
	   if(ch=='Y'||ch=='y')
	   {
	   		system("cls");
		   flag=1;
		}
	   else
		   flag=0;
	   }
	   s->next=NULL;
	  
}

int SaveData(Book *p,char *FileName)//�����ļ�
{
	
   FILE *fp;
   Book *L;
   L=p->next;
   int i=0; 
   if((fp=fopen(FileName,"wt"))==NULL)
   {
   	  system("cls");
      windows(56,20+CensusAll*2,text7);
   	  gotoxy(PageRetraction*2+30+20-1,PageRetraction-1+9);
      printf("�ļ�û�����ݣ�");
	  fclose(fp);
	  gotoxy(0,20+CensusAll*2+4);
	  getch();
	  return 0;
   }
   fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s\n","����","������","�����","���浥λ","������",
   "������","������","�۸�","�Ƿ񱻽�(��:1,��:0)","�޸���","�޸���","�޸���");
   for(;i<CensusAll&&L!=NULL;i++)
   {   
	  
      fprintf(fp,"%s %s %d %s %d %d %d %.2f %d %d %d %d\n",L->BookName,L->AutherName,L->ClassNumber,L->PublishUnit,L->PublishTime.year,L->PublishTime.month,L->PublishTime.day,
	                                  L->Price,L->Borrow,L->ReviseTime.year,L->ReviseTime.month,L->ReviseTime.day);
      L=L->next;
   }
   fclose(fp);


}

int ReadDataCreateList(Book *&L,char FileName[]) //��ȡ�ļ����������� 
{
	FILE* fp;//�ļ�ָ�� 
 	Book *p1,*p2;
 	int i;
 	fp = fopen(FileName, "rt");
 	if (!fp) 
 	{ 
 		system("cls");
 		windows(56,20+CensusAll*2,text7);
 		gotoxy(PageRetraction*2+30+20-1,PageRetraction-1+9);
	  	printf("�ļ�û�����ݣ�");
	  	fclose(fp);
	  	gotoxy(0,20+CensusAll*2+4);
	  	getch();
	  	return 0;
 	} 
 	for(i=0;i<12;i++)		//��ȡ�ļ���һ�� 
 		fscanf(fp,"%s",Headline[i]);
	 L=(Book *)malloc(sizeof(Book));
	 p2=L;
	 while(!feof(fp))
	 { 
		  p1 = (Book *)malloc(sizeof(Book));
		  fscanf(fp,"%s%s%d%s%d%d%d%f%d%d%d%d\n",
		  p1->BookName,p1->AutherName,&p1->ClassNumber,p1->PublishUnit,&p1->PublishTime.year,&p1->PublishTime.month,
		  &p1->PublishTime.day,&p1->Price,&p1->Borrow,&p1->ReviseTime.year,&p1->ReviseTime.month,&p1->ReviseTime.day); 	  
		  p2->next = p1;
		  p2 = p1;
	 }
	 p2->next = NULL;
	 fclose(fp);
}

void Input()//¼�루��Ϣ�� 
{
	Book *L;
	ReadDataCreateList(L,FileName);
	InPutData(L);
	SaveData(L,FileName);
	free(L);
}
