// Own headers
#include <DynamicLib.h>
// System headers
#include <iostream>

int min (const int a, const int b) {
    int result = (a < b) ? a : b;
    std::cout << "Dynamic Lib <min> function:" << std::endl 
              << "From given: " << a << " and " << b << ", smaller is " << result << std::endl; 
    return result;
}

DynamicLibClass::DynamicLibClass()
    : m_member {0}
{
    std::cout << "Constructor form the dll: " << std::endl;
}

DynamicLibClass::~DynamicLibClass() {
    std::cout << "Destructor form the dll (memeber: " << m_member << ")"<< std::endl;
}

void DynamicLibClass::print() {
    std::cout << "Function form dll => Current member: " << m_member << std::endl;
}
void DynamicLibClass::setMember(const int member) {
    if(member != m_member) {
        m_member = member;
    }
}
const int DynamicLibClass::getMemebr() const {
    return m_member;
}