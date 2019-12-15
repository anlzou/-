//#include "LibraryClerk.h"
//#include "PrintfData.cpp"
//#include "Page.c"
//#include "FileIo.c"
//int CensusAll=2;
//��ȡ�ļ����������� 
char Uppercase(char *str)
{

      char ch;
      int n, tmp;
      tmp=(unsigned char)str[0]*256+(unsigned char)str[1];
      if(tmp >= 45217 && tmp <= 45252) ch='A'; 
      else if(tmp >= 45253 && tmp <= 45760) ch='B'; 
      else if(tmp >= 45761 &&  tmp <= 46317) ch='C';
      else if(tmp >= 46318 && tmp <= 46825) ch='D'; 
      else if(tmp >= 46826 && tmp <= 47009) ch='E';
      else if(tmp >= 47010 && tmp <= 47296) ch='F';
      else if(tmp >= 47297 && tmp <= 47613) ch='G';
      else if(tmp >= 47614 && tmp <= 48118) ch='H'; 
      else if(tmp >= 48119 && tmp <= 49061) ch='J'; 
      else if(tmp >= 49062  && tmp <= 49323) ch='K'; 
      else if(tmp >= 49324 && tmp <= 49895) ch='L';
      else if(tmp >= 49896 &&tmp <=  50370) ch='M';
      else if(tmp >= 50371 && tmp <= 50613) ch='N';
      else if(tmp >= 50614 && tmp <= 50621) ch='O';
      else if(tmp >= 50622 && tmp <= 50905) ch='P';
      else if(tmp >= 50906 && tmp <= 51386) ch='Q';
      else if(tmp >= 51387 && tmp <= 51445) ch='R';
      else if(tmp >= 51446 && tmp <= 52217) ch='S';
      else if(tmp >= 52218 && tmp  <= 52697) ch='T';
      else if(tmp >= 52698 && tmp <= 52979) ch='W';
      else if(tmp >= 52980 && tmp <= 53640) ch='X';
      else if(tmp >= 53689 && tmp <=  54480) ch='Y';
      else if(tmp >= 54481 && tmp <= 55289) ch='Z';
      else ch=' '; 
      n=ch;
      return n;
}

