#include "My_String.hpp"
#include<cstring>
#include<cctype>
using std :: endl, std :: cout, std :: strlen, std :: strcpy, std  :: tolower;

std :: ostream& operator<<(std :: ostream &op, const My_String &rhs) {        //Overloaded Stream extraction
    op << rhs.str;
    return op;
}

My_String :: My_String()                 // No Args Constructor
           : str{nullptr} 
{
    str = new char[1];
    str[0] = '\0';
} 

My_String :: My_String(const char *tempo)          // 1 Args constructor
           : str{nullptr} 
{
    if(tempo == nullptr)
        My_String();
    this -> str = new char[strlen(tempo) + 1];
    strcpy(this -> str, tempo);
}

My_String :: My_String(const My_String &source)          //Copy Constructor
           : str{nullptr}
{
    this -> str = new char[strlen(source.str) + 1];
    strcpy(this -> str, source.str);
}

My_String :: My_String(My_String &&source)         //Move constructor
           : str{nullptr}
{
    this -> str = source.str;
    source.str = nullptr;
} 

My_String :: ~My_String(){                 // Destructor
    delete [] this -> str;
}

/*=============================================================================================================================
Overloaded Operators
===============================================================================================================================*/

My_String My_String :: operator-() const                 //To Lowercase
{ 
    char * Buff{new char[strlen(this -> str) + 1]};
    strcpy(Buff, this-> str);
    for (size_t i = 0; i < strlen(Buff); i++) {
        Buff[i] = tolower(Buff[i]);
    }
    My_String temp{Buff};
    delete [] Buff;
    return temp;
}

// Relational Operators
bool My_String :: operator==(const My_String &rhs) const        // Check for Equality
{
    if(std :: strcmp(this -> str, rhs.str) == 0)
        return true;
    else
        return false;    
}

bool My_String :: operator!=(const My_String& rhs) const       // Check for Inequality
{
    if(std :: strcmp(this -> str, rhs.str) != 0)
        return true;
    else
        return false; 
}

bool My_String :: operator<(const My_String& rhs) const              // Lexically lower in order
{
    if(std :: strcmp(this -> str, rhs.str) > 0)
        return true;
    else
        return false; 
}

bool My_String :: operator>(const My_String& rhs) const            // Lexically greater in order
{
    if(std :: strcmp(this -> str, rhs.str) < 0)
        return true;
    else
        return false; 
}

//Concatenation Operator and Astrix
My_String My_String :: operator+(const My_String& rhs) const
{   
    char *Buff{new char[strlen(this -> str) + 1 + strlen(rhs.str) + 1]};
    strcpy(Buff, this -> str);
    strcat(Buff, rhs.str);
    My_String temp{Buff};
    delete [] Buff;
    return temp;
}

My_String My_String :: operator*(int n) const{
    char * Buff{new char [(strlen(this -> str)) * n + n]};
    strcpy(Buff, this -> str);

    for (int i = 1; i <= n - 1; i++) {
        strcat(Buff, this->str);
    }
    My_String temp{Buff};
    delete [] Buff;
    return temp;
}

// Assignment operators
My_String & My_String :: operator=(const My_String &rhs)     // Copy Assignments
{
    if (this == &rhs)
        return *this;
    delete [] this -> str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this -> str, rhs.str);
    return *this;
}

My_String & My_String :: operator=(My_String &&rhs)     // Move Assignment
{
    if (this == &rhs)
        return *this;
    delete [] this -> str;
    this -> str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

//Compound operators
My_String & My_String :: operator+=(const My_String &rhs) {
    *this = *this + rhs;
    return *this;
}

My_String & My_String :: operator*=(int n) {
    *this = *this * n;
    return *this;
}

//Post and pre increment
My_String & My_String :: operator++() {
    for (size_t i = 0; i < strlen(this -> str); i++) {
        this -> str[i] = toupper(this -> str[i]);
    }
    return *this;
}

My_String My_String :: operator++(int) {
    My_String temp {*this};
    ++(*this);
    return temp;
}