// ������� ����
#include "tbitfield.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "TBitField" << endl;

    setlocale(LC_ALL, "RUSSIAN");
    int len; // ����� �������� ����
    cout << "������� ����� ����: ";
    cin >> len;


    TBitField bitField1(len); // �������� ������� TBitField � ������� ������������


    cout << "������� ������� ���� (������ " << len << " ���): "; // ���������� �������� �������� ���� � ������� ��������� �����
    cin >> bitField1;


    cout << "������� ���� 1: " << bitField1 << endl; // ����� �������� �������� ���� � ������� ��������� ������


    TBitField bitField2(bitField1);    // �������� ������� ������� TBitField � ������� ������������ �����������


    cout << "������� ������� ���� (������ " << len << " ���): "; // ���������� �������� �������� ���� � ������� ��������� �����
    cin >> bitField2;


    cout << "������� ���� 2: " << bitField2 << endl; // ����� �������� �������� ���� � ������� ��������� ������


    cout << "����� ������� �������� ����: " << bitField2.GetLength() << " ���" << endl; // ��������� ����� �������� ����


    int indexToSet = 4; // ��������� ����
    bitField2.SetBit(indexToSet);
    cout << "���������� ��� �� ������ ���� ��� �������� " << indexToSet << endl;
    cout << "������� ���� 2: " << bitField2 << endl;


    int indexToGet = 5; // ��������� �������� ����
    int bitValue = bitField2.GetBit(indexToGet);
    cout << "�������� ���� �� ������ ���� ��� �������� " << indexToGet << ": " << bitValue << endl;
    cout << "������� ���� 2: " << bitField2 << endl;


    int indexToClear = 2; // ������� ����
    bitField2.ClrBit(indexToClear);
    cout << "������ ��� �� ������ ���� ��� �������� " << indexToClear << endl;
    cout << "������� ���� 2: " << bitField2 << endl;


    if (bitField1 == bitField2) { // �������� ��������� ���������
        cout << "������� ���� �����" << endl;
    }
    else {
        cout << "������� ���� �� �����" << endl;
    }


    TBitField bitField3(len); // �������� ��������� ������������
    bitField3 = bitField1;
    if (bitField3 == bitField1) {
        cout << "������� ���� ������� �����������" << endl;
        cout << "������� ���� 1: " << bitField3 << endl;
    }


    TBitField bitField4(len); // �������� ��������� "���"
    bitField4 = bitField1 | bitField2;
    cout << "��������� 1 � 2 �������� '���': " << bitField4 << endl;


    TBitField bitField5(len); // �������� ��������� "�"
    bitField5 = bitField1 & bitField2;
    cout << "��������� 1 � 2 �������� '�': " << bitField5 << endl;


    TBitField bitField6(len); // �������� ��������� ���������
    bitField6 = ~bitField1;
    cout << "��������� �������� ��������� ������� ����: " << bitField6 << endl;

    return 0;
}