//#include "LibraryClerk.h"
//#include "SystemBasicFun.cpp"
float f(float x, float y, float z) 
{
	float a;
    a = x*x + 9.0f/4.0f*y*y + z*z - 1;
    return a*a*a - x*x*z*z*z - 9.0f/80.0f*y*y*z*z*z;
}

float h(float x, float z) 
{
	float y;
    for (y = 1.0f; y >= 0.0f; y -= 0.001f)
	{
        if (f(x, y, z) <= 0.0f)
            return y;
	}
    return 0.0f;
}

int EnterPage()
{
	float z,x,v;
	int i;
    for (z = 1.5f; z > -1.5f; z -= 0.06f) 
	{
        for (x = -1.5f; x < 1.5f; x += 0.030f) 
		{
            v = f(x, 0.0f, z);
            if (v <= 0.0f) 
			{
                float y0 = h(x, z);
                float ny = 0.01f;
                float nx = h(x + ny, z) - y0;
                float nz = h(x, z + ny) - y0;
                float nd = 1.0f / sqrtf(nx*nx + ny*ny + nz*nz);
                float d = (nx + ny - nz)*nd*0.5f + 0.5f;
                color(4);
                putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }
    //system("mode con cols=120 lines=44");//CMD���ڿ�͸� 
    color(14);//�����ɫ 
    gotoxy(34,46);
    printf("��ӭ����\"����ͼ�����Ϣ����ϵͳ\"��\n");
    gotoxy(34,48);
    printf("Designers by Anlzou with JingHong.");
    for(i=5;i>=0;i--)
    {
    	Sleep(1000);
    	gotoxy(40,45);
    	printf("�����ɹ���������½��%d\n",i);
    }
    Sleep(1000);
    color(15);//�����ɫ 
    system("cls");
	return 0;
}

int LoginPage(int x,int y,char text[])
{
	int choice;
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 ��½");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 �޸�����");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+10);
	printf("0 �˳�");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+15);
		printf("ѡ�������");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+15);
		printf("ѡ�������");
		scanf("%d",&choice);
	}while(choice<0  || choice>2);
	if(choice==0)
	{
		gotoxy(0,34);
		exit(0);
	}	
	return choice;
}

int MenuPage(int x,int y,char text[])
{
	int choice;
	system("cls");
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 ¼��");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 ���");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+10);
	printf("3 ��ѯ");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+12);
	printf("4 �޸�");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+14);
	printf("5 ɾ��");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+16);
	printf("6 ͳ��");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+18);
	printf("0 �˳�");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+23);
		printf("ѡ�������");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+23);
		printf("ѡ�������");
		scanf("%d",&choice);
	}while(choice<0  || choice>6);
	if(choice==0)
	{
		gotoxy(0,44);
		exit(0);
	}	
	return choice;
}

int CompositorPage(int x,int y,char text[])
{
	int choice;
	system("cls");
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 ����������");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 ���۸�����");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+10);
	printf("3 �����������");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+12);
	printf("4 ������������");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+14);
	printf("5 ������ʱ������");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+16);
	printf("6 ���޸�ʱ������");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+18);
	printf("0 �������˵�");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+23);
		printf("ѡ�������");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+23);
		printf("ѡ�������");
		scanf("%d",&choice);
	}while(choice<0  || choice>6);	
	return choice;
}

int SeekPage(int x,int y,char text[])
{
	int choice;
	system("cls");
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 ��������ѯ");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 ����������ѯ");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+13);
		printf("ѡ�������");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+13);
		printf("ѡ�������");
		scanf("%d",&choice);
	}while(choice<=0  || choice>=3);	
	return choice;
}

int RevisePage(int x,int y,char text[])
{
	int choice;
	system("cls");
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 �޸��������");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 �޸���������");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+10);
	printf("3 �޸�������");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+12);
	printf("4 �޸ĳ��浥λ");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+14);
	printf("5 �޸ĳ�����");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+16);
	printf("6 �޸ĳ�����");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+18);
	printf("7 �޸ĳ�����");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+20);
	printf("8 �޸���ļ۸�");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+22);
	printf("9 �޸���Ľ軹");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+27);
		printf("ѡ�������");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+27);
		printf("ѡ�������");
		scanf("%d",&choice);
	}while(choice<=0  || choice>=10);
	return choice;
}
