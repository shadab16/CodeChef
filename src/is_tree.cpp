#include <bitset>
#include <iostream>
#include <list>
#include <vector>

typedef std::vector<std::list<int> > adjacency_list_t;

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int V, E;
	std::cin >> V >> E;
	adjacency_list_t adj(V);

	for (int i = 0, u = 0, v = 0; i < E; ++i) {
		std::cin >> u >> v;
		adj[u - 1].push_back(v - 1);
	}

	std::bitset<10000> visited;
	std::list<int> queue;

	visited[0] = true;
	queue.merge(adj[0]);

	while (!queue.empty()) {

		int u = queue.front();
		queue.pop_front();

		if (visited[u]) {
			std::cout << "NO" << std::endl;
			return 0;
		}

		visited[u] = true;
		queue.merge(adj[u]);
	}

	std::cout << (int(visited.count()) == V ? "YES" : "NO") << std::endl;

	return 0;
}

