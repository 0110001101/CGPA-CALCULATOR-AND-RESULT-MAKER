#ifndef VARIABLES
#define VARIABLES
#include <string.h>
#include <iostream>
using namespace std;

// 'subject' class declaration 
class subject
{
private:
    string name;
    int Ncredits;
    int TotalMarks;
    float ObtainedMarks;

public:
    class subject *next;
    subject() = default;
    subject(string name, int Ncredits, int TotalMarks, float ObtainedMarks);
    int get_Ncredits(); 
    int get_TotalMarks();
    float get_ObtainedMarks();
    string get_name();
    // ~subject();
};

// Definition of functions used in main.cpp and subject.cpp
int grade(float ObtainMarks);
float GPA(int tcred, float score);
void traverse(class subject *head);
void store(class subject *head);
#endif