#pragma once
#include <string>

using namespace std;

class Patient {
    private:
        string firstName, lastName, 
        diagnostic, blood, // blood type
        DOB, admission, discharge; //all dates

        long int ID, doctor; //doctor ID number
 
        public:
            Patient();

            //names
            string getFirstName(); 
            void setFirstName(string name);
            string getLastName(); 
            void setLastName(string name);

            //medical info
            string getDiagnostic();
            void setDiagnostic(string diag);
            string getBlood();
            void setBlood(string type);

            //dates
            string getDOB();
            void setDOB(string date);
            string getAdmission();
            void setAdmission(string date);
            string getDischarge();
            void setDischarge(string date);

            //ID's
            long int getID();
            void setID(long int num);
            long int getDoctor();
            void setDoctor(long int num);

            //Functions
            bool IsDischarged(); //Discharge date != -1 -> return true, else false
            string Patient_Status(); //Return critical, moderate or stable
            void Print_Patient_Info(); //Prints all info
};
