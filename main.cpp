#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "Hash.h"

using namespace std;

int main() {
  //int index;
  string name = "";
  Hash hashObject;
  //index = hashObject.Hash("Ryan");
  
  hashObject.AddInfo("Ryan", "Le", 2, 3.34);
  hashObject.AddInfo("John", "Ho", 15, 5.4);
  hashObject.AddInfo("Caitlyn", "Apple Cider", 4, 2.39);
  hashObject.AddInfo("Ha", "Ginger", 9, 15.4);
  hashObject.AddInfo("Tran", "TeaTree", 12, 5.41);
  
  //cout << "hashObject = " <<  HashTable[index] << endl;
  
  //hashObject.PrintItemsInIndex(9);
  
  while(name != "exit") {
    cout << "Search for ";
    cin >> name;
    if(name != "exit") {
      hashObject.FindLastName(name);
    }
  }
  
}
