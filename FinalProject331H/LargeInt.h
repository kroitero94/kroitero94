#include <string>
#include <fstream>
#include <vector>
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
    
      //Constructor
      inline LargeInt() {str = "";}
    
      // Overload the == operator
      inline friend bool operator == (LargeInt &q,LargeInt &p)
      {
          q.num.setIteratorForward();
          p.num.setIteratorForward();
            bool status = true;
          
            if(q.num.getLength() != p.num.getLength())
              return status = false;
            else
            {
              int i = 0;
              while ((status) && i < p.num.getLength())
              {
                  if(q.num.getIteratorForInfo() != p.num.getIteratorForInfo())
                  {
                      status = false;
                      cout << "They are not equal";
                  }
                  p.num.walkIteratorForward();
                  q.num.walkIteratorForward();
                  i++;
              }
            }
            return status;
      };
    
      // Overload the < operator
      inline friend bool operator < (LargeInt &p, LargeInt &q)
      {
          bool status = false;
          q.num.setIteratorBackward();
          p.num.setIteratorBackward();
          int x = p.num.getIteratorBackInfo();
          int y =q.num.getIteratorBackInfo();
          
          if (p.num.getLength() < q.num.getLength())
            return status = true;
          else if(p.num.getLength() > q.num.getLength())
            return status = false;
          else
          {
              while (p.num.iteratorBack() != NULL)
              {
                  if(x == y)
                  {
                      p.num.walkIteratorBackward();
                      q.num.walkIteratorBackward();
                  }
                  else if(x < y)
                    return status = true;
                  else return status = false;
              }
          }
          return status;
      }
    
      // Overload the <= operator
      inline friend bool operator <= (LargeInt &p, LargeInt &q)
      {
          bool status = true;
          q.num.setIteratorBackward();
          p.num.setIteratorBackward();
          int x = p.num.getIteratorBackInfo();
          int y =q.num.getIteratorBackInfo();
          
          if (p.num.getLength() < q.num.getLength())
            return status = true;
          else if(p.num.getLength() > q.num.getLength())
            return status = false;
          else
          {
              while (p.num.iteratorBack() != NULL)
              {
                  if(x == y)
                  {
                      p.num.walkIteratorBackward();
                      q.num.walkIteratorBackward();
                  }
                  else if(x < y)
                    return status = true;
                  else return status = false;
              }
          }
          return status;
      }
    
      // Overload the > operator
      inline friend bool operator > (LargeInt &p, LargeInt &q)
      {
          bool status = false;
          q.num.setIteratorBackward();
          p.num.setIteratorBackward();
          int x = p.num.getIteratorBackInfo();
          int y =q.num.getIteratorBackInfo();
          
          if (p.num.getLength() > q.num.getLength())
            return status = true;
          else if(p.num.getLength() < q.num.getLength())
            return status = false;
          else
          {
              while (p.num.iteratorBack() != NULL)
              {
                  if(x == y)
                  {
                      p.num.walkIteratorBackward();
                      q.num.walkIteratorBackward();
                  }
                  else if(x > y)
                    return status = true;
                  else return status = false;
              }
          }
          return status;
      }
      // Overload the >= operator
      inline friend bool operator >= (LargeInt &p, LargeInt &q)
      {
          bool status = true;
          q.num.setIteratorBackward();
          p.num.setIteratorBackward();
          int x = p.num.getIteratorBackInfo();
          int y =q.num.getIteratorBackInfo();
          
          if (p.num.getLength() > q.num.getLength())
              return status = true;
          else if(p.num.getLength() < q.num.getLength())
              return status = false;
          else
          {
              while (p.num.iteratorBack() != NULL)
              {
                  if(x == y)
                  {
                      p.num.walkIteratorBackward();
                      q.num.walkIteratorBackward();
                  }
                  else if(x > y)
                      return status = true;
                  else return status = false;
              }
          }
          return status;
      }
      // Overload the << operator
      inline friend istream & operator >> (istream &IN , LargeInt &p)
      {
        IN >> p.str;

        for (int i = 0; i < p.str.length(); i++)
        {
           int val = int(p.str[i] - 48);
           p.num.insertItemFront(val);
        }
        return IN;
      }

      // Overload the >> operator
      inline friend ostream & operator << (ostream &OUT, LargeInt &p)
      {
          p.num.setIteratorBackward();
//        for (int i = 0; i < p.num.getLength(); i++)
          while (p.num.iteratorBack() != NULL)
          {
            OUT << p.num.getIteratorBackInfo();
            p.num.walkIteratorBackward();
          }
        return OUT;
      }

      // Overload the + operator
      inline friend LargeInt & operator+ (LargeInt &p, LargeInt &q)
      {
            p.num.setIteratorForward();
            q.num.setIteratorForward();
            int shorter,longer, sum, difference;
            int carry = 0;
            LargeInt result;
            
            if(p.num.getLength() >= q.num.getLength())
            {
                shorter = q.num.getLength();
                longer = p.num.getLength();
                difference = longer - shorter;
            }
            else
            {
                shorter = p.num.getLength();
                longer = q.num.getLength();
                difference = longer - shorter;
            }
            
            for(int i = 0; i < shorter; i++)
            {
              sum = p.num.getIteratorForInfo() + q.num.getIteratorForInfo() + carry;
              if (sum >= 10)
              {
                  carry = 1;
              }
                
              if(sum < 9)
              {
                if (carry == 0)
                  result.num.insertItemEnd(sum);
                else
                {
                  result.num.insertItemEnd(sum);
                  carry = 0;
                }
              }
              else if (sum == 9)
              {
                  if (carry == 0)
                  {
                      result.num.insertItemEnd(sum);
                  }
              }
              else
              {
                if (carry == 0)
                  result.num.insertItemEnd(sum - 10);
                else if (carry ==1)
                {
                    result.num.insertItemEnd(sum -10);
                    carry = 1;
                }
              }
              p.num.walkIteratorForward();
              q.num.walkIteratorForward();
              
            }
            for (int i = 0; i < difference; i++)
            {
              if(carry == 0)
              {
                if(longer == p.num.getLength())
                {
                    result.num.insertItemEnd(p.num.getIteratorForInfo());
                    p.num.walkIteratorForward();
                }
                else
                {
                    result.num.insertItemEnd(q.num.getIteratorForInfo());
                    q.num.walkIteratorForward();
                }
              }
              else if(carry == 1)
              {
                  if(longer == p.num.getLength())
                  {
                      sum = p.num.getIteratorForInfo()+1;
                      if(sum <= 9)
                      {
                          result.num.insertItemEnd(sum);
                          p.num.walkIteratorForward();
                          carry = 0;
                      }
                      else
                      {
                          result.num.insertItemEnd(sum - 10);
                          p.num.walkIteratorForward();
                          carry = 1;
                      }
                  }
                  else if (longer == q.num.getLength())
                  {
                      sum = q.num.getIteratorForInfo()+1;
                      if(sum <= 9)
                      {
                          result.num.insertItemEnd(sum);
                          q.num.walkIteratorForward();
                          carry = 0;
                      }
                      else
                      {
                          result.num.insertItemEnd(sum - 10);
                          q.num.walkIteratorForward();
                          carry = 1;
                      }
                  }
             }
             else
             {
                result.num.insertItemEnd(q.num.getIteratorForInfo()+1);
                q.num.walkIteratorForward();
                carry = 0;
             }
            }
            
          if(carry == 1) result.num.insertItemEnd(carry);

          cout << "\n\nResult: "<<result << "\n\n*";
            
          return result;
      }
    inline void operator= (LargeInt &p)
    {
        this->num.setIteratorForward();
        p.num.setIteratorForward();
        
        while(p.num.iteratorFor() != NULL)
        {
            int y = p.num.getIteratorForInfo();
            this->num.insertItemEnd(y);
            this->num.walkIteratorForward();
            p.num.walkIteratorForward();
        }
    }

      // Overload the * operator
      inline LargeInt & operator * (LargeInt &q)
    {
        LargeInt result;
        string str_result, a= this->str, b= q.str;
        str_result = multiply(a,b);
        converToLargeInt(str_result,result);
        
        //printing the result.
        cout << result << "\n\n";
        return result;
    }
    
      // Overload the / operator
      inline LargeInt & operator / (LargeInt &q)
      {
          LargeInt result;
          string str_result, a= this->str, b= q.str;
          str_result = longDivision(a,b);
          converToLargeInt(str_result,result);
          
          cout << result << "\n\n";
          return result;
      }
      // Overload the % operator
