#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cstring>

using namespace std;
class Hash {
  private:
  static const int tableSize = 10;

struct studentInfo {
  char* firstName;
  char* lastName;
  int id;
  float gpa;
  studentInfo* next;
};

  studentInfo* HashTable[tableSize];

public:
  Hash();
  int Hash_index(int key);
  void AddInfo(char* firstName, char* lastName, int id, float gpa);
  int NumberOfItemsInIndex(int index);
  void PrintTable();
  void PrintItemsInIndex(int index);
  void PrintStudentInfo();
  void RemoveItem(int id);
};

#endif
