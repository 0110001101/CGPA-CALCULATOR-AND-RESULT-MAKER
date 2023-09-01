#include <iostream>
#include <string.h>
#include <iomanip>
#include "methods.h"
#include "globals.h"
using namespace std;

int main()
{
    char choice;
    start:
    int Nsub;
    // Grade divisions of the user
    cout << "Enter GRADE divisions of your college : " << endl;
    cout << "Enter Lower bound for 'AA' Grade : " << endl;
    cin >> AAl;
    cout << "Enter Lower bound for 'AB' Grade : " << endl;
    cin >> ABl;
    cout << "Enter Lower bound for 'BB' Grade : " << endl;
    cin >> BBl;
    cout << "Enter Lower bound for 'BC' Grade : " << endl;
    cin >> BCl;
    cout << "Enter Lower bound for 'CC' Grade : " << endl;
    cin >> CCl;
    cout << "Enter Lower bound for 'CD' Grade : " << endl;
    cin >> CDl;
    cout << "Enter Lower bound for 'DD' Grade : " << endl;
    cin >> DDl;

    // Creating linked list where each node contains 'subject' object
    class subject *head = nullptr;
    class subject *tail = nullptr;

    // Declaration of variables(as parameter passing) for constructor 'subject'
    int cred;
    int tmarks;
    float obmarks;
    string Name;
    int question;
    cout << "Press 1 for calculating CGPA and 0 for SGPA" << endl;
    cin >> question;

    if (question)
    {
        cout << "Enter the number of semesters for you course : " << endl;
        cin >> semesters;

        for (size_t i = 1; i <= semesters; i++)
        {
            cout << "Enter the following informations for Semester - " << i << endl;

            // Asking for no of subjects
            cout << "Enter the no of Subjects : " << endl;
            cin >> Nsub;

            // Creation of linked list and storing the data for each subject in a nodes
            for (size_t i = 1; i <= Nsub; i++)
            {

                // Taking the data for subject constructor
                cin.ignore();
                cout << "Enter the subject name for subject" << i << ":" << endl;
                getline(cin, Name);
                cout << "Enter the total credits for the subject" << i << ":" << endl;
                cin >> cred;
                cout << "Enter the total marks for the subject" << i << ": " << endl;
                cin >> tmarks;
                cout << "Enter the obtained marks for the subject" << i << ": " << endl;
                cin >> obmarks;

                class subject *newnode = new subject(Name, cred, tmarks, obmarks);
                tcred = tcred + cred;
                score = score + (cred * grade(obmarks));
                newnode->next = nullptr;

                if (head == nullptr)
                {
                    head = newnode;
                    tail = newnode;
                }
                else
                {
                    tail->next = newnode;
                    tail = newnode;
                }
            }

            // Function call that return grade point average
            gpa = GPA(tcred, score);
            CGPA = CGPA + gpa;

            // Printing collected data on console
            int quest;
            cout << "Do you want to see all the data : (1 for yes or 0 for no)" << endl;
            cin >> quest;
            cout << "The GPA for this semester is : " << gpa << endl;

            if (quest)
            {
                traverse(head);
            }

            int quest2;
            cout << "Do you want to save all the data : 1/0" << endl;
            cin >> quest2;
            if (quest2)
            {
                store(head);
            }

            if (i == semesters)
            {
                cout << "The CGPA for is : " << CGPA / semesters << endl;
                cout << "Thank You !" << endl;
            }
        }
    }
    // else statement for calculating semester grade point
    else
    {
        // Asking for no of subjects
        cout << "Enter the no of Subjects : " << endl;
        cin >> Nsub;

        // Creation of linked list and storing the data for each subject in a nodes
        for (size_t i = 1; i <= Nsub; i++)
        {
            // Taking the data for subject constructor
            cin.ignore();
            cout << "Enter the subject name for subject" << i << ":" << endl;
            getline(cin, Name);
            cout << "Enter the total credits for the subject" << i << ":" << endl;
            cin >> cred;
            cout << "Enter the total marks for the subject" << i << ": " << endl;
            cin >> tmarks;
            cout << "Enter the obtained marks for the subject" << i << ": " << endl;
            cin >> obmarks;

            class subject *newnode = new subject(Name, cred, tmarks, obmarks);
            tcred = tcred + cred;
            score = score + (cred * grade(obmarks));
            newnode->next = nullptr;

            if (head == nullptr)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
        }

        // Function call that return grade point average
        gpa = GPA(tcred, score);

        // Printing collected data on console
        int quest;
        cout << "Do you want to see all the data : (1 for yes or 0 for no)" << endl;
        cin >> quest;
        cout << "The GPA for this semester is : " << gpa << endl;
        cout << endl;


        if (quest)
        {
            traverse(head);
        }

        int quest2;
        cout << "Do you want to save all the data : 1/0" << endl;
        cin >> quest2;
        if (quest2)
        {
            store(head);
        }

    }

    cout << "All operations are done" << endl;
    cout << "Do want to close the program (1/0) or Rerun : " ;
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        goto start;
    }
    else
    {
        cout << "Exiting the program !" << endl;
        cout << "Thank You !" << endl;
    }
    
    return 0;
}
