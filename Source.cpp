#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
template <typename T>//прототип шаблона фн-ии создания пустого массива
bool createArrD(T * &ptrDarr, const int row);
template <typename T>//прототип шаблона фн-ии удаления динамического 2Д массива 
void deleteArrD(T * &ptrDarr, const int row);
struct author//структура "автор"
{
	char * name;//имя
	char * sname;//фамилия
	char * country;//страна

	void showAuthor()//вывод автор
	{
		cout << sname << " /// " << name << " /// " << country << " /// ";
	}
};
struct book//структура книга
{
	
	char * title;//название
	author * writer;//автор
	char * publHouse;//издательство
	char * genre;//жанр

	void showBook()//вывод книги
	{
		cout  << "  " << title << " / ";
		writer->showAuthor();
		cout << publHouse << " / " << genre << endl;
	}

	

	int searchWriter(char * str)//поиск по имени автора
	{
		int p = strcmp(str, writer->sname);
		if (p == 0)//есть ли совпадения
		{
			return 1;//если да,возврат 1
		}
		return 0;//иначе 0
	}

	int searchTitle(char * str)//поиск по названию
	{
		int p = strcmp(str, title);
		if (p == 0)//есть ли совпадения
		{
			return 1;//если да,возврат 1
		}
		return 0;//иначе 0
	}
};
void edit(book * ptr, char k,int n)//редактирование
{
	if (k == '1')
	{
		char * str = new char[15]{ '\0' };
		cout << "New title:\n";//новое названи
		cin.getline(str, 15);
		gets_s(str, 15);
		strcpy(ptr[n-1].title,str);
		delete[]str;
	}
	if (k == '2')
	{
		char * str = new char[15]{ '\0' };
		cout << "New writ.name:\n";//новое имя писателя
		cin.getline(str, 15);
		gets_s(str, 15);
		strcpy(ptr[n - 1].writer->name, str);
		delete[]str;
	}
	if (k == '3')
	{
		char * str = new char[15]{ '\0' };
		cout << "New writ.sname:\n";//новое 2имя писателя
		cin.getline(str, 15);
		gets_s(str, 15);
		strcpy(ptr[n - 1].writer->sname, str);
		delete[]str;
	}
	if (k == '4')
	{
		char * str = new char[15]{ '\0' };
		cout << "New writ.country:\n";//новая страна писателя
		cin.getline(str, 15);
		gets_s(str, 15);
		strcpy(ptr[n - 1].writer->country, str);
		delete[]str;
	}
	if (k == '5')
	{
		char * str = new char[15]{ '\0' };
		cout << "New publHouse:\n";//новое издательство
		cin.getline(str, 15);
		gets_s(str, 15);
		strcpy(ptr[n - 1].publHouse, str);
		delete[]str;
	}
	if (k == '6')
	{
		char * str = new char[15]{ '\0' };
		cout << "New genre:\n";//новый жанр
		cin.getline(str, 15);
		gets_s(str, 15);
		strcpy(ptr[n - 1].genre, str);
		delete[]str;
	}
}

book*  sortTitl(book * str)//сортировка
{
	book * tmp = new book[15]{ '\0' };
	for (int i = 0; i<5 - 1; i++)
	{
		for (int j = i + 1; j<5; j++)
		{
			if (strcmp(str[i].title, str[j].title)>0)
			{
				*tmp = str[i];
				str[i] = str[j];
				str[j] = *tmp;
			}
		}
	}
	delete[]tmp;
	return str;
}

book* sortSname(book * str)//сортировка
{
	book * tmp = new book[15]{ '\0' };
	for (int i = 0; i<5 - 1; i++)
	{
		for (int j = i + 1; j<5; j++)
		{
			if (strcmp(str[i].writer->sname, str[j].writer->sname)>0)
			{
				*tmp = str[i];
				str[i] = str[j];
				str[j] = *tmp;
			}
		}
	}
	delete[]tmp;
	return str;
}

book* sortPublHous(book * str)//сортировка
{
	book * tmp = new book[15]{ '\0' };
	for (int i = 0; i<5 - 1; i++)
	{
		for (int j = i + 1; j<5; j++)
		{
			if (strcmp(str[i].publHouse, str[j].publHouse)>0)
			{
				*tmp = str[i];
				str[i] = str[j];
				str[j] = *tmp;
			}
		}
	}
	delete[]tmp;
	return str;
}

