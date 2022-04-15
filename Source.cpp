#include "Header.h"

//////CONTROL///////

int controlInd() //�������� �������
{

	cout << "������� ������ ���������� (������ ������ �������� �� ����� ����): " << endl;
	while (true) { // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������

		int checkind;
		cin >> checkind;

		if (cin.fail() or (checkind <= 99999) or (checkind > 999999)) // ���� ���������� ���������� ��������� ���������,
		{

			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������

		}
		else // ���� �� ������, �� ���������� checkind
			return checkind;

	}

}


int controlConsent() //�������� ��������
{

	cout << "������� 1 ���� ��, � 0, ���� ���: " << endl;

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


int controlCount() //�������� ������ �����
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


double controlCost() //�������� ����
{

	cout << "������� ���� ������(���� ����� - ���������� �����, ������� �������� ������� ����� �������): " << endl;

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


char* controlChar() //�������� ���
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
			cout << "������� �� �����(" << endl << "��������� ����" << endl;

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


void saveBase(letter* Obj, int fcount) //��������� ���� � ����
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


void createBase(letter* Obj,int fcount) //������� ����
{

		Obj[fcount].setInd(controlInd());

		Obj[fcount].setCost(controlCost());

		// for man

		cout << "������ ����� ����������(����������; ��� ��������)" << endl;
		Obj[fcount].man_class1.setAdr(controlChar());

		cout << "������� ��� ����������(����������; ��� ��������):" << endl;
		Obj[fcount].man_class1.setName(controlChar());

		cout << "������ ����� �����������(����������; ��� ��������):" << endl;
		Obj[fcount].man_class2.setAdr(controlChar());

		cout << "������� ��� �����������(����������; ��� ��������):" << endl;
		Obj[fcount].man_class2.setName(controlChar());

		cout << endl;

}

void readBase(letter*& Obj, int fcount) //������� ���� � �����
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

		cout << "���� ����";

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

	cout << "������� ������������ ����? ���� ��, �� � ���� ������ �� ���������� ����� ������������ (1 - ��, 0 - ���)" << endl;
	consent = controlConsent();
	if (consent == 1) {
		fout.open("Base.txt", ofstream::out | ofstream::trunc);
		fout.close();
		cout << "���� ������� �������" << endl;
	}
	else
		cout << "�������� ��������" << endl;

}*/


//////FUNCTIONS//////


void SearchLetterBySender(letter* Obj, int fcount) //����� ������ �� �����������
{

	char* foundname2;
	int count1 = 0;
	cout << "������� ��� �����������(����������; ��� ��������): " << endl;
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

		cout << "�� ������� �����, ������������ ���� ���������" << endl;

	}

}


void FilterByIndex(letter* Obj,int fcount) //������ �� ������
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

		cout << "�� ������� ����� � ������ ��������" << endl;

	}

}


void SortByCostIncreasing(letter* Obj,int fcount) //����������
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