#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

std::vector<std::set<int>> graph;
std::vector<int> parent, size;

int findSet(int at) {
    if (parent[at] == at) return at;
    return parent[at] = findSet(parent[at]);
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return;
    if (size[a] < size[b]) std::swap(a, b);
    parent[b] = a;
    size[a] += size[b];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    // Invariant checks for performance bottlenecks
    check_union_find_invariant(n, m);
    check_sort_invariant(n);
    check_graph_operations_invariant(n, m);

    graph.resize(n);
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    
    std::vector<int> vec(n);
    std::map<int, int> nz;
    for (int i = 0; i < n; i++) vec[i] = i, parent[i] = i, nz[i] = 3;
    std::sort(vec.begin(), vec.end(), [&](int a, int b) {
        return graph[a].size() != graph[b].size()
                   ? graph[a].size() < graph[b].size()
                   : (12345 ^ a) < (12345 ^ b);
    });
    for (int _i = 0; _i < n; _i++) {
        int i = vec[_i];
        for (auto it = nz.begin(); it != nz.end();) {
            bool del = false;
            if (graph[i].find(it->first) == graph[i].end()) {
                unionSets(i, it->first);
                nz[it->first]--;
                if (nz[it->first] == 0) del = true;
            }
            if (del)
                it = nz.erase(it);
            else
                it++;
        }
    }
    for (int i = 0; i < n; i++) findSet(i);
    std::set<int> uniq;
    for (int el : parent) uniq.insert(el);
    std::cout << (uniq.size() - 1) << '\n';
}