#include <iostream>
#include <string>

bool add[8][8][8];
bool diff[8][8][8];

// ABO Blood types
const char types[8][4] = {
	"O+", "A+", "B+", "AB+",
	"O-", "A-", "B-", "AB-",
};

int typenum(const char* str) {

	return 0;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	// Generate lookup table for the child
	// parent1 (m) + parent2 (f)
	for (size_t m = 0; m < 8; ++m) {

		char m1 = types[m][0];
		char m2 = 'O';
		bool mrh = types[m][1] == '+';
		if (types[m][1] == 'B') {
			m2 = 'B';
			mrh = types[m][2] == '+';
		}

		for (size_t f = 0; f < 8; ++f) {

			char f1 = types[f][0];
			char f2 = 'O';
			bool frh = types[f][1] == '+';
			if (types[f][1] == 'B') {
				f2 = 'B';
				frh = types[f][2] == '+';
			}
		}
	}

	int n = 0;
	while (true) {
		std::string type[3];
		std::string* result;
		bool* cases;
		std::cin >> type[0] >> type[1] >> type[2];
		if (type[0] == 'E') {
			break;
		}
		if (type[0] == '?') {
			// ? T T
			result = &type[0];
			cases = diff[typenum(type[2])][typenum(type[1])];
		} else if (type[1] == '?') {
			// T ? T
			result = &type[1];
			cases = diff[typenum(type[2])][typenum(type[0])];
		} else {
			// T T ?
			result = &type[2];
			cases = add[typenum(type[0])][typenum(type[1])];
		}
		for (size_t i = 0; i < 8; ++i) {
			if (cases[i]) {
				if (!result->empty()) {
					*result += ", ";
				}
				*result += types[i];
			}
		}
		if (!result->empty()) {
			*result = "{" + *result + "}";
		} else {
			*result = "IMPOSSIBLE";
		}
		std::cout << "Case " << (++n) << ": ";
		std::cout << type[0] << " " << type[1] << " " << type[2] << "\n";
	}

	return 0;
}
