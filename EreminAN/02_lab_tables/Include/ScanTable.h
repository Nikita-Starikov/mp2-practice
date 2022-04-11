#pragma once
#include "Table.h" 
#include "TArrayTable.h"

//Просматриваемые таблицы:
//Записи хранятся в порядке их добавления. Храним в виде массива;


template <typename TData>
class  ScanTable : public TArrayTable<TData>
{
public:
	ScanTable(int Size = TabMaxSize) : TArrayTable<TData>(Size) {}; //конструктор

	// основные методы
	virtual TData* FindRecord(const TableKey key_);                        //найти запись                        
	virtual void InsRecord(const TableKey key_, TData* data_);      //вставить                             
	virtual void DelRecord(const TableKey key_);                         //удалить запись                      
};

template <typename TData>
TData* ScanTable<TData>::FindRecord(const TableKey key_)
{
	if (IsEmpty())
		return nullptr;

	int i = 0;
	Reset();
	for (i; i < DataCount; i++)
		if (pRecs[i]->GetKey() == key_)
			break;
	if (i < DataCount)
	{
		CurrPos = i;
		return pRecs[i]->GetData();
	}
	return nullptr;
}

template <typename TData>
void ScanTable<TData>::InsRecord(const TableKey key_, TData* data_)
{
	if (IsFull())
		throw"Error";

	TData* tmp = FindRecord(key_);
	Reset();
	if (tmp == nullptr)
	{
		pRecs[DataCount] = new TabRecord<TData>(key_, data_);
		DataCount++;
	}
	else throw "Error";
	Reset();
}

template <typename TData>
void ScanTable<TData>::DelRecord(const TableKey key_)
{
	if (FindRecord(key_) == nullptr)
		throw "Error";
	else
	{
		pRecs[CurrPos] = pRecs[DataCount - 1];
		pRecs[DataCount - 1] = nullptr;
		DataCount--;
	}
}
