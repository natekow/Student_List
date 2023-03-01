#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "student.h"
#include "studentList.h"
#include <vector>
using namespace std;

student& studentList::getStudent(int i)
{ 
  return empList.at(i);
}

int studentList::searchById(string Id)
{  
  for (unsigned int index = 0; index < maxSize; index++)
    {
      if ((empList.at(index)).getId() == Id)
	  return index;
    }
  return -1;
}

bool studentList::addStudent(student emp)
{  
  if ((empList.size()) >= maxSize)
     return false;  
  empList.push_back(emp);
  return true;  
}  
void studentList::writeData(ostream& outfile)
{
  for(unsigned int index = 0; index < empList.size(); index++)
    {       
      (empList.at(index)).writeStudent(outfile);
       outfile << endl;
    }
}

void studentList::processRecords()
{
 for(unsigned int index = 0; index < empList.size(); index++)  
    (empList.at(index)).processRecord();
}
void studentList::printRecords(ostream& outfile)
{
  for(unsigned int index = 0; index < empList.size(); index++)
  {  
   (empList.at(index)).printRecord(outfile);
  }
}