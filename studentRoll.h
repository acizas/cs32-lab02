#ifndef STUDENTROLL_H
#define STUDENTROLL_H 

#include <string>
#include "student.h"

class StudentRoll {

 public:
  StudentRoll();                                      // Constructor
  void insertAtTail(const Student &s);                // Add a New Student
  std::string toString() const;                       // Outputs Students as a String

  StudentRoll(const StudentRoll &orig);               // Copy Constructor
  ~StudentRoll();                                     // Destructor
  StudentRoll & operator=(const StudentRoll &right);  // Overloaded Copy Constructor

 private:
  struct Node {
    Student *s;
    Node *next;
  };
  Node *head;
  Node *tail;
};


#endif
