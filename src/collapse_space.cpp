#include <iostream>
#include <string>

int main() {
	std::string result;
	std::string word;
	while (std::cin >> word) {
		if (!result.size()) {
			result = word;
		} else {
			result += " " + word;
		}
	}
	std::cout << result << std::endl;
}
