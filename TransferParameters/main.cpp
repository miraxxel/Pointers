#include<iostream>
using namespace std;

void Exchange(int& a, int& b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << " " << b << endl;
	Exchange(a, b);
	cout << a << " " << b << endl;
}

void Exchange(int& a, int& b)
{
	int buffer = a; 
	a = b;
	b = buffer;
}