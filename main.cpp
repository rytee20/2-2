#include "Header.h"

void menu(int *command) 
{

	cout << "===============МЕНЮ===============" << endl;

	cout << "Доступные действия:" << endl;

	cout << "\t" << "1) Поиск письма по отправителю" << endl;
	cout << "\t" << "2) Фильтр по индексу" << endl;
	cout << "\t" << "3) Сортировать по увеличению стоимости" << endl;
	cout << "\t" << "4) Печать базы" << endl;
	cout << "\t" << "5) Добавить данные" << endl;
	cout << "\t" << "6) Завершение программы" << endl;

	cout << "==============================" << endl;

	cout << "Введите цифру от 1 до 6: " << endl;

	cout << "==============================" << endl << endl;

	cin >> *(command);

}


int letter::count = 0;

int main() 
{
	setlocale(LC_ALL, "Russian");
	
	letter_box element;

	readBase(element, letter::count);

	int command;

	do
	{

		menu(&command);
		switch (command) 
		{

		case 1:
			SearchLetterBySender(element.letterBase, letter::count);
			break;

		case 2:
			FilterByIndex(element.letterBase, letter::count);
			break;

		case 3:
			SortByCostIncreasing(element.letterBase, letter::count);
			saveBase(element.letterBase, letter::count);

		case 4: 
			printBase(element.letterBase, letter::count);
			break;

		case 5:
			element.addElement();
			saveBase(element.letterBase, letter::count);
			break;

		case 6:
			break;

		default:
			cout << "Неверно введен номер действия";
			system("pause");
			break;

		}

	} while (command != 6);

	return 0;

}
