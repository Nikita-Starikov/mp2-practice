#pragma once 
#include <string>
#include <iostream>
#include <iomanip>


using namespace std;
typedef std::string TableKey;

//Класс записи;
template <typename TData>
class TabRecord
{
protected:
	TableKey Key;            //Ключ;
	TData* Data;            // Указатель на данные;
public:

	TabRecord(TableKey key_ = "", TData* data_ = nullptr)
	{
		Key = key_; Data = data_;
	}
	TabRecord(const TabRecord& TabR_)
	{
		Key = TabR_.Key; Data = TabR_.Data;
	}

	void SetKey(const TableKey key_) { Key = key_; }
	TableKey GetKey() { return Key; }

	void SetData(TData* data_) { Data = data_; }
	TData* GetData() const { return Data; }

	TabRecord& operator=(const TabRecord& TabR)
	{
		Data = TabR.Data; Key = TabR.Key; return *this;
	}
};


//Класс таблиц;
template <typename TData>
class Table
{
protected:
	int DataCount;                    //Текущее количество записей;
public:
	Table() { DataCount = 0; }
	virtual ~Table() {};

	// информационные методы; 
	int GetDataCount() const { return DataCount; }                                    // к-во записей;
	int IsEmpty() const { return DataCount == 0; }                                   //пуста?;
	virtual int IsFull() const = 0;                                                 // заполнена?;

	// основные методы;
	virtual TData* FindRecord(const TableKey key_) = 0;                          // найти запись;
	virtual void InsRecord(const TableKey Key_, TData* Data_) = 0;              // вставить;
	virtual void DelRecord(const TableKey Key_) = 0;                           // удалить запись;


	// навигация;
	virtual void Reset() = 0;                                               // установить на первую запись;
	virtual int IsTabEnded() const = 0;                                    // таблица завершена?;
	virtual void GoNext() = 0;                                            // переход к следующей записи;
																		 // (=1 после применения для последней записи таблицы);

	virtual TableKey GetKey() const = 0;
	virtual TData* GetData() const = 0;


	friend std::ostream& operator<<(std::ostream& os, Table<TData>& tab)
	{
		cout << "Table" << endl;
		cout << "|\t"<< "Key" << "\t" << "|" << "\t" << "Data" << "\t|" << endl;
		cout <<"+-------------------------------+\t"<< endl;
		for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
		{
			os << "|\t" << tab.GetKey() << "\t" << "|"<<"\t" << *tab.GetData() <<"\t|"<< endl;
		}
		return os;
	}
};