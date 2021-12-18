/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DOTY.h
 * Author: michaelcooper
 *
 * Created on November 21, 2021, 9:19 PM
 */

#ifndef DOTY_H
#define DOTY_H
#include <iostream>
#include <string>
using namespace std;
class DOTY{
private:
    int day;
    string months[12];
    int end[13];
    static string dayMnth;
    static int remDays;
public:
    DOTY(int d);
    void print();
    void setend();
    void setmonth();
};


#endif /* DOTY_H */

