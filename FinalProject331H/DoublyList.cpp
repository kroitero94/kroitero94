#include "DoublyList.h"

/***************************************************************/
/* Programmer: Bar Kroitoro                                    */
/* Date: December 19th, 2022                                      */
/* Purpose: Linked  DoublyList class  -   implementation file  */
/* Input: there are inputs made by the user after he select an operation in main.cpp.                                                                      */
/* Output: there are functions which output based on user selection in main.cpp*/
/*                                                             */
/***************************************************************/

//Constructor
template <class T>
DoublyList<T> :: DoublyList ()
{
  head = NULL;
  tail = NULL;
  iteratorForward = head;
  iteratorBackward = tail;
  length = 0;
}

//Destructor
template <class T>
DoublyList<T> :: ~DoublyList ()
{
  destroy();
}

template <class T>
DoublyList<T> :: DoublyList (const DoublyList<T> &other)
{
  copy(other);
}

//Overloading with operator =.
template <class T>
const DoublyList<T> & DoublyList<T> :: operator= (const DoublyList<T> &other)
{
  if (this != &other)
  {
    destroy();
    copy(other);
  }
  return *this;
}

//Return the length.
template <class T>
int DoublyList<T> :: getLength ()
{
  return length;
}

//Function that checking if the list is empty.
template <class T>
bool DoublyList<T> :: isEmpty()
{
  if(head == NULL)
  {
    cout << "\n *** THE LIST IS EMPTY *** \n\n";
    return true;
  }
  else
  {
    cout << "\n *** THE LIST IS NOT EMPTY *** \n\n";
    return false;
  }
}

//Copy constructor that copying the old list to the new one.
template <class T>
void DoublyList<T> :: copy(const DoublyList<T> &other)
{
   if (other.head == NULL)
  {
    head = NULL;
  }
  else
  {
    node<T> *myNode = new node<T>;
    myNode->prev = NULL;
    myNode->info = other.head->info;
    node<T> *next = other.head->next;
    head = myNode;

    while (next != NULL)
    {
      myNode->next = new node<T>;
      myNode->next->info = next->info;
      myNode->next->prev = myNode;
      myNode = myNode->next;
      next = next->next;
    }
    myNode->next=NULL;
  }
     
}

//Function that deleting an entire list.
template <class T>
void DoublyList<T> :: destroy()
{
    node<T>* p;
  
  while (head != NULL)
  {
    p = head;
    head = head->next;
    delete p;
    p = NULL;
  }
}

//Function that searching for an item in the list with recursion.
// template <class T>
// bool DoublyList<T> :: searchItem ( node<T> *p, T item )
// {
//   if (p == NULL)
//     return false;
//   else if (p->info == item)
//     return true;
//   else
//     searchItem(p->next,item);
// }

//A function that searching the user input in the list.
template <class T>
bool DoublyList<T> :: clientSearch(T item)
{
  node<T> *current = head;
  if (current == NULL)
  {
    cout << "\nTHE LIST IS EMPTY\n";
    return false;
  }
  else
  {
    while (current != NULL)
    {
      if(current->info == item)
      {
        return true;
      }
      else
      {
        current = current->next;
      }
    }
    return false;
  }
}

//Function that deleting an item from the list.
template <class T>
void DoublyList<T> :: deleteItem (T item)
{
  node<T> *temp;
  node<T> *q = head;
  if (clientSearch(item) == false)
    cout << "ITEM " << item << ", NOT FOUND";
  else if(q->next == NULL)
  {
    delete q;
    cout << "\n" << item << " DELETED FROM THE LIST.\n";
    q = NULL;
    head = NULL;
    tail = NULL;
    length = 0;
  }
  else if(head->info == item)
  {
    temp = head;
    head = head->next;
    delete temp;
    cout << "\n" << item << " DELETED FROM THE LIST.\n";
    head->prev = NULL;
    setTail();
    setIteratorForward();
    setIteratorBackward();
    length--;
  }
  else
  {
    while(q->info != item && q != NULL)
    {
      temp = q;
      q = q->next;
    }
    if(q->next == NULL)
    {
      temp->next = q->next;
      delete q;
      cout << "\n" << item << " DELETED FROM THE LIST.\n";
      setTail();
      setIteratorForward();
      setIteratorBackward();
    }
    else
    {
    temp->next = q->next;
    q->next->prev = temp;
    delete q;
    cout << "\n" << item << " DELETED FROM THE LIST.\n";
    q = NULL;
    setTail();
    setIteratorForward();
    setIteratorBackward();
    }
  length--;
  }
  
}

