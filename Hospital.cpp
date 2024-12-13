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
Hospital::~Hospital() {
    delete doctors;
    delete patients;
}