#include "Patient.h"
#include <string>
#include <iostream>

using namespace std;


//Constructors
Patient::Patient()
{
    firstName
    lastName
    diagnostic
    blood
    DOB
    admission
    discharge
    ID
    doctor
}
Patient::Patient(string fname, string lname, long int id, long int doc, string dob, string bld, string diag, string adm, string disch)
{
    firstName = fname;
    lastName = lname;
    diagnostic = diag;
    blood = bld;
    DOB = dob;
    admission = adm;
    discharge = disch;
    ID = id;
    doctor = doc;
}

//names
string Patient::getFirstName()
{
    return firstName;
}
void Patient::setFirstName(string name)
{
    firstName = name;
}
string Patient::getLastName()
{
    return lastName;
}
void Patient::setLastName(string name)
{
    lastName = name;
}

//medical info
string Patient::getDiagnostic()
{
    return diagnostic;
}
void Patient::setDiagnostic(string diag)
{
    diagnostic = diag;
}
string Patient::getBlood()
{
    return blood;
}
void Patient::setBlood(string type)
{
    blood = type;
}

//dates
string Patient::getDOB()
{
    return DOB;
}
void Patient::setDOB(string date)
{
    DOB = date;
}
string Patient::getAdmission()
{
    return admission;
}
void Patient::setAdmission(string date)
{
    admission = date;
}
string Patient::getDischarge()
{
    return discharge;
}
void Patient::setDischarge(string date)
{
    discharge = date;
}

//ID's
long int Patient::getID()
{
    return ID;
}
void Patient::setID(long int num)
{
    ID = num;
}
long int Patient::getDoctor()
{
    return doctor;
}
void Patient::setDoctor(long int num)
{
    doctor = num;
}

//Functions
bool Patient::IsDischarged() //Discharge date != -1 -> return true, else false
{
    if(discharge == "-1")
        return false;
    else  
        return true;  
}
string Patient::Patient_Status() //Return critical, moderate or stable
{
    string status;
    for(char c : diagnostic)
    {
        if(c == ' ')
            break;
        else
            status = status + c; //append character
    }
    return status;
}
void Patient::Print_Patient_Info() //Prints all info
{
    cout << "First Name: " << firstName << endl <<
    "Last Name: " << lastName << endl <<
    "ID: " << ID << endl <<
    "Diagnostic: " << diagnostic << endl <<
    "Blood Type: " << blood << endl <<
    "Date of Birth: " << DOB << endl <<
    "Admission Date: " << admission << endl <<
    "Discharge date: " << discharge << endl;
    //Use getDoctor() in Driver.cpp to find doctor info using doctor ID
}

