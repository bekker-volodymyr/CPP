#include <iostream>

using namespace std;

#define MAX_NAME_LEN 30

struct StudentStruct {
    int assessmentCount = 5;
    int assessments[5];

    char name[MAX_NAME_LEN];
};

int avgAssessment(const StudentStruct& st) {
    int sum = st.assessments[0];
    for (int i = 1; i < st.assessmentCount; i++) {
        sum += st.assessments[i];
    }
    return sum / st.assessmentCount;
}

class Student {
private:
    char name[MAX_NAME_LEN];
    int assessments[5];
    int assessmentCount = 5;
public:
    Student(const char* name, int* assessments) {
        strcpy_s(this->name, 30, name);
        for (int i = 0; i < assessmentCount; i++) {
            this->assessments[i] = assessments[i];
        }
    }
    int avgAssessment() {
        int sum = this->assessments[0];
        for (int i = 1; i < this->assessmentCount; i++) {
            sum += this->assessments[i];
        }
        return sum / this->assessmentCount;
    }
};

int main()
{
    StudentStruct st = { 5, {10,6,7,9,12}, "Mykola Tarasuk" };

    cout << avgAssessment(st) << '\n';

    int assessments[] = { 10, 6, 7, 9, 12 };
    Student student = Student("Mykola Tarasuk", assessments);

    cout << student.avgAssessment() << '\n';
}