//      inline friend LargeInt & operator % (LargeInt &p, LargeInt &q)
//      {
//        LargeInt temp = q;
//        p.num.setIteratorForward();
//        q.num.setIteratorForward();
//        p.num.setIteratorBackward();
//        q.num.setIteratorBackward();
//
//          // Initialize result
//          int res = 0;
//
//          // One by one process all digits of 'num'
//          for (int i = 0; i < num.length(); i++)
//              res = (res * 10 + (int)num[i] - '0') % a;
//
//          return res;
//
//      }
      //Returns the length of the Large Int.
      int getLargeIntLength() {return this->num.getLength();}
    
   // Function to return sum of two
   // large numbers given as strings
    inline string sumBig(string a, string b)
   {

       // Compare their lengths
       if (a.length() > b.length())
           swap(a, b);

       // Stores the result
       string str = "";

       // Store the respective lengths
       int n1 = a.length(), n2 = b.length();
       
       //stores the difference between the lenghts
       int diff = n2 - n1;

       // Initialize carry
       int carry = 0;

       // Traverse from end of both strings
       for (int i = n1 - 1; i >= 0; i--) {

           // Compute sum of
           // current digits and carry
           int sum
               = ((a[i] - '0')
                  + (b[i + diff] - '0') + carry);

           // Store the result
           str.push_back(sum % 10 + '0');

           // Update carry
           carry = sum / 10;
       }

       // Add remaining digits of str2[]
       for (int i = n2 - n1 - 1; i >= 0; i--) {

           int sum = ((b[i] - '0') + carry);

           str.push_back(sum % 10 + '0');
           carry = sum / 10;
       }

       // Add remaining carry
       if (carry)
           str.push_back(carry + '0');

       // Reverse resultant string
       reverse(str.begin(), str.end());

       return str;
   }

   // Function return 10's
   // complement of given number
   inline string complement10(string v)
   {
       // Stores the complement
       string complement = "";

       // Calculate 9's complement
       for (int i = 0; i < v.size(); i++) {

           // Subtract every bit from 9
           complement += '9' - v[i] + '0';
       }

       // Add 1 to 9's complement
       // to find 10's complement
       complement = sumBig(complement, "1");
       return complement;
   }

   // Function returns subtraction
   // of two given numbers as strings
   inline string subtract(string a, string b)
   {

       // If second string is larger
       if (a.length() < b.length())
           swap(a, b);

       // Calculate respective lengths
       int l1 = a.length(), l2 = b.length();

       // If lengths aren't equal
       int diffLen = l1 - l2;

       for (int i = 0; i < diffLen; i++) {

           // Insert 0's to the beginning
           // of b to make both the lengths equal
           b = "0" + b;
       }

       // Add (complement of B) and A
       string c = sumBig(a, complement10(b));

       // If length of new string is greater
       // than length of first string,
       // than carry is generated
       if (c.length() > a.length()) {
           string::iterator it;

           // Erase first bit
           it = c.begin();

           c.erase(it);

           // Trim zeros at the beginning
           it = c.begin();

           while (*it == '0')
               c.erase(it);

           return c;
       }

       // If both lengths are equal
       else {
           return complement10(c);
       }
   }
    
      //Insert each character into a node and creating a linked list from the string.
      inline void converToLargeInt(string x, LargeInt & p)
      {
          for (int i = 0; i < x.length(); i++)
          {
             int val = int(x[i] - 48);
             p.num.insertItemFront(val);
          }
      }
    
    inline LargeInt & operator- (LargeInt &q)
    {
        LargeInt result;
        string str_result, a= this->str, b= q.str;
        str_result = subtract(a,b);
        converToLargeInt(str_result,result);
        if(*this < q)
            cout << "-" << result << "\n\n";
        else
            cout << result << "\n\n";
        return result;
    }
    
    // Multiplies str1 and str2, and prints result.
    inline string multiply(string num1, string num2)
    {
        int len1 = num1.size();
        int len2 = num2.size();
        if (len1 == 0 || len2 == 0)
        return "0";
     
        // will keep the result number in vector
        // in reverse order
        vector<int> result(len1 + len2, 0);
     
        // Below two indexes are used to find positions
        // in result.
        int i_n1 = 0;
        int i_n2 = 0;
         
        // Go from right to left in num1
        for (int i=len1-1; i>=0; i--)
        {
            int carry = 0;
            int n1 = num1[i] - '0';
     
            // To shift position to left after every
            // multiplication of a digit in num2
            i_n2 = 0;
             
            // Go from right to left in num2
            for (int j=len2-1; j>=0; j--)
            {
                // Take current digit of second number
                int n2 = num2[j] - '0';
     
                // Multiply with current digit of first number
                // and add result to previously stored result
                // at current position.
                int sum = n1*n2 + result[i_n1 + i_n2] + carry;
     
                // Carry for next iteration
                carry = sum/10;
     
                // Store result
                result[i_n1 + i_n2] = sum % 10;
     
                i_n2++;
            }
     
            // store carry in next cell
            if (carry > 0)
                result[i_n1 + i_n2] += carry;
     
            // To shift position to left after every
            // multiplication of a digit in num1.
            i_n1++;
        }
     
        // ignore '0's from the right
        int i = result.size() - 1;
        while (i>=0 && result[i] == 0)
        i--;
     
        // If all were '0's - means either both or
        // one of num1 or num2 were '0'
        if (i == -1)
        return "0";
     
        // generate the result string
        string s = "";
         
        while (i >= 0)
            s += to_string(result[i--]);
     
        return s;
    }
    
    // A function to perform division of large numbers
    inline string longDivision(string number, string divisor)
    {
        // As result can be very large store it in string
        string result;
        long long d = stoll(divisor, nullptr, 10);
        if (d == 0)
        {
            cout << "UNVALID DIVISOR!!!\n\n";
            exit(0);
        }

        // Find prefix of number that is larger
        // than divisor.
        int idx = 0;
        int temp = number[idx] - '0';
        while (temp < d)
            temp = temp * 10 + (number[++idx] - '0');
     
        // Repeatedly divide divisor with temp. After
        // every division, update temp to include one
        // more digit.
        while (number.size() > idx) {
            // Store result in answer i.e. temp / divisor
            result += (temp / d) + '0';
     
            // Take next digit of number
            temp = (temp % d) * 10 + number[++idx] - '0';
        }
     
        // If divisor is greater than number
        if (result.length() == 0)
            return "0";
     
        // else return ans
        return result;
    }
};
#endif

