#include <iostream>
#include "LargeInt.h"
using namespace std;

/***************************************************************/
/* Programmer: Bar Kroitoro                                    */
/* Date: December 19th, 2022                                     */
/* Purpose: Linked  DoublyList class  -   implementation file  */
/* Input: User's choise which operation to apply.              */
/* Output: Menu of operations and the output for each one of them.*/
/*                                                             */
/***************************************************************/

void printSelection ();



int main() {

    LargeInt num1;
    LargeInt num2;
    LargeInt num3;

    cout<<"Enter the first large integer : ";
    cin >> num1;

    cout<<"\nEnter the second large integer : ";
    cin >> num2;


    if ( num1 > num2 )
      cout <<"\n\nThe first large integer is grater\n\n";
    else if ( num1 == num2 )
      cout <<"\n\nThe two large integers are the same\n\n";
    else if ( num1 < num2 )
      cout <<"\n\nThe first large integer is smaller\n\n";

//    cout << num1 << " + " << num2 << "\n\n";
    
    cout << "num1 has " << num1.getLargeIntLength() << " nodes\n\n";
    cout << "num2 has " << num2.getLargeIntLength() << " nodes\n\n";

    
//    num3 = num2;
//    cout << "num3 has " << num3.getLargeIntLength() << " nodes\n\n";
//    cout << "Number 3 : "<<num3 << "\n\n";
//    cout<<"\n\n"<<num1 << " + " << num2 <<" = "<<  (num1+num2) << "\n\n";
    
//    cout<<"\n\n"<<num1 << " - " << num2 <<" = " <<  (num1-num2);
//
//    cout<<"\n\n"<<num1 << " * " << num2 <<" = "<<  (num1*num2);
//
//    cout<<"\n\n"<<num1 << " / " << num2 <<" = "<<  (num1/num2);
//
    cout<<"\n\n"<<num1 << " % " << num2 <<" = "<<  (num1%num2);


    
    
    
    
    
    
    
    
/* **** Part 1 **** */
    
    
    
// printSelection();
// char userChoise;
// cin >> userChoise;
// DoublyList<int> L1;
// int item;
  
// while (userChoise != 'Q')
// {
//     switch (userChoise)
//     {
//         case 'A':
//         {
//           cout << "\nTYPE IN A NUMBER YOU WANT TO DELETE FROM THE LIST: ";
//           cin >> item;
//           if (!cin >> item)
//           {
//             cin.clear();
//             cin.ignore();
//             cout << "INVALID INPUT, TRY AGAIN.\n";
//             break;
//           }
//           L1.deleteItem(item);
//           break;
//         }
//         case 'B':
//         {
//           cout << "\nTYPE IN A NUMBER YOU WANT TO INSERT AT THE FORNT OF THE LIST: ";
//           cin >> item;
//           if (!cin >> item)
//           {
//             cin.clear();
//             cin.ignore();
//             cout << "INVALID INPUT, TRY AGAIN.\n";
//             break;
//           }
//           L1.insertItemFront(item);
//           break;
//         }
//         case 'C':
//         {
//           cout << "\nTYPE IN A NUMBER YOU WANT TO INSERT AT THE BACK PF THE LIST: ";
//           cin >> item;
//           if (!cin >> item)
//           {
//             cin.clear();
//             cin.ignore();
//             cout << "INVALID INPUT, TRY AGAIN.\n";
//             break;
//           }
//           L1.insertItemEnd(item);
//           break;
//         }
//         case 'D':
//         {
//           cout << L1.getLength();
//           break;
//         }
//         case 'E':
//         {
//           cout << "\nTYPE IN THE NUMBER YOU WANT TO CHECK: ";
//           cin >> item;
//           if (!cin >> item)
//           {
//             cin.clear();
//             cin.ignore();
//             cout << "INVALID INPUT, TRY AGAIN.\n";
//             break;
//           }
//           if(L1.clientSearch(item))
//             cout << "\nTHE NUMBER " << item << " IS IN THE LIST\n";
//           else
//             cout << "\nTHE NUMBER " << item << " IS NOT IN THE LIST\n";
//           break;
//         }
//         case 'F':
//         {
//           cout << L1.isEmpty();
//           break;
//         }
//         // case 'P':
//         // {
//         //   cout << "******\tTHE LIST IS:    ******\n\n";
//         //   L1.printDoublyList();
//         //   break;
//         // }
//         case 'G':
//         {
//           DoublyList<int> L2(L1);
//           cout << "\n\nYOUR ORIGINAL LIST COPIED SUCCESSFULLY\n\n";
//           cout << "--------THE NEW LIST IS:--------\n\n";
//           L2.printDoublyList();
//           break;
//         }
//         case 'H':
//         {
//           L1.setIteratorForward();
//           if( L1.iteratorForIsEmpty())
//             cout << "List is empty" << endl;
//           while ( !L1.iteratorForIsEmpty ())
//           {
//             int item;
//             item = L1.getIteratorForInfo();
//             cout << item << " ";
//             L1.walkIteratorForward();
//           }
//           break;
//         }
//         case 'I':
//         {
//           L1.setIteratorBackward();
//           if( L1.iteratorBackIsEmpty())
//             cout << "List is empty" << endl;
//           while (!L1.iteratorBackIsEmpty())
//           {
//             int item;
//             item = L1.getIteratorBackInfo();
//             cout << item << " ";
//             L1.walkIteratorBackward();
//           }
//           break;
//         }
//         default:
//         {
//           cout << "\nINVALID CHOISE\n";
//           break;
//         }
//       }
//     cout << "\n\n";
//     printSelection();
//     cin >> userChoise;
//   }
// cout << "\nPROGRAM TERMINATED\n";
  return 0;
}

void printSelection ()
{
  cout << "\n\nTYPE A TRANACTION THAT YOU WOULD LIKE TO USE:\n\n";
  cout << "A) DELETE A NUMBER FROM THE LIST\n";
  cout << "B) INSERT A NUMBER AT THE FRONT OF THE LIST\n";
  cout << "C) INSERNT A NUMBER AT THE END OF THE LIST\n";
  cout << "D) GET THE LENGTH OF THE LIST\n";
  cout << "E) SEARCH TO CHECK IF THE NUMBER IS IN THE LIST\n";
  cout << "F) CHECK IF THE LIST IS EMPTY\n";
  cout << "G) TO MAKE A NEW COPY OF YOUR LIST\n";
  // cout << "P) = PRINT THE LIST\n";
  cout << "H) ITERATE FORWARD\n";
  cout << "I) ITERATE BACKWARD\n";
  cout << "Q) TO END THE PROGRAM\n\n";
}
