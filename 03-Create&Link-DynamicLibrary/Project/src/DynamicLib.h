#ifndef __DYNAMICLIB__
#define __DYNAMICLIB__

// Print which from two arguments is smaller and return it
int min(const int a, int const b);

class DynamicLibClass {
public:
    // Constructor & Destructor
    DynamicLibClass();
    ~DynamicLibClass();

    void print();
    void setMember(const int member);
    const int getMemebr() const;

private:
    int m_member;
};

#endif