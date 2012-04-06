#include <iostream>
#include <vector>

struct coin_t {
	unsigned int value: 16;
	unsigned int weight: 16;
};

int main() {

	int cases = 0;
	std::cin >> cases;

	while (cases--) {
		int empty, full, N, W;
		std::cin >> empty >> full >> N;
		W = full - empty;

		std::vector<coin_t> coins(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> coins[i].value >> coins[i].weight;
		}

		int C[N][W + 1] = {0};

		for (int w = 0; w <= W; ++w) {
			C[0][w] = 0;
		}
		for (int n = 0; n < N; ++n) {
			C[n][0] = 0;
		}
		for (int n = 0; n < N; ++n) {
			for (int w = 0; w <= W; ++w) {
				if (
			}
		}
	}

	return 0;
}

