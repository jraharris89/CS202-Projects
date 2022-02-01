/*Jonathon Harris- CS202- Project 3 Monster bash
 * This file contains my definitions for my overloaded
 * string class. A string has a char * for the input and 
 * a size representing the size of the string. 
 * */
#include "string.h"
//STRING CLASS -----------------------------------------
String::String()
{
    input = new char[1];
    input[0] = '\0';
    size = 1;
}
String::String(char *load)
{
    if(load)
    {
        size = strlen(load)+1;
        input = new char[size];
        strcpy(input,load);
    }
    else
    {   
        size = 0;
        input = NULL;
    }
}
String::String(const String &copy)
{
    if(copy.input)
    {
        size = strlen(copy.input) + 1;
        input = new char[size];
        strcpy(input,copy.input);
    }
    else
    {
        size = 0;
        input = NULL;
    }
}
//concatonates a char * to a string
String operator+(const char *op1, const String &op2)
{
    char * temp = new char[strlen(op1)+op2.size+1];
    strcpy(temp, op1);
    strcat(temp,op2.input);
    return String(temp);
}
//concatonates a char * to a string
String operator+(const String &op1, const char *op2)
{
    char * temp = new char[strlen(op2)+op1.size+1];
    strcpy(temp, op1.input);
    strcat(temp,op2);
    return String(temp);
}
//concatenates a string to a string
String operator+(const String &op1, const String &op2)
{
    char * temp = new char[op1.size+op2.size+1];
    strcpy(temp, op1.input);
    strcat(temp,op2.input);
    return String(temp);
}
//ASSIGNMENT 
/*
String& String::operator=(const char *copy )
{
    if(this->input  == &copy)
        return *this;
    delete [] input;
    size = strlen(copy)+1;
    input = new char[size];
    strcpy(input, copy.input);
    return *this;
}
*/
//returns true if LSH < RHS
bool operator<(const String& LHS, const char * RHS)
{
    return (strcmp(LHS.input,RHS)< 0);
}
//returns true if LSH < RHS
bool operator<(const char *LHS, const String &RHS)
{
    return (strcmp(LHS,RHS.input)< 0);
}
//returns true if LSH < RHS
bool operator<(const String &LHS, const String &RHS)
{
    return (strcmp(LHS.input,RHS.input)< 0);
}

//returns true if LSH > RHS
bool operator>(const String & LHS, const char * RHS)
{
    return (strcmp(LHS.input,RHS)> 0);
}
//returns true if LSH > RHS
bool operator>(const char *LHS, const String &RHS)
{
    return (strcmp(LHS,RHS.input)> 0);
}
//returns true if LSH > RHS
bool operator>(const String &LHS, const String &RHS)
{
    return (strcmp(LHS.input,RHS.input)> 0);
}
//Returns true if LHS <= to RHS
bool operator<=(const String &LHS, const char *RHS)
{
    return (strcmp(LHS.input,RHS) <= 0);
}
//Returns true if LHS <= to RHS
bool operator<=(const char *LHS, const String &RHS)
{
    return (strcmp(LHS,RHS.input) <= 0);
}
//Returns true if LHS <= to RHS
bool operator<=(const String &LHS, const String &RHS)
{
    return (strcmp(LHS.input,RHS.input) <= 0);
}
//Returns true if LHS >= to RHS
bool operator>=(const String& LHS, const char * RHS)
{
    return (strcmp(LHS.input,RHS) >= 0);
}
//Returns true if LHS >= to RHS
bool operator>=(const char *LHS, const String &RHS)
{
    return (strcmp(LHS,RHS.input) >= 0);
}
//Returns true if LHS >= to RHS
bool operator>=(const String &LHS, const String &RHS)
{
    return (strcmp(LHS.input,RHS.input) >= 0);
}
//returns true if LSH != RHS
bool operator!=(const String & LHS, const char * RHS)
{
    return (strcmp(LHS.input, RHS) != 0);
}
//returns true if LSH != RHS
bool operator!=(const char *LHS, const String &RHS)
{
    return (strcmp(LHS, RHS.input) != 0);
}
//returns true if LSH != RHS
bool operator!=(const String &LHS, const String &RHS)
{
    return (strcmp(LHS.input, RHS.input) != 0);
}
//returns true if the strings match
bool operator==(const String &LHS, const char *RHS)
{
    if(strcmp(LHS.input, RHS)==0)
        return true;
    return false;
}
//returns true if the strings match
bool operator==(const char *  LHS, const String & RHS)
{
    if(strcmp(LHS, RHS.input)==0)
        return true;
    return false;
}
//returns true if the strings match
bool operator==(const String &LHS, const String &RHS)
{
    if(strcmp(LHS.input, RHS.input)==0)
        return true;
    return false;
}
//Outputs the string to an ostream reference
ostream& operator<<(ostream &out, const String &RHS)
{
    out << RHS.input;
    return out;
}
//inputs the string to an istream reference
istream& operator>>(istream &in, String &RHS)
{
    char temp[100];
    in >> temp;
    RHS.size = strlen(temp);
    RHS.input = new char[RHS.size+1];
    strcpy(RHS.input,temp);
    return in;
}
//Assigns a string to another string
String& String::operator=(const String &copy)
{
    if(this == &copy)
        return *this;
    if(input)
        delete [] input;
    size = strlen(copy.input)+1;
    input = new char[size];
    strcpy(input, copy.input);
    return *this;
}
//Concatenates a string to existing string
String& String::operator+=(const String &copy)
{
    size = size + copy.size;
    char *temp = new char[size];
    strcpy(temp,input);
    if(input)
        delete input;
    input = temp;
    input = strcat(input, copy.input);
    return *this;

    
}
//Returns the index of the string 
const char& String::operator[](int index) const//TODO Fix the bounds
{
//    if(index >= (int) strlen(input) || index < 0)
 //       return '\0';
    return input[index];
}
//Destructor for string class
String::~String()
{
    if(input)
        delete [] input;
}

