#include "Patient.h"
#include "Doctor.h"
#include "Hospital.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

Hospital::Hospital(){

    ifstream fileDoctor("doctor_sample.txt");

    if (!fileDoctor) {
    cerr << "Error: Could not open Doctor file!" << endl;
    return;
    }
    int nbDoctors;

    string firstName;
    string lastName;
    int id;
    string speciality;
    int yearsExp;
    double salary;
    double salaryBonus;

    fileDoctor >> nbDoctors;

    while (fileDoctor >> firstName >> lastName >> id >> speciality >> yearsExp >> salary >> salaryBonus) { // Read data into variables
        speciality.erase(0,1);
        speciality.erase(speciality.length() - 1, 1);
        doctors->push_back(Doctor(firstName, lastName, id, speciality, yearsExp, salary, salaryBonus));
    }
    fileDoctor.close();


    ifstream filePatient("patients_sample.txt");
    if (!filePatient) {
    cerr << "Error: Could not open Patient file!" << endl;
    return;
    }
    int nbPatients;

    string firstNamePatient, lastNamePatient, 
    diagnostic, blood, // blood type
    DOB, admission, discharge; //all dates

    long int ID, doctor; //doctor ID number

    filePatient >> nbPatients;

    while (filePatient >> firstNamePatient >> lastNamePatient >> ID >> doctor >> DOB >> blood >> diagnostic >> admission >> discharge) { // Read data into variables
        diagnostic.erase(0,1);
        diagnostic.erase(diagnostic.length() - 1, 1);
        patients->push_back(Patient(firstNamePatient, lastNamePatient, ID, doctor, DOB, blood, diagnostic, admission, discharge));
    }
    filePatient.close();

}
Hospital::~Hospital() { //delete pointers
    delete doctors;
    delete patients;
}

//Functions
void Hospital::Find_Oldest_Patient() //Find and print details of oldest patient
{
    long int min = 2024; //youngest possible patient
    Patient *p;
    for(int i = 0; i < (*patients).size(); i++) //Find
    {
        long int tmp = stoi((*patients)[i].getDOB());
        if(tmp < min)
            min = tmp;
            *p = (*patients)[i];
    }
    Show_Patient_By_ID((*p).getID()); //Print
}

void Hospital::Count_Critical_Patients() //Count and return num of critical patients
{
    int count = 0;
    for(int i = 0; i < (*patients).size(); i++)
    {
        if((*patients)[i].getDiagnostic() == "Critical")
            ++count;
    }
    cout << count << " critical patients." << endl;
}

void Hospital::Doctors_By_Specialty(string specialty)
{
    cout << "Doctors specializing in " << specialty << ":";
    int check = 0;
    for(int i = 0; i < (*doctors).size(); i++)
    {
        if((*doctors)[i].getSpecialty() == specialty)
        {
            if(check == 1)
                cout << ",";
            else
                check = 1;

            cout << endl << (*doctors)[i].getFirstName() <<
            " " << (*doctors)[i].getLastName();
        }
    }
    cout << endl;
}

void Hospital::Show_Patient_By_ID(long int id)
{
    int check = 0;
    for(int i = 0; i < (*patients).size(); i++)
    {
        if((*patients)[i].getID() == id)
        {
            check++;
            (*patients)[i].Print_Patient_Info();
            break;
        }
    }
    if(check == 0)
        cout << "No patient has the provided ID" << endl;
}

void Hospital::Show_Doctor_By_ID(long int id)
{
    int check = 0;
    for(int i = 0; i < (*doctors).size(); i++)
    {
        if((*doctors)[i].getId() == id)
        {
            check++;
            (*doctors)[i].Print_Doctor_Info();
            break;
        }
    }
    if(check == 0)
        cout << "No patient has the provided ID" << endl;
}

void Hospital::Show_Assigned_Doctor(long int id)
{
    for(int i = 0; i < (*patients).size(); i++)
    {
        if((*patients)[i].getID() == id)
        {
            long int tmp = (*patients)[i].getDoctor();
            if(tmp != -1)
            {
                cout << "Assigned Doctor:" << endl;
                Show_Doctor_By_ID(tmp);
                break;
            }else{
                cout << "Assigned Doctor: No doctor assigned" << endl;
                break;
            }

        }
    }
}
void Hospital::Show_Assigned_Patients(long int id){
    for(int i = 0; i < patients->size(); i++){
        if(patients->at(i).getDoctor() == id){
            patients->at(i).Print_Patient_Info();

        }
    }
}
