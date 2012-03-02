// USDll.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Dll.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	PPut pput;
	PShow pshow;
	LPut lput;
	LShow lshow;
	LLen llen;
	PPL ponl;
	PPL pinl;
	Area larea;
	HINSTANCE pdll;
	pdll = LoadLibrary(TEXT("EDll"));
	if (pdll)
	{
		(FARPROC&)larea=GetProcAddress(pdll,LPCSTR(0x1));
		(FARPROC&)llen=GetProcAddress(pdll,LPCSTR(0x2));
		(FARPROC&)lput=GetProcAddress(pdll,LPCSTR(0x3));
		(FARPROC&)lshow=GetProcAddress(pdll,LPCSTR(0x4));
		(FARPROC&)pinl=GetProcAddress(pdll,LPCSTR(0x5));
		(FARPROC&)ponl=GetProcAddress(pdll,LPCSTR(0x6));
		(FARPROC&)pput=GetProcAddress(pdll,LPCSTR(0x7));
		(FARPROC&)pshow=GetProcAddress(pdll,LPCSTR(0x8));

		Point *P1=new Point;
		Point *P2=new Point;
		Point *P3=new Point;
		pput(1,7,*P1);
		pput(16,10,*P2);
		pput(16.5,10.1,*P3);
		Line *L1=new Line;
		lput(*P1,*P2,*L1);
		lshow(*L1);
		cout<<pinl(*L1,*P3)<<endl
			<<ponl(*L1,*P3)<<endl
			<<larea(*L1,*P3)<<endl;

		cout<<"Library";

		delete P1;
		P1=NULL;
		delete P2;
		P2=NULL;
		delete P3;
		P3=NULL;
		delete L1;
		L1=NULL;
	}
	else cout<<"Can not open";
	getch();
	return 0;
}

