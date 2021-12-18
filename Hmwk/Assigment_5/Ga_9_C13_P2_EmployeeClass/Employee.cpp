
/* 
 * File:   Employee.cpp
 * Author: michaelcooper
 *
 * Created on November 16, 2021, 5:46 PM
 */

#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string newName, int newId, string newDept, string newPost) {
    name = newName;
    idNumb = newId;
    dept = newDept;
    post = newPost;
}
Employee::Employee() {
    name = "";
    idNumb = 0;
    dept = "";
    post = "";
}
void Employee::setName(string newName) {
    name = newName;
}
void Employee::setIdNm(int newId) {
    idNumb = newId;
}
void Employee::setDept(string newDept) {
    dept = newDept;
}
void Employee::setPost(string newPost) {
    post = newPost;
}
string Employee::getName()const {
    return name;
}
int Employee::getIdNum()const {
    return idNumb;
}
string Employee::getDept()const {
    return dept;
}
string Employee::getPost()const {
    return post;
}
