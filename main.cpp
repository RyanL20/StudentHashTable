#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "Hash.h"

using namespace std;

int main() {
  //int index;
  string input = "";
  string firstName = "";
  string lastName = "";
  int id;
  float gpa;
  Hash hashObject;
  //index = hashObject.Hash("Ryan");
  
  hashObject.AddInfo("Dell", "Le", 2, 3.34);
  hashObject.AddInfo("Dell", "Ho", 15, 5.4);
  /*hashObject.AddInfo("Caitlyn", "Apple Cider", 4, 2.39);
  hashObject.AddInfo("Ha", "Ginger", 9, 15.4);
  hashObject.AddInfo("Tran", "TeaTree", 12, 5.41);
  */
  bool exit = 0;
  while(exit == 0) {
    cout << "Executable Actions: STUDENTGEN, ADD, PRINT, DELETE, QUIT" << endl;
    cin >> input;
    //if(input == "STUDENTGEN") {}
    if(input == "ADD") {
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
    else if(input == "PRINT") {
      //hashObject.PrintTable();
      //hashObject.PrintItemsInIndex(5);
      string whichPrint = "";
      cout << "PRINT 'TABLE' OR 'ALL'" << endl;
      cin >> whichPrint;
      if(whichPrint == "TABLE") {
	  hashObject.PrintTable();
	}
      else if(whichPrint ==  "ALL") {
	  hashObject.PrintStudentInfo();
      }
    }
    else if (input == "DELETE") {
      cout << "Enter Student First Name: ";
      cin >> firstName;
      hashObject.RemoveItem(firstName);
    }
    else if (input == "QUIT") {
      exit = 1;
    }
  }
  
}
