#include <iostream>
#include "header.h"

using namespace std;

// utilities

intVector& intVector::operator= (const intVector& right) {
    for (unsigned int i = 0; i <= intVector::Back(); i++)
        this->arr[i] = right.arr[i];
    return *this;
}

int intVector::operator[](const int index) const{
    return arr[index];
}

charVector& charVector::operator= (const charVector& right) {
    for (unsigned int i = 0; i <= charVector::Back(); i++)
        this->charArr[i] = right.charArr[i];
    return *this;
}

char charVector::operator[](const int index) const{
    return charArr[index];
}

//<<================================>>
//base class implementation
int base::get_capacity() const {
    return this->capacity;
}
void base::set_capacity(int ts) {
    capacity = ts;
}
int base::get_size() const {
    return this->Size;
}

void base::pop__back() {
    if (Size == 0)
    {
        cout << "Vector is empty!" << endl;
        exit(1);
    }
    --Size;
}
bool base::isEmpty() {
    if (Size == 0)
        return 1;
    else
        return 0;
}
//function to reset the vector to ZERO
void base::Clear() {
    Size = 0;
}

base::~base() {
    cout << "Base class destroyed" << endl;
}

//<<================================>>
//<<================================>>
// intVector class implementation

intVector::intVector(){
    arr = new int[capacity];
    Size = 0;
    capacity = 0;
}
intVector::~intVector() {
    cout << "Vector class destructor called" << endl;
    delete[] arr;
}

void intVector::print() {
    for (int* itr = Begin(); itr <= End(); itr++)
        cout << *itr << " ";
}
//returns data
int& intVector::Back() const{
    //Error handling function
    if (Size == 0) {
        cout << "Vector is empty" << endl;
        exit(-3);
    }
    return arr[Size - 1];
}
//returns data
int &intVector::Front() const{
    //Error handling function
    if (Size == 0) {
        cout << "Vector is empty" << endl;
        exit(-4);
    }
    return *arr;
}

int& intVector::At(int index) const{
    //Error handling function
    if (Size == 0 || index < 0 || index > Size)
    {
        cout << "index entered is not valid" << endl;
        exit(-5);
    }
    return arr[index];
}

void intVector::push__back(int data)
{
    if (Size < capacity) {
        arr[Size] = data;
        Size++;
    }
    else if (Size == capacity) {
        int* tempArr = new int[capacity *= 2];
        for (int i = 0; i <= Size; i++)
            tempArr[i] = arr[i];
        //delete the array in order to reallocate it with bigger capacity
        delete[] arr;
        intVector::reallocate();
        //initialize the array with the tempArr but with bigger capacity
        arr = tempArr;
        arr[Size] = data;
        Size++;
    }
}
//returns pointer
int *intVector::Begin() const{
    return arr;
}
//returns pointer
int *intVector::End() const{
    return &arr[Size];
}
//insert function at specific index but before that,
//shift all the element to the right from the entered index
void intVector::Insert(int index, int value) {
    if (Size < capacity)
    {
        for (int i = Size - 1; i >= index; i--){
            arr[i + 1] = arr[i];
        }
        ++Size;
        arr[index] = value;
    }
    else {
        int* tempArr = new int[capacity *= 2];
        for (int i = 0; i <= Size; i++)
            tempArr[i] = arr[i];
        //delete the array in order to reallocate it with bigger capacity
        delete[] arr;
        intVector::reallocate();
        //initialize the array with the tempArr but with bigger capacity
        arr = tempArr;//overloading operator
        intVector::Insert(index, value);
    }
}

//Erase a specific element
void intVector::Erase(int index)
{
    for (int i = index; i < Size; i++)
        arr[i] = arr[i + 1];
    Size--;
}
// re initialize the array with the double of the capacity
void intVector::reallocate() {
    int *arr = new int[capacity *= 2];
}


// <<================================>>
// <<================================>>
// charVector class implementation

charVector::charVector() {
    charArr = new char[capacity];
    Size = 0;
    capacity = 0;
}

charVector::~charVector() {
    cout << "Char vector class destroyed" << endl;
    delete[] charArr;
}

void charVector::print() {
    for (char* itr = Begin(); itr <= End(); ++itr)
        cout << *itr << " ";
}

char& charVector::Back() const {
    return charArr[Size - 1];
}

char &charVector::Front() const{
    if (Size == 0) {
        cout << "Vector is empty" << endl;
        exit(-4);
    }
    return *charArr;
}

char& charVector::At(int index) const{
    if (Size == 0 || index < 0 || index > Size)
    {
        cout << "index entered is not valid" << endl;
        exit(-5);
    }
    return charArr[index];
}

void charVector::push__back(char data) {
    char* tempArr = new char[capacity *= 2];
    if (Size < capacity) {
        charArr[Size] = data;
        Size++;
    }
    else if (Size == capacity) {
        tempArr = charArr; // operator overloading
        //delete the array in order to reallocate it with bigger capacity
        delete[] charArr;
        //initialize the array with the tempArr but with bigger capacity
        reallocate();
        charArr = tempArr; // operator overloading
        charArr[Size] = data;
        Size++;
    }
}

char* charVector::Begin() const {
    return charArr;
}

char* charVector::End() const{
        return &charArr[Size];

}

void charVector::Insert(int index, char value) {
    char* tempArr = new char[capacity *= 2];
    if (Size < capacity)
    {
        for (int i = (Size - 1); i >= index; --i)
            charArr[i + 1] = charArr[i];
        charArr[index] = value;
        ++Size;
    }
    else {
        tempArr = charArr;
        //delete the array in order to reallocate it with bigger capacity
        delete[] charArr;
        reallocate();
        //initialize the array with the tempArr but with bigger capacity
        charArr = tempArr;
        //charVector::Insert(index, value);
        charArr[index] = value;
        ++Size;
    }
}

void charVector::Erase(int index)
{
    for (int i = index; i < Size; i++)
        charArr[i] = charArr[i + 1];
    Size--;
}

void charVector::reallocate() {
    char *charArr = new char[capacity *= 1.5];
}
