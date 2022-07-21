#include<iostream>
#ifndef _MY_STRING_H_
#define _MY_STRING_H_

class My_String
{
    friend std :: ostream& operator<<(std :: ostream &op, const My_String &rhs);
    private:
    char *str;
    public:
    My_String();                               //Constructors
    My_String(const char *);
    My_String(const My_String &source);
    My_String(My_String &&source);
    ~My_String();                             // Destructor

    // Assignment operators
    My_String & operator=(const My_String &rhs);       // copy assignment
    My_String & operator=(My_String &&rhs);       // Move assignment

    // Relational Operators
    My_String operator-() const;             // To lowercase
    bool operator==(const My_String&rhs) const ;   //Check for equality
    bool operator!=(const My_String &rhs) const;   // check for inequality
    bool operator<(const My_String &rhs) const;    // Lexically lower in order 
    bool operator>(const My_String &rhs) const;    // Lexically greater in order

    //Concatenation and astrix
    My_String operator+(const My_String&rhs) const;   
    My_String operator*(int n) const;

    //Compound operators
    My_String & operator+=(const My_String &rhs);
    My_String & operator*=(int n);   

    // Post and pre increment
    My_String & operator++();
    My_String operator++(int);
};

#endif