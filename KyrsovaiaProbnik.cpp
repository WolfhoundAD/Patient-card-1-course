
//#include <iostream>
//#include <iomanip>
//#include <Windows.h>
//#include <string>
#include "list1.h"



//функции
void menu();
void vvod(list* l);
void vivod(list* l);
void search(list* l);
void del(list* l);
void edit(list* l);
void vihod(list* l);

//указатель на функцию
typedef void (*pf)(list*);
//массив для привязки функций к меню
pf menu_list[] = { &vvod, &vivod, &search, &del, &edit, &vihod };



//функция меню
void menu()
{
	cout << "\n МЕНЮ \n";
	cout << "1.Ввод данных " << endl;
	cout << "2.Вывод данных " << endl;
	cout << "3.Поиск" << endl;
	cout << "4.Удаление " << endl;
	cout << "5.Редактирование " << endl;
	cout << "6.Выход " << endl;
	cout << "Введите номер пункта меню для дальнейшей работы" << endl;
}

//функция ввода данных
void vvod(list* l)
{
	int n;
	int num;

	char name[20];
	char name1[20];
	char name2[20];
	char addres[20];
	char diagnos[20];
	char namedoc[20];

	cout << "Введите количество добавляемых записей в список = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите номер мед. карты ";
		cin >> num;

		cout << "Введите фамилию пациента  ";
		while (cin.get() != '\n');
		cin.getline(name, 20);

		cout << "Введите имя пациента  ";
		cin.getline(name1, 20);

		cout << "Введите отчество пациента  ";
		cin.getline(name2, 20);

		cout << "Введите адрес пациента  ";
		cin.getline(addres, 20);

		cout << "Введите диагноз пациента  ";
		cin.getline(diagnos, 20);

		cout << "Введите фамилия лечащего врача  ";
		cin.getline(namedoc, 20);

		l->add_sort(num, name, name1, name2, addres, diagnos, namedoc);
	}
}

//функция вывода данных
void vivod(list* l)
{
	if (!l->is_empty())
		l->show();
	else
		cout << endl << "Список пуст" << endl;
}
//функция реализации поиска
void search(list* l)
{
	if (!l->is_empty())
	{
		int k_poisk;
		cout << "Выберите критерий поиска" << endl;
		cout << "1. Поиск по номеру мед. карты" << endl;
		cout << "2. Поиск по фамилии " << endl;
		cout << "3. Поиск по имени" << endl;
		cout << "4. Поиск по отчеству" << endl;
		cout << "5. Поиск по адресу" << endl;
		cout << "6. Поиск по диагнозу" << endl;
		cout << "7. Поиск по фамилии лечащего врача" << endl;
		cout << "Введите номер критерия" << endl;
		cin >> k_poisk;

		switch (k_poisk)
		{
		case 1:
		{
			int i_num;
			cout << endl << "Введите номер мед. карты" << endl;
			cin >> i_num;
			if (list::item* pv = l->find(i_num))
			{
				cout << endl << "Результат поиска:" << endl;
				cout << "Номер мед. карты:" << pv->get_item_num() << endl;
				cout << "Фамилия пациента:" << pv->get_item_name() << endl;
				cout << "Имя пациента:" << pv->get_item_name1() << endl;
				cout << "Отчество пациента:" << pv->get_item_name2() << endl;
				cout << "Адрес пацента:" << pv->get_item_address() << endl;
				cout << "Диагноз:" << pv->get_item_diagnosis() << endl;
				cout << "Фамилия лечащего врача:" << pv->get_item_namedoctor() << endl;
			}
			else
				cout << "Мед. карта с таким номером не найдена" << endl;
		}
		break;
		case 2:
		{
			string i_name;
			cout << endl << "Введите фамилию пациента" << endl;
			while (cin.get() != '\n');
			getline(cin, i_name);
			cout << endl << "Результат поиска:" << endl;
			if (!l->find_data("item_name", i_name))
				cout << "Такой фамилии не найдено" << endl;
		}
		break;
		case 3:
		{
			string i_name1;
			cout << endl << "Введите имя пациента" << endl;
			while (cin.get() != '\n');
			getline(cin, i_name1);
			cout << endl << "Результат поиска:" << endl;
			if (!l->find_data("item_name", i_name1))
				cout << "Такого имени не найдено" << endl;
		}
		break;


		case 4:
		{
			string i_name2;
			cout << endl << "Введите отчество пациента" << endl;
			while (cin.get() != '\n');
			getline(cin, i_name2);
			cout << endl << "Результат поиска:" << endl;
			if (!l->find_data("item_name", i_name2))
				cout << "Такое отчества не найдено" << endl;
		}
		break;


		case 5:
		{
			string i_adress;
			cout << endl << "Введите адрес пациента" << endl;
			while (cin.get() != '\n');
			getline(cin, i_adress);
			cout << endl << "Результат поиска:" << endl;
			if (!l->find_data("item_name", i_adress))
				cout << "Такого адреса не найдено" << endl;
		}
		break;

		case 6:
		{
			string i_diagnosis;
			cout << endl << "Введите диагноз пациента:" << endl;
			while (cin.get() != '\n');
			getline(cin, i_diagnosis);
			cout << endl << "Результат поиска" << endl;
			if (!l->find_data("item_name", i_diagnosis))
				cout << "Такого диагноза не найдено" << endl;
		}
		break;

		case 7:
		{
			string i_namedoctor;
			cout << endl << "Введите фамилии лечащего врача " << endl;
			while (cin.get() != '\n');
			getline(cin, i_namedoctor);
			cout << endl << "Результат поиска:" << endl;
			if (!l->find_data("item_name", i_namedoctor))
				cout << "Такого врача не найдено" << endl;
		}
		break;


		default:
			cout << "Неверный вариант выбора" << endl;
		}
	}
	else
		cout << endl << "Список пуст" << endl;
}
//функция удаления
void del(list* l)
{
	if (!l->is_empty())
	{
		int i_num;
		cout << "Введите номер мед. карты для удаления" << endl;
		cin >> i_num;
		if (l->remove(i_num))
			cout << endl << "Элемент удален" << endl;
		else
			cout << endl << "Мед. карта с таким номером не найдена" << endl;
	}
	else
		cout << endl << "Список пуст" << endl;
}

