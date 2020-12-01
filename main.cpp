#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Hash.h"

using namespace std;

int main() {
  //int index;
  char* input = new char[80];  
  int id;
  float gpa;
  Hash hashObject;

  
  bool exit = 0;
  while(exit == 0) {
    cout << "Executable Actions: STUDENTGEN, ADD, PRINT, DELETE, QUIT" << endl;
    cin >> input;
    //if(input == "STUDENTGEN") {}
    if(input[0] == 'A' && input[1] == 'D' && input[2] == 'D' && input[3] == '\0') {
      char* firstName = new char[80];
      char* lastName = new char[80];
      cout << "Student First Name: ";
      cin >> firstName;
      cout << "Student Last Name: ";
      cin >>lastName;
      cout << "Student ID: ";
      cin >> id;
      cout << "Student GPA: ";
      cin >> gpa;
      hashObject.AddInfo(firstName, lastName, id, gpa);
    }
    else if (input[0] == 'P' && input[1] == 'R' && input[2] == 'I' && input[3] == 'N' && input[4] == 'T' && input[5] == '\0') { 
      char whichPrint[80] = "";
      cout << "PRINT 'TABLE' OR 'ALL'" << endl;
      cin >> whichPrint;
      if(whichPrint[0] == 'T' && whichPrint[1] == 'A' && whichPrint[2] == 'B' && whichPrint[3] == 'L' && whichPrint[4] == 'E' && whichPrint[5] == '\0') {
	  hashObject.PrintTable();
	}
      else if(whichPrint[0] ==  'A' && whichPrint[1] == 'L' && whichPrint[2] == 'L') {
	  hashObject.PrintStudentInfo();
      }
    }
    else if (input[0] == 'D' && input[1] == 'E' && input[2] == 'L' && input[3] == 'E' && input[4] == 'T' && input[5] == 'E' && input[6] == '\0') {
      cout << "Enter Student ID: ";
      cin >> id;
      hashObject.RemoveItem(id);
    }
    else if (input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T' && input[4] == '\0') {
      cout << "EXITED PROGRAM" << endl;
      exit = 1;
    }
  }
  
}
