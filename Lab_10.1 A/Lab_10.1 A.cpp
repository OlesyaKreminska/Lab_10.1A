#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_AND_ECON, PHYSICS_AND_INFORMATICS, LABOR_EDUCATION };
string specialityStr[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

struct Student {
    string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
    Student() : surname(""), course(0), speciality(COMPUTER_SCIENCE), physicsGrade(0), mathGrade(0), informaticsGrade(0) {}
};


void Create(Student* students, int N) {
    int speciality;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":\n";
        cout << " �������: "; cin >> students[i].surname;
        cout << " ����: "; cin >> students[i].course;
        cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> speciality;
        students[i].speciality = static_cast<Speciality>(speciality);
        cout << " ������ � ������: "; cin >> students[i].physicsGrade;
        cout << " ������ � ����������: "; cin >> students[i].mathGrade;
        cout << " ������ � �����������: "; cin >> students[i].informaticsGrade;
    }
}


void Print(const Student* students, int N) {
    cout << "===============================================================================================\n";
    cout << "| �  | �������         | ���� | ������������            | Գ���� | ���������� | ����������� |\n";
    cout << "-----------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < N; i++) {
        cout << left << "| " << setw(3) << i + 1 << "| " << setw(17) << left << students[i].surname
            << "| " << setw(4) << students[i].course
            << " | " << setw(24) << specialityStr[students[i].speciality]
            << " | " << setw(6) << students[i].physicsGrade
            << " | " << setw(10) << students[i].mathGrade
            << " | " << setw(11) << students[i].informaticsGrade << " |\n";
    }
    cout << "===============================================================================================\n";
}


int CountHighAverageGrade(const Student* students, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        double avg = (students[i].physicsGrade + students[i].mathGrade + students[i].informaticsGrade) / 3.0;
        if (avg > 4.5) {
            count++;
        }
    }
    return count;
}

string HighestAverageGradeSubject(const Student* students, int N) {
    double physicsSum = 0, mathSum = 0, informaticsSum = 0;
    for (int i = 0; i < N; i++) {
        physicsSum += students[i].physicsGrade;
        mathSum += students[i].mathGrade;
        informaticsSum += students[i].informaticsGrade;
    }
    double physicsAvg = physicsSum / N;
    double mathAvg = mathSum / N;
    double informaticsAvg = informaticsSum / N;

    if (physicsAvg >= mathAvg && physicsAvg >= informaticsAvg)
        return "Գ����";
    else if (mathAvg >= physicsAvg && mathAvg >= informaticsAvg)
        return "����������";
    else
        return "�����������";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    int N;
    cout << "������ ������� ��������: "; cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    int highAvgCount = CountHighAverageGrade(students, N);
    cout << "ʳ������ �������� �� ������� ����� ����� �� 4.5: " << highAvgCount << endl;

    string highestAvgSubject = HighestAverageGradeSubject(students, N);
    cout << "������� �� ��������� ������� �����: " << highestAvgSubject << endl;

    delete[] students;
    return 0;
}
