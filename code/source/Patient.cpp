#include "pch.h"
#include "Patient.h"
#include "Doctor.h"

void Patient::info() {
	cout << "��� :" << name << endl;
	cout << "�������: " << surname << endl;
	cout << "�������: " << age << endl;
	cout << "�����������: " << disease << endl;
}

string Patient::get_name() const {
	return name;
}

string Patient::get_surname() const {
	return surname;
}

string Patient::get_disaese() const {
	return disease;
}

void Patient::add_doctor(Doctor* doctor) {
	doctors.push_back(doctor);
}

void Patient::show_doctors() {
	for (auto doc : doctors) {
		doc->info();
	}
}

void Patient::add_treat(string procedure, int number)
{
	treat = new Treatment(procedure, number);
}