#include "pch.h"
#include "Clinic.h"
#include <fstream>

Clinic A("����������� ������ ������ �1", "�������", "�����", 44, 3290.35, "�������", "������", 58, 1293);
string path = "C:/�������/�����/���� 2/�����/����� 2/����� 2/pharm.p";
ifstream fin(path);

string name;
double price;

TEST(PharmacyTest, DrugsInfo) {
	while (fin >> name >> price) {
		A.pharm->add_drug(price, name);
	}
	while (fin >> name >> price) {
		double price_ = A.pharm->get_drug(name);
		EXPECT_EQ(price, price_);
	}
	system("chcp 1251>nul");
	EXPECT_NO_THROW(A.pharm->info());
}

Doctor B1("���������", "��������", 28, 2395.35, "������"), B2("��������", "���������", 38, 1855.35, "��������");

Nurse C1("�����", "�������", 28, 1034.4, "��������"), C2("�����", "��������", 32, 1034.4, "����������");

Room D1("������� �������", "������������� ����"), D2("������� ���������", "��������������� ���������");

Patient E1("��������", "������", 20, "����������"), E2("�������", "�������", 31, "���������� ������� ������� �����");


TEST(DoctorTest, NameSurname_return) {
	A.add_doctor(&B1);
	A.add_doctor(&B2);

    EXPECT_EQ(B1.get_name(), "���������");
	EXPECT_EQ(B2.get_name(), "��������");

	EXPECT_EQ(B1.get_surname(), "��������");
	EXPECT_EQ(B2.get_surname(), "���������");

	EXPECT_EQ(A.get_doctor("���������", "��������"), &B1);
	EXPECT_EQ(A.get_doctor("��������", "���������"), &B2);
}

TEST(NurseTest, NameSurname_return) {
	A.add_nurse(&C1);
	A.add_nurse(&C2);

	EXPECT_EQ(C1.get_name(), "�����");
	EXPECT_EQ(C2.get_name(), "�����");

	EXPECT_EQ(C1.get_surname(), "�������");
	EXPECT_EQ(C2.get_surname(), "��������");
}

TEST(RoomTest, Specialization_return) {
	A.add_room(&D1);
	A.add_room(&D2);

	EXPECT_EQ(D1.get_specialization(), "������� �������");
	EXPECT_EQ(D2.get_specialization(), "������� ���������");

	EXPECT_EQ(A.get_room("������� �������"), &D1);
	EXPECT_EQ(A.get_room("������� ���������"), &D2);
}

TEST(PatientTest, NameSurnameDisease_return) {
	A.add_patient(&E1);
	A.add_patient(&E2);

	EXPECT_EQ(E1.get_name(), "��������");
	EXPECT_EQ(E2.get_name(), "�������");

	EXPECT_EQ(E1.get_surname(), "������");
	EXPECT_EQ(E2.get_surname(), "�������");

	EXPECT_EQ(E1.get_disaese(), "����������");
	EXPECT_EQ(E2.get_disaese(), "���������� ������� ������� �����");

	EXPECT_EQ(A.get_patient("��������", "������"), &E1);
	EXPECT_EQ(A.get_patient("�������", "�������"), &E2);
}

DateTime time1(21, 12, 2024, 13, 20);
DateTime time2(3, 5, 2025, 9, 0);

TEST(DateTimeTest, construct) {
	EXPECT_EQ(time1.day, 21);
	EXPECT_EQ(time1.month, 12);
	EXPECT_EQ(time1.year, 2024);
	EXPECT_EQ(time1.hour, 13);
	EXPECT_EQ(time1.minute, 20);

	EXPECT_EQ(time2.day, 3);
	EXPECT_EQ(time2.month, 5);
	EXPECT_EQ(time2.year, 2025);
	EXPECT_EQ(time2.hour, 9);
	EXPECT_EQ(time2.minute, 0);
}

TEST(AppointmentTest, Construct){
	Appointment *App = new Appointment(&B1, &E1, &D1, &time1);
	EXPECT_NE(&App, nullptr);
}

TEST(LabTests, Construct) {
	LabTest test("������� ������� � �����",&time2);
	string const str1 = "normal", str2 = "bad", str3 = "good";
	EXPECT_TRUE(test.get_result() == str1|| test.get_result() == str2|| test.get_result() == str3);
}

TEST(MedicalRecordTest, Construct) {
	MedicalRecord* rec = new MedicalRecord(&E1);
	EXPECT_NE(&rec, nullptr);
}

TEST(PrescriptionTest, add_prescription) {
	Prescription prescr;
	prescr.add_prescription(&B2, &E2, "��������");
	EXPECT_EQ(prescr.name_of_med, "��������");
}

TEST(ClinicTest, AddNurseAndShow) {
	A.add_nurse(&C1);
	system("chcp 1251>nul");
	EXPECT_NO_THROW(C1.info());
}

TEST(PharmacyTest, AddDrugTwice) {
	A.pharm->add_drug(10.0, "�������");
	A.pharm->add_drug(10.0, "�������"); 
	EXPECT_EQ(A.pharm->get_drug("�������"), 10.0); 
}

