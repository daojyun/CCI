
#include<iostream>
#include<string>
#include<algorithm>

const int N_chars = 128;

bool compare_sorted_strings (std::string str1, std::string str2);
int main () {
	std::string str1{"abcde"};
	std::string str2{"edcba"};
	std::string str3{""};
	
	std::cout << "check_permutation(" << str1 << ", " << str2 << ") = " << (compare_sorted_strings (str1, str2)?"TRUE":"FALSE") << std::endl;
	std::cout << "check_permutation(" << str1 << ", " << str3 << ") = " << (compare_sorted_strings (str1, str3)?"TRUE":"FALSE") << std::endl;
}

bool compare_sorted_strings (std::string str1, std::string str2) {
	std::sort(str1.begin(),str1.end());
	std::sort(str2.begin(),str2.end());
	return str1 == str2;
}
