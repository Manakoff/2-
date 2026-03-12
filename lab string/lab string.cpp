#include <iostream>
#include <fstream>
#include <string>
#include < windows.h >

const int MAX_RES = 100;

void print_alph();

std::string sortWord(std::string word, char s);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Задание 0

	print_alph();
	
	std::cout << std::endl;

	//Задание 1

	char stroka[101];
	std::cin.getline(stroka, 100);

	char glas[] = "аеёиоуъыьэюя";

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (stroka[i] == glas[j])
			{
				if (stroka[i] == char(-72))
					stroka[i] -= 16;
				else
					stroka[i] -= 32;
			}
		}
	}

	std::cout << stroka << std::endl;

	// Задание 2
	int n;
	char symbol;
	std::ifstream file_in_first("input.txt");
	if (!file_in_first)
		return 1;
	file_in_first >> n >> symbol;
	file_in_first.close();
	
	symbol = tolower((unsigned char)symbol);

	std::string res[MAX_RES];
	int res_c = 0;

	std::ifstream file_in("text.txt");
	if (!file_in)
		return 1;

	std::string word;
	while (file_in >> word)
	{
		std::string w = sortWord(word, symbol);
		if (!w.empty())
		{

			bool un = true;
			for (int i = 0; i < res_c; i++)
			{
				if (res[i] == w)
				{
					un = false;
					break;
				}
			}
			if (!un)
				continue;

			if (res_c < n)
			{
				res[res_c] = w;
				res_c++;
			}
			else
			{
				int max_i = 0;
				for (int i = 1; i < n; i++)
				{
					if (res[i].length() > res[max_i].length())
						max_i = i;
				}

				if (w.length() < res[max_i].length())
				{
					res[max_i] = w;
				}
			}
		}
	}

	for (int i = 0; i < res_c - 1; i++)
	{
		for (int j = i + 1; j < res_c; j++)
		{
			if (res[j].length() > res[i].length())
			{
				std::string temp = res[i];
				res[i] = res[j];
				res[j] = temp;
			}
		}
	}

	std::ofstream file_out("result.txt");
	for (int i = 0; i < n; i++)
	{
		if (i < res_c)
			file_out << res[i] << std::endl;
	}

	return 0;
}


void print_alph()
{
	std::cout << "English alphabet" << std::endl;
	for (unsigned char i = 'a'; i <= 'z'; i++)
	{
		std::cout << int(i - 32) << ". " << char(int(i - 32)) << " | " << int(i) << ". " << i << std::endl;

	}
	std::cout << std::endl;

	std::cout << "Русский алфавит" << std::endl;
	for (unsigned char i = 192; i <= 223; i++)
	{
		std::cout << int(i) << ". " << i << " | " << int(i) + 32 << ". " << char(int(i) + 32) << std::endl;

		if (int(i) == 197)
			std::cout << 168 << ". " << char(168) << " | " << 184 << ". " << char(184) << std::endl;

	}
	
	std::cout << std::endl;
	std::cout << "Знаки препинания" << std::endl;
	for (char i = 0; i < 100; i++)
	{
		if (std::ispunct(i))
			std::cout << int(i) << ". " << i << " | ";
	}
	std::cout << std::endl;
}

std::string sortWord(std::string word, char s)
{
	int start = 0;
	int end = (int)word.length() - 1;

	while (start <= end && !isalnum(unsigned char(word[start])))
		start++;

	while (end >= start && !isalpha(unsigned char(word[end])))
		end--;

	if (start > end)
		return "";

	int median = start;
	for (int i = start; i <= end; i++)
	{
		if (!isalnum(unsigned char(word[i])) && word[i + 1] != 'й')
			median = i;
	}

	std::string res = "";
	for (int i = start; i <= end; i++)
	{
		if (i != median || median == start)
			res += tolower(unsigned char(word[i]));
	}

	if (!res.empty() && res.back() == s)
		return res;

	return "";
}