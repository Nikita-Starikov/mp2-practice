#include <iostream>
#include "talgorithm.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	std::string s;
	std::cin >> s;
	try
	{
		Postfix postfix = postfix.ConvertToPol(s);
		std::cout << "������� : " << s << std::endl;
		std::cout << "�������� : " << postfix << std::endl;
		postfix.setValues();
		double result = postfix.calculate();
		std::cout << "��������� ������� = " << result << std::endl;
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}

	return 0;

}