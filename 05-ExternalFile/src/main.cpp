// This program will open/create file ExternalFile.txt append
// line and next it will read the hole content of the file

#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char** argv ) {
    std::cout << "External File:"<< std::endl;
    std::fstream file;
    file.open("ExternalFile.txt", std::fstream::out | std::fstream::app);
    if(file.is_open()) {
        std::cout << "Success" << std::endl;
        file << "New line\n";
    }
    else {
        std::cout << "Cannot open file" << std::endl;
    }
    file.close();

    file.open("ExternalFile.txt", std::fstream::in);
    if(file.is_open()) {
        std::string line;
        while(!file.eof()) {
            std::getline(file, line);
            std::cout << line.data() << std::endl;
        }
    }    
    else {
        std::cout << "Cannot open file" << std::endl;
    }
    file.close();
}