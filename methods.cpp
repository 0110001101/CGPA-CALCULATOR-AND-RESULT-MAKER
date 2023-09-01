#include <iostream>
#include <iomanip>
#include <fstream>
#include "methods.h"
#include "globals.h"
using namespace std;

subject::subject(string name, int Ncredits, int TotalMarks, float ObtainedMarks)
{
    this->name = name;
    this->Ncredits = Ncredits;
    this->TotalMarks = TotalMarks;
    this->ObtainedMarks = ObtainedMarks;
};

int subject::get_Ncredits()
{
    return Ncredits;
};
int subject::get_TotalMarks()
{
    return TotalMarks;
};
float subject::get_ObtainedMarks()
{
    return ObtainedMarks;
};
string subject::get_name()
{
    return name;
};

// Function definition for grad point average
float GPA(int tcred, float score)
{
    return (score / tcred);
}

// Function definition of linked list traversal
int i = 1;
int counter = 1;
void store(class subject *head)
{
    class subject *ptr;
    ptr = head;
    ofstream onFile;
    onFile.open("C:\\Users\\HP\\OneDrive\\Desktop\\PROJECTs\\01_CGPA.txt", ios::app);
    do
    {
        if (i > 1)  // increament after first node
        {
            ptr = ptr->next;
        }

        // storing collected data into file named CGPA
        onFile << left;
        onFile << setw(30) << "Subject " + to_string(i) + " name is " << ": " << ptr->get_name() << std::endl;
        onFile << setw(30) << "Subject " + to_string(i) + " credits is " << ": " << ptr->get_Ncredits() << std::endl;
        onFile << setw(30) << "Subject " + to_string(i) + " total marks is " << ": " << ptr->get_TotalMarks() << std::endl;
        onFile << setw(30) << "Subject " + to_string(i) + " obtained marks is " << ": " << ptr->get_ObtainedMarks() << std::endl;
        onFile << endl;
        onFile << endl;
        i++;

    } while (ptr->next != nullptr);
    onFile << "===================================================================================" << endl;
    onFile << setw(30) << "The GPA for this semester is : " << gpa << endl;
    counter++;
    if (counter == semesters)
    {
        onFile << setw(30) << "The CGPA for is : " << CGPA / semesters << endl;
    }
    onFile.close();
    cout << "You can read the data through file named CGPA.txt" << endl;
}

void traverse(class subject *head)
{
    class subject *ptr;
    ptr = head;
    do
    {
        if (i > 1)
        {
            ptr = ptr->next;
        }
         // Printing data for each traversal
        cout << left; // Set the alignment to 
        cout << setw(30) << "Subject " + to_string(i) + " name is " << ": " << ptr->get_name() << std::endl;
        cout << setw(30) << "Subject " + to_string(i) + " credits is " << ": " << ptr->get_Ncredits() << std::endl;
        cout << setw(30) << "Subject " + to_string(i) + " total marks is " << ": " << ptr->get_TotalMarks() << std::endl;
        cout << setw(30) << "Subject " + to_string(i) + " obtained marks is " << ": " << ptr->get_ObtainedMarks() << std::endl;
        cout << endl;
        i++;
    } while (ptr->next != nullptr);
}
 

// Function for calculating grade points form obtained marks
int grade(float ObtainMarks)
{
    if (ObtainMarks >= AAl)
    {
        return 10;
    }
    else if (ObtainMarks >= ABl)
    {
        return 9;
    }
    else if (ObtainMarks >= BBl)
    {
        return 8;
    }
    else if (ObtainMarks >= BCl)
    {
        return 7;
    }
    else if (ObtainMarks >= CCl)
    {
        return 6;
    }
    else if (ObtainMarks >= CDl)
    {
        return 5;
    }
    else if (ObtainMarks >= DDl)
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

