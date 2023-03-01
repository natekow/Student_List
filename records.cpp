#include <iostream>  
#include <fstream>  
#include <cstring>  
#include <string>  
#include <iomanip>  
#include "studentList.h"
using namespace std;  


const int maxSize = 20; 
const int nameLength = student::nameLength;   
studentList empList(5);   
ofstream outfile;  
ifstream infile;    
char input_file_name[21], output_file_name[21], name[nameLength+1]; 
string id;  
//***************************************************************************
void showmenu()  
{  
  cout<< "Please type in  one of the following options: \n";  
  cout<< "'L' to load the class list \n";  
  cout<< "'D' to display the student data \n";  
  cout<< "'P' to process student records\n";  
  cout<< "'C' to change an student's test scores \n";  
  cout<< "'A' to add a new student \n";  
  cout<< "'S' to search for a particular student's information \n";  
  cout<< "'R' to display the grade results \n";  
  cout<< "'M' to display the menu \n";  
  cout<< "'E' to save and exit \n";  
}  
  
void loadStudentList()  
{  
  student e_temp;  float hwScores[11]; float tScores[4];
  int deductions; float hrlyWage; 
  int i;int j=0; bool done;
  cout << "Please enter name of the data file: ";  
  cin >> input_file_name;  
  infile.open(input_file_name);  
  if ( !infile)  
    {  
      cout << "Could not open input file \n";  
      infile.close();  
      infile.clear();  
      return;  
    }  
  infile >> name; e_temp.setName(name);

  while(!infile.eof())  
    {  
      infile >> id; e_temp.setId(id);
      i = 0; done = false;
  for (i=0;i<11;i++)
infile>>hwScores[i]; 
      e_temp.setHW(hwScores, i);

for(j=0;j<4;j++)
infile>> tScores[j];
e_temp.setTest(tScores,j);
   
   empList.addStudent(e_temp);
      infile >> name; e_temp.setName(name);
    }  

  infile.close();  
  infile.clear();  
}     
void displayData()
{
  empList.writeData(cout);
}

void processRecords()  
{  
  cout << "Processing student records \n";
  empList.processRecords();
}  
  
void changeScores()  
{  
int i; float testScores[4];
  cout<<"Please enter student's ID: ";
cin>>id;
i=empList.searchById(id);
if (i!=-1)
{
cout<<"Please input new test scores (4): ";
cin>> testScores[0]>> testScores[1]>> testScores[2]>> testScores[3];
(empList.getStudent(i)).setTest(testScores,4);
}
else
cout<<"Could not find student\n";
}  
  
void addNewStudent()  
{  
student e_temp;
float hworkScores[11];
float testScores[4];

cout << "Please enter the name of the student: ";
cin >> name; e_temp.setName(name);
cout<<"Please enter the student's ID: ";
cin>> id; e_temp.setId(id);
cout<<"please enter homework scores (10), followed by participation score: ";
cin>> hworkScores[0] >> hworkScores[1] >> hworkScores[2] >> hworkScores[3] >> hworkScores[4] >>
hworkScores[5] >>hworkScores[6] >>hworkScores[7] >>hworkScores[8] >>hworkScores[9] >> hworkScores[10];
e_temp.setHW(hworkScores,10);
cout<<"Please enter the four test scores: ";
cin>>testScores[0]>>testScores[1]>>testScores[2]>>testScores[3];
e_temp.setTest(testScores,4);
if (empList.addStudent(e_temp))
cout<<"Successfully added student!"<<endl;
else
cout<<"Error: student could not be added =( "<<endl;

}  
    
void searchAStudent()  
{  
   char c; int j; float wage;
      cout << "Please enter id of the student:  ";
      cin >> id;
      j = empList.searchById(id);
    
  if (j!= -1)
   empList.getStudent(j).writeStudent(cout);
  else
    cout << "Sorry, the student could not be found";
    cout << endl;

}  
  
void printRecords()  
{  
   
  cout << "Please enter name of output  file: ";
  cin >> output_file_name;
  outfile.open(output_file_name);
empList.printRecords(outfile);  
}  
  
void saveInfo()  
{  
  cout << "Please enter name of the  new data file:  ";  
  cin >> output_file_name;  
  outfile.open(output_file_name);  
  if ( !outfile)  
    {  
      cout << "Could not open file \n";  
      outfile.close();  
      outfile.clear();  
      return;  
    }  
  empList.writeData(outfile);
  outfile.close();
  outfile.clear();
}  //******************************************************************
int main()  
{  
  
  char choice;  
    
  showmenu();  
  cout << "Please indicate your choice of operation (m for menu): ";  
  cin >> choice;  
  
  while ((choice != 'e')&& (choice != 'E'))  
    {  
      switch(choice)  
	{  
	case 'l':  
	case 'L': loadStudentList() ; break;  
        case 'd':
	case 'D': displayData(); break;
	case 'p':  
	case 'P': processRecords();break;  
	case 'c':  
	case 'C': changeScores();break;  
	case 'a':  
	case 'A': addNewStudent();break;  
	case 's':  
	case 'S': searchAStudent();break;  
	case 'r':  
	case 'R': printRecords();break;  
	case 'm':  
	case 'M': showmenu();break;	default : cout << "Not a valid choice" << endl;  
	}  
      cin.ignore(200, '\n'); cin.clear(); //clear out all input  
      cout << "Please indicate your choice of operation (m for menu): ";  
      cin >> choice;  
    }  
  saveInfo();  
  cout << "Thank you, good-bye! \n";  
}  
  