void AutherSort(Book *&Head)//����������
{
    Book *pfirst;      /* ���к��������ı�ͷָ�� */  
    Book *ptail;       /* ���к��������ı�βָ�� */  
    Book *pminBefore;  /* ������ֵ��С�Ľڵ��ǰ���ڵ��ָ�� */  
    Book  *pmin;        /* �洢��С�ڵ�   */  
    Book  *p;           /* ��ǰ�ȽϵĽڵ� */  
	Book  *head=Head->next;
    pfirst = NULL;  
    while (head != NULL)         /*���������Ҽ�ֵ��С�Ľڵ㡣*/  
    {  
    /* ע�⣺����for����������ѡ������˼��ĵط� */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/  
        {  
            if (Uppercase(p->next->AutherName)<Uppercase(pmin->AutherName)) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/  
            {  
                pminBefore = p;           /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/  
                pmin       = p->next;     /*�����ֵ��С�Ľڵ㡣*/  
            }  
        }
    
    /*����for�������󣬾�Ҫ�������£�һ�ǰ����������������У����Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/  
      
        /*��һ����*/  
        if (pfirst == NULL)     /* �����������Ŀǰ����һ��������                      */  
        {  
            pfirst = pmin;      /* ��һ���ҵ���ֵ��С�Ľڵ㡣                          */  
            ptail  = pmin;      /* ע�⣺βָ������ָ������һ���ڵ㡣                */  
        }  
        else                    /* �����������Ѿ��нڵ�                                */  
        {  
            ptail->next = pmin; /* �Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/  
            ptail = pmin;       /* βָ��ҲҪָ������                                  */  
        }  
  
        /*�ڶ�����*/  
        if (pmin == head)        /* ����ҵ�����С�ڵ���ǵ�һ���ڵ�                    */  
        {  
            head = head->next;   /* ��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK       */  
        }  
        else /*������ǵ�һ���ڵ�*/  
        {  
            pminBefore->next = pmin->next;/*ǰ����С�ڵ��nextָ��ǰpmin��next,��������pmin�뿪��ԭ����*/  
        }  
    }  
  
    if (pfirst != NULL)     /*ѭ�������õ���������first                */  
    {  
        ptail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL */   
    }  
    Head->next = pfirst;  
}
void ClassSort(Book *&Head)//�����������
{
    Book *pfirst;      /* ���к��������ı�ͷָ�� */  
    Book  *ptail;       /* ���к��������ı�βָ�� */  
    Book  *pminBefore;  /* ������ֵ��С�Ľڵ��ǰ���ڵ��ָ�� */  
    Book  *pmin;        /* �洢��С�ڵ�   */  
    Book  *p;           /* ��ǰ�ȽϵĽڵ� */  
	Book *head=Head->next;
   
    pfirst = NULL;  
    while (head != NULL)         /*���������Ҽ�ֵ��С�Ľڵ㡣*/  
    {  
    /* ע�⣺����for����������ѡ������˼��ĵط� */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/  
        {  
            if (p->next->ClassNumber<pmin->ClassNumber) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/  
            {  
                pminBefore = p;           /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/  
                pmin       = p->next;     /*�����ֵ��С�Ľڵ㡣*/  
            }  
        }  
    
    /*����for�������󣬾�Ҫ�������£�һ�ǰ����������������У����Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/  
      
        /*��һ����*/  
        if (pfirst == NULL)     /* �����������Ŀǰ����һ��������                      */  
        {  
            pfirst = pmin;      /* ��һ���ҵ���ֵ��С�Ľڵ㡣                          */  
            ptail  = pmin;      /* ע�⣺βָ������ָ������һ���ڵ㡣                */  
        }  
        else                    /* �����������Ѿ��нڵ�                                */  
        {  
            ptail->next = pmin; /* �Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/  
            ptail = pmin;       /* βָ��ҲҪָ������                                  */  
        }  
  
        /*�ڶ�����*/  
        if (pmin == head)        /* ����ҵ�����С�ڵ���ǵ�һ���ڵ�                    */  
        {  
            head = head->next;   /* ��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK       */  
        }  
        else /*������ǵ�һ���ڵ�*/  
        {  
            pminBefore->next = pmin->next; /*ǰ����С�ڵ��nextָ��ǰpmin��next,��������pmin�뿪��ԭ����*/  
        }  
    }  
  
    if (pfirst != NULL)     /*ѭ�������õ���������first                */  
    {  
        ptail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL */   
    }  
    Head->next = pfirst;   
}  
void PublishSort(Book *&Head)//�����浥λ���� 
{
	Book *pfirst;      /* ���к��������ı�ͷָ�� */  
    Book *ptail;       /* ���к��������ı�βָ�� */  
    Book *pminBefore;  /* ������ֵ��С�Ľڵ��ǰ���ڵ��ָ�� */  
    Book  *pmin;        /* �洢��С�ڵ�   */  
    Book  *p;           /* ��ǰ�ȽϵĽڵ� */  
	Book  *head=Head->next;
    pfirst = NULL;  
    while (head != NULL)         /*���������Ҽ�ֵ��С�Ľڵ㡣*/  
    {  
    /* ע�⣺����for����������ѡ������˼��ĵط� */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/  
        {  
            if (Uppercase(p->next->PublishUnit)<Uppercase(pmin->PublishUnit)) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/  
            {  
                pminBefore = p;           /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/  
                pmin       = p->next;     /*�����ֵ��С�Ľڵ㡣*/  
            }  
        }
    
    /*����for�������󣬾�Ҫ�������£�һ�ǰ����������������У����Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/  
      
        /*��һ����*/  
        if (pfirst == NULL)     /* �����������Ŀǰ����һ��������                      */  
        {  
            pfirst = pmin;      /* ��һ���ҵ���ֵ��С�Ľڵ㡣                          */  
            ptail  = pmin;      /* ע�⣺βָ������ָ������һ���ڵ㡣                */  
        }  
        else                    /* �����������Ѿ��нڵ�                                */  
        {  
            ptail->next = pmin; /* �Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/  
            ptail = pmin;       /* βָ��ҲҪָ������                                  */  
        }  
  
        /*�ڶ�����*/  
        if (pmin == head)        /* ����ҵ�����С�ڵ���ǵ�һ���ڵ�                    */  
        {  
            head = head->next;   /* ��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK       */  
        }  
        else /*������ǵ�һ���ڵ�*/  
        {  
            pminBefore->next = pmin->next;/*ǰ����С�ڵ��nextָ��ǰpmin��next,��������pmin�뿪��ԭ����*/  
        }  
    }  
  
    if (pfirst != NULL)     /*ѭ�������õ���������first                */  
    {  
        ptail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL */   
    }  
    Head->next = pfirst; 
}
void PriceSort(Book *&Head)//���۸�����
{
    Book  *pfirst;      /* ���к��������ı�ͷָ�� */  
    Book  *ptail;       /* ���к��������ı�βָ�� */  
    Book  *pminBefore;  /* ������ֵ��С�Ľڵ��ǰ���ڵ��ָ�� */  
    Book  *pmin;        /* �洢��С�ڵ�   */  
    Book  *p;           /* ��ǰ�ȽϵĽڵ� */
	Book  *head=Head->next;
    pfirst = NULL;  
    while (head != NULL)         /*���������Ҽ�ֵ��С�Ľڵ㡣*/  
    {  
    /* ע�⣺����for����������ѡ������˼��ĵط� */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/  
        {  
            if (p->next->Price<pmin->Price) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/  
            {  
                pminBefore = p;           /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/  
                pmin       = p->next;     /*�����ֵ��С�Ľڵ㡣*/  
            } 
        }  
    
    /*����for�������󣬾�Ҫ�������£�һ�ǰ����������������У����Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/  
      
        /*��һ����*/  
        if (pfirst == NULL)     /* �����������Ŀǰ����һ��������                      */  
        {  
            pfirst = pmin;      /* ��һ���ҵ���ֵ��С�Ľڵ㡣                          */  
            ptail  = pmin;      /* ע�⣺βָ������ָ������һ���ڵ㡣                */  
        }  
        else                    /* �����������Ѿ��нڵ�                                */  
        {  
            ptail->next = pmin; /* �Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/  
            ptail = pmin;       /* βָ��ҲҪָ������                                  */  
        }  
  
        /*�ڶ�����*/  
        if (pmin == head)        /* ����ҵ�����С�ڵ���ǵ�һ���ڵ�                    */  
        {  
            head = head->next;   /* ��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK       */  
        }  
        else /*������ǵ�һ���ڵ�*/  
        {  
            pminBefore->next = pmin->next; /*ǰ����С�ڵ��nextָ��ǰpmin��next,��������pmin�뿪��ԭ����*/  
        }  
    }  
  
    if (pfirst != NULL)     /*ѭ�������õ���������first                */  
    {  
        ptail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL */   
    }  
    Head->next = pfirst;

}
void PubTimeSort(Book *&Head)//������ʱ������
{
    Book  *pfirst;      /* ���к��������ı�ͷָ�� */  
    Book  *ptail;       /* ���к��������ı�βָ�� */  
    Book  *pminBefore;  /* ������ֵ��С�Ľڵ��ǰ���ڵ��ָ�� */  
    Book  *pmin;        /* �洢��С�ڵ�   */  
    Book  *p;           /* ��ǰ�ȽϵĽڵ� */
	Book  *head=Head->next;
    pfirst = NULL;  
    while (head != NULL)         /*���������Ҽ�ֵ��С�Ľڵ㡣*/  
    {  
    /* ע�⣺����for����������ѡ������˼��ĵط� */  
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/  
        {  
            if(p->next->PublishTime.year<pmin->PublishTime.year||p->next->PublishTime.month<pmin->PublishTime.month||p->next->PublishTime.day<pmin->PublishTime.day) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/  
            {  
                pminBefore = p;           /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/  
                pmin       = p->next;     /*�����ֵ��С�Ľڵ㡣*/  
            } 
        }  
    
    /*����for�������󣬾�Ҫ�������£�һ�ǰ����������������У����Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/  
      
        /*��һ����*/  
        if (pfirst == NULL)     /* �����������Ŀǰ����һ��������                      */  
        {  
            pfirst = pmin;      /* ��һ���ҵ���ֵ��С�Ľڵ㡣                          */  
            ptail  = pmin;      /* ע�⣺βָ������ָ������һ���ڵ㡣                */  
        }  
        else                    /* �����������Ѿ��нڵ�                                */  
        {  
            ptail->next = pmin; /* �Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/  
            ptail = pmin;       /* βָ��ҲҪָ������                                  */  
        }  
  
        /*�ڶ�����*/  
        if (pmin == head)        /* ����ҵ�����С�ڵ���ǵ�һ���ڵ�                    */  
        {  
            head = head->next;   /* ��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK       */  
        }  
        else /*������ǵ�һ���ڵ�*/  
        {  
            pminBefore->next = pmin->next; /*ǰ����С�ڵ��nextָ��ǰpmin��next,��������pmin�뿪��ԭ����*/  
        }  
    }  
  
    if (pfirst != NULL)     /*ѭ�������õ���������first                */  
    {  
        ptail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL */   
    }  
    Head->next = pfirst;
}
void ReviseTimeSort(Book *&Head)//���޸�ʱ������
{
    Book *pfirst;
	Book *ptail;
	Book *p;
	Book *head=Head->next;
	Book *pmin;
	Book *pminbefore;
	pfirst=NULL;
	while(head!=NULL)
	{
	  for(p=head,pmin=head;p->next!=NULL;p=p->next)
		  if(p->next->ReviseTime.year<pmin->ReviseTime.year||p->next->ReviseTime.month<pmin->ReviseTime.month||p->next->ReviseTime.day<pmin->ReviseTime.day)
		  {
		  pminbefore=p;
		  pmin=p->next;
		  }
		  if(pfirst==NULL)
		  {
		  pfirst=pmin;
		  ptail=pmin;
		  }
		  else
		  {
		  ptail->next=pmin;
		  ptail=pmin;		  
		  }
		  if(pmin==head)
		  {
		  head=head->next;
		  }
		  else
		  {
		  pminbefore->next=pmin->next;
		  }
	}
	if(pfirst!=NULL)
		ptail->next=NULL;
	Head->next=pfirst;
}

void Compositor()
{
	int choice;
	Book *L;
	choice=CompositorPage(36,40,text3);
	ReadDataCreateList(L,FileName);
	switch(choice)
	{
	case 1:
		AutherSort(L);
		PrintfData(L,TextSort[choice-1]);
		break;
	case 2:
		PriceSort(L); 
		PrintfData(L,TextSort[choice-1]);
		break;
	case 3:
		ClassSort(L); 
		PrintfData(L,TextSort[choice-1]);
		break;
	case 4:
		PublishSort(L);
		PrintfData(L,TextSort[choice-1]);
		break;
	case 5:
		PubTimeSort(L);
		PrintfData(L,TextSort[choice-1]);
		break;
	case 6:
		ReviseTimeSort(L);
		PrintfData(L,TextSort[choice-1]);
		break;
	}
	return ;
}
