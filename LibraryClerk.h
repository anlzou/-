#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> //system("color 1");_�ı���ɫ.txt 
#include <windows.h> //Sleep(1);_������.tx
#include <conio.h>
#include <malloc.h>
#include <unistd.h>	//ȷ���ļ����ļ��еķ���Ȩ��
char text[2][20]={"���������롿","���޸����롿"};
char text1[]={"����½��"};
char text2[]={"���˵���"};
char text3[]={"�������"};
char text4[]={"����ѯ��"};
char text5[2][20]={"����������ѯ��","������������ѯ��"};
char text6[]={"���޸���Ϣ��"};
char text7[]={"���ļ��򿪡�"};
char TextSort[6][20]={
"������������","�����۸�����","�������������",
"��������������","��������ʱ������","�����޸�ʱ������"};
char TextRevise[]={"���޸ġ�"};
char TextDelete[]={"��ɾ����"}; 
char TextCensus[]={"��ͳ�ơ�"}; 
char FileName[32]="BookData.txt";
char Headline[12][32];
int CensusAll;//ͳ���鱾���� (1-n)
typedef struct LNode
{
	char BookName[20];		//���� 
	char AutherName[20];	//������ 
	int ClassNumber;		//����� 1-20
	char PublishUnit[20];	//���浥λ 
	struct					//����ʱ��     %s%s%s%s%d%d%d%f%d%d%d%d
	{
		int year;     //��
		int month;    //��
		int day;      //��
	}PublishTime;
	float Price;			//�۸�
	struct 					//�޸�ʱ�� 
	{
		int year;
		int month;
		int day;	
	}ReviseTime;
	int Borrow;	//����鱻�����Borrow=false
	struct LNode *next;		//ָ�� 
}Book;
