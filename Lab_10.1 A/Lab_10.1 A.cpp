#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_AND_ECON, PHYSICS_AND_INFORMATICS, LABOR_EDUCATION };
string specialityStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

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
        cout << "Студент № " << i + 1 << ":\n";
        cout << " Прізвище: "; cin >> students[i].surname;
        cout << " Курс: "; cin >> students[i].course;
        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> speciality;
        students[i].speciality = static_cast<Speciality>(speciality);
        cout << " Оцінка з фізики: "; cin >> students[i].physicsGrade;
        cout << " Оцінка з математики: "; cin >> students[i].mathGrade;
        cout << " Оцінка з інформатики: "; cin >> students[i].informaticsGrade;
    }
}


void Print(const Student* students, int N) {
    cout << "===============================================================================================\n";
    cout << "| №  | Прізвище         | Курс | Спеціальність            | Фізика | Математика | Інформатика |\n";
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
        return "Фізика";
    else if (mathAvg >= physicsAvg && mathAvg >= informaticsAvg)
        return "Математика";
    else
        return "Інформатика";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    int highAvgCount = CountHighAverageGrade(students, N);
    cout << "Кількість студентів із середнім балом вищим за 4.5: " << highAvgCount << endl;

    string highestAvgSubject = HighestAverageGradeSubject(students, N);
    cout << "Предмет із найбільшим середнім балом: " << highestAvgSubject << endl;

    delete[] students;
    return 0;
}
