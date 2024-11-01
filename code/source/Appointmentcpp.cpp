#include "pch.h"
#include "Appointment.h"

Appointment::Appointment(Doctor* doc, Patient* pat, Room* off, DateTime* date_time) {
	doctor = doc;
	patient = pat;
	office = off;
	srand(date_time->year * date_time->month - date_time->day + date_time->hour * date_time->minute);
	time_of_app = date_time;
	status = true;
	indf = (rand() + 11111) % 100000;
	doc->add_patient(pat);
}

void Appointment::cancel() { status = false; }

void Appointment::info() {
	if (status){ 
		cout << "������ �: " << indf << endl;
		cout << "����:" << endl;
		doctor->info();
		cout << "�������:" << endl;
		patient->info();
		cout << "� ��������:" << endl;
		office->info();
		time_of_app->date();
		time_of_app->time();
	}
	else {
		cout << "����� ������" << indf << endl;
		cout << "������ �������";
	}
}