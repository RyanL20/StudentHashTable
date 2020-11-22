#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "Hash.h"

using namespace std;

Hash::Hash() {
  for(int i = 0; i < tableSize; i++) {
    HashTable[i] = new studentInfo;
    HashTable[i]->firstName = "empty";
    HashTable[i]->lastName = "empty";
    HashTable[i]->id = 0;
    HashTable[i]->gpa = 0.0;
    HashTable[i]->next = NULL;
  }
}

void Hash::AddInfo(string firstName, string lastName, int id, float gpa) {
  int index = Hash_index(firstName);
  
  if(HashTable[index]->firstName == "empty") {
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
  
  if(HashTable[index]->firstName == "empty") {
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
    cout << HashTable[i]->firstName << endl;
    cout << HashTable[i]->lastName << endl;
    cout << HashTable[i]->id << endl;
    cout << HashTable[i]->gpa << endl;
    cout << "# of Items = " << number << endl;
    cout << "-----------------\n";
  }
}

void Hash::PrintItemsInIndex(int index) {
  studentInfo* Ptr = HashTable[index];
  if(Ptr->firstName == "empty") {
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

void Hash::FindDrink(string firstName) {
  int index = Hash_index(firstName);
  bool foundName = false;
  string lastName;
  studentInfo* Ptr = HashTable[index];
  while(Ptr != NULL) {
    if(Ptr->firstName == firstName) {
      foundName = true;
      lastName = Ptr->lastName;
    }
    Ptr = Ptr->next;
  }
  if(foundName == true) {
    cout << "Last Name = " << lastName << endl;
  }
  else {
    cout << firstName << "'s info was not found in the Hash Table\n";
  }
}

void Hash::RemoveItem(string firstName) {
  int index = Hash_index(firstName);
}

int Hash::Hash_index(string key) {
  int hash = 0;
  int index;
  // index = key.length();
  
  for(int i = 0; i < key.length(); i++) {
    hash = (hash + (int)key[i]);
    cout << "hash = " << hash << endl;
  }
  
  index = hash % tableSize;
  
  return index;
  
}
