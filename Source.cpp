#include "Header.h"

//////CONTROL///////

int controlInd() //КОНТРОЛЬ ИНДЕКСА
{

	cout << "Введите индекс получателя (индекс должен состоять из шести цифр): " << endl;
	while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

		int checkind;
		cin >> checkind;

		if (cin.fail() or (checkind <= 99999) or (checkind > 999999)) // если предыдущее извлечение оказалось неудачным,
		{

			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера

		}
		else // если всё хорошо, то возвращаем checkind
			return checkind;

	}

}


int controlConsent() //КОНТРОЛЬ СОГЛАСИЯ
{

	cout << "Введите 1 если да, и 0, если нет: " << endl;

	while (true) {

		int checkconsent;
		cin >> checkconsent;

		if (cin.fail() or ((checkconsent != 0) and (checkconsent != 1))) {
			cin.clear();
			cin.ignore(32767, '\n');

		}

		else
			return checkconsent;

	}

}


int controlCount() //КОНТРОЛЬ ПРОСТО ЧИСЕЛ
{

	while (true) 
	{

		int checkcount;
		cin >> checkcount;

		if (cin.fail() or (checkcount <= 0)) {

			cin.clear();
			cin.ignore(32767, '\n');

		}

		else
			return checkcount;

	}

}


double controlCost() //КОНТРОЛЬ ЦЕНЫ
{

	cout << "Введите цену письма(если число - десятичная дробь, следует отделить дробную часть запятой): " << endl;

	while (true) 
	{

		double checkcost;
		cin >> checkcost;

		if (cin.fail() or (checkcost <= 0.0)) 
		{

			cin.clear();
			cin.ignore(32767, '\n');
		}

		else
			return checkcost;

	}

}


char* controlChar() //КОНТОРЛЬ ЧАР
{

	int i;
	char* str;
	str = new char[15];
	char* Obj = new char[15];

	do 
	{

		cin >> str;

		for (i = 0; str[i]; i++)
			if ((str[i] >= '0' and str[i] <= '9' and str[i]) or (str[i] <= '/' and str[i] >= '!') or (str[i] <= '@' and str[i] >= ':') or (str[i] <= '`' and str[i] >= '[') or (str[i] <= '~' and str[i] >= '{'))
				break;

		if (str[i])
			cout << "Введены не буквы(" << endl << "Повторите ввод" << endl;

	} while (str[i]);

	for (i = 0; str[i]; i++) 
	{

		Obj[i] += str[i];

	}

	return Obj;

}


//////WORK WITH BASE//////

void printBase(letter* Obj, int fcount)
{

	int fnumber = 0;

	while (fnumber < fcount)
	{

		cout << Obj[fnumber].ind1 << " " << Obj[fnumber].man_class1.GetAdr() << " " << Obj[fnumber].man_class1.GetName() << " " << Obj[fnumber].man_class2.GetAdr() << " " << Obj[fnumber].man_class2.GetName() << " " << Obj[fnumber].GetCost() << endl;
		fnumber++;

	}

}


void saveBase(letter* Obj, int fcount) //СОХРАНИТЬ БАЗУ В ФАЙЛ
{

	ofstream fout ("Base.txt", ios::app);
	int fnumber = 0;

	while (fnumber < fcount)
	{

		fout << " " << Obj[fnumber].ind1 << " " << Obj[fnumber].man_class1.GetAdr() << " " << Obj[fnumber].man_class1.GetName() << " " << Obj[fnumber].man_class2.GetAdr() << " " << Obj[fnumber].man_class2.GetName() << " " << Obj[fnumber].GetCost() << endl;
		fnumber++;

	}

	fout.close();

}


void createBase(letter* Obj,int fcount) //СОЗДАТЬ БАЗУ
{

		Obj[fcount].setInd(controlInd());

		Obj[fcount].setCost(controlCost());

		// for man

		cout << "ведите адрес получателя(ГородУлица; БЕЗ ПРОБЕЛОВ)" << endl;
		Obj[fcount].man_class1.setAdr(controlChar());

		cout << "Введите имя получателя(ИмяФамилия; БЕЗ ПРОБЕЛОВ):" << endl;
		Obj[fcount].man_class1.setName(controlChar());

		cout << "ведите адрес отправителя(ГородУлица; БЕЗ ПРОБЕЛОВ):" << endl;
		Obj[fcount].man_class2.setAdr(controlChar());

		cout << "Введите имя отправителя(ИмяФамилия; БЕЗ ПРОБЕЛОВ):" << endl;
		Obj[fcount].man_class2.setName(controlChar());

		cout << endl;

}

