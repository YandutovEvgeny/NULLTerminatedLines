#include<iostream>
#include<Windows.h>
using namespace std;
#pragma warning(disable : 4996)

int StringLenth(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
void remove_symbol(char str[], const char symbol);
bool is_palindrome(char str[]);
bool is_int_number(char str[], char a, char b);
bool is_bin_number(char str[], char a, char b);

void main()
{
	setlocale(LC_ALL, "Russian");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	const int n = 256;
	char str[n]{};
	cout << "Введите строку: "; 
	//cin >> str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.getline(str, n);  //Позволяет ввести с клавиатуры строку с пробелами
	                      //str - строка, n - размер строки
	cout << str << endl;
	cout << "Длина строки: " << StringLenth(str) << " символов" << endl;
	to_upper(str);
	cout << "Возведение строки в верхний регистр: " << str << endl;
	to_lower(str);
	cout << "Возведение строки в нижний регистр: " << str << endl;
	shrink(str);
	cout << "Удаление лишних пробелов: " << str << endl;
	cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	//cout << str << endl;
	cout << "десятичное 1b, двоичное 0b, шестнадчатеричное 0x " << endl;
	cout << "Строка " << (is_int_number(str, '1', 'b') ? "" : "НЕ ")  << "является целым десятичным числом" << endl;
	cout << "Строка " << (is_bin_number(str, '0', 'b') ? "" : "НЕ ")  << "является целым двоичным числом" << endl;
	cout << is_bin_number(str, '0', 'b');
	main();
}
int StringLenth(char str[])
{
	int i = 0;
	/*for (; str[i]; i++);
	return i;*/
	while (str[i] != '\0')i++;
	return i;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if( //Если
			str[i] >= 'a' && str[i] <= 'z' || //элемент строки маленькая английская буква
			str[i] >= 'а' && str[i] <= 'я')  //ИЛИ маденькая русская буква
			str[i] -= 32;  //Переводим его в верхний регистр
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')str[i] += 32;
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && (str[i + 1] == ' ' || str[i+1] == 0))
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
bool is_palindrome(char str[])
{ 
	int n = strlen(str);
	char* buffer = new char[n + 1]{};
	for (int i = 0; str[i]; i++)
	{
		buffer[i] = str[i];
	}
	to_upper(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
bool is_int_number(char str[], char a, char b)
{
	if (str[0] == a && str[1] == b)
	{
		bool is_number = true;
		for (int i = str[2]; str[i]; i++)
		{
			if ((str[i] >= '0' && str[i] <= '9') == false)return !is_number;
			//if ((str[i] == '0' || str[i] == '1') == false)return !is_number;
		}
		return is_number;
	}
	else return false;
}
bool is_bin_number(char str[], char a, char b)
{
	//if (str[0] == a && str[1] == b)
	//{
	//	bool is_number = true;
	//	for (int i = str[2]; str[i]; i++)
	//	{
	//		if ((str[i] == '0') || (str[i + 1] == '1'))/* == false*/ return true;
	//	}
	//	return false;
	//}
	//else return false;

	if (str[0] == a && str[1] == b)
	{
		bool is_number = false;
		for (int i = str[2]; str[i]; i++)
		{
			if (str[i] >= '2' && str[i] <= '9') return false;
			if (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'а' && str[i] <= 'я')) || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'А' && str[i] <= 'Я')) return false;
			if (str[i] == '0' || str[i] == '1') return true;
			//else return false;
		}
	}
	else return false;
}