#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Hash.h"
#include <vector>

using namespace std;


struct store_randStudent{
  char* first_name;
  char* last_name;
  int rand_ID;
  float rand_GPA;
};

void randomStudent(vector<store_randStudent*>*);
void randomStudentLast(vector<store_randStudent*>*);
void randomID_GPA(vector<store_randStudent*>*);

vector<store_randStudent*>* list = new vector<store_randStudent*>();

void randomStudent(vector<store_randStudent*>* paramlist) {

  // read first name text file
  char randomFirstName[50] = {'\0'};

  ifstream firstNameFile ("genFirstName.txt");

  firstNameFile >> randomFirstName;
  while (!firstNameFile.eof() ) {
    store_randStudent* new_student = new store_randStudent();
    new_student->first_name = new char[80];

    char* first_name = new char[50];

    strcpy (first_name, randomFirstName);
    new_student->first_name = first_name;
    paramlist->push_back(new_student);
    firstNameFile >> randomFirstName;
  }
}

void randomStudentLast(vector<store_randStudent*>* paramlist) {
  
  char randomLastName[50] = {'\0'};
  ifstream lastNameFile ("genLastName.txt");
  int i = 0;
  lastNameFile >> randomLastName;
  while (!lastNameFile.eof() ) {
    char* last_name = new char[50];
    strcpy (last_name, randomLastName);
    
    paramlist->at(i)->last_name = last_name;
    cout << paramlist->at(i)->last_name << i << "param" << endl;
    lastNameFile >> randomLastName;
    
    i++;
  }
}
void randomID_GPA(vector<store_randStudent*>* paramlist) {
  for(int i = 0; i < list->size(); i++) {
    int randID = i + 1000;
    float rand_num = 0.00;
    paramlist->at(i)->rand_ID = randID;
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //srand(unsigned(time(0)));
    rand_num = rand() % 300 + 100;
    rand_num = rand_num /100;
    cout << "-D- " << rand_num << endl;
    paramlist->at(i)->rand_GPA = rand_num;

    cout << paramlist->at(i)->first_name << " " << paramlist->at(i)->last_name << " " << paramlist->at(i)->rand_ID << " " << paramlist->at(i)->rand_GPA << " || " << endl;
    

  }
}
  
void print_student(vector<store_randStudent*>* paramlist) {
  cout << "ORDER: FIRST LAST, ID, GPA \n" << endl; 
  
  for(int i = 0; i < list->size(); i++) {
    
    //prints first, last, & id
    
    cout << list->at(i)->first_name << " " << list->at(i)->last_name << ", " << ", "<< endl;
  }
}



int main() {
  randomStudent(list);
  randomStudentLast(list);
  randomID_GPA(list);
  
  cout << "size:" << list->size() << endl;
  for (int i=0; i < list->size(); i++) {
    cout << "size: " << i << list->at(i)->first_name << endl;

  }
  print_student(list); 
 
  
  int index;
  char* input = new char[80];  
  int id;
  float gpa;
  Hash hashObject;

  int student_amount;
  //char randomFirstName[50];
  //ifstream firstNameFile ("genFirstName.txt");

  //while (! firstNameFile.eof() ) {
  // firstNameFile >> randomFirstName;
  // cout << randomFirstName << endl;
  //}
  
  //firstNameFile.close();
  //return 0;
  
  bool exit = 0;

  int j = 0;
  int current_amount = 0;
 
  while(exit == 0) {
    cout << "Executable Actions: STUDENTGEN, ADD, PRINT, DELETE, QUIT" << endl;
    cin >> input;
    if(input[0] == 'S' && input[1] == 'T' && input[2] == 'U' && input[3] == 'D' && input[4] == 'E' && input[5] == 'N' && input[6] == 'T' && input[7] == 'G' && input[8] == 'E' && input[9] == 'N' && input[10] == '\0') {
      cout << "How Many Students?" << endl;
      cin >> student_amount;
      current_amount = current_amount + student_amount;
      while (j < current_amount) {
	hashObject.AddInfo(list->at(j)->first_name, list->at(j)->last_name, list->at(j)->rand_ID, list->at(j)->rand_GPA);
	j++;
      }   
    }
    else if(input[0] == 'A' && input[1] == 'D' && input[2] == 'D' && input[3] == '\0') {
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

//void randomStudent() {
/*struct store_randStudent{
  char* first_name;
  char* last_name;
};

store_randStudent* randArray[100];

void randomStudent(char* first_name, char* last_name) {
  //store_randStudent* randArray[100];
  
  char randomFirstName;
  ifstream firstNameFile ("genFirstName.txt");
  
  int i = 0;
  while (! firstNameFile.eof() ) {
    //char randomFirstName = new char[80];
    firstNameFile.get(randomFirstName);
    //randArray[i]->first_name = randomFirstName;
    cout << randArray[i]->first_name << endl;
    i++;
    cout << i << endl;
  }
  firstNameFile.close();
  //return 0;
}*/
