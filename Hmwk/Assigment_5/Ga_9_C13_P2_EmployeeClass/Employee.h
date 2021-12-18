/*
  * File:   employee.h
  * Author: Michael Cooper
  * Created on November 17, 2021, 2:30 PM
  */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iomanip>
using namespace std;

class Employee {
private:
    string name;
    string dept;    //department
    string post;    //position
    int idNumb;
public:
    Employee(string newName, int newId, string newDept, string newPost);
    Employee(string newName, int newId);
    Employee();
    void setName(string);
    void setIdNm(int);
    void setDept(string);
    void setPost(string);
    string getName() const;
    int getIdNum() const;
    string getDept() const;
    string getPost() const;
};
#endif /* EMPLOYEE_H */


