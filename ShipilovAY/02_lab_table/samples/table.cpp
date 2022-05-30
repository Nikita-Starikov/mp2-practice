#include <cstdio>
#include <string>

#include <iostream>
#include "polinom.h"
#include "monom.h"
#include "ListHash.h"
#include "ScanTable.h"
#include "SortTable.h"

using namespace std;

void print_menu() {
	cout << "Выберите операцию:" << endl;
	cout << "1.Ввод элемента" << endl;
	cout << "2.Удаление элемента" << endl;
	cout << "3.Поиск элемента" << endl;
	cout << "4.Выполнить одну из вычислительных операций" << endl;
	cout << "5.Печать таблиц" << endl;
	cout << "6.Очистить таблицы" << endl;
	cout << "0.Выход" << endl;
};

void print_menu1() {
	cout << "Выберите операцию:" << endl;
	cout << "1.Ввод элемента в просматриваемую таблицу" << endl;
	cout << "2.Ввод элемента в упорядоченную таблицу" << endl;
	cout << "3.Ввод элемента в хеш-таблицу" << endl;
	cout << "4.Ввод элемента во все таблицы" << endl;
	cout << "0.Назад" << endl;
};

void print_menu2() {
	cout << "Выберите операцию:" << endl;
	cout << "1.Удаление элемента из просматриваемой таблицы" << endl;
	cout << "2.Удаление элемента из упорядоченной таблицы" << endl;
	cout << "3.Удаление элемента из хеш-таблицы" << endl;
	cout << "4.Удаление элемента из все таблиц" << endl;
	cout << "0.Назад" << endl;
};

void print_menu3() {
	cout << "Выберите операцию:" << endl;
	cout << "1.Поиск элемента в просматриваемой таблице" << endl;
	cout << "2.Поиск элемента в упорядоченной таблице" << endl;
	cout << "3.Поиск элемента в хеш-таблице" << endl;
	cout << "4.Поиск элемента во всех таблицах" << endl;
	cout << "0.Назад" << endl;
};

void print_menu4() {
	cout << "Выберите операцию, которую хотите применить:" << endl;
	cout << "1.Сумма полиномов" << endl;
	cout << "2.Разность полиномов" << endl;
	cout << "3.Произведение полиномов" << endl;
	cout << "4.Произведение одного из полиномов на константу" << endl;
	cout << "0.Назад" << endl;
};
void print_menu41() {
	cout << "Выберите таблицу в которой хотите выполнить вычислительную операцию:" << endl;
	cout << "1.Просматриваемая таблица" << endl;
	cout << "2.Упорядоченная таблица" << endl;
	cout << "3.Хеш-таблица" << endl;
	cout << "0.Назад" << endl;
}

void print_menu5() {
	cout << "Выберите операцию:" << endl;
	cout << "1.Печать просматриваемой таблицы" << endl;
	cout << "2.Печать упорядоченной таблицы" << endl;
	cout << "3.Печать хеш-таблицы" << endl;
	cout << "4.Печать всех таблиц" << endl;
	cout << "0.Назад" << endl;
};

void print_menu6() {
	cout << "Выберите операцию:" << endl;
	cout << "1.Очистить просматриваемую таблицу" << endl;
	cout << "2.Очистить упорядоченную таблицу" << endl;
	cout << "3.Очистить хеш-таблицу" << endl;
	cout << "4.Очистить все таблицы" << endl;
	cout << "0.Назад" << endl;
};

