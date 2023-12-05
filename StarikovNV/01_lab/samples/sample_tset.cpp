// ���������
#include <iostream>
#include "tset.h"

using namespace std;

int main()
{
    cout << "TSet" << endl;

    int maxPower = 10;  // ������������ �������� ���������

    // �������� ��������� � ������������ ��������� maxPower
    TSet set1(maxPower);
    TSet set2(maxPower);

    // ���������� ��������� � ���������
    set1.InsElem(2);
    set1.InsElem(4);
    set1.InsElem(5);
    set1.InsElem(8);

    set2.InsElem(1);
    set2.InsElem(3);
    set2.InsElem(8);
    set2.InsElem(9);

    // ����� ��������� �� �����
    cout << "set1: " << set1 << endl;
    cout << "set2: " << set2 << endl;

    // �������� ������� ��������� � ���������
    cout << "Element 5 in set1: " << set1.IsMember(5) << endl;
    cout << "Element 2 in set2: " << set2.IsMember(2) << endl;

    // �������� ������ ��������� set2, ������� set1

    // �������� �������� �� ��������� set2
    set2.DelElem(3);

    // ����� ��������� set2 �� �����
    cout << "set2 after delete 3: " << set2 << endl;

    // �������� ��������
    cout << "operator==: " << (set1 == set2) << endl;
    cout << "operator!=: " << (set1 != set2) << endl;
    cout << "operator+ (elem): " << (set1 + 0) << endl;
    cout << "operator- (elem): " << (set1 - 5) << endl;
    cout << "operator*: " << (set1 * set2) << endl;
    cout << "operator+: " << (set1 + set2) << endl;
    cout << "operator~: " << ~set1 << endl;
    return 0;
}