//функция реализации выхода
void vihod(list* l)
{
	l->~list();
}
//функция реализации редактирования

void edit(list* l)
{
	int item_num;
	string item_name;
	string item_name1;
	string item_name2;
	string item_address;
	string item_diagnosis;
	string item_namedoctor;

	cout << "Введите номер мед карты для поиска" << endl;

	cin >> item_num;
	list::item* ind = l->find(item_num);
	if (ind)
	{
		cout << endl << "Даные найдены" << endl;
		cout << setw(5) << ind->get_item_num() << setw(10) << ind->get_item_name() << setw(10) << ind->get_item_name1() << setw(10) << ind->get_item_name2()
			<< setw(10) << ind->get_item_address() << setw(10) << ind->get_item_diagnosis() << setw(10) << ind->get_item_namedoctor() << endl;

		cout << endl << "Введите новый номер мед карты или 0,если хотите оставить старый " << endl;
		cin >> item_num;
		if (item_num != 0)
			ind->set_item_num(item_num);

		cout << endl << "Введите новую фамилию или 0,если хотите оставить старую " << endl;
		while (cin.get() != '\n');
		getline(cin, item_name);
		if (item_name != "0")
			ind->set_item_name(item_name);

		cout << endl << "Введите новое имя или 0,если хотите оставить старое " << endl;
		getline(cin, item_name1);
		if (item_name1 != "0")
			ind->set_item_name1(item_name1);

		cout << endl << "Введите новое отчество или 0,если хотите оставить старое " << endl;
		getline(cin, item_name2);
		if (item_name2 != "0")
			ind->set_item_name2(item_name2);

		cout << endl << "Введите новый адрес или 0,если хотите оставить старый " << endl;
		getline(cin, item_address);
		if (item_address != "0")
			ind->set_item_address(item_address);

		cout << endl << "Введите новый диагноз или 0,если хотите оставить старый " << endl;
		getline(cin, item_diagnosis);
		if (item_diagnosis != "0")
			ind->set_item_diagnosis(item_diagnosis);

		cout << endl << "Введите новую фамилию врача или 0,если хотите оставить старую " << endl;
		getline(cin, item_namedoctor);
		if (item_namedoctor != "0")
			ind->set_item_namedoctor(item_namedoctor);

		cout << endl << "Измения сохранены " << endl;
	}
	else
		cout << "Данные для редактирования не найдены проверьте правльность введенных данных " << endl;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list l;
	int num = 0;
	while (num != 6)
	{
		menu();
		cin >> num;
		if (num < 1 || num > 6)
			cout << "Неверный вариант выбора" << endl;
		else
			menu_list[num - 1](&l);
	}
	return 0;
}
