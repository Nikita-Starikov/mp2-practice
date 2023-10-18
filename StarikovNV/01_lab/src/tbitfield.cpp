// ����, ���, ���� "������ ����������������-2", �++, ���
//
// tbitfield.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (19.04.2015)
//
// ������� ����

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len > 0)
    {
        BitLen = len;
        MemLen = (len + sizeof(TELEM) * 8 - 1) / (sizeof(TELEM) * 8);
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++)
            pMem[i] = 0;
    }
    else if (len == 0)
    {
        BitLen = 0;
        MemLen = 0;
        pMem = nullptr;
    }
    else
        throw "Size error";


}

TBitField::TBitField(const TBitField& bf) // ����������� �����������
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    if (MemLen)
    {
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++)
            pMem[i] = bf.pMem[i];
    }
    else
        pMem = nullptr;
}

TBitField::~TBitField()
{
    if (MemLen > 0)
        delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // ������ ��� ��� ���� n
{
    return n / (sizeof(TELEM) * 8);//���������� ������ ������ ��� ���� � ������� n
}



TELEM TBitField::GetMemMask(const int n) const // ������� ����� ��� ���� n
{
    return 1 << (n % (sizeof(TELEM) * 8));
}

// ������ � ����� �������� ����

int TBitField::GetLength(void) const // �������� ����� (�-�� �����)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // ���������� ���
{
    if (n >= 0 && n < BitLen)
        pMem[GetMemIndex(n)] |= GetMemMask(n);
    else
        throw "Error";
}

void TBitField::ClrBit(const int n) // �������� ���
{
    if (n >= 0 && n < BitLen)
        pMem[GetMemIndex(n)] &= ~GetMemMask(n);
    else
        throw "Error";
}

int TBitField::GetBit(const int n) const // �������� �������� ����
{
    if (n >= 0 && n < BitLen)
        return (pMem[GetMemIndex(n)] & GetMemMask(n)) != 0;
    else
        throw "Error";
}

// ������� ��������

TBitField& TBitField::operator=(const TBitField& bf) // ������������
{
    if (this != &bf)
    {
        if (MemLen != bf.MemLen)
        {
            delete[] pMem;
            MemLen = bf.MemLen;
            pMem = new TELEM[MemLen];
        }
        BitLen = bf.BitLen;
        for (int i = 0; i < MemLen; i++)
            pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField& bf) const // ���������
{
    if (BitLen != bf.BitLen)
        return 0;
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i])
            return 0;
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // ���������
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // �������� "���"
{
    int len = BitLen;
    if (bf.BitLen > len)
        len = bf.BitLen;
    TBitField result(len);
    for (int i = 0; i < MemLen; i++)
        result.pMem[i] = pMem[i] | bf.pMem[i];
    return result;
}

TBitField TBitField::operator&(const TBitField& bf) // �������� "�"
{
    int len = BitLen;
    if (bf.BitLen > len)
        len = bf.BitLen;
    TBitField result(len);
    for (int i = 0; i < MemLen; i++)
        result.pMem[i] = pMem[i] & bf.pMem[i];
    return result;
}

TBitField TBitField::operator~(void) // ���������
{
    TBitField result(BitLen);
    for (int i = 0; i < BitLen; i++)
        if (!GetBit(i)) result.SetBit(i);
    return result;
}

// ����/�����

istream& operator>>(istream& istr, TBitField& bf) // ����
{
    string str;
    istr >> str;
    for (int i = 0; i < bf.BitLen; i++)
    {
        int bit = str[i] - '0';
        if (bit)
            bf.SetBit(i);
        else
            bf.ClrBit(i);
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // �����
{
    //for (int i = bf.BitLen - 1; i >= 0; i--) 
    for (int i = 0; i < bf.BitLen; i++)
        ostr << bf.GetBit(i);
    return ostr;
}