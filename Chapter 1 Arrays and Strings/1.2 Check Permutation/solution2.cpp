
#include<iostream>
#include<vector>
#include<string>

const int N_chars = 128;

bool permutation (std::string str1, std::string str2);
int main () {
	std::string str1{"abcde"};
	std::string str2{"edcba"};
	std::string str3{""};
	
	std::cout << "check_permutation(" << str1 << ", " << str2 << ") = " << (permutation(str1, str2)?"TRUE":"FALSE") << std::endl;
	std::cout << "check_permutation(" << str1 << ", " << str3 << ") = " << (permutation(str1, str3)?"TRUE":"FALSE") << std::endl;
}

bool permutation(std::string str1, std::string str2) {
	if (str1.size() != str2.size())
		return false;

	int letters[N_chars] {};

	for (char a_char: str1)
		letters[a_char]++;

	for (char a_char: str2) {

		letters[a_char]--;
		if (letters[a_char] < 0) 
			return false;
	}

	return true;
}
