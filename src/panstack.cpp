#include <iostream>

int bell[1001] = {1, 1};

void generate() {

	int A[1001] = {0};
	A[0] = 1;

	for (int n = 1; n < 1000; ++n) {
		A[n] = A[0];
		for (int k = n; k > 0; --k) {
			A[k-1] = (A[k-1] + A[k]) % 1000000007;
		}
		bell[n+1] = A[0];
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	generate();

	int cases;
	std::cin >> cases;

	while (cases--) {
		int n;
		std::cin >> n;
		std::cout << bell[n] << '\n';
	}

	std::cout.flush();

	return 0;
}
