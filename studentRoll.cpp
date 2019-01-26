#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *temp = new Node;
  temp->s=s;
  temp->next=NULL;
  if(head==NULL) {
    head=temp;
    tail=temp;
    temp=NULL;
  }
  
  else {
    tail->next=temp;
    tail=temp; 
  }
}

std::string StudentRoll::toString() const {
  std::string studentRollString = "[";
  Node *temp = new Node;
  temp = head;
  while(temp != NULL){
    studentRollString += temp->s;
    studentRollString += ",";
    temp = temp->next;
  }
  studentRollString += "]";
  return studentRollString; 
}

StudentRoll::StudentRoll(const StudentRoll &orig) {

  Node oneStudent = origin.head;
  while (oneStudent != NULL) {
    insertAtTail(oneStudent->s);
    oneStudent = oneStudent->next;
  }
}

StudentRoll::~StudentRoll() {
  Node *pointer, *nextNode;
  while (pointer) {
    nextNode = pointer->next;
    delete pointer;
    pointer = nextNode;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

  Node *listCopy, *nextNode;
  listCopy = head;
  nextNode = NULL;
  while(listCopy){
    nextNode = listCopy->next;
    delete listCopy;
    listCopy = nextNode;
  }
  Node *current = new Node;
  current = right.head;
  current->next = NULL;

  temp = right.head->next;
  while (temp) {
    current->next = new Node;
    current->next = temp;
    current = current->next;
    current->next = NULL;
    temp = right.head->next;
  }
  
  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}
