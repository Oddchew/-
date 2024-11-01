#include "Clinic.h"
#include <conio.h>
#include <fstream>

int static input() {
	unsigned int n;
	while (1) {
		cin >> n;
		if (!cin.fail()){
			if(n<=17) break;
		}
		cin.clear();
		cout << "������������ ���� \n";
		cin.ignore(5475785, '\n');
	}
	return n;
}

string static input_str() {
	string str;
	cin >> str;
	return str;
}

string const static path = "pharm.p";
void static add_grugs_file(string path, Pharmacy* pharm) {
	ifstream fin(path);
	if (!fin.is_open()) {
		cout << "������ ����� �� ����������";
		return;
	}
	string name;
	double price;

	while (fin >> name >> price) {
		pharm->add_drug(price,name);
	}
}

int static menu() {
	int n;
	cout << "������� ����� ����������� ��������:\n";
	cout << " 1.����� ���� ������\n";
	cout << " 2.����� ���� ���������\n";
	cout << " 3.����� ���� ���������\n";
	cout << " 4.����� ���� ���������\n";
	cout << " 5.����� ���� ������� �� �����\n";
	cout << " 6.����� ���� ��������\n";
	cout << " 7.���������� ������ ��������\n";
	cout << " 8.������ �� ����� � �����\n";
	cout << " 9.����� ��������\n";
	cout << " 10.��������������� ������ �����\n";
	cout << " 11.��������������� ����� ���������\n";
	cout << " 12.��������� ������ ��������\n";
	cout << " 13.���������� ������ ������������\n";
	cout << " 14.������ ����������\n";
	cout << " 15.������� ��������\n";
	cout << " 16.�������� ������\n";
	cout << " 17.��������� ������\n";
	n = input();
	return n;
}

