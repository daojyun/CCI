
#include<iostream>
#include<vector>
#include<string>

const int N_chars = 128;

bool check_permutation (std::string str1, std::string str2);
int main () {
	std::string str1{"abcde"};
	std::string str2{"edcba"};
	std::string str3{""};
	
	std::cout << "check_permutation(" << str1 << ", " << str2 << ") = " << (check_permutation(str1, str2)?"TRUE":"FALSE") << std::endl;
	std::cout << "check_permutation(" << str1 << ", " << str3 << ") = " << (check_permutation(str1, str3)?"TRUE":"FALSE") << std::endl;
}

std::vector<int> chars_frequence (std::string str) {
	std::vector<int> frequences(N_chars);
	for (char a_char : str)
		frequences[a_char]++;
	return frequences;
}

bool frequence_compare (std::vector<int> freq1, std::vector<int> freq2)
{
	for (int i = 0; i<N_chars; ++i)
		if (freq1[i]!=freq2[i])
			return false;
	return true;
}

bool check_permutation (std::string str1, std::string str2)
{
	return frequence_compare (chars_frequence(str1), chars_frequence(str2));
}
