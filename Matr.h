#include <iostream>
#ifndef MATR
#define MATR
class Matr
{
	unsigned size;
	int * matr;
public:
	Matr()//����������� �� ������������� ������ ������ �� ������� 5�5
		:size((unsigned)5)
	{
		this->matr=new int[this->size*this->size];
		//this->Start();//����� ���� ���������
	}
	//--------------------------------------------------------
	Matr(unsigned s)//����������� ������ ������ �� ������� N�N
		:size(s)
	{
		this->matr=new int[this->size*this->size];
	}
	//--------------------------------------------------------
	Matr(const Matr& p)//����������� �������� ��� ������ �������
		:size(p.size)
	{
		this -> matr = new int[this -> size * this -> size];
		for(unsigned i = (unsigned)0; i < this -> size; ++i)
		{
			this -> matr[i] = p.matr[i];
		}
	}
	//--------------------------------------------------------
	int MatrXYRead(unsigned x, unsigned y, int& p);
	unsigned SizeRead();
	int MatrXYWrite(unsigned x, unsigned y, const int& p);
	~Matr()
	{
		delete [] this -> matr;
		matr=NULL;
	}
	//--------------------------------------------------------
	void Start();
	void End();
	int Z10(int n, int &res);
	int Z11(int n, int &res);
	int Z12(int n, int &res);
};
#endif//MATR