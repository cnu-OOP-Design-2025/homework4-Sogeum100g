#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students++] = Student(name, id, midterm, final);
    
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    for (int i=0; i<num_of_students; i++){
        if (students[i].getID() == id){
            for (int j=i; j<num_of_students; j++){
                students[j] = students[j+1];
            }
            num_of_students--;
            break;
        }
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getID() == student.getID()){
            students[i] = student;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    int idx = -1;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getID() == id){
            idx = i;
        }
    }
    return idx;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    float max=0.0f;
    int idx = -1;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > max){
            max = students[i].getRecord().getMidterm();
            idx = i;
        }
    }
    return idx;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    float max = 0.0f;
    int idx = -1;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getRecord().getFinal() > max) {
            max = students[i].getRecord().getFinal();
            idx = i;
        }
    }
    return idx;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    float max = 0.0f;
    int id = -1;
    for (int i=0; i<num_of_students; i++) {
        float total = students[i].getRecord().getMidterm() + students[i].getRecord().getFinal();
        if (total > max){
            max = total;
            id = students[i].getID();
        }
    }
    return id;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum=0.0f;
    for (int i=0; i<num_of_students; i++) {
        sum += students[i].getRecord().getMidterm();
    }

    return (float) sum/num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float sum=0.0f;
    for (int i=0; i<num_of_students; i++) {
        sum += students[i].getRecord().getFinal();
    }

    return (float) sum/num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float sum=0.0f;
    for (int i=0; i<num_of_students; i++) {
        sum += students[i].getRecord().getMidterm() + students[i].getRecord().getFinal();
    }

    return (float) sum/num_of_students;
}

