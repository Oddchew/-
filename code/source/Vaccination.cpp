#include "pch.h"
#include "Vaccination.h"

void Vaccination::info() {
	cout << "������ ����������� ����������:" << endl;
	doctor->info();
	cout << "��� �������:" << endl;
	cout << type << endl;
	time->date();
	time->time();
}