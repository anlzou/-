//#include "LibraryClerk.h"
//#include "SystemBasicFun.cpp"
//#include "Page.cpp"
//#include "FileIo.cpp" 
//#define PageRetraction 3
int BookNameRevise(Book *&head)//�������޶�������Ϣ
{
	system("cls");
	windows(56,20+CensusAll*2,TextRevise);
    Book *p;
    char BookName[20];
	p=head->next;
	if(p==NULL)
	{
    	gotoxy(PageRetraction+1+40-4+10,PageRetraction-1+7);
		printf("δ¼������!");
		gotoxy(0,20+CensusAll*2+4);
		getch();
		return 1;
	}
	int choice;
	gotoxy(PageRetraction*2+6,PageRetraction-1+4);
	printf("������������֣�");
	scanf("%s",BookName);
	while(p!=NULL)
	{
	  if(strcmp(p->BookName,BookName)==0)
	  {
	  	   	choice=RevisePage(36,40,text6);
	  		system("cls");
			windows(56,20+CensusAll*2,TextRevise);
			gotoxy(PageRetraction*2+6,PageRetraction-1+4);
			printf("�������Ϊ��%s",BookName);
		   switch(choice)
		   {
		   case 1:
		   	{
		   	   gotoxy(PageRetraction*2+6,PageRetraction-1+6);
			   printf("�������������");
			   gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   		   printf("                     ");
	   		   gotoxy(PageRetraction*2+6,PageRetraction-1+7);
			   scanf("%s",p->BookName);//%s%s%s%s%d%d%d%f%d%d%d%d
			   break;
			}
		   case 2:
		   	{
		   	   gotoxy(PageRetraction*2+6,PageRetraction-1+6);
			   printf("���������ߵ�����");
			   gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   		   printf("                     ");
	   		   gotoxy(PageRetraction*2+6,PageRetraction-1+7);
			   scanf("%s",p->AutherName);
			   break;
			}
		   case 3:
			{
				gotoxy(PageRetraction*2+6,PageRetraction-1+6);
				printf("����������");
			   	while(1)
			   	{
			   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   				printf("                     ");
	   		   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
			   		scanf("%d",&p->ClassNumber);
			   		if(p->ClassNumber<0||p->ClassNumber>20)
			   		{
					   gotoxy(PageRetraction*2+6,PageRetraction-1+6); 
				   		printf("��������ȷ�ķ����");
				   	}
			   		else
				   		break;
			   	}
				break; 
			}
		   case 4:
		   	{
		   	   gotoxy(PageRetraction*2+6,PageRetraction-1+6);
			   printf("��������浥λ");
			   gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   		   printf("                     ");
	   		   gotoxy(PageRetraction*2+6,PageRetraction-1+7);
			   scanf("%s",p->PublishUnit);
			   break;
			}
		   case 5:
		   	{
		   		gotoxy(PageRetraction*2+6,PageRetraction-1+6);
			   printf("�������޸ĵĳ������");
			   while(1)
			   {
			   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   		   		printf("                     ");
	   		   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
			   		scanf("%d",&p->PublishTime.year);
			   		if(p->PublishTime.year>=1900&&p->PublishTime.year<=2100)
				   		break;
			   		else
			   		{
			   			gotoxy(PageRetraction*2+6,PageRetraction-1+6);
				   		printf("��������ȷ�����");
				   	}
			   }
			   break;
			}
		   case 6:
		   	{
		   	   gotoxy(PageRetraction*2+6,PageRetraction-1+6);
			   printf("�������޸ĵĳ����·�");
			   while(1)
			   {
			   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   		   		printf("                     ");
	   		   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
			   		scanf("%d",&p->PublishTime.month);
			    	if(p->PublishTime.month<=12&&p->PublishTime.month>=1)
		         		break;
	              	else
	              	{
	              		gotoxy(PageRetraction*2+6,PageRetraction-1+6);
		         		printf("��������ȷ���·�");
		         	}
			   }
			   break;
			}
		   case 7:
		   	{
		   		gotoxy(PageRetraction*2+6,PageRetraction-1+6);
				printf("�������޸ĵĳ�����");
			  	while(1)
			   	{
			   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   		   		printf("                     ");
	   		   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
			   		scanf("%d",&p->PublishTime.day);
			   		if((p->PublishTime.year%4==0&&p->PublishTime.year%100!=0)||p->PublishTime.year%400==0)//����
			   		{
				   		if(p->PublishTime.day>=0&&p->PublishTime.day<=dath[1][p->PublishTime.month-1])
					   		break;
				   		else
				   		{
				   			gotoxy(PageRetraction*2+6,PageRetraction-1+6);
				   			printf("��������ȷ����");	
						}
			   		}
			   		else
			   		{
			   			if(p->PublishTime.day>0&&p->PublishTime.day<=dath[0][p->PublishTime.month-1])
					   		break;
				   		else
				   		{
				   			gotoxy(PageRetraction*2+6,PageRetraction-1+6);
				   			printf("��������ȷ����");
				   		}
			   		}
				}
			   	break;
			}
		   case 8:
		   	{
		   	   gotoxy(PageRetraction*2+6,PageRetraction-1+6);
			   printf("��������ļ۸�");
			   while(1)
			   {
			   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   				printf("                     ");
	   		   		gotoxy(PageRetraction*2+6,PageRetraction-1+7);
			   		scanf("%f",&p->Price);
			   		if(p->Price<=0)
			   		{
			   			gotoxy(PageRetraction*2+6,PageRetraction-1+6);
				   		printf("��������ȷ�ļ۸�");
				   	}
			   		else
				   		break;
			   }
			   break;
			}
		   case 9:
		   	{
		   		gotoxy(PageRetraction*2+6,PageRetraction-1+6);
			   	printf("���Ƿ񱻽裨�ǣ�1����0��");
				while(1)
	   			{
	   				gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   				printf("                     ");
	   				gotoxy(PageRetraction*2+6,PageRetraction-1+7);
	   				scanf("%d",&p->Borrow);
	   				getchar();
	   				if(p->Borrow>=0 && p->Borrow<=1)
		   				break;
	   				else
	   				{
	   					gotoxy(PageRetraction*2+6,PageRetraction-1+6);
		   				printf("��������ȷ��ֵ�����Ƿ񱻽裨�ǣ�1����0��");
					}
	   			}
	   			break;
			}
		   }
		    gotoxy(PageRetraction*2+6,PageRetraction-1+9);
			printf("����������޸����");
	        while(1)
			{
				gotoxy(PageRetraction*2+6,PageRetraction-1+10);
	   			printf("                     ");
	   			gotoxy(PageRetraction*2+6,PageRetraction-1+10);
	           	scanf("%d",&p->ReviseTime.year);
	        	if(p->ReviseTime.year<=2100&&p->ReviseTime.year>=1900)
		          	break;
	          	else
	          	{
	          		gotoxy(PageRetraction*2+6,PageRetraction-1+9);
		      		printf("��������ȷ�����");
		      	}
		   	}
		   	gotoxy(PageRetraction*2+6,PageRetraction-1+12);
			printf("�������޸��·�");
			while(1)
			{
				gotoxy(PageRetraction*2+6,PageRetraction-1+13);
	   			printf("                     ");
	   			gotoxy(PageRetraction*2+6,PageRetraction-1+13);
			  	scanf("%d",&p->ReviseTime.month);
			   	if(p->ReviseTime.month<=12&&p->ReviseTime.month>=0)
				  	break;
			   	else
			   	{
			   		gotoxy(PageRetraction*2+6,PageRetraction-1+12);
				  	printf("��������ȷ���·�");
				}
			}
			gotoxy(PageRetraction*2+6,PageRetraction-1+15);
			printf("�������޸���");
	 	    while(1)
			{
				gotoxy(PageRetraction*2+6,PageRetraction-1+16);
	   			printf("                     ");
	   			gotoxy(PageRetraction*2+6,PageRetraction-1+16);
	         	scanf("%d",&p->ReviseTime.day);
	          	if((p->ReviseTime.year%4==0&&p->ReviseTime.year%100!=0)||p->ReviseTime.year%400==0)//����
				{
		      		if(p->ReviseTime.day>0&&p->ReviseTime.day<=dath[1][p->ReviseTime.month-1])
			    		goto A;
		      		else
		      		{
		      			gotoxy(PageRetraction*2+6,PageRetraction-1+15);
		        		printf("��������ȷ����"); 
		        	}
			  	}
	        	else
				{
		         	if(p->ReviseTime.day>0&&p->ReviseTime.day<=dath[0][p->ReviseTime.month-1])
				  	 	goto A;
			   		else
			   		{
			   			gotoxy(PageRetraction*2+6,PageRetraction-1+15);
			      		printf("��������ȷ����");
					}
		   		}
		   }
	   }
	   	p=p->next;
	   	if(p==NULL)
	   	{ 
	   		gotoxy(PageRetraction*2+6+42,PageRetraction-1+7);
			printf("û���Ȿ��!");
			gotoxy(0,20+CensusAll*2+4);
			getch();
			return 1;
		}
	}
	A:
	gotoxy(PageRetraction*2+6+42,PageRetraction-1+7);
	printf("�޸ĳɹ�!");
	gotoxy(0,20+CensusAll*2+4);
	getch();
	return 0;
}

