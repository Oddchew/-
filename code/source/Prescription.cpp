#include "pch.h"
#include "Prescription.h"

void Prescription::add_prescription(Doctor* doc, Patient* patient1, string name_of_medicament) {
	doctor = doc;
	patient = patient1;
	name_of_med = name_of_medicament;
}

void Prescription::show() {
	cout << "����, ���������� ������";
	doctor->info();
	cout << endl;
	cout << "�������";
	patient->info();
	cout << endl;
	cout << "�������� ���������: " << name_of_med << endl;
}