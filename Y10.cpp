/*
10 Задана квадратна матриця розмірності m × 3. Матрицю задати в класі Matr. 
Знайти скалярний добуток першого рядка матриці на m-мірний вектор, кожна координата якого є залишок по mod n  
від різних елементів бічної діагоналі. 
Розмірність задати в головній програмі константою. Елементами матриці є цілі числа.
11 Задана квадратна матриця розмірності m × 3. Матрицю задати в класі Matr. 
Знайти скалярний добуток першого рядка матриці на m-мірний вектор, кожна координата якого є залишок по mod n 
від різних елементів першого стовбця. 
Розмірність задати в головній програмі константою. Елементами матриці є цілі числа.
12 Задана квадратна матриця розмірності m × 3. Матрицю задати в класі Matr. 
Знайти скалярний добуток першого рядка матриці на m-мірний вектор, кожна координата якого є залишок по mod n  
від різних елементів останнього стовбця. 
Розмірність задати в головній програмі константою. Елементами матриці є цілі числа.
*/
#include "Matr.h"
#include "Matr.h"
#include <ctime>
#include <conio.h>

int main()
{
	srand((unsigned)time(0));
	const int size = rand()%10+1;
	Matr *Mas;
	Mas = new Matr(size);
	Mas->Start();
	std::cout<<"Please, enter the number N\n";
	int n=10;
	int res=0;
	std::cin>>n;
	//Задача 10
	if(Mas->Z10(n,res))
		std::cout<<"Error, calculations are not possible\n";
	else std::cout<<"The result of computing tasks 10\n"
				  <<res<<"\n\n\n";
	//Задача 11
	if(Mas->Z11(n,res))
		std::cout<<"Error, calculations are not possible\n";
	else std::cout<<"The result of computing tasks 11\n"
				  <<res<<"\n\n\n";
	//Задача 12
	if(Mas->Z12(n,res))
		std::cout<<"Error, calculations are not possible\n";
	else std::cout<<"The result of computing tasks 12\n"
				  <<res<<"\n\n\n";
	Mas->End();
	getch();
	return 0;
}