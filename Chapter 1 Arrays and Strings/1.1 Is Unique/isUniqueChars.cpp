

#include <string>
#include <iostream>
#include <vector>
#include <cctype>


bool isUniqueChars(std::string data);
bool isUniqueChars_bit_vector(std::string data);

int main() {

    std::vector<std::string> inputs;

    inputs.push_back("abc");
    inputs.push_back("abcdefd");
    inputs.push_back("Abcdef aijk");
    inputs.push_back("");

    std::cout << std::endl << "isUniqueChars:";
    for (std::string input : inputs){

        std::cout << std::endl << "> " << input << " ";
        if (isUniqueChars(input))
            std::cout << "is Unique chars.";
        else
            std::cout << "is not Unique chars.";
    }

    std::cout << std::endl << "isUniqueChars_bit_vector:";
    for (std::string input : inputs){

        std::cout << std::endl << "> " << input << " ";
        if (isUniqueChars_bit_vector(input))
            std::cout << "is Unique chars.";
        else
            std::cout << "is not Unique chars.";
    }

    return 0;
}

bool isUniqueChars(std::string data){

    if (data.size()>128)
        return false;
    
    bool char_set[128]{};
    
    for (char a_char: data) {

        if (char_set[a_char])
            return false;
        else
            char_set[a_char] = true;
    }

    return true;

}

bool isUniqueChars_bit_vector(std::string data) {
    int checker = 0x0;
    static_assert(sizeof(int)>=4,"*** Error: size of 'int' to small");
    for (char a_char: data) {
        int value = std::tolower(a_char) - 'a';
        if ((checker & (1 << value)) >0 ) {
            return false;
        }
        checker |= (1 << value);
    }
    return true;
}