void deleteBook(book *lop)
{
	delete[]lop->writer->name;
	delete[]lop->writer->sname;
	delete[]lop->writer->country;
	delete[]lop->writer;
	delete[]lop->title;
	delete[]lop->publHouse;
	delete[]lop->genre;
}

int main()
{
	cout << endl;
	cout << "\t\tFrom March 8!!!\n";
	cout << endl;
	cout << "\tLibrary\n";
	cout << endl;
	int size = 25;
	int row = 5;
	book * ptrDarr = new book[row];

	book one;//книга 1
	//one.numb = 1;
	one.title = new char[size] {'V', 'i', 'y', '\0'};
	one.writer = new author;
	one.writer->name = new char[size] {'N', 'i', 'k', 'o', 'l', 'a', 'y', '\0'};
	one.writer->sname = new char[size] {'G', 'o', 'g', 'o', 'l', '\0'};
	one.writer->country = new char[size] {'R', 'u', 's', '/', 'U', 'k', 'r', '\0'};
	one.publHouse = new char[size] {'A', 'S', 'T', '\0'};
	one.genre = new char[size] {'S', 't', 'o', 'r', 'y', '\0'};

	book two;//книга 2
	//two.numb = 2;
	two.title = new char[size] {'M','a','s','t','e','r',' ','a','n','d',' ','M','a','r','g','a','r','i','t','a','\0'};
	two.writer = new author;
	two.writer->name = new char[size] {'M','i','c','h','a','e','l', '\0'};
	two.writer->sname = new char[size] {'B','u','l','g','a','k','o','v', '\0'};
	two.writer->country = new char[size] {'R', 'u', 's','s','i','a','\0'};
	two.publHouse = new char[size] {'Y','M','C','A','-','p','r','e','s','s', '\0'};
	two.genre = new char[size] {'N', 'o', 'v', 'e', 'l', '\0'};

	book three;//книга 3
	//three.numb = 3;
	three.title = new char[size] {'B','o','o','k',' ','o','f',' ','N','a','m','e','s', '\0'};
	three.writer = new author;
	three.writer->name = new char[size] {'J','i','l','l', '\0'};
	three.writer->sname = new char[size] {'G', 'r','e','g','o','r','y', '\0'};
	three.writer->country = new char[size] {'U', '.','S','.','A', '\0'};
	three.publHouse = new char[size] {'P','r','i','n','t','-','f','a','c','t','o','r', '\0'};
	three.genre = new char[size] {'N', 'o', 'v', 'e', 'l', '\0'};

	book four;//книга 4
	//four.numb = 4;
	four.title = new char[size] {'N','o','r','t','h',' ','w','a','t','e','r', '\0'};
	four.writer = new author;
	four.writer->name = new char[size] {'I','a','n', '\0'};
	four.writer->sname = new char[size] {'M','c','G','u','i','r','e', '\0'};
	four.writer->country = new char[size] {'R', 'u', 's', '/', 'U', 'k', 'r', '\0'};
	four.publHouse = new char[size] {'A', 'S', 'T', '\0'};
	four.genre = new char[size] {'N', 'o', 'v', 'e', 'l', '\0'};

	book five;//книга 5
	//five.numb = 5;
	five.title = new char[size] {'S','t','a','y',' ','a','l','i','v','e', '\0'};
	five.writer = new author;
	five.writer->name = new char[size] {'N', 'i', 'c', 'o', 'l', 'a', 's', '\0'};
	five.writer->sname = new char[size] {'V', 'a', 'n', 'i', 'e','r', '\0'};
	five.writer->country = new char[size] {'E', 'n', 'g', 'l', 'a', 'n','d' ,'\0'};
	five.publHouse = new char[size] {'B','e','l','o','t','s','e','r','k','o','v','s','k','y',' ','b','o','o','k',' ','f','a','c','t','o','r','y', '\0'};
	five.genre = new char[size] {'N', 'o', 'v', 'e', 'l', '\0'};


	//bool create = createArrD(ptrDarr, row);//вызов фн-ии создания пустого массива
	if (ptrDarr)//проверка наличия пустого массива
	{//если да,то:
		for (int i = 0; i < row; i++)
		{
			if (i == 0)
			{
				*(ptrDarr + i) = one;
			}
			if (i == 1)
			{
				*(ptrDarr + i) = two;
			}
			if (i == 2)
			{
				*(ptrDarr + i) = three;
			}
			if (i == 3)
			{
				*(ptrDarr + i) = four;
			}
			if (i == 4)
			{
				*(ptrDarr + i) = five;
			}
		}
		char choise{};//объявление переменной для выбора
		while (true || choise != '0')//условие входа в блок while
		{//начало блока while
			system("cls");//очистка экрана
			cout << endl;
			cout << "\t\tFrom March 8!!!\n";
			cout << endl;
			cout << "\tLibrary\n";
			cout << endl;
			cout << "Good day!Choose action:\n";//просит сделать выбор
			cout << endl;
			cout << "1 - Edit book\n";
			cout << "2 - Printing all books\n";
			cout << "3 - Book search by author (by sname)\n";
			cout << "4 - Book search by title\n";
			cout << "5 - Sort by book title\n";
			cout << "6 - Sort by author (by sname)\n";
			cout << "7 - Sort by publHouse\n";
			cout << "0 - Exit\n";
			cout << endl;
			cin >> choise;//ввод выбора
			if (choise == '0')break;//условие выхода из while
			switch (choise)//множественный выбор
			{//начало блока switch
			case '1':
			{
				cout << endl;
				int n = 9;
				while (true || n < 1 || row < n)
				{
					cout << endl;
					cout << "Enter serial number:\n";
					cin >> n;
					if ((1 <= n) & (n <= row))break;
					else
					{
						cout << endl;
						cout << "Error!\n";
					}
				}
				char res = '0';
				while (true || res < '1 '|| '6' < res)
				{
					cout << endl;
					cout << "Enter choose what you want to change: 1 - title; 2 - writ.name; 3 - writ.sname; 4 - writ.country; 5 - publHouse; 6 - genre\n";
					cin >> res;
					if (('1' <= res) & (res <= '6'))break;
					else
					{
						cout << endl;
						cout << "Error!\n";
					}
				}
				edit(ptrDarr, res, n);
			}
			break;

			case '2':
			{
				cout << endl;
				cout << "List of books in the library\n";
				cout << endl;
				for (int i = 0; i < row; i++)
				{
					cout << i + 1 << "  ";
					ptrDarr[i].showBook();
					cout << endl;
				}
			}
			break;

			case '3':
			{
				cout << endl;
				char * str = new char[size] {'\0'};
				cout << "Enter sname writer:\n";
				cin.getline(str, size);
				gets_s(str, size);
				for (int i = 0; i < row; i++)
				{
					int res = ptrDarr[i].searchWriter(str);
					if (res == 1)
					{
						ptrDarr[i].showBook();
						cout << endl;
						break;
					}
					else
					{
						cout << "Not found\n";
						cout << endl;
						break;
					}
				}
			}
			break;

			case '4':
			{
				cout << endl;
				char * str = new char[size] {'\0'};
				cout << "Enter title:\n";
				cin.getline(str, size);
				gets_s(str, size);
				for (int i = 0; i < row; i++)
				{
					int res = ptrDarr[i].searchTitle(str);
					if (res == 1)
					{
						ptrDarr[i].showBook();
						cout << endl;
						break;
					}
					else
					{
						cout << "Not found\n";
						cout << endl;
						break;
					}
				}
			}
			break;

		case '5':
			{
				book * ptrDarrSort = new book[row];
				ptrDarrSort = sortTitl(ptrDarr);
				for (int i = 0; i < row; i++)
				{
					cout << i + 1 << "  ";
					ptrDarrSort[i].showBook();
					cout << endl;
				}
				delete[]ptrDarrSort;
			}
			break;

			case '6':
			{
				book * ptrDarrSort = new book[row];
				ptrDarrSort = sortSname(ptrDarr);
				for (int i = 0; i < row; i++)
				{
					cout << i + 1 << "  ";
					ptrDarrSort[i].showBook();
					cout << endl;
				}
				delete[]ptrDarrSort;
			}
			break;

			case '7':
			{
				book * ptrDarrSort = new book[row];
				ptrDarrSort = sortPublHous(ptrDarr);
				for (int i = 0; i < row; i++)
				{
					cout << i+1 << "  ";
					ptrDarrSort[i].showBook();
					cout << endl;
				}
				delete[]ptrDarrSort;
			}
			break;

			default:
				cout << "Error!Task not found\n";
				cout << endl;
				break;
			}
			system("pause");//задержка
		}//конец блока while
		delete[]ptrDarr;//вызов фн-ии удаления массив
	}
	
	cout << endl;
	cout << "Thanks for Your attention, goodbay\n";
	cout << endl;
	return 0;
}

