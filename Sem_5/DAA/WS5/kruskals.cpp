// Kruskals with disjoin sets
#include <iostream>
#include <vector>
#include <algorithm>

class DisjoinSet {
    std::vector<int> parent;
    int size;
public:
    DisjoinSet(int size) {
        this->size = size;
        parent.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) {
            return;
        }
        parent[xRoot] = yRoot;
    }
};

int main() {

    int n, m;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;

    std::cout << "Enter number of edges: ";
    std::cin >> m;

    std::vector<std::pair<int, std::pair<int, int>>> edges;
    std::cout << "Enter edges as (s, d, weight)" << std::endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    std::sort(edges.begin(), edges.end());

    DisjoinSet ds(n);
    int cost = 0;
    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;
        if (ds.find(u) != ds.find(v)) {
            cost += w;
            ds.merge(u, v);
        }
    }

    std::cout << cost << std::endl;

    return 0;
}