#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_iteration_invariant(long long current_range) {
    if (current_range > 100000000) {
        cerr << "Warning: Large iteration range - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_large_digit_extraction_invariant(long long number) {
    if (number > 1000000000000) {
        cerr << "Warning: Large number digit extraction - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_function_call_frequency(long long n) {
    if (n > 100000000) {
        cerr << "Warning: High function call frequency - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_sequence_position_invariant(long long position, long long now, long long len) {
    if (position > now + len) {
        cerr << "Warning: Sequence position vs. length computation - potential performance bottleneck!" << endl;
        abort();
    }
}

// Main function and logic
void R(int &x) { scanf("%d", &x); }
void R(long long &x) { scanf("%lld", &x); }
int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
vector<pair<long long, long long> > AA;
int an[500];

long long g(long long x, int it) {
    vector<int> ker;
    while (x) {
        ker.push_back(x % 10);
        x /= 10;
    }
    reverse((ker).begin(), (ker).end());
    return ker[it];
}

long long f(long long n) {
    check_function_call_frequency(n); // Check for high function call frequency
    if (n <= 9) return n;
    n -= 9;
    if (n <= 90 * 2) {
        return g(10 + (n - 1) / 2, (n - 1) % 2);
    }
    n -= 90 * 2LL;
    if (n <= 900 * 3) {
        return g(100 + (n - 1) / 3, (n - 1) % 3);
    }
    n -= 900 * 3LL;
    if (n <= 9000 * 4LL) {
        return g(1000 + (n - 1) / 4, (n - 1) % 4);
    }
    n -= 9000 * 4LL;
    if (n <= 90000 * 5LL) {
        return g(10000 + (n - 1) / 5, (n - 1) % 5);
    }
    n -= 90000 * 5LL;
    if (n <= 900000 * 6LL) {
        return g(100000 + (n - 1) / 6, (n - 1) % 6);
    }
    n -= 900000 * 6LL;
    if (n <= 9000000 * 7LL) {
        return g(1000000 + (n - 1) / 7, (n - 1) % 7);
    }
    n -= 9000000 * 7LL;
    if (n <= 90000000 * 8LL) {
        return g(10000000 + (n - 1) / 8, (n - 1) % 8);
    }
    n -= 90000000 * 8LL;
    if (n <= 900000000 * 9LL) {
        return g(100000000 + (n - 1) / 9, (n - 1) % 9);
    }
    return -1;
}

int main() {
    int q;
    R(q);
    for (int i = 0; i < (q); ++i) {
        long long x;
        R(x);
        AA.push_back({x, i});
    }
    sort((AA).begin(), (AA).end());
    long long now = 0;
    long long len = 0;
    int it = 0;
    for (int i = (1); i <= (9); ++i) {
        len++;
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len); // Check sequence position vs. length
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    for (int i = (10); i <= (99); ++i) {
        len += 2;
        check_large_iteration_invariant(len); // Check for large iteration range
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len);
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    for (int i = (100); i <= (999); ++i) {
        len += 3;
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len);
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    for (int i = (1000); i <= (9999); ++i) {
        len += 4;
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len);
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    for (int i = (10000); i <= (99999); ++i) {
        len += 5;
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len);
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    for (int i = (100000); i <= (999999); ++i) {
        len += 6;
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len);
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    for (int i = (1000000); i <= (9999999); ++i) {
        len += 7;
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len);
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    for (int i = (10000000); i <= (99999999); ++i) {
        len += 8;
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len);
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    for (int i = (100000000); i <= (482720320); ++i) {
        len += 9;
        while (it < q && now + len >= AA[it].first) {
            check_sequence_position_invariant(AA[it].first, now, len);
            an[AA[it].second] = f(AA[it].first - now);
            it++;
        }
        now += len;
    }
    W(vector<int>(an, an + q));
    return 0;
}