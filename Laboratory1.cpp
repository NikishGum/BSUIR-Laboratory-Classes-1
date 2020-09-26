#include <stdio.h>
#include <locale>
#include <iostream>
#include <cstring>

double get_number() //метод проверки на число
{
    double result = 0;
    char c_space[255];
    char* temp;
    int err = 0;
    while (err == 0) {
        std::cout << std::endl;
        std::cout << "Enter number : ";
        std::cin >> c_space;
        size_t len = strlen(c_space);
        temp = new char[len];
        result = std::atof(c_space); // convert char into double

        for (int i = 0; i < len; i++) {
            std::cout << "  ghh[i] : " << isdigit((unsigned char)c_space[i]) << std::endl;
            err = c_space[i];
            if (!isdigit((unsigned char)c_space[i])) {                                          // usigned char, so it can also accpt cyrillic symbols. (cyrillic numbers are above 127)
                err = 0;
                break;
            }
        }
        if (!err) {
            std::cout << "Entered value isn't a number : " << std::endl;
        }
    } 
    delete[] temp;
    return result;
}



int main()
{
    std::cout << get_number() << "\n"; 
    return 0;
}