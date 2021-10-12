#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
#pragma warning(disable : 4996)

int StringLenth(char* str);
char* to_upper(char* str);
char* to_lower(char* str);
char* shrink(char* str);
void is_palindrome(char* str);


void main()
{
	setlocale(LC_ALL, "Russian");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	const int n = 20;
	char str[n]{};
	cout << "Введите строку: "; 
	//cin >> str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.getline(str, n);  //Позволяет ввести с клавиатуры строку с пробелами
	                      //str - строка, n - размер строки
	//cout << str << endl;
	cout << StringLenth(str) << endl;
	cout << to_upper(str) << endl;
	cout << to_lower(str) << endl;
	cout << shrink(str) << endl;
	is_palindrome(str);
	main();
}
int StringLenth(char *str)
{
	int i = 0;
	/*for (i < 20; i++)
	{
		if (str[i] == '\0')return i;
	}*/
	while (str[i] != '\0')i++;
	return i;
}
char* to_upper(char* str)
{
	for (int i = 0; i < str[i]; i++)
	{
		str[i] = str[i] - 32;
	}
	return str;
}
char* to_lower(char* str)
{
	for (int i = 0; i < str[i]; i++)
	{
		str[i] = str[i] + 32;
	}
	return str;
}
char* shrink(char* str)
{
	for (int i = 0; StringLenth(str); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			
		}
	}
	return str;
}
void is_palindrome(char* str)
{ 
	for (int i = 0; i < str[i]; i++)
	{
		
	}
  
}