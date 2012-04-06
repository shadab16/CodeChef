#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <numeric>
#include <limits>
#include <cstdlib>
#include <cmath>

typedef std::complex<double> complex;

const double toradian = std::acos(-1) / 180.0;
const double epsilon = std::numeric_limits<double>::epsilon() * 10;

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string line;

	std::getline(std::cin, line);
	int cases = std::atoi(line.c_str());

	while (cases--) {

		std::getline(std::cin, line);
		std::istringstream is(line);

		std::vector<complex> vec;
		vec.reserve(line.size() / 4 + 1);

		double distance = 0;
		int angle = 0;
		char turn = 'L';

		is >> distance;

		do {
			angle = (angle + (turn == 'L' ? +90 : -90)) % 360;
			const complex c = std::polar(distance, angle * toradian);
			vec.push_back(c);
		}
		while (is >> turn && is >> distance);

		const complex result = std::accumulate(vec.begin(), vec.end(), complex());
		const double magnitude = std::abs(result);
		std::cout << std::fixed << std::setprecision(1) << magnitude;

		if (std::abs(result.imag()) < epsilon) {
			if (std::abs(result.real()) < epsilon) {
				// Do nothing
			} else if (result.real() > 0.0) {
				std::cout << "E";
			} else {
				std::cout << "W";
			}
		} else if (result.imag() > 0.0) {
			if (std::abs(result.real()) < epsilon) {
				std::cout << "N";
			} else if (result.real() > 0.0) {
				std::cout << "NE";
			} else {
				std::cout << "NW";
			}
		} else {
			if (std::abs(result.real()) < epsilon) {
				std::cout << "S";
			} else if (result.real() > 0.0) {
				std::cout << "SE";
			} else {
				std::cout << "SW";
			}
		}

		std::cout << std::endl;
	}

	return 0;
}
