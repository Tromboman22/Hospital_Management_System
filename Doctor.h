#ifndef DOCTORS.H
#define DOCTORS.H

#include <string>
using namespace std;

class Doctor {

private:
    string firstName, lastName, specialty;
    int id, yearsExp;
    double salary, performanceBonus;
    

public:

    Doctor();
    Doctor(const string& fName, const string& lName, const int& inpId, const string& inpSpeciality, const int& years, const double& inpSalary, const double& perfBonus);

    void setFirstName(string name);
    string getFirstName();

    void setLastName(string name);
    string getLastName();

    void setSpecialty(string name);
    string getSpecialty();

    void setId(int inpId);
    int getId();

    void setYearsExp(int years);
    int getYearsExp();

    void setSalary(int inpSalary);
    double getSalary();

    void setPerformanceBonus(double bonus);
    double getPerformanceBonus();

    double Calculate_Salary();

    void Print_Doctor_Info();




};
#endif
