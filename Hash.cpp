#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Hash.h"

using namespace std;

Hash::Hash() {
  for(int i = 0; i < tableSize; i++) {
    HashTable[i] = new studentInfo;
    HashTable[i]->firstName = NULL;
    HashTable[i]->lastName = NULL;
    HashTable[i]->id = 0;
    HashTable[i]->gpa = 0.0;
    HashTable[i]->next = NULL;
  }
}

void Hash::AddInfo(char* firstName, char* lastName, int id, float gpa) {
  int index = Hash_index(id);
  
  if(HashTable[index]->firstName == NULL) {
    HashTable[index]->firstName = firstName;
    HashTable[index]->lastName = lastName;
    HashTable[index]->id = id;
    HashTable[index]->gpa = gpa;
    cout << "HashTable " << HashTable[index]->firstName << endl;
  }
  else {
    studentInfo* Ptr = HashTable[index];
    studentInfo* n = new studentInfo;
    n->firstName = firstName;
    n->lastName = lastName;
    n->id = id;
    n->gpa = gpa;
    n->next = NULL;
    while(Ptr->next != NULL) {
      Ptr = Ptr->next;
    }
    Ptr->next = n;
  }
}

int Hash::NumberOfItemsInIndex(int index) {
  int count = 0;
  
  if(HashTable[index]->firstName == NULL) {
    return count;
  }
  else {
    count++;
    studentInfo* Ptr = HashTable[index];
    while(Ptr->next != NULL) {
      count++;
      Ptr = Ptr->next;
    }
  }
  return count;
}

void Hash::PrintTable() {
  int number;
  for(int i = 0; i < tableSize; i++) {
    number = NumberOfItemsInIndex(i);
    cout << "-----------------\n";
    cout << "index = " << i << endl;
    if(HashTable[i]->firstName == NULL) {
        cout << "First Name: empty" << endl;
    } else {
      cout << "First Name: " << HashTable[i]->firstName << endl;
    }
    if(HashTable[i]->lastName == NULL) {
      cout << "Last Name: empty" << endl;
    } else {
      cout << "Last Name: " << HashTable[i]->lastName << endl;
    }
    cout << "ID: " << HashTable[i]->id << endl;
    cout << "GPA: " << HashTable[i]->gpa << endl;
    cout << "# of Items = " << number << endl;
    cout << "-----------------\n";
   }
}

void Hash::PrintItemsInIndex(int index) {
  studentInfo* Ptr = HashTable[index];
  if(Ptr->firstName == NULL) {
    cout << "index = " << index << " is empty";
  }
  else {
    cout << "index " << index << " contains the following item\n";
    while(Ptr != NULL) {
      cout << "-----------------\n";
      cout << Ptr->firstName << endl;
      cout << Ptr->lastName << endl;
      cout << Ptr->id << endl;
      cout << Ptr->gpa << endl; 
      cout << "-----------------\n";
      Ptr = Ptr->next;
    }
  }
}

void Hash::PrintStudentInfo() {
  int number;
  for(int i = 0; i < tableSize; i++) {
    studentInfo* Ptr = HashTable[i];


    if(Ptr->firstName != NULL) {
      cout << "-----------------\n";
      cout << "index = " << i << endl;
      cout << endl;
      while(Ptr != NULL) {
	number = NumberOfItemsInIndex(i);
	cout << Ptr->firstName << " ";
	cout << Ptr->lastName << ", ";
	cout << Ptr->id << ", ";
	cout << Ptr->gpa << endl;
	Ptr = Ptr->next;
      }
      cout << "-----------------\n";
    }
  }
}

int Hash::Hash_index(int key) {
  int hash = 0;
  int index;
  
  //  for(int i = 0; i < key; i++) {
  //  hash = (hash + (int)key[i]);
   //    cout << "hash = " << hash << endl;
  // }
  
  // index = hash % tableSize;
  
  index = key % tableSize;

  
  return index;
  
}

void Hash::RemoveItem(int id) {
  int index = Hash_index(id);

  studentInfo* delPtr;
  studentInfo* Ptr1;
  studentInfo* Ptr2;

  //Case 0 - bucket is empty
  if(HashTable[index]->id == 0) {
    cout << id << " was not found in the Hash Table Case 0\n";
  }

  //Case 1 - only 1 item contained in bucket and that item has matching id
  else if(HashTable[index]->id == id && HashTable[index]->next == NULL) {  
    cout << HashTable[index]->firstName << " " << HashTable[index]->lastName << ", ID: " << id << " was removed from the Hash Table (Case 1)\n";

    HashTable[index]->firstName = NULL;
    HashTable[index]->lastName = NULL;
    HashTable[index]->id = 0;
    HashTable[index]->gpa = 0.0;

  }
  //Case 2 - match is located in the first item in the bucket but there are more items in the bucket
  else if (HashTable[index]->id == id) {
    cout << HashTable[index]->firstName << " " << HashTable[index]->lastName << ", ID: " << id << " was removed from the Hash Table (Case 2)\n";

    delPtr = HashTable[index];
    HashTable[index] = HashTable[index]->next;
    delete delPtr;

  }
  //Case 3 - bucket contains items but first item is not a match
  else {
    Ptr1 = HashTable[index]->next;
    Ptr2 = HashTable[index];
    while(Ptr1 != NULL && Ptr1->id != id) {
      Ptr2 = Ptr1;
      Ptr1 = Ptr1->next;
    }
    //Case 3.1 - no match
    if(Ptr1 == NULL) {
      cout << id << " was not found in the Hash Table (Case 3.1)\n";
    }
    //Case 3.2 - match is found
    else {
      cout << id << " was removed from the Hash Table (Case 3.2)\n";

      delPtr = Ptr1;
      Ptr1 = Ptr1->next;
      Ptr2->next = Ptr1;

      delete delPtr;
    }
  }
}
