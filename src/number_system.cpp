#include <iostream>
#include <string>

int main() {

	typedef unsigned int uint; // assuming a 32bit int

	std::string block;

	bool flag = 0;
	uint num = 0;

	while (std::cin >> block) {
		if (block == "~") {
			break;
		}
		if (block == "#") {
			std::cout << num << '\n';
			num = 0;
			continue;
		}
		const size_t len = block.size();
		switch (len) {
			case 1:
				flag = 1;
				break;
			case 2:
				flag = 0;
				break;
			default:
				num <<= len - 2;
				if (flag) {
					num |= ~((~(uint) 0) << (len - 2));
				}				
		}
	}

	return 0;
}

