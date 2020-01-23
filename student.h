#ifndef STUDENT_H
#define STUDENT_H 

#include <string>

class Student {

 public:
  Student(const char * const name, int perm);

  int getPerm() const;                        // Returns Perm Number
  const char * const getName() const;         // Returns Name

  void setPerm(const int perm);               // Sets Perm Number to Input
  void setName(const char * const name);      // Sets Name to Input

  Student(const Student &orig);               // Copy Constructor
  ~Student();                                 // Destructor
  Student & operator=(const Student &right);  // Overloaded Copy Constructor

  std::string toString() const;               // Outputs as String

 private:
  int perm;
  char *name; // allocated on heap
};

#endif