TEST(DoctorTest, AddSamePatientMultipleTimes) {
	A.add_doctor(&B1);
	B1.add_patient(&E1, &A);
	EXPECT_NO_THROW(B1.add_patient(&E1, &A)); 
}

TEST(RoomTest, CheckNonExistentEquipment) {
	EXPECT_FALSE(D1.exist_equipment("������������� �������")); 
}

TEST(AppointmentTest, CancelAppointment) {
	Appointment* app = new Appointment(&B1, &E1, &D1, &time1);
	for (auto app : A.appointments) {
		EXPECT_NO_THROW(app->cancel());
		EXPECT_NO_THROW(app->info());
	}
}

TEST(LabTest, LabTestResultConsistencyInfo) {
	LabTest test("������� ������� � �����", &time2);
	system("chcp 1251>nul");
	string result1 = test.get_result();
	string result2 = test.get_result(); 
	EXPECT_NO_THROW(test.info());
	EXPECT_EQ(result1, result2); 
}

TEST(MedicalRecordTest, RetrieveRecordByPatient) {
	MedicalRecord rec(&E1);
	rec.add_rec("��������� ������");
	EXPECT_NO_THROW(rec.check_history()); 
}

TEST(PrescriptionTest, VerifyDoctorInPrescription) {
	Prescription prescr;
	prescr.add_prescription(&B1, &E1, "��������");
	EXPECT_NO_THROW(prescr.show());
}

TEST(AppointmentTest, CancelAndInfo) {
	Appointment* app = new Appointment(&B1, &E1, &D1, &time1);
	D1.add_working_doc(&B1);
	system("chcp 1251>nul");

	EXPECT_NO_THROW(app->info());

	app->cancel(); 
	EXPECT_NO_THROW(app->info()); 
}

TEST(DoctorTest, ShowAllPAtient) {
	B1.add_patient(&E1, &A);
	B1.add_patient(&E2, &A);
	B2.add_patient(&E1);
	EXPECT_NO_THROW(B1.show_patients());
	EXPECT_NO_THROW(B2.show_patients());
}
TEST(ClinicTest, Shows) {
	system("chcp 1251>nul");
	D1.add_working_doc(&B1);
	D1.add_nurse(&C1);
	D2.add_working_doc(&B2);
	D2.add_nurse(&C2);
	Appointment* app = new Appointment(&B1, &E1, &D1, &time1);
	A.appointments.push_back(app);
	EXPECT_NO_THROW(A.show_all_appointments());
	EXPECT_NO_THROW(A.show_all_doctors());
	EXPECT_NO_THROW(A.show_all_nurses());
	EXPECT_NO_THROW(A.show_all_patients());
	EXPECT_NO_THROW(A.show_all_prescriptions());
	EXPECT_NO_THROW(A.show_all_rooms());
}

TEST(VacinationTest, Info) {
	system("chcp 1251>nul");
	Vaccination vac("������� �� covid 19", &time1, &B1);
	EXPECT_NO_THROW(vac.info());
}

TEST(TreatmentTest, Info) {
	system("chcp 1251>nul");
	Treatment treat("���� �������� ����", INT_MAX - 1);
	EXPECT_NO_THROW(treat.info());
}

TEST(ClinicTest, Kill) {
	Patient E24("��������", "����������", 16, "������");
	EXPECT_NO_THROW(A.patient_dead("��������", "����������"));
	EXPECT_NE(A.get_patient("��������", "����������"), &E24);
	LabTest* test = new LabTest("������� ����������� � �����", &time1);
	E1.tests.push_back(test);
	EXPECT_NO_THROW(A.kill());
}

TEST(DateTimeTest, SetDateTime) {
	system("chcp 1251>nul");
	DateTime* time21 = new DateTime();
	EXPECT_NO_THROW(time21->set_date_time());
}

TEST(EmployeeTest, InfoGetNameSurname) {
	system("chcp 1251>nul");
	Employee emp("�������", "������", 23, 1203.53);
	EXPECT_NO_THROW(emp.info());
	EXPECT_EQ(emp.get_name(), "�������");
	EXPECT_EQ(emp.get_surname(), "������");
}

TEST(PersonTest, InfoGetNameSurname) {
	system("chcp 1251>nul");
	Person emp("�����", "���������", 23);
	EXPECT_NO_THROW(emp.info());
	EXPECT_EQ(emp.get_name(), "�����");
	EXPECT_EQ(emp.get_surname(), "���������");
}

TEST(PatienTest, TreatShowDoctors) {
	system("chcp 1251>nul");
	E1.add_doctor(&B1);
	E1.add_doctor(&B2);
	EXPECT_NO_THROW(E1.show_doctors());
	EXPECT_EQ(E1.treat, nullptr);
	E1.add_treat("������ �� �������� �� �������� ����������", 1);
	EXPECT_NO_THROW(E1.treat->info());
}

TEST(RegistryTest, AddRecord) {
	Registry reg("���������", "������",36,1521.43);
	MedicalRecord rec(&E1);
	rec.add_rec("��������� ������");
	EXPECT_NO_THROW(reg.add_record(&rec));
}