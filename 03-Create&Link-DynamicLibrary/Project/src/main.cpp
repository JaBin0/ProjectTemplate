// Own headers
#include <DynamicLib.h>
// System headers
#include <iostream>

int main(int argc, char** argv ) {
    std::cout << "Project Template: Dynamic Lib"<< std::endl;
    int result = min(20, 14);

    std::cout << "T1 obejct from dll clas declaration"<< std::endl;
    DynamicLibClass t1;
    t1.print();
    t1.setMember(20);
    t1.print();
    std::cout << "T2 obejct from dll clas declaration"<< std::endl;
    DynamicLibClass t2;
    t2.setMember(32);
    std::cout << "Class form dynamic value of member: "<< t2.getMemebr() <<  std::endl;

    return 0;
}