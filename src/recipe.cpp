#include <algorithm>
#include <iostream>
#include <set>
#include <string>

struct recipe {
	std::string name;
	int priority;
};

bool operator <(const recipe& lhs, const recipe& rhs) {

	return lhs.priority < rhs.priority;
}

struct starts_with {
	const std::string prefix;
	starts_with(std::string q) : prefix(q) {}
	bool operator()(const recipe& r) {
		return r.name.compare(0, prefix.length(), prefix) == 0;
	}
};

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::set<recipe> recipes;

	int count;
	std::cin >> count;

	while (count--) {
		recipe r;
		std::cin >> r.name >> r.priority;
		recipes.insert(r);
	}

	std::cin >> count;
	std::string query;
	std::set<recipe>::const_reverse_iterator it;

	while (count--) {
		std::cin >> query;
		it = find_if(recipes.rbegin(), recipes.rend(), starts_with(query));
		if (it == recipes.rend()) {
			std::cout << "NO\n";
		} else {
			std::cout << it->name << '\n';
		}
	}

	return 0;
}

