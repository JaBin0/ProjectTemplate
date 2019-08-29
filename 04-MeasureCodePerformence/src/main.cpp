// This project shows how simpli measure time of the function or take configuration of timer

#include <iostream>
#include <chrono>


int main(int argc, char** argv ) {
    std::cout << "Configuration of the clocks: "<< std::endl; 
    std::cout << "system_clock" << std::endl
              << "<num, den>: <" << std::chrono::system_clock::period::num << ", "
              << std::chrono::system_clock::period::den << ">" << std::endl
              << "Stedy = " << std::boolalpha << std::chrono::system_clock::is_steady << std::endl;
    std::cout << std::endl;
    std::cout << "high_resolution_clock" << std::endl
              << "<num, den>: <" << std::chrono::high_resolution_clock::period::num << ", "
              << std::chrono::high_resolution_clock::period::den << ">" << std::endl
              << "Stedy = " << std::boolalpha << std::chrono::high_resolution_clock::is_steady << std::endl;
    std::cout << std::endl;
    std::cout << "steady_clock" << std::endl
              << "<num, den>: <" << std::chrono::steady_clock::period::num << ", "
              << std::chrono::steady_clock::period::den << ">" << std::endl
              << "Steady = " << std::boolalpha << std::chrono::steady_clock::is_steady << std::endl;
    std::cout << std::endl 
              << "Time of the simple code execiution: " << std::endl;
    // For performence use steady timer as theay are not adjusted by the system
    // Hight resolution or system also can be steady, it depends on the machine
    std::chrono::steady_clock::time_point time_0 = std::chrono::steady_clock::now();
    std::cout << "Printing out 1000 stars...\n";
    for(int i=0; i<1000; ++i) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::chrono::steady_clock::time_point time_1 = std::chrono::steady_clock::now();

    // Result
    std::chrono::duration<double> diff = time_1 - time_0;
    std::cout << "This code took: " << std::chrono::duration<double, std::milli>(diff).count() << "ms" << std::endl;

    // Other posiible conversion (std::ratio)   <num, den>
    // std::chrono::duration<double, std::pico>  <1, 1000000000000>
    // std::chrono::duration<double, std::nano>  <1, 1000000000>
    // std::chrono::duration<double, std::micro> <1, 1000000>
    // std::chrono::duration<double, std::milli> <1, 1000>
    // std::chrono::duration<double, std::centi> <1, 100>
    // std::chrono::duration<double, std::deci>  <1, 10>
    // std::chrono::duration<double, std::deca>  <10, 1>
}