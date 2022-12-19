/************************************************************************/
/* Programmer: Bar Kroitoro                                             */
/* Date: December 19th, 2022                                             */
/* Purpose:  Unsorted  DoublyList class, linked implementation, header file */
/* Input: none                                                          */
/* Output: none                                                         */
/************************************************************************/

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

template <class T>
struct node
{
  node<T> *next;
  T info;
  node<T> *prev;
};

template <class T>
class DoublyList
{
   private:
      node<T> *head;
      node<T> *tail;
      node<T> *iteratorForward;
      node<T> *iteratorBackward;
      int length;

   public:
      //Constructor
      DoublyList ();
      // destructor
     ~DoublyList ();
      // Copy constructor
      DoublyList ( const DoublyList<T> & );
      // Overload the = operator
      const DoublyList<T> & operator= ( const DoublyList<T> &);
      // Insert an item parameter into the list at the front.
      void insertItemFront ( T );
      // Insert an item parameter into the list at the end.
      void insertItemEnd (T);
      // Delete an item parameter from the list
      void deleteItem (T item );
      // Search for an item parameter, return true if found false
      // otherwise
      // bool searchItem (node<T> *p, T item);

      //Dummy function for the client.
      bool clientSearch (T item);

      // bool searchByUser(T item);

      // Return the length of the list
      int getLength ();

      // Return true if list is empty, false otherwise
      bool isEmpty ();

      // Print all the items in the list
      void printDoublyList();

      //Function that copy the list to another list.
      void copy (const DoublyList<T> &other);

      //Function that delete the list.
      void destroy();
    
      //functions that set the iterators.
      void setIteratorForward();
      void setIteratorBackward();

      //Functions that check if the iterator is empty.
      bool iteratorForIsEmpty();
      bool iteratorBackIsEmpty();
      bool iteratorEnd();

      //functions that walk the iterators.
      void walkIteratorForward();
      void walkIteratorBackward();

      //function that sets the tail to the last node.
      void setTail();

    //Functions that return the iterator info.
      T getIteratorForInfo();
      T getIteratorBackInfo();
};
#endif

