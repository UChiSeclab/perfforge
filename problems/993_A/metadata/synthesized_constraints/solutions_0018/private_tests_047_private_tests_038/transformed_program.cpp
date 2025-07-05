#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y;
};

node s1[4];
node s2[4];

long long int dist2(node a, node b) {
    long long ans = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return ans;
}

long long int cross_prod(node v1, node v2) {
    long long int k = v1.x * v2.y - v2.x * v1.y;
    if (k < 0)
        return -1;
    else if (k == 0)
        return 0;
    else
        return 1;
}

int comp_dist(node c, node a, node b) {
    long long int d1 = dist2(a, b), d2 = dist2(a, c), d3 = dist2(c, b);
    long long int d = d2 * d3;
    d = sqrtl(d);
    if (d * d != d2 * d3) return 0;
    if (d1 == d2 + d3 + 2 * d) return 1;
    return 0;
}

int in(node pt, node sq[]) {
    for (int i = 0; i < 4; i++) {
        if (pt.x == sq[i].x && pt.y == sq[i].y) return 1;
    }
    vector<int> x;
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        node v1, v2;
        v1.x = sq[j].x - sq[i].x;
        v1.y = sq[j].y - sq[i].y;
        v2.x = pt.x - sq[i].x;
        v2.y = pt.y - sq[i].y;
        if (comp_dist(pt, sq[i], sq[j])) {
            return 1;
        }
        x.push_back(cross_prod(v1, v2));
    }
    for (int i = 0; i < 4; i++) {
        if (x[i] != x[0]) return 0;
    }
    return 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    node mid1;
    mid1.x = mid1.y = 0;
    int l1;
    for (int i = 0; i < 4; i++) {
        cin >> s1[i].x >> s1[i].y;
        mid1.x += s1[i].x;
        mid1.y += s1[i].y;
    }
    l1 = abs(s1[0].x - s1[1].x) + abs(s1[0].y - s1[1].y);

    node s2[4];
    node mid2;
    mid2.x = mid2.y = 0;
    for (int i = 0; i < 4; i++) {
        cin >> s2[i].x >> s2[i].y;
        mid2.x += s2[i].x;
        mid2.y += s2[i].y;
    }

    // Integrate invariant checker for large search space
    check_search_space_invariant(201, 201);

    // Count the number of checks performed and integrate an invariant checker
    int num_checks = 0;

    for (int i = -100; i <= 100; i++) {
        for (int j = -100; j <= 100; j++) {
            node pt;
            pt.x = i;
            pt.y = j;
            if (in(pt, s1) && in(pt, s2)) {
                cout << "YES\n";
                return 0;
            }
            num_checks++;
        }
    }

    // Integrate invariant checker for expensive computations
    check_expensive_computation_invariant(num_checks);

    cout << "NO\n";
    return 0;
}