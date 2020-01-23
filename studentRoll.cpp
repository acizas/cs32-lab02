#include <string>
#include "studentRoll.h"
#include "student.h"

// Constructor of Linked List
StudentRoll::StudentRoll() {
  head = tail = NULL;
}

// Adds new node to linked list 
void StudentRoll::insertAtTail(const Student &s) {
  if(head==NULL) {
    head = new Node;
    tail = head;
    head->s = new Student(s);
    head->next = NULL;
  }
  
  else {
    tail->next = new Node;
    tail->next->s = new Student(s);
    tail->next->next = NULL;
    tail = tail->next;
  }
}

// Outputs the linked list as a string
std::string StudentRoll::toString() const {
  std::string studentRollString = "[";
  Node *temp = head;
  if (head == NULL) {
    return studentRollString = "[]";
  }
  
  while(temp != NULL){
    studentRollString += temp->s->toString();
    if (temp->next != NULL) {
       studentRollString += ",";
    }
    temp = temp->next;
  }
  
  studentRollString += "]";
  return studentRollString;
  
}

// Copies one linked list and creates another
StudentRoll::StudentRoll(const StudentRoll &orig) {

  head = tail = NULL;
  Node *oneStudent = orig.head;
  while (oneStudent != NULL) {
    insertAtTail(*oneStudent->s);
    oneStudent = oneStudent->next;
  }
}

// Destructor of Linked List
StudentRoll::~StudentRoll() {
  Node *pointer = head;
  while (pointer != NULL) {
    Node *nextNode = pointer->next;
    delete pointer->s;
    delete pointer;
    pointer = nextNode;
  }
  head=tail=NULL;
}

// Overloaded Copy Constructor of Linked List
StudentRoll & StudentRoll::operator =(const StudentRoll &right) {

  if (&right == this) 
    return (*this);

  StudentRoll equivalentRoll(right);
  using std::swap;
  swap(this->head, equivalentRoll.head);
  swap(this->tail, equivalentRoll.tail);
 
  return (*this); 
  
}

