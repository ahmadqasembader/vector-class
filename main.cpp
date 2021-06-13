#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    cout << "INTEGER VECTOR DRIVER PROGRAM!!" << endl ;
    intVector vec;
    vec.set_capacity(4);
    cout << "capacity: " << vec.get_capacity() << endl;
    cout << "Size = " << vec.get_size() << endl;
    cout << "is vector empty? " << ((vec.isEmpty()) ? "Yes" : "No") << endl;

    for(int i = 0; i <= 9; i++){
        vec.push__back(i);
    }
    cout << "capacity: " << vec.get_capacity() << endl;
    cout << "Size = " << vec.get_size() << endl;

    cout << "Deleting the last element --> " << vec.Back() << endl;
    vec.pop__back();

    cout << "Last element is " << vec.Back() << endl;
    cout << "First element is " << vec.Front() << endl;
    cout << "Element in index 2 is --> " << vec.At(2) << endl;

    cout << "Printing the Integer Vector " << endl;
    vec.print();
    cout << endl;

    vec.Erase(1);
    cout << "Printing the Integer Vector - Erase function " << endl;
    vec.print();
    cout << endl;
    vec.Insert(1, 1);
    cout << "Printing the Integer Vector - Insert function" << endl;
    vec.print();
    cout << endl;
    vec.Clear();


    cout << endl << endl << "CHAR VECTOR DRIVER PROGRAM!!" << endl ;

    charVector vec2;
    cout << "is vector empty? " << ((vec2.isEmpty()) ? "Yes" : "No") << endl;
    vec2.set_capacity(4);
    cout << "capacity: " << vec2.get_capacity() << endl;
    cout << "Size = " << vec2.get_size() << endl;

    vec2.push__back('A');
    vec2.push__back('h');
    vec2.push__back('m');
    vec2.push__back('a');
    vec2.push__back('d');

    cout << "Element in index 2 is --> " << vec2.At(2) << endl;

    cout << "capacity = " << vec2.get_capacity() << endl;
    cout << "Size = " << vec2.get_size() << endl;

    cout << "Printing the Integer Vector " << endl;
    vec2.print();
    cout << endl;

    vec2.Erase(1);
    cout << "Printing the Integer Vector - Erase function " << endl;
    vec2.print();
    cout << endl;
    vec2.Insert(1, 'h');
    cout << "Printing the Integer Vector - Insert function" << endl;
    vec2.print();
    cout << endl;

    vec2.Clear();
    cout << endl << endl << "================================" << endl;
    cout << "The destructor list:" << endl;
    return 0;
}
