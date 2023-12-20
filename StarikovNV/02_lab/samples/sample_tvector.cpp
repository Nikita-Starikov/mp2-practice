#include <iostream>
#include "tvector.h"
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    TVector<int> v1(4, 1);
    TVector<int> v2(4, 1);
    TVector<int> v3(3, 2);
    TVector<int> v4(4, 1);

    for (int i = 0; i < 4; i++)
    {
        v1[i] = i + 2;
        v2[i] = i * 2 + 1;
        v4[i] = v2[i];
    }

    for (int i = 0; i < 3; i++)
    {
        v3[i] = i * 2 + 2;
    }
    std::cout << "�������:" << '\n';
    std::cout << "v1 = " << v1 << '\n';
    std::cout << "v2 = " << v2 << '\n';
    std::cout << "v3 = " << v3 << '\n';
    std::cout << "v4 = " << v4 << '\n' << '\n';
    std::cout << "������ v1 = v2 = " << v1.GetSize() << '\n';// ������
    std::cout << "������ v3 = " << v3.GetSize() << '\n';
    std::cout << "������ v1 = v2 = " << v1.GetIndex() << '\n'; // ������
    std::cout << "������ v3 = " << v3.GetIndex() << '\n';
    std::cout << "������� v2 �� ������� 3 = " << v2[3] << '\n' << '\n'; //������� � ������� = ������
    std::cout << "�������� �� ���������/�����������:" << '\n';
    std::cout << "v1 == v2 " << (v1 == v2) << '\n'; //==, !=    //0
    std::cout << "v2 != v4 " << (v2 != v4) << '\n';             //0  
    std::cout << "v2 == v4 " << (v2 == v4) << '\n' << '\n';             //1  
    std::cout << "�������� ������� � ������" << '\n';
    std::cout << "v1 * 5 = " << v1 * 5 << '\n';
    std::cout << "v1 + 5 = " << v1 + 5 << '\n';
    std::cout << "v1 - 5 = " << v1 - 5 << '\n' << '\n';
    std::cout << "�������� ������� � ��������" << '\n';
    std::cout << "v1 + v2 = " << v1 + v2 << '\n';
    std::cout << "v2 - v1 = " << v2 - v1 << '\n';
    std::cout << "v1 * v2 (��������) = " << v1 * v2 << '\n';

    return 0;

}