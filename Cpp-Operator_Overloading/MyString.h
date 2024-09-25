#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString {
            friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
            friend std::istream &operator>>(std::istream &in, MyString &rhs);
    private:
        char* str;
    public:
        MyString(); // no-args constructor
        MyString(const char* s); // overloaded constructor
        MyString(const MyString &source); // copy constructor
        MyString(MyString &&source); // move constructor
        ~MyString(); // destructor

        MyString &operator=(const MyString &rhs); // copy assignment
        MyString &operator=(MyString &&rhs); // move assignment

        // MyString &operator-();
        MyString operator-() const;
        
        bool operator==(const MyString &rhs) const;
        bool operator!=(const MyString &rhs) const;
        bool operator<(const MyString &rhs) const;
        bool operator>(const MyString &rhs) const;
        
        MyString operator+(const MyString &rhs) const;

        MyString &operator+=(const MyString &rhs);

        MyString operator*(int n) const;

        MyString &operator*=(int n);

        MyString &operator++();
        MyString operator++(int);

        // getters
        int getLength() const;
        const char* getStr() const;

        void display() const;
};

#endif