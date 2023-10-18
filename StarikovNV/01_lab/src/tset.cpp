// ����, ���, ���� "������ ����������������-2", �++, ���
//
// tset.cpp - Copyright (c) ������� �.�. 04.10.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (19.04.2015)
//
// ��������� - ���������� ����� ������� ����

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
    if (mp >= 0)
        MaxPower = mp;
    else
        throw "Size Error";
}

TSet::TSet(const TSet& s) : BitField(s.BitField) // ����������� �����������
{
    MaxPower = s.MaxPower;
}

TSet::TSet(const TBitField& bf) : BitField(bf) // ����������� �������������� ����
{
    MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const // �������� ����. �-�� ��-���
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // ������� ���������?
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // ��������� �������� ���������
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    return BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // ���������� �������� ���������
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    return BitField.ClrBit(Elem);
}

// ���������-������������� ��������

TSet& TSet::operator=(const TSet& s) // ������������
{
    if (this != &s)
    {
        MaxPower = s.MaxPower;
        BitField = s.BitField;
    }
    return *this;
}

int TSet::operator==(const TSet& s) const // ���������
{
    return BitField == s.BitField;;
}

int TSet::operator!=(const TSet& s) const // ���������
{
    return BitField != s.BitField;
}

TSet TSet::operator+(const TSet& s) // �����������
{
    size_t newMaxPower;
    if (MaxPower > s.MaxPower)
        newMaxPower = MaxPower;
    else
        newMaxPower = s.MaxPower;
    TSet result(newMaxPower);
    result.BitField = BitField | s.BitField;
    return result;
}

TSet TSet::operator+(const int Elem) // ����������� � ���������
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    TSet temp(*this);
    temp.BitField.SetBit(Elem);
    return temp;
}

TSet TSet::operator-(const int Elem) // �������� � ���������
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    TSet tmp(*this);
    tmp.BitField.ClrBit(Elem);
    return tmp;
}

TSet TSet::operator*(const TSet& s) // �����������
{
    size_t newMaxPower;
    if (MaxPower > s.MaxPower)
        newMaxPower = MaxPower;
    else
        newMaxPower = s.MaxPower;
    TSet result(newMaxPower);
    result.BitField = BitField & s.BitField;
    return result;
}

TSet TSet::operator~(void) // ����������
{
    TSet result(MaxPower);
    result.BitField = ~BitField;
    return result;
}

// ���������� �����/������

istream& operator>>(istream& istr, TSet& s) // ����
{
    istr >> s.BitField;
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // �����
{
    ostr << s.BitField;
    return ostr;
}