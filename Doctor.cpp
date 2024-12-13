#include "Doctor.h"
#include <iostream>
#include <string>
using namespace std;


Doctor::Doctor(){
    firstName = "";
    lastName = "";
    specialty = "";
    id = 0;
    yearsExp = 0;
    salary = 0;
    performanceBonus = 0;
}

Doctor::Doctor(const string& fName, const string& lName, const int& inpId, const string& inpSpeciality, const int& years, const double& inpSalary, const double& perfBonus){
    firstName = fName;
    lastName = lName;
    specialty = inpSpeciality;
    id = inpId;
    yearsExp = years;
    salary = inpSalary;
    performanceBonus = perfBonus;
}

void Doctor::setFirstName(string name){
    firstName = name;
}

string Doctor::getFirstName(){
    return firstName;
}
    

void Doctor::setLastName(string name){
    lastName = name;
}
string Doctor::getLastName(){
    return lastName;
}

void Doctor::setSpecialty(string name){
    specialty = name;
}
string Doctor::getSpecialty(){
    return specialty;
}

void Doctor::setId(int inpId){
    id = inpId;
}
int Doctor::getId(){
    return id;
}
void Doctor::setYearsExp(int years){
    yearsExp = years;
}
int Doctor::getYearsExp(){
    return yearsExp;
}
void Doctor::setSalary(int inpSalary){
    salary = inpSalary;
}
double Doctor::getSalary(){
    return salary;
}

void Doctor::setPerformanceBonus(double bonus){
    performanceBonus = bonus;
}
double Doctor::getPerformanceBonus(){
    return performanceBonus;
}

double Doctor::Calculate_Salary(){
    return salary + salary*performanceBonus;
}
void Doctor::Print_Doctor_Info(){
    cout << firstName << " " << lastName << " " << id << " " << specialty << " " << yearsExp << " " << salary << " " << performanceBonus;
}
