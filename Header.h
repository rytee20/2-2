#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <locale>

using namespace std;

class man {

private:

	char* adr; //адрес
	char* name; //имя

public:

	man() {
		adr = new char[4];
		strcpy(adr, "adr");
		name = new char[5];
		strcpy(name, "name");
	}

	//~man() {
	//	cout << "";
	//}

	void setAdr(char* new_adr)
	{
		adr = new char[15];
		adr = new_adr;
	};

	void setName(char* new_name)
	{
		name = new char[15];
		name = new_name;
	};

	char* GetAdr() { return adr; };
	char* GetName() { return name; };
};

class letter{

private:

	double cost;		// стоимость письма

public:

	man man_class1; //получателя
	man man_class2; // отправителя
	static int count; 

	int ind1;		    // индекс получателя

	double GetCost() { return cost; };

	void setInd(int new_ind) {
		ind1 = new_ind;
	} 
	void setCost(double new_cost) {
		cost = new_cost;
	}

	letter()
	{
		ind1 = 0;
		cost = 0.0;
		count++;
	}

	/*~letter()
	{
		cout << "Память отчистилась" << endl;
	}*/

	friend void SearchLetterBySender(letter* Obj, int fcount);
	friend void FilterByIndex(letter* Obj, int fcount);
	friend void SortByCostIncreasing(letter* Obj, int fcount);

	friend void saveBase(letter* Obj, int fcount);
	friend void createBase(letter* Obj, int fcount);
	friend void printBase(letter* Obj, int fcount);
	friend void readBase(letter*& Obj, int fcount);

};

class letter_box 
{
public:

	letter* letterBase;
	man* manBase;

	letter_box()
	{

		letterBase = new letter[0];

	}

	void addElement() {

		letter* tmp;
		tmp = (letter*)realloc(letterBase, (letter::count + 1) * sizeof(letter));
		if (tmp != nullptr) {
			letterBase = tmp;
			createBase(letterBase, letter::count);
			letter::count++;
		}
		else {
			cout << "не получилос";
		}

	}

};
