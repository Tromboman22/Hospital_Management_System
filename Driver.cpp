#include "Patient.h"
#include "Doctor.h"
#include "Hospital.h"
#include <vector>
#include <string>
#include <limits>
#include <iostream>

using namespace std;

int main()
{
    Hospital hospital = Hospital();

    cout << "Welcome to the hospital simulation, how may we help you?" << endl;

    while(true)
    {
        //initial message
        cout << "\n1. Find Oldest Patient" << endl
            << "2. Count Critial Patients" << endl
            << "3. List Doctors by Specialty" << endl
            << "4. Show Patient by ID" << endl
            << "5. Show Doctor by ID" << endl 
            << "6. Show Assigned Doctor" << endl 
            << "7. Show Assigned Patients" << endl
            << "8. Exit\n" << endl
            << "Enter your choice (number from 1 to 8): ";
        int in;
        cin >> in;

        switch (in)
        {
        case 1:
            hospital.Find_Oldest_Patient();
            break;
        case 2:
            hospital.Count_Critical_Patients();
            break;
        case 3:
            {
                string specs;
                cout << "Enter the specialty: ";
                cin >> specs;
                hospital.Doctors_By_Specialty(specs);
                break;
            }            
        case 4:
            {
                long int id;
                cout << "Enter patient ID: ";
                cin >> id;
                hospital.Show_Patient_By_ID(id);
                break; 
            }
            
        case 5:
        {
            long int id;
            cout << "Enter doctor ID: ";
            cin >> id;
            hospital.Show_Doctor_By_ID(id);
            break;
        }
        case 6: 
        {
            long int id;
            cout << "Enter patient ID: ";
            cin >> id;
            hospital.Show_Assigned_Doctor(id);
            break;
        }
        case 7:
        {
            long int id;
            cout << "Enter doctor ID: ";
            cin >> id;
            hospital.Show_Assigned_Patients(id);
            break;
        }
        case 8: 
        {
            hospital.~Hospital();
            cout << "Goodbye!";
            return 0; //Free memory and exit program
        }

        default:
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear cin if fails
            break;
        }

    }
}

