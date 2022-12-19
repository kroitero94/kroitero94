
#include <iostream>
#include <fstream>
#include <string>
#include "DoublyList.cpp"
using namespace std;
/************************************************************************/
/* Programmer: Bar Kroitoro                                             */
/* Date:  December 19th, 2022                                           */
/* Purpose:  Create a large int from the linked list's nodes            */
/* Input: none                                                          */
/* Output: none                                                         */
/************************************************************************/

#ifndef LARGEINT_H
#define LARGEINT_H

//A+B     operator+ (A,B)      A.operator+(B)
//cin >> A      operator>>(istream, A)

class LargeInt
{
  private:
      DoublyList<int> num;
      string str;
  public:
      // Overload the == operator
      bool operator == (LargeInt &);
      // Overload the < operator
      bool operator < (LargeInt &);
      // Overload the <= operator
      bool operator <= (LargeInt &);
      // Overload the > operator
      bool operator > (LargeInt &);
      // Overload the >= operator
      bool operator >= (LargeInt &);

      // Overload the << operator
      friend istream & operator >> (istream &IN , LargeInt &p)
      {
        cout << "Insert a very large number: ";
        IN >> p.str;
        cout << "Hello";
        for (int i = 0; i < p.str.length(); i++)
        {
          int val;
          // cout << p.str[i] << " ";
          // val = stoi(p.str[i]);
          // p.num.insertItemFront(p.str[i]);
          // p.num.walkIteratorForward();
        }
        return IN;
      }

      // Overload the >> operator
      friend ostream & operator << (ostream &OUT, LargeInt &p)
      {
        for (int i = 0; i < p.num.getLength(); i++)
        {
          OUT << p.num.getIteratorForInfo();2433
          p.num.walkIteratorForward();
        }
        return OUT;
      }

      // Overload the + operator
      LargeInt & operator+ (LargeInt &);
      // Overload the - operator
      LargeInt & operator - (LargeInt &);
      // Overload the * operator
      LargeInt & operator * (LargeInt &);
      // Overload the / operator
      LargeInt & operator / (LargeInt &);
      // Overload the % operator
      LargeInt & operator % (LargeInt &);
      // void insertItemEnd (int);

};
#endif

