#include <iostream>
#include <string>

int reduce(int n) {
	int reduced = 0;
	while (n) {
		reduced += n % 10;
		n /= 10;
	}
	return (reduced > 9) ? reduce(reduced) : reduced;
}

int main() {

	int date;
	int year;
	std::string month;

	std::cin >> date;
	std::cin >> month;
	std::cin >> year;

	int month_ = 0;

	// THE wtf!!
	if (month == "January")
		month_ = 1;
	else if (month == "February")
		month_ = 2;
	else if (month == "March")
		month_ = 3;
	else if (month == "April")
		month_ = 4;
	else if (month == "May")
		month_ = 5;
	else if (month == "June")
		month_ = 6;
	else if (month == "July")
		month_ = 7;
	else if (month == "August")
		month_ = 8;
	else if (month == "September")
		month_ = 9;
	else if (month == "October")
		month_ = 10;
	else if (month == "November")
		month_ = 11;
	else
		month_ = 12;

	int lucky = date * month_ + year;
	std::cout << reduce(lucky) << std::endl;

	return 0;
}
