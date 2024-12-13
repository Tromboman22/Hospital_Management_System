#pragma once
#include "Patient.h"
#include "Doctor.h"
#include <vector>
#include <string>

using namespace std;

class Hospital
{
    private:
        vector <Patient>* patients;
        vector <Doctor>* doctors;

    public:
        //Constructor
        Hospital();
        //Functions
        void Find_Oldest_Patient();
        void Count_Critical_Patients();
        void Doctors_By_Specialty(string specialty);
        void Show_Patient_By_ID(long int id);
        void Show_DOctor_By_ID(long int id);
        void Show_Assigned_Doctor(long int id);
        void Show_Assigned_Patients(long int id);
};