int main()
{
	int c = 0;
	int menu = 0;
	int SIZE;
	string a;
	setlocale(LC_ALL, "Russian");
	cout << "Введите размер таблиц:" << endl;
	cin >> SIZE;
	ScanTable <TPolinom, string> A(SIZE);
	SortTable <TPolinom, string> B(SIZE);
	ListHash  <TPolinom, string> C(SIZE);

	system("cls");
	print_menu();
	cin >> menu;
	while (menu != 0)
	{
		switch (menu)
		{
		case 1:
		{
			int case1;
			system("cls");
			print_menu1();
			cin >> case1;
			while (case1 != 0)
			{
				switch (case1)
				{
				case 1:
				{
					string str, key;
					cout << "Введите ваш полином:" << endl;
					cin >> str;
					cout << "Введите ваш ключ:" << endl;
					cin >> key;
					TPolinom P(str);
					try
					{
						A.Insert(P, key);
					}
					catch (...)
					{
						cout << "Повторный ключ" << endl;
					}
					system("cls");
					print_menu1();
					cin >> case1;
					break;
				}
				case 2:
				{
					string str, key;
					cout << "Введите ваш полином:" << endl;
					cin >> str;
					cout << "Введите ваш ключ:" << endl;
					cin >> key;
					TPolinom P(str);
					try
					{
						B.Insert(P, key);
					}
					catch (...)
					{
						cout << "Повторный ключ" << endl;
					}
					system("cls");
					print_menu1();
					cin >> case1;
					break;
				}
				case 3:
				{
					string str, key;
					cout << "Введите ваш полином:" << endl;
					cin >> str;
					cout << "Введите ваш ключ:" << endl;
					cin >> key;
					TPolinom P(str);
					try
					{
						C.Insert(P, key);
					}
					catch (...)
					{
						cout << "Повторный ключ" << endl;
					}
					system("cls");
					print_menu1();
					cin >> case1;
					break;
				}
				case 4:
				{
					string str, key;
					cout << "Введите ваш полином:" << endl;
					cin >> str;
					cout << "Введите ваш ключ:" << endl;
					cin >> key;
					TPolinom P(str);
					try
					{
						A.Insert(P, key);
					}
					catch (...)
					{
						cout << "Повторный ключ" << endl;
					}
					try
					{
						B.Insert(P, key);
					}
					catch (...)
					{
						cout << "Повторный ключ" << endl;
					}
					try
					{
						C.Insert(P, key);
					}
					catch (...)
					{
						cout << "Повторный ключ" << endl;
					}
					system("cls");
					print_menu1();
					cin >> case1;
					break;
				}
				default: break;
				}

			}
			print_menu();
			cin >> menu;
			system("cls");
			break;
		}
		case 2:
		{
			int case2;
			system("cls");
			print_menu2();
			cin >> case2;
			while (case2 != 0)
			{
				switch (case2)
				{
				case 1:
				{
					string key;
					cout << "Введите ключ элемента который хотите удалить:" << endl;
					cin >> key;
					A.Delete(key);
					print_menu2();
					cin >> case2;
					break;
				}
				case 2:
				{
					string key;
					cout << "Введите ключ элемента который хотите удалить:" << endl;
					cin >> key;
					B.Delete(key);
					print_menu2();
					cin >> case2;
					break;
				}
				case 3:
				{
					string key;
					cout << "Введите ключ элемента который хотите удалить:" << endl;
					cin >> key;
					C.Delete(key);
					print_menu2();
					cin >> case2;
					break;
				}
				case 4:
				{
					string key;
					cout << "Введите ключ элемента который хотите удалить:" << endl;
					cin >> key;
					A.Delete(key);
					B.Delete(key);
					C.Delete(key);
					print_menu2();
					cin >> case2;
					break;
				}

				}
			}
			print_menu();
			cin >> menu;
			system("cls");
			break;
		}
		case 3:
		{

			int case3;
			system("cls");
			print_menu3();
			cin >> case3;
			while (case3 != 0)
			{
				switch (case3)
				{
				case 1:
				{
					string key;
					cout << "Введите ключ элемента который хотите найти:" << endl;
					cin >> key;
					try
					{
						if (A.Search(key) != nullptr)
							cout << "Найден: " << *(TPolinom*)A.Search(key) << endl;
						else
							cout << "Not found!" << endl;
					}
					catch (...) { cout << "Не найден" << endl; }
					print_menu3();
					cin >> case3;
					break;
				}
				case 2:
				{
					string key;
					cout << "Введите ключ элемента который хотите найти:" << endl;
					cin >> key;
					try
					{
						if (B.Search(key) != nullptr)
							cout << "Найден: " << *(TPolinom*)A.Search(key) << endl;
						else
							cout << "Not found!" << endl;
					}
					catch (...) { cout << "Не найден" << endl; }
					print_menu3();
					cin >> case3;
					break;
				}
				case 3:
				{
					string key;
					cout << "Введите ключ элемента который хотите найти:" << endl;
					cin >> key;
					try
					{
						if (C.Search(key) != nullptr)
							cout << "Найден: " << *(TPolinom*)A.Search(key) << endl;
						else
							cout << "Not found!" << endl;
					}
					catch (...) { cout << "Не найден" << endl; }
					print_menu3();
					cin >> case3;
					break;
				}
				case 4:
				{
					string key;
					cout << "Введите ключ элемента который хотите найти:" << endl;
					cin >> key;
					try
					{
						if (A.Search(key) != nullptr)
							cout << "Найден: " << *(TPolinom*)A.Search(key) << endl;
						else
							cout << "Not found!" << endl;
					}
					catch (...) { cout << "Не найден" << endl; }
					try
					{
						if (B.Search(key) != nullptr)
							cout << "Найден: " << *(TPolinom*)B.Search(key) << endl;
						else
							cout << "Not found!" << endl;
					}
					catch (...) { cout << "Не найден" << endl; }
					try
					{
						if (C.Search(key) != nullptr)
							cout << "Найден: " << *(TPolinom*)C.Search(key) << endl;
						else
							cout << "Not found!" << endl;
					}
					catch (...) { cout << "Не найден" << endl; }
					print_menu3();
					cin >> case3;
					break;
				}
				}
			}
			print_menu();
			cin >> menu;
			system("cls");
			break;
		}
		case 4:
		{
			print_menu4();
			int case4;
			cin >> case4;
			while (case4 != 0)
			{
				switch (case4)
				{
				case 1:
				{
					print_menu41();
					int case41;
					cin >> case41;
					while (case41 != 0)
					{
						switch (case41)
						{
						case 1:
						{
							cout << "Просматриваемая таблица:" << endl;
							cout << A << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (A.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)A.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (A.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)A.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)A.Search(key1) + *(TPolinom*)A.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								A.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case41;
							break;
						}
						case 2:
						{
							cout << "Упорядоченная таблица:" << endl;
							cout << B << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (B.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)B.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (B.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)B.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)B.Search(key1) + *(TPolinom*)B.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								B.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case41;
							break;
						}
						case 3:
						{
							cout << "Hash:" << endl;
							cout << C << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (C.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)C.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (C.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)C.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)C.Search(key1) + *(TPolinom*)C.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								C.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case41;
							break;
						}
						}
					}
				print_menu4();
				cin >> case4;
				break;
				}
				case 2:
				{
					print_menu41();
					int case42;
					cin >> case42;
					while (case42 != 0)
					{
						switch (case42)
						{
						case 1:
						{
							cout << "Просматриваемая таблица:" << endl;
							cout << A << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (A.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)A.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (A.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)A.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)A.Search(key1) - *(TPolinom*)A.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								A.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case42;
							break;
						}
						case 2:
						{
							cout << "Упорядоченная таблица:" << endl;
							cout << B << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (B.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)B.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (B.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)B.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)B.Search(key1) - *(TPolinom*)B.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								B.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case42;
							break;
						}
						case 3:
						{
							cout << "Hash:" << endl;
							cout << C << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (C.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)C.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (C.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)C.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)C.Search(key1) - *(TPolinom*)C.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								C.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case42;
							break;
						}
						}
					}
					print_menu4();
					cin >> case4;
					break;
				}
				case 3:
				{
					print_menu41();
					int case43;
					cin >> case43;
					while (case43 != 0)
					{
						switch (case43)
						{
						case 1:
						{
							cout << "Просматриваемая таблица:" << endl;
							cout << A << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (A.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)A.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (A.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)A.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)A.Search(key1) * *(TPolinom*)A.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								A.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case43;
							break;
						}
						case 2:
						{
							cout << "Упорядоченная таблица:" << endl;
							cout << B << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (B.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)B.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (B.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)B.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)B.Search(key1) * *(TPolinom*)B.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								B.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case43;
							break;
						}
						case 3:
						{
							cout << "Hash:" << endl;
							cout << C << endl;
							cout << "Выберите полиномы по ключу над которыми хотите выполнить арифметическую операцию:" << endl;
							string key1, key2, key3;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (C.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)C.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Полином 2" << endl;
							cin >> key2;
							try
							{
								if (C.Search(key2) != nullptr)
									cout << "Найден: " << *(TPolinom*)C.Search(key2) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							TPolinom res = *(TPolinom*)C.Search(key1) * *(TPolinom*)C.Search(key2);
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key3;
							try
							{
								C.Insert(res, key3);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case43;
							break;
						}
						}
					}
					print_menu4();
					cin >> case4;
					break;
				}
				case 4:
				{
					print_menu41();
					int case44;
					cin >> case44;
					while (case44 != 0)
					{
						switch (case44)
						{
						case 1:
						{
							cout << "Просматриваемая таблица:" << endl;
							cout << A << endl;
							cout << "Выберите полином по ключу над которым хотите выполнить умножение на константу:" << endl;
							string key1, key2;
							double b;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (A.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)A.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Ввведите константу на которую хотите умноженить полином:" << endl;
							cin >> b;
							
							TPolinom res = *(TPolinom*)A.Search(key1) * b;
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key2;
							try
							{
								A.Insert(res, key2);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case44;
							break;
						}
						case 2:
						{
							cout << "Упорядоченная таблица:" << endl;
							cout << B << endl;
							cout << "Выберите полином по ключу над которым хотите выполнить умножение на константу:" << endl;
							string key1, key2;
							double b;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (B.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)B.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Ввведите константу на которую хотите умноженить полином:" << endl;
							cin >> b;

							TPolinom res = *(TPolinom*)B.Search(key1) * b;
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key2;
							try
							{
								B.Insert(res, key2);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case44;
							break;
						}
						case 3:
						{
							cout << "Hash:" << endl;
							cout << C << endl;
							cout << "Выберите полином по ключу над которым хотите выполнить умножение на константу:" << endl;
							string key1, key2;
							double b;
							cout << "Полином 1" << endl;
							cin >> key1;
							try
							{
								if (C.Search(key1) != nullptr)
									cout << "Найден: " << *(TPolinom*)C.Search(key1) << endl;
								else
									cout << "Not found!" << endl;
							}
							catch (...) { cout << "Не найден" << endl; }
							cout << "Ввведите константу на которую хотите умноженить полином:" << endl;
							cin >> b;
							
							TPolinom res = *(TPolinom*)C.Search(key1) * b;
							cout << "Результат: " << res << endl;
							cout << "Введите ключ под которым хотите занести полученный результат в таблицу:" << endl;
							cin >> key2;
							try
							{
								C.Insert(res, key2);
							}
							catch (...)
							{
								cout << "Повторный ключ" << endl;
							}
							print_menu41();
							cin >> case44;
							break;
						}
						}
					}
				print_menu4();
				cin >> case4;
				break;
				}
				}
			}
		print_menu();
		cin >> menu;
		system("cls");
		break;
		}
		case 5:
		{
			int case5;
			system("cls");
			print_menu5();
			cin >> case5;
			while (case5 != 0)
			{
				switch (case5)
				{
				case 1:
				{
					cout << "Просматриваемая:" << endl;
					cout << A << endl;
					print_menu5();
					cin >> case5;
					break;
				}
				case 2:
				{
					cout << "Упорядоченная:" << endl;
					cout << B << endl;
					print_menu5();
					cin >> case5;
					break;
				}
				case 3:
				{
					cout << "Hash:" << endl;
					cout << C << endl;
					print_menu5();
					cin >> case5;
					break;
				}
				case 4:
				{
					cout << "Просматриваемая:" << endl;
					cout << A << endl;
					cout << "Упорядоченная:" << endl;
					cout << B << endl;
					cout << "Hash:" << endl;
					cout << C << endl;
					print_menu5();
					cin >> case5;
					break;
				}
				}
			}
		print_menu();
		cin >> menu;
		system("cls");
		break;
		}
		case 6:
		{
			int case6;
			system("cls");
			print_menu6();
			cin >> case6;
			while (case6 != 0)
			{
				switch (case6)
				{
				case 1:
				{
					A.Clear();
					cout << "Просматриваемая:" << endl;
					cout << A << endl;
					print_menu6();
					cin >> case6;
					break;
				}
				case 2:
				{
					B.Clear();
					cout << "Упорядоченная:" << endl;
					cout << B << endl;
					print_menu6();
					cin >> case6;
					break;
				}
				case 3:
				{
					C.Clear();
					cout << "Hash:" << endl;
					cout << C << endl;
					print_menu6();
					cin >> case6;
					break;
				}
				case 4:
				{
					A.Clear();
					B.Clear();
					C.Clear();
					cout << "Просматриваемая:" << endl;
					cout << A << endl;
					cout << "Упорядоченная:" << endl;
					cout << B << endl;
					cout << "Hash:" << endl;
					cout << C << endl;
					print_menu6();
					cin >> case6;
					break;
				}
				}
			}
			print_menu();
			cin >> menu;
			system("cls");
			break;
		}
		default:
		{
			cout << "Ошибка" << endl;
			break;
		}
		}
	}
	return 0;
}