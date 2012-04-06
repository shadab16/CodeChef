#include <iostream>
#include <string>

int main() {

	std::string num;
	std::cin >> num;

	int code = 0;
	for (int i = 0; i < 5; ++i) {
		code += (num[i] - '0') * (num[i + 5] - '0');
	}

	std::cout << code << std::endl;

	return 0;
}
