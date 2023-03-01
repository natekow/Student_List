#include <iostream>  
#include <fstream>  
#include <cstring>  
#include <string> 
#include <iomanip> 
#ifndef STUDENT
#define STUDENT 
using namespace std;  


class student{

 public:
  
  const static int nameLength = 20;   
  const static int idLength = 9; 
  const static int maxHW = 11;
const static int maxTest = 4;
  
 private:
  char name[nameLength];
  string id;  // id stored as string
  float teTotal;  
  float hwTotal; 
  char lTotal; 
  float overallTotal;
  float hworkScores[maxHW],testScores[maxTest];  
 
  
 public:
    
    
  void setName(char n[])   
   {
      strcpy(name, n); 
    }
  
  void setId(string n ) 
    {
      id =  n; // can be assigned
    }
  
  void setHW(float scores[], int size)
    {
      for (int i = 0; i < maxHW; i++)
	hworkScores[i] = scores[i];
    }
	  
    void setTest(float scores[], int size)
    {
      for (int i = 0; i < maxTest; i++)
	testScores[i] = scores[i];
    }
  
  string getId() 
    {
      return id;
    }
  
  char* getName() 
    {
      return name;
    }

  void writeStudent(ostream& outfile)  
    {
      char space = ' ';
      outfile << name << space << id << space;
      for (int i = 0; i < maxHW; i++)
        outfile << hworkScores[i] << space;
      for (int j=0; j<maxTest;j++)
	outfile << testScores[j] << space;
    } 
   void processRecord()
{
hwTotal=0;
teTotal=0;
overallTotal=0;
     bool error= false;
     

  for (int i=0;i<10;i++)
    {
            if ((hworkScores[i] < 0) || (hworkScores[i] > 100))
        { error = true; }  
	else
hwTotal+=hworkScores[i];
    }
	hwTotal/=20;
 	 if (error)
hwTotal=-1;

//---   ---   ---   ---   ---
     bool Terror= false;
  for (int i=0;i<4;i++)
    {
            if ((testScores[i] < 0) || (testScores[i] > 100))
        { error = true; }  
teTotal+=testScores[i];
    }
teTotal+=testScores[3];
	teTotal/=10;
 	 if (Terror)
teTotal=-1;
//---   ---   ---   ---   ---
if ((teTotal==-1) || (hwTotal==-1))
overallTotal= -1;
else
overallTotal=teTotal+hwTotal; 

//---   ---   ---   ---   ---
if (overallTotal==-1){
lTotal='Z';
}

   else if (overallTotal < 60){
lTotal='F';
}
else if (overallTotal < 70){
lTotal='D';
  }
 else  if (overallTotal < 80){
lTotal='C';
  }
  else if (overallTotal < 90){
lTotal='B';
  }
  else{
lTotal='A';
 }
    


}
void printRecord(ostream& outfile)
{
        outfile<<setw(15)<< name << setw(10)<< id
		<<setw(10)<<hwTotal
		<<setw(10)<<teTotal
		<<setw(10)<<overallTotal
		<<setw(10)<<lTotal 
	<<endl;
}
};
#endif