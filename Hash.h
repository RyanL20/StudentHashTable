#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cstring>

using namespace std;
class Hash {
  private:
  static const int tableSize = 10;

struct studentInfo {
  string firstName;
  string lastName;
  int id;
  float gpa;
  studentInfo* next;
};

  studentInfo* HashTable[tableSize];

public:
  Hash();
  int Hash_index(string key);
  void AddInfo(string firstName, string lastName, int id, float gpa);
  int NumberOfItemsInIndex(int index);
  void PrintTable();
  void PrintItemsInIndex(int index);
  void PrintStudentInfo();
  void FindDrink(string name);
  void RemoveItem(string name);
};

#endif
