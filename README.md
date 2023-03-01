# Student_List
 
This is a C++ program that stores a list of students and their repective data. The program also uses the data for simple grade calculations.

To compile on linux:
g++ -c studentList.cpp
g++ records.cpp studentList.o

To execute:
./a.out

How to use:
Once the program has been executed a menu of various options will appear on the terminal for the users. 
- The first option L is to load a class list into the program. This will take a file name from the user with existing student info and save it.
- "D" will allow the user to see the list of students that are stored in the class. 
- "P" will process the students' data.
- "C" will change the test scores for a student. This will prompt the user for the desired student ID and then will have the user input all of the users test scores.
- "A" will add a new student to the list. The program will prompt the user to manually enter of the the students data. This includes their name in Last,First format. Then an ID which for the sake of this program is 2 capitalized letters followed by 5 numbers. Following that a prompt for homework scores and the participation score appears. All of these scores (including test scores), will be out of 100 points. So after the user enters 10 homework scoeres and  the particiation score, they will need to enter the 4 test scores. Then the student will be added to the list
- "S" will search for a user that is stored in the class. This is done by the user entering the desired student ID.
- "R" will display each students letter grade. The user will have to enter a file name for the grades to be displayed in.
- "M" is to simpily display all the menu options again.
- "E" is to exit and save. The user will have to enter a file name to save the current class list in and then will terminate the program.