//Function that insert item at the front of the list.
template <class T>
void DoublyList<T> :: insertItemFront ( T item)
{
  node<T> *p = new node<T>;
  if (head == NULL)
  {
    p->info = item;
    p->prev = NULL;
    p->next = NULL;
    head = p;
    tail = p;
    // setIteratorForward();
    // setIteratorBackward();
    length++;
  }
  else
  {
    p->info = item;
    p->prev = NULL;
    p->next = head;
    head->prev = p;
    head = p;
    setTail();
    // setIteratorForward();
    // setIteratorBackward();
    length++;
  }
}

//Function that insert item at the end of the list.
template <class T>
void DoublyList<T> :: insertItemEnd ( T item)
{
  node<T> *q = new node<T>;
  node<T> *p = head;
  if (p == NULL)
  {
    q->info = item;
    q->prev = NULL;
    q->next = NULL;
    head = q;
    tail = q;
    setIteratorForward();
    setIteratorBackward();
    length++;
  }
  else
  {
    while (p->next != NULL)
    {
      p = p->next;
    }
    q->info = item;
    p->next = q;
    q->prev = p;
    q->next = NULL;
    tail = q;
    setIteratorForward();
    setIteratorBackward();
    length++;
  }
}

//Function that printing the whole list (Just for experimental checkings).
template <class T>
void DoublyList<T> :: printDoublyList()
{
  node<T>* current = head;
  if (current == NULL)
    cout << "\nTHE LIST IS EMPTY\n" << endl;
  else
  {
    while (current != NULL)
    {
      cout << current->info << " ";
      current = current->next;
    }
  }
}

//functions that set the iterators.
template <class T>
void DoublyList<T> :: setIteratorForward()
{
  iteratorForward = head;
}

template <class T>
void DoublyList<T> :: setIteratorBackward()
{
  iteratorBackward = tail;
}

//function that walks the iterator from the beginning to the end.
template <class T>
void DoublyList<T> :: walkIteratorForward()
{
    iteratorForward = iteratorForward->next;
}

//function that walk the iterator backwards from the end up until the beginning.
template <class T>
void DoublyList<T> :: walkIteratorBackward()
{
    iteratorBackward = iteratorBackward->prev;
}

//Function that sets the tail to be updated each time there is an alteration.
template <class T>
void DoublyList<T>:: setTail()
{
  node<T>* p = head;
  while (p->next != NULL)
  {
      p = p->next;
  }
  tail = p;
}
template <class T>
bool DoublyList<T> :: iteratorForIsEmpty()
{
  return iteratorForward == NULL;
}
template <class T>
bool DoublyList<T> :: iteratorBackIsEmpty()
{
  return iteratorBackward == NULL;
}

template <class T>
T DoublyList<T> :: getIteratorForInfo()
{
  return iteratorForward->info;
}
template <class T>
T DoublyList<T> :: getIteratorBackInfo()
{
  return iteratorBackward->info;
}
template <class T>
bool DoublyList<T>::iteratorEnd()
{
  node<T>* p = head;
  while (p != NULL)
  {
      p = p->next;
  }
  return true;
}
template <class T>
node<T>* DoublyList<T>::iteratorBack()
{
  return iteratorBackward;
}
template <class T>
node<T>* DoublyList<T>::iteratorFor()
{
  return iteratorForward;
}
