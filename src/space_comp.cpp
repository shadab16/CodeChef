#include <iostream>
#include <string>

int value(const std::string& color) {

	switch (color[0]) {
		case 'b':
			switch (color[2]) {
				case 'a': // black
					return 0;
					break;
				case 'o': // brown
					return 1;
					break;
				case 'u': // blue
					return 6;
					break;
			}
			break;
		case 'r': // red
			return 2;
			break;
		case 'o': // orange
			return 3;
			break;
		case 'y': // yellow
			return 4;
			break;
		case 'g':
			switch (color[3]) {
				case 'e': // green
					return 5;
					break;
				case 'y': // gray
					return 8;
					break;
			}
			break;
		case 'v': // violet
			break;
	}

	return 9; // white
}

int main() {

	std::string color[4];
	unsigned int val = 0;

	std::cin >> color[0] >> color[1] >> color[2] >> color[3];

	for (int i = 0; i < 4; ++i) {
		val <<= 4;
		val |= value(color[i]);
	}

	std::cout << val;

	for (int i = 0; i < value(color[3]); ++i) {
		std::cout << '0';
	}

	std::cout << " Guntur" << std::endl;

	return 0;
}