void readBase(letter*& Obj, int fcount) //СЧИТАТЬ БАЗУ С ФАЙЛА
{

	ifstream fin;
	int count1 = 0;
	fin.open("Base.txt");
	char* str = new char[1024];
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(str, 1024,'\n');
			count1++;
		}
		delete[] str;
	}
	fcount = count1 - 1;
	cout << "ok";
	if (fin)
	{
		Obj = new letter[fcount];
		for (int i = 0; i < fcount; i++) {
			char* adr1, * adr2, * name1, * name2;
			double cost;
			fin >> Obj[i].ind1 >> adr1 >> name1 >> adr2 >> name2 >> cost;
			Obj[i].man_class1.setAdr(adr1);
			Obj[i].man_class1.setName(name1);
			Obj[i].man_class1.setAdr(adr2);
			Obj[i].man_class1.setName(name2);
			Obj[i].setCost(cost);
		}
	}

	fin.close();

	letter::count = fcount;

	/*string s;

	while (fin.peek() != EOF) {
		getline(fin, s);
		count1++;
	}

	if (count1 == 0)
	{

		cout << "Файл пуст";

	}

	else
	{

		cout << "smth";*/

		/*char buff[50];

		while (number < fcount)
		{

			fin >> buff;
			letterBase[number].ind1 = atoi(buff);
			fin >> buff;
			letterBase[number].GetAdr1() = new char[strlen(buff) + 1];
			strcpy(letterBase[number].GetAdr1(), buff);
			fin >> buff;
			letterBase[number].GetName1() = new char[strlen(buff) + 1];
			strcpy(letterBase[number].GetName1(), buff);
			fin >> buff;
			letterBase[number].GetAdr2() = new char[strlen(buff) + 1];
			strcpy(letterBase[number].GetAdr2(), buff);
			fin >> buff;
			letterBase[number].GetName2() = new char[strlen(buff) + 1];
			strcpy(letterBase[number].GetName2(), buff);
			fin >> buff;
			letterBase[number].GetCost() = atof(buff);
			number++;

		}*/
	//}

	fin.close();

}

/*void deleteBase()
{

	ofstream fout;
	int consent;

	cout << "Удалить существующую базу? Если да, то в этом случае ее невозможно будет восстановить (1 - да, 0 - нет)" << endl;
	consent = controlConsent();
	if (consent == 1) {
		fout.open("Base.txt", ofstream::out | ofstream::trunc);
		fout.close();
		cout << "База успешно удалена" << endl;
	}
	else
		cout << "Удаление отменено" << endl;

}*/


//////FUNCTIONS//////


void SearchLetterBySender(letter* Obj, int fcount) //ПОИСК ПИСЬМА ПО ОТПРАВИТЕЛЮ
{

	char* foundname2;
	int count1 = 0;
	cout << "Введите имя отправителя(ИмяФамилия; БЕЗ ПРОБЕЛОВ): " << endl;
	foundname2 = controlChar();
	int fnumber = 0;

	while (fnumber < fcount)
	{

		if (Obj[fnumber].man_class2.GetName() == foundname2)
		{

			count1++;
			cout << " " << Obj[fnumber].ind1 << " " << Obj[fnumber].man_class1.GetAdr() << " " << Obj[fnumber].man_class1.GetName() << " " << Obj[fnumber].man_class2.GetAdr() << " " << Obj[fnumber].man_class2.GetName() << " " << Obj[fnumber].GetCost() << endl;
		
		}

		fnumber++;

	}

	if (count1 == 0) 
	{

		cout << "Не найдено писем, отправленных этим человеком" << endl;

	}

}


void FilterByIndex(letter* Obj,int fcount) //ФИЛЬТР ПО НДЕКСУ
{

	int foundind;
	int count1 = 0;
	foundind = controlInd();
	int fnumber = 0;
	while (fnumber < fcount)
	{

		if (Obj[fnumber].ind1 == foundind) 
		{

			count1++;
			cout << " " << Obj[fnumber].ind1 << " " << Obj[fnumber].man_class1.GetAdr() << " " << Obj[fnumber].man_class1.GetName() << " " << Obj[fnumber].man_class2.GetAdr() << " " << Obj[fnumber].man_class2.GetName() << " " << Obj[fnumber].GetCost() << endl;
		
		}

		fnumber++;

	}

	if (count1 == 0) 
	{

		cout << "Не найдено писем с данным индексом" << endl;

	}

}


void SortByCostIncreasing(letter* Obj,int fcount) //СОРТИРОВКА
{

	for (int j = 0; j < fcount - 1; j++)
	{

		for (int l = j + 1; l < fcount; l++)

			if (Obj[j].GetCost() < Obj[l].GetCost())
			{

				swap(Obj[j], Obj[l]);

			}

	}

}
