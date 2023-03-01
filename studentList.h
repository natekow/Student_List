#include <fstream>
using namespace std;
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "student.h"
#ifndef STUDENTLIST
#define STUDENTLIST
class studentList 
{
private:

 unsigned int maxSize; 

 int  nameLength, idLength; 

vector<student> empList;


public: 
studentList(unsigned int size=0)

{
   maxSize = 20;
   nameLength = student::nameLength; 
}

int searchById(string Id);


bool addStudent(student); 


void writeData(ostream& outfile);

void printRecords(ostream& outfile);
void processRecords();
student& getStudent(int i);


};


#endif

