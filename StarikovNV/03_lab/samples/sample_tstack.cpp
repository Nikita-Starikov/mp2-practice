#include <iostream>
#include "tstack.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    try {
        TStack<int> S;
        S.Push(15);
        S.Push(5);
        int b = S.Pop();
        std::cout << "������� 15, � ����� 5 � ����" << std::endl;
        std::cout << "���������� �������� = " << b << std::endl;
        S.Push(10);
        b = S.Pop();
        std::cout << "������� 10" << std::endl;
        std::cout << "���������� �������� = " << b << std::endl;
    }
    catch (std::invalid_argument const& ex)
    {
    };

    return 0;
}