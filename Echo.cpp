#include <iostream>
#include <limits>
#include <string>
#include <random>

int main()
 {
    std::string x;
    std::cout << "*Talk to me!*" << std::endl;
    do{
        std::getline (std::cin,x);
        
        if(x == "Goodbye Echo")
        {
            break;
        }
        else
        {
            std::cout << "*" << x << "*" << std::endl;
            x.clear();    
        }
    }while(x.empty());
    
    return 0;
}