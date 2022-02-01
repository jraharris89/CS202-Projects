/* Jonathon Harris - Project 3 - Monster bash
 * This header contains all the overloaded operator functions
 * for my string class. String class has a char * for the input,
 * and an integer size, representing the size of the string.
 */

#include<iostream>
#include<cstring>
#include<cctype>
#include<ctime>
#include<stdlib.h>
#include<chrono>
#include<thread>
using namespace std;
#ifndef STRING_H 
#define STRING_H 

class String
{
    public:
        String();
        String(char *);
        String(const String &copy);
        friend String operator+(const char *, const String &) ;
        friend String operator+(const String &, const char *) ;
        friend String operator+(const String &,const String &) ;
        //LESS THAN
        friend bool operator<(const char *, const String &);
        friend bool operator<(const String & ,const char *);
        friend bool operator<(const String &, const String & );
        //GREATER THAN
        friend bool operator>(const char *, const String &);
        friend bool operator>(const String & ,const char *);
        friend bool operator>(const String &, const String &);
        //LESS THAN OR EQUAL
        friend bool operator<=(const char *, const String &);
        friend bool operator<=(const String & ,const char *);
        friend bool operator<=(const String &, const String &);
        //LESS THAN OR EQUAL
        friend bool operator>=(const char *, const String &);
        friend bool operator>=(const String & ,const char *);
        friend bool operator>=(const String &, const String &);
        //NOT EQUAL
        friend bool operator!=(const char *, const String &);
        friend bool operator!=(const String & ,const char *);
        friend bool operator!=(const String &, const String &);
        // IF EQUAL 
        friend bool operator==(const char *, const String &);
        friend bool operator==(const String & ,const char *);
        friend bool operator==(const String &, const String &);

        friend ostream &operator<<(ostream &, const String &);
        friend istream &operator>>(istream &, String &);
        const char & operator[](int) const; 
        String & operator=(const String &);
        String & operator+=(const String &);
        //friend strcmp
        ~String();

    private:
        char *input;
        int size;
};

#endif


/*
 * int get_height(Node * root)
 *{
 *      return root == NULL ? 0 : 1 + max(get_height(root->get_left()), get_height(root->get_right()));
 *}
   bool is_balanced(Node *root)
   {
        if(root == NULL)
            return true;

        int left = get_height(root->get_left());
        int right= get_height(root->get_right());
        return abs(left - right) <= 1 && is_balanced(root->get_left()) && is_balanced(root->get_right()))
   }
*/
