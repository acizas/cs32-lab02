#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return *name;
}

void Student::setPerm(const int permNumber) {
  perm = permNumber;
  return 0;
}

void Student::setName(const char * const name) {
  this->name = new char[strlen(name)+1];
  strcpy(this->name, name);
}


Student::Student(const Student &orig) {
  this->setName(orig.getName());
  this->setPerm(orig.getPerm());
}

Student::~Student() {
  delete name;
  delete perm;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.

  this->setName(Student.getName());
  this->setPerm(Student.getPerm());
  
  return (*this); 

}

std::string Student::toString() const {
  return "[" + getName() + "," + getPerm() + "]";
}
