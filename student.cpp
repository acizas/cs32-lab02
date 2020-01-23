#include "student.h"
#include <string>
#include <cstring>

// Constructor of Student
Student::Student(const char * const name, int perm) {
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
  this->setPerm(perm);
}

// Returns Perm Number
int Student::getPerm() const {
  return perm;
}

// Returns Name
const char * const Student::getName() const {
  return name;
}

// Sets Perm Number to Input
void Student::setPerm(const int permNumber) {
  perm = permNumber;
  return;
}

// Sets Name to Input
void Student::setName(const char * const name) {
 
  strcpy(this->name, name);
  
}

// Copy Copy Constructor of Student
Student::Student(const Student &orig) {
  
  this->name = new char[strlen(orig.getName())+1];
  strcpy(this->name,orig.getName());
  this->setPerm(orig.getPerm());
  
}

// Destructor of Student
Student::~Student() {
  
  delete[] name;

}

// Overloaded Copy Constructor of Student
Student & Student::operator=(const Student &right) {

  if (&right == this) 
    return (*this);

  this->setName(right.getName());
  this->setPerm(right.getPerm());
  
  return (*this); 

}

// Outputs Student Name and Perm Number to String
std::string Student::toString() const {
  std::string myName = getName();
  std::string myPerm = std::to_string(getPerm());
  return "[" + myName + "," + myPerm + "]";
}

