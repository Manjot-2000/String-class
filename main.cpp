#include "My_String.hpp"
using std :: cout, std :: endl;
void break_section();
void farewell_message();
int main()
{
    cout << std :: boolalpha;
    // Creating new objects for test cases
    My_String nos;
    My_String The_Raven{"Deep into that darkness peering,"};
    My_String By{"Long I stood there, wondering, fearing,"};
    My_String Edgar_Allen_Poe{"Doubting, dreaming dreams no mortals"};
    My_String repeat{"Ever dared to dream before;"};
    My_String Assign_to_this{"But the silence was unbroken,"};
    

    //Test cases for assignment operators
    cout << Assign_to_this << endl;
    Assign_to_this = Edgar_Allen_Poe;
    cout << Assign_to_this << endl;
    Assign_to_this = My_String{"And the stillness gave no token,"};
    cout << Assign_to_this << endl;
    break_section();

    //Test cases Relational operators
    cout << nos << endl;
    cout << (-The_Raven) << endl;
    cout << The_Raven << endl;
    cout << (The_Raven == By) << endl;
    cout << (The_Raven != nos) << endl;
    cout << (Edgar_Allen_Poe < The_Raven) << endl;    
    break_section();

    //Test cases for concatenation and astrix operator
    cout << (The_Raven + Edgar_Allen_Poe) << endl;
    cout << (repeat * 5) << endl;
    break_section();

    //Test cases for compound operators
    My_String next_snippet{"And the only word there spoken"};
    cout << next_snippet << endl;
    Assign_to_this += next_snippet;
    cout << Assign_to_this << endl;
    next_snippet *= 4;
    cout << next_snippet << endl;
    next_snippet = My_String{"Was the whispered word, Lenore!"};

    //Test cases for pre and post increment
    ++next_snippet;
    cout << next_snippet << endl;

    My_String Last_Stanza {"This I whispered, and an echo"};
    My_String result {"Murmured back the word, Lenore! Merely this, and nothing more."};
    cout << result << endl;
    result = Last_Stanza++;
    cout << result << endl;
    cout << Last_Stanza << endl;
    break_section();
    farewell_message();
    return 0;
}

void break_section() {
    cout << "===============================================" << endl;
}

void farewell_message(){
    cout << "Poetry is an echo, asking a shadow to dance.\n -Carl Sandberg" << endl;
}