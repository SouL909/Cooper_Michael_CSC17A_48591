/*
 * Michael Cooper
 */

#include "DOTY.h"

string DOTY::dayMnth="";    //day in month
int DOTY::remDays=0;        //remaining days
DOTY::DOTY(int d){
    day=d;
}
void DOTY::setend(){
    end[0]=0;
    end[1]=31;
    end[2]=59;
    end[3]=90;
    end[4]=120;
    end[5]=151;
    end[6]=181;
    end[7]=212;
    end[8]=243;
    end[9]=273;
    end[10]=304;
    end[11]=334;
    end[12]=365;
}
void DOTY::setmonth(){
    months[0]="January";
    months[1]="February";
    months[2]="March";
    months[3]="April";
    months[4]="May";
    months[5]="June";
    months[6]="July";
    months[7]="August";
    months[8]="September";
    months[9]="October";
    months[10]="November";
    months[11]="December";
}
void DOTY::print(){
    int month=0;
    while(end[month]<day)
        month++;
    dayMnth+=months[month-1];
    remDays+=day-end[month-1];
    cout << "Date :" << dayMnth <<" "<< remDays << endl;     
}
