#pragma once

class base{
public:
    int get_capacity() const;
    void set_capacity(int);
    int get_size() const;
    void pop__back();
    bool isEmpty();
    void Clear();
    ~base();
protected:
    unsigned Size, capacity;
};


class intVector : public base{
public:
    intVector &operator=(const intVector &);
    int operator[](const int ) const;
    intVector();
    ~intVector();
    void print();
    int &Back() const;
    int &Front() const;
    int &At(int) const;
    void push__back(int);
    int *Begin() const;
    int *End() const;
    void Insert(int, int);
    void Erase(int);
    void reallocate();

private:
    int *arr;
};



class charVector : public base{
public:
    charVector &operator=(const charVector &);
    char operator[](const int ) const;
    charVector();
    ~charVector();
    void print();
    char &Back() const;
    char &Front() const;
    char &At(int) const;
    void push__back(char);
    char *Begin() const;
    char *End() const;
    void Insert(int, char);
    void Erase(int);
    void reallocate();

private:
    char *charArr;
};