int BookNameDelete(Book *&L)//������ɾ��ĳ������ڵ�
{
		ReadDataCreateList(L,FileName);
		system("cls");
		windows(36,30,TextDelete);
       char BookName[20];
	   Book *p=L->next,*q=L,*s;       //ֻ�Ǽ򵥵�������һ��20
	   	gotoxy(PageRetraction*2+30-2,PageRetraction-1+4);
	   printf("�������������");
	   	gotoxy(PageRetraction*2+30-2,PageRetraction-1+5);
	   scanf("%s",BookName);
	   while(p!=NULL)
	   {
	      if(strcmp(p->BookName,BookName)==0)
		  {
		     q->next=p->next;
			 s=p;
			 p=p->next;
			 gotoxy(PageRetraction*2+30-2,PageRetraction-1+14);
			 printf("ɾ���ɹ���");
			 CensusAll--; 
			 free(s);
			gotoxy(0,34);
			getch();
	   		return 0;
		  }
		  else
		  {
		     q=q->next;
			 p=p->next;
		  }  
	   }
	    gotoxy(PageRetraction*2+30-2,PageRetraction-1+14);
		printf("û���Ȿ��!");
		gotoxy(0,34);
		getch();
	   return 1;
}

int CensusAllBooks()//ͳ��һ���ж��ٱ���
{
	Book *L;
	ReadDataCreateList(L,FileName);
	int i=0;
    if(L->next==NULL)  return 0;
	Book *p=L->next;
	while(p!=NULL)
	{
	   i++;
	   p=p->next;
	}
     CensusAll=i;
     return CensusAll;
}