int main()
{
	system("chcp 1251 > nul");
	Clinic A("����������� ������ ������ �1", "�������", "�����", 44, 3290.35, "�������", "������",58,1293);
	add_grugs_file(path, A.pharm);

	Doctor B1("���������","��������",28,2395.35,"������"), B2("��������", "���������", 38, 1855.35, "��������"), 
		B3("�������", "���������", 58, 1885.35, "���� ����� ��������"),B4("��������", "������", 45, 2025.35, "�������"), 
		B5("�������", "�����������", 27, 2045.35, "����������"), B6("�����", "�������", 42, 1815.35, "�����������");

	Nurse C1("�����", "�������", 28, 1034.4, "��������"), C2("�����", "��������", 32, 1034.4, "����������"),
		C3("���������", "��������", 29, 1034.4, "����� ��������"), C4("���������", "��������", 44, 1034.4, "������������"),
		C5("�����", "���������", 51, 1034.4, "���������"), C6("���������", "��������", 39, 1034.4, "�������������");

	Room D1("������� �������", "������������� ����"), D2("������� ���������", "��������������� ���������"),
		D3("������� ����� ����� ��������", "��������"), D4("������� ��������", "����"),
		D5("������� �����������", "����������������� ������"), D6("������� ������������", "�������-�������");

	Patient E1("��������", "������", 20, "����������"), E2("�������", "�������", 31, "���������� ������� ������� �����"),
		E3("��������", "��������", 42, "���������"), E4("���������", "����������", 24, "���������� �����"),
		E5("�������", "�����������", 51, "�����"), E6("�����", "��������", 12, "����"),
		E7("�������", "�������", 72, "��� ������"), E8("�������", "������", 88, "��������"),
		E9("������", "��������", 36, "�������"), E10("��������", "����������", 16, "������");

	A.add_doctor(&B1);
	A.add_doctor(&B2);
	A.add_doctor(&B3);
	A.add_doctor(&B4);
	A.add_doctor(&B5);
	A.add_doctor(&B6);

	A.add_nurse(&C1);
	A.add_nurse(&C2);
	A.add_nurse(&C3);
	A.add_nurse(&C4);
	A.add_nurse(&C5);
	A.add_nurse(&C6);

	D1.add_working_doc(&B1);
	D1.add_nurse(&C1);
	D2.add_working_doc(&B2);
	D2.add_nurse(&C2);
	D3.add_working_doc(&B3);
	D3.add_nurse(&C3);
	D4.add_working_doc(&B4);
	D4.add_nurse(&C5);
	D5.add_working_doc(&B5);
	D5.add_nurse(&C4);
	D6.add_working_doc(&B6);
	D6.add_nurse(&C6);

	A.add_room(&D1);
	A.add_room(&D2);
	A.add_room(&D3);
	A.add_room(&D4);
	A.add_room(&D5);
	A.add_room(&D6);

	B1.add_patient(&E1, &A);
	B1.add_patient(&E2, &A);
	B2.add_patient(&E3, &A);
	B2.add_patient(&E4, &A);
	B3.add_patient(&E5, &A);
	B3.add_patient(&E6, &A);
	B4.add_patient(&E7, &A);
	B4.add_patient(&E8, &A);
	B5.add_patient(&E9, &A);
	B5.add_patient(&E10, &A);

	//A.patient_dead("�������", "�������");
	int n = 0;
	while (n != 17) {
		n = menu();
		string name, surname, disease, test_name, specialization,equipment,type_vaccine, procedure;
		double salary;
		int age, number;
		Patient* pat;
		Doctor* doc;
		Nurse* nur;
		Room* office;
		Appointment* app;
		DateTime* date_and_time;
		LabTest* test;
		switch (n) {
		case 1:
			system("cls");
			A.show_all_doctors();
			break;
		case 2:
			system("cls");
			A.show_all_nurses();
			break;
		case 3:
			system("cls");
			A.show_all_patients();
			break;
		case 4:
			system("cls");
			A.show_all_rooms();
			break;
		case 5:
			system("cls");
			A.show_all_appointments();
			break;
		case 6:
			system("cls");
			A.show_all_prescriptions();
			break;
		case 7:
			system("cls");
			cout << "������� ��� ��������" << endl;
			cin >> name;
			cout << "������� ������� ��������" << endl;
			cin >> surname;
			cout << "������� ������� ��������" << endl;
			cin >> age;
			cout << "������� ������� ��������" << endl;
			cin.clear();
			cin.ignore();
			getline(cin, disease);
			pat = new Patient(name, surname, age, disease);
			system("cls");
			A.show_all_doctors();
			do {
				cout << "������� ��� �����, ������� ����� ������ ��������" << endl;
				cin >> name;
				cout << "������� ������� �����, ������� ����� ������ ��������" << endl;
				cin >> surname;
				doc = A.get_doctor(name, surname);
			} while (doc == nullptr);
			doc->add_patient(pat, &A);
			break;
		case 8:
			system("cls");
			A.show_all_patients();
			do {
				cout << "������� ��� ��������" << endl;
				cin >> name;
				cout << "������� ������� ��������" << endl;
				cin >> surname;
				pat = A.get_patient(name, surname);
			} while (pat == nullptr);
			system("cls");
			A.show_all_doctors();
			do {
				cout << "������� ��� �����, ������� ����� ������ ��������" << endl;
				cin >> name;
				cout << "������� ������� �����, ������� ����� ������ ��������" << endl;
				cin >> surname;
				doc = A.get_doctor(name, surname);
			} while (doc == nullptr);
			system("cls");
			A.show_all_rooms();
			do {
				cout << "������� �������� ��������" << endl;
				getline(cin, name);
				office = A.get_room(name);
			} while (office == nullptr);
			system("cls");
			date_and_time = new DateTime();
			cin.clear();
			date_and_time->set_date_time();
			app = new Appointment(doc, pat, office,date_and_time);
			A.appointments.push_back(app);
			break;
		case 9:
			system("cls");
			A.show_all_patients();
			cout << "������� ����� ������� �������" << endl;
			do {
				cout << "������� ��� ��������" << endl;
				cin >> name;
				cout << "������� ������� ��������" << endl;
				cin >> surname;
				pat = A.get_patient(name, surname);
			} while (pat == nullptr);
			cout << "������� ����������, ������� ����� �����������" << endl;
			cin.clear();
			cin.ignore();
			getline(cin, test_name);

			date_and_time = new DateTime();
			date_and_time->set_date_time();
			test = new LabTest(test_name, date_and_time);
			pat->tests.push_back(test);
			break;
		case 10:
			system("cls");
			cout << "������� ��� �����" << endl;
			cin >> name;
			cout << "������� ������� �����" << endl;
			cin >> surname;
			cout << "������� ������� �����" << endl;
			cin >> age;
			cout << "������� ������������� �����" << endl;
			getline(cin, disease);
			cout << "������� �������� �����" << endl;
			cin >> salary;
			doc = new Doctor(name, surname, age, salary,specialization);
			A.add_doctor(doc);

			A.show_all_rooms();
			cout << "� ����� �������� ������ ����� ��������?" << endl;
			do {
				cout << "������� �������� ��������" << endl;
				getline(cin, name);
				office = A.get_room(name);
			} while (office == nullptr);
			office->add_working_doc(doc);
			break;
		case 11:
			system("cls");
			cout << "������� ��� ���������" << endl;
			cin >> name;
			cout << "������� ������� ���������" << endl;
			cin >> surname;
			cout << "������� ������� ���������" << endl;
			cin >> age;
			cout << "������� ������������� ���������" << endl;
			getline(cin, disease);
			cout << "������� �������� ���������" << endl;
			cin >> salary;
			nur = new Nurse(name, surname, age, salary, specialization);
			A.add_nurse(nur);

			A.show_all_rooms();
			cout << "� ����� �������� ��������� ����� ��������?" << endl;
			do {
				cout << "������� �������� ��������" << endl;
				getline(cin, name);
				office = A.get_room(name);
			} while (office == nullptr);
			office->add_nurse(nur);
			break;
		case 12:
			system("cls");
			cout << "������� ����� ������������� ����� ���� �������" << endl;
			getline(cin, specialization);
			cout << "������� ������������ ������������" << endl;
			getline(cin, equipment);
			office = new Room(specialization,equipment);
			A.add_room(office);
			break;
		case 13:
			system("cls");
			A.show_all_rooms();
			cout << "������� � ����� ������� �� ������ �������� ������������" << endl;
			cin.clear();
			cin.ignore();
			do {
				getline(cin, specialization);
				office = A.get_room(specialization);
			} while (office == nullptr);
			cout << "������� �������� ������������" << endl;
			getline(cin, equipment);
			office->add_equipment(equipment);
			break;
		case 14:
			system("cls");
			A.show_all_patients();
			cout << "���� ����� �������������?\n";
			do {
				cout << "������� ��� ��������" << endl;
				cin >> name;
				cout << "������� ������� ��������" << endl;
				cin >> surname;
				pat = A.get_patient(name, surname);
			} while (pat == nullptr);

			system("cls");
			A.show_all_doctors();
			do {
				cout << "������� ��� �����, ������� ����� ������������� ��������" << endl;
				cin >> name;
				cout << "������� ������� �����, ������� ����� ������������� ��������" << endl;
				cin >> surname;
				doc = A.get_doctor(name, surname);
			} while (doc == nullptr);

			date_and_time = new DateTime();
			date_and_time->set_date_time();

			cout << "������� ������� �� ������� �������� �������\n" << endl;
			cin.clear();
			cin.ignore();
			getline(cin, type_vaccine);

			pat->vaccin = new Vaccination(type_vaccine, date_and_time, doc);
			pat->vaccin->info();
			break;
		case 15:
			system("cls");

			A.show_all_patients();
			cout << "���� ����� ������?\n";
			do {
				cout << "������� ��� ��������" << endl;
				cin >> name;
				cout << "������� ������� ��������" << endl;
				cin >> surname;
				pat = A.get_patient(name, surname);
			} while (pat == nullptr);

			cout << "��� �������� ���������� ��������� ��� ������?\n" << endl;
			cin.clear();
			cin.ignore();
			getline(cin, procedure);
			cout << "������� ���������� ����������" << endl;
			cin >> number;
			pat->add_treat(procedure, number);
			pat->treat->info();
			break;
		case 16:
			system("cls");

			A.show_all_patients();
			cout << "���� �������� ������?\n";
			do {
				cout << "������� ��� ��������" << endl;
				cin >> name;
				cout << "������� ������� ��������" << endl;
				cin >> surname;
				pat = A.get_patient(name, surname);
			} while (pat == nullptr);

			system("cls");
			A.show_all_doctors();
			do {
				cout << "������� ��� �����, ������� ���������� ������" << endl;
				cin >> name;
				cout << "������� ������� �����, ������� ���������� ������" << endl;
				cin >> surname;
				doc = A.get_doctor(name, surname);
			} while (doc == nullptr);
			
			cout << "����� ��������� �������� ����� ���������" << endl;
			cin.clear();
			cin.ignore();
			getline(cin, name);
			Prescription* prescr = new Prescription();
			prescr->add_prescription(doc, pat, name);
			A.prescriptions.push_back(prescr);
			break;
		}
		A.kill();
		cout << "��� ����������� ������� ����� �������\n";
		_getch();
		system("cls");
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////   ������ ������ OpenCppCoverage --source PPOIS2 -- .\x64\Debug\Test_PPOIS2.exe   ///////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////