#include "LibraryClerk.h"
#include "IncludeFile.h"
int main()
{
	int choice;
	Book *L;
	EnterPage();//Logoҳ�� 
	choice=LoginPage(30,30,text1);//��½�˵�
	Login(30,30,text[choice-1],choice);
	while(1)
	{
		choice=MenuPage(36,40,text2);//���˵�
		switch(choice)
		{
			case 1:
				Input();//���뱣������ 
				break;
			case 2:
				Compositor();//������� 
				break;
			case 3:
				Seek();//��ѯ 
				break;
			case 4:
				Revise();//�޸� 
				break;
			case 5:
				Delete();//ɾ�� 
				break;
			case 6:
				Census();//ͳ�� 
				break;
		}
	}
	return 0;
}
