#include <bits/stdc++.h>
using namespace std;

unsigned long long h, w, n;
vector<unsigned long long> factorials;
vector<pair<int, int> > coords;
unsigned long long primaldialga = 1000000007;
vector<unsigned long long> invfact;
vector<unsigned long long> coorddp;

unsigned long long powerpower(unsigned long long s, unsigned long long power) {
    if (power == 0) return 1;
    unsigned long long counter = 1;
    unsigned long long acc = s;
    vector<unsigned long long> memo;
    memo.push_back(acc);
    while (2 * counter <= power) {
        counter *= 2;
        acc = (acc * acc) % primaldialga;
        memo.push_back(acc);
    }
    acc = 1;
    int tracker = 0;
    while (power != 0) {
        if (power % 2 == 1) acc = (acc * memo[tracker]) % primaldialga;
        tracker++;
        power /= 2;
    }
    acc %= primaldialga;
    return acc;
}

unsigned long long nchoosek(int n, int k) {
    unsigned long long step1 = factorials[n];
    unsigned long long step2 = (invfact[k] * invfact[n - k]) % primaldialga;
    unsigned long long step3 = (step1 * step2) % primaldialga;
    return step3;
}

unsigned long long waystone(int coordindex) {
    if (coorddp[coordindex] != -1) return coorddp[coordindex];
    pair<int, int> tangerage = coords[coordindex];
    unsigned long long acc = 0;
    for (int i = 0; i < n; i++) {
        if (coords[i].first <= tangerage.first &&
            coords[i].second <= tangerage.second &&
            (coords[i].first != tangerage.first ||
             coords[i].second != tangerage.second)) {
            unsigned long long intermed = waystone(i);
            unsigned long long travers =
                nchoosek((tangerage.first - coords[i].first) +
                         (tangerage.second - coords[i].second),
                         tangerage.first - coords[i].first);
            unsigned long long toAdd = (intermed * travers) % primaldialga;
            acc = (acc + toAdd) % primaldialga;
        }
    }
    unsigned long long totalit =
        nchoosek(tangerage.first + tangerage.second - 2, tangerage.first - 1);
    coorddp[coordindex] = (totalit + (primaldialga - acc)) % primaldialga;
    return coorddp[coordindex];
}

void check_large_combinatorial_calculations(unsigned long long h, unsigned long long w) {
    if (h + w > 150000) {  // Threshold based on problem constraints.
        cerr << "Warning: Large combinatorial calculations - Potential performance bottleneck!" << endl;
        abort();
    }
}

void check_modular_exponentiation_usage(unsigned long long h, unsigned long long w) {
    if (h + w > 150000) {  // Similar threshold as above since it derives from factorial calculations.
        cerr << "Warning: Heavy modular exponentiation usage - Potential performance bottleneck!" << endl;
        abort();
    }
}

void check_large_black_cell_density(unsigned long long n) {
    if (n > 1500) {  // Threshold to consider many black cells potentially affecting path dynamics.
        cerr << "Warning: High density of black cells - Potential performance bottleneck!" << endl;
        abort();
    }
}

void check_dense_intermediate_path_calculations(unsigned long long h, unsigned long long w, unsigned long long n) {
    if ((h + w > 150000) && (n > 1500)) {  // Combination of constraints indicating dense paths.
        cerr << "Warning: Dense intermediate path calculations - Potential performance bottleneck!" << endl;
        abort();
    }
}

int main() {
    cin >> h >> w >> n;
    check_large_combinatorial_calculations(h, w);
    check_modular_exponentiation_usage(h, w);
    check_large_black_cell_density(n);
    check_dense_intermediate_path_calculations(h, w, n);

    coords = vector<pair<int, int> >(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second;
        if (coords[i].first == h && coords[i].second == w) {
            cout << 0 << endl;
            return 0;
        }
    }
    coords[n].first = h;
    coords[n].second = w;
    factorials = vector<unsigned long long>(h + w + 1);
    invfact = vector<unsigned long long>(h + w + 1);
    coorddp = vector<unsigned long long>(n + 1, -1);
    factorials[0] = 1;
    for (int i = 1; i <= h + w; i++) {
        factorials[i] = i * factorials[i - 1];
        factorials[i] %= primaldialga;
    }
    for (int i = 0; i <= h + w; i++) {
        invfact[i] = powerpower(factorials[i], primaldialga - 2);
    }
    cout << waystone(n) << endl;
    return 0;
}