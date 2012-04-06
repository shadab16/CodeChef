#include <iostream>
#include <map>

typedef std::map<int, int> age_map;
typedef std::map<int, age_map> sex_map;
typedef std::map<int, sex_map> region_map;
typedef std::map<int, region_map> city_map;
typedef std::map<int, city_map> province_map;
typedef std::map<int, province_map> size_map;
typedef std::map<int, size_map> product_map;

product_map db;

struct query {
	int product;
	int size;
	int province;
	int city;
	int region;
	int sex;
	int age;
	int maxage;
};

query q;

int get_int(const char*& c) {

	int n = 0;
	int sign = 1;
	if (*c == '-') {
		sign = -1;
		++c;
	}
	while (*c >= '0' && *c <= '9') {
		n = (n * 10) + (*c - '0');
		++c;
	}
	return n * sign;
}

void insert_record(const char* c) {

	int product, size = 0, province, city = 0, region = 0, sex, age, units;

	product = get_int(c);
	if (*c == '.') {
		++c;
		size = get_int(c) + 1;
	}
	++c;
	province = get_int(c);
	if (*c == '.') {
		++c;
		city = get_int(c) + 1;
		if (*c == '.') {
			++c;
			region = get_int(c) + 1;
		}
	}
	++c;
	sex = *c++;
	++c;
	age = get_int(c);
	++c;
	units = get_int(c);

	db[product][size][province][city][region][sex][age] += units;
}

void prepare_query(const char* c) {

	q.size = 0;
	q.city = 0;
	q.region = 0;
	q.maxage = 0;
	q.product = get_int(c);
	if (*c == '.') {
		++c;
		q.size = get_int(c) + 1;
	}
	++c;
	q.province = get_int(c);
	if (*c == '.') {
		++c;
		q.city = get_int(c) + 1;
		if (*c == '.') {
			++c;
			q.region = get_int(c) + 1;
		}
	}
	++c;
	q.sex = *c++;
	++c;
	q.age = get_int(c);
	if (*c == '-') {
		++c;
		q.maxage = get_int(c);
	}
}

long count_records() {

	long units = 0;

	product_map::const_iterator pIter = db.begin();
	product_map::const_iterator pEnd = db.end();

	if (q.product != -1) {
		pIter = db.find(q.product);
		if (pIter != pEnd) {
			pEnd = ++pIter; --pIter;
		}
	}

	for (; pIter != pEnd; ++pIter) {

		size_map::const_iterator sIter = pIter->second.begin();
		size_map::const_iterator sEnd = pIter->second.end();

		if (q.size) {
			sIter = pIter->second.find(q.size);
			if (sIter != sEnd) {
				sEnd = ++sIter; --sIter;
			}
		}

		for (; sIter != sEnd; ++sIter) {

			province_map::const_iterator pvIter = sIter->second.begin();
			province_map::const_iterator pvEnd = sIter->second.end();

			if (q.province != -1) {
				pvIter = sIter->second.find(q.province);
				if (pvIter != pvEnd) {
					pvEnd = ++pvIter; --pvIter;
				}
			}

			for (; pvIter != pvEnd; ++pvIter) {
				
				city_map::const_iterator cIter = pvIter->second.begin();
				city_map::const_iterator cEnd = pvIter->second.end();

				if (q.city) {
					cIter = pvIter->second.find(q.city);
					if (cIter != cEnd) {
						cEnd = ++cIter; --cIter;
					}
				}

				for (; cIter != cEnd; ++cIter) {
					
					region_map::const_iterator rIter = cIter->second.begin();
					region_map::const_iterator rEnd = cIter->second.end();

					if (q.region) {
						rIter = cIter->second.find(q.region);
						if (rIter != rEnd) {
							rEnd = ++rIter; --rIter;
						}
					}

					for (; rIter != rEnd; ++rIter) {

						const age_map& ageMap = rIter->second.find(q.sex)->second;
						age_map::const_iterator aIter;
						age_map::const_iterator aEnd;

						if (q.maxage) {
							aIter = ageMap.lower_bound(q.age);
							aEnd = ageMap.upper_bound(q.maxage);
						} else {
							aIter = ageMap.find(q.age);
							if (aIter != ageMap.end()) {
								aEnd = ++aIter; --aIter;
							} else {
								aEnd = ageMap.end();
							}
						}

						for (; aIter != aEnd; ++aIter) {
							units += aIter->second;
						}
					}
				}
			}
		}
	}

	return units;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int limit = 0;
	std::cin >> limit;
	std::cin.ignore();

	char line[100] = {0};

	while (limit--) {
		std::cin.getline(line, 100);
		if (line[0] == 'I') {
			insert_record(line + 2);
		} else {
			prepare_query(line + 2);
			std::cout << count_records() << '\n';
		}
	}

	return 0;
}