int CensusBorrow(Book *L)//ͳ��һ��������ٱ���
{
	int i=0;
    if(L->next==NULL)  return 0;
	Book *p=L->next;
	while(p!=NULL)
	{
	   if(p->Borrow==1)
		   i++;
	   p=p->next;
	}
    return i;
}

void Revise()
{
	Book *L;
	ReadDataCreateList(L,FileName);
	if(BookNameRevise(L)==0)
		SaveData(L,FileName);
	free(L);
}

void Delete()
{
	Book *L;
	ReadDataCreateList(L,FileName);
	if(BookNameDelete(L)==0)
		SaveData(L,FileName);
	free(L);
}

void Census()
{
	Book *L;
	ReadDataCreateList(L,FileName);
	system("cls");
	windows(36,30,TextCensus);
	gotoxy(PageRetraction*2+30-2,PageRetraction-1+4);
	printf("һ����%2d����",CensusAllBooks());
	gotoxy(PageRetraction*2+30-2,PageRetraction-1+6);
	printf("�����%2d����",CensusBorrow(L));
	gotoxy(PageRetraction*2+30-2,PageRetraction-1+8);
	printf("������%2d����",CensusAllBooks()-CensusBorrow(L));
	gotoxy(0,34);
	getch();
	free(L);
}
