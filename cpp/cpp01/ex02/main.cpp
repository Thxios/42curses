
#include <iostream>
#include <string>


int main() {

    std::string str("HI THIS IS BRAIN");
    std::string* stringPTR(&str);
    std::string& stringREF(str);

    std::cout << "===== address =====" << std::endl;
    std::cout << "original: " << &str << std::endl;
    std::cout << "ptr: " << &stringPTR << std::endl;
    std::cout << "ref: " << &stringREF << std::endl;
    std::cout << std::endl;
    

    std::cout << "===== value =====" << std::endl;
    std::cout << "original: " << str << std::endl;
    std::cout << "ptr: " << *stringPTR << std::endl;
    std::cout << "ref: " << stringREF << std::endl;
    std::cout << std::endl;
}

