#include "pch.h"
#include "Person.h"

void Person::info(){
	cout << "��� :" << name << endl;
	cout << "�������: " << surname << endl;
	cout << "�������: " << age << endl;
}

string Person::get_name() {
	return name;
}

string Person::get_surname() {
	return surname;
}