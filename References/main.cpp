#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	int a = 2;
	int& ra = a;
	ra += 3; // изменяя ссылку, мы изменяем значение переменной 'a'
	
	cout << a << endl;
	cout << &a << endl;
	cout << &ra << endl;
}