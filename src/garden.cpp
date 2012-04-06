#include <iostream>

const char response[4][5] = {
	"NO\n", "YES\n", "NO\n", "NO\n"
};

char buffer[1000000 * 8];
char* buf = buffer;

int next() {
	while (*buf < '0') {
		++buf;
	}
	int n = 0;
	while (*buf >= '0') {
		n = (n * 10) + (*buf - '0');
		++buf;
	}
	return n;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int cases;
	std::cin >> cases;

	std::cin.read(buffer, cases * 8);

	while (cases--) {
		const int n = next();
		if (n == 2) {
			std::cout << response[1];
		} else {
			std::cout << response[n % 4];
		}
	}

	return 0;
}

