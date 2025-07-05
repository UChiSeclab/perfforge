#include <bits/stdc++.h>

using namespace std;

// Checkers for performance bottlenecks
void check_high_input_range(int maxN) {
    if (maxN >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - High input range." << endl;
        abort();
    }
}

void check_frequent_prime_checks(int testCases, int maxN) {
    if (testCases > 1 && maxN >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - Frequent prime checks." << endl;
        abort();
    }
}

void check_large_prime_collection(const std::vector<int>& primes) {
    if (primes.size() > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - Large prime collection." << endl;
        abort();
    }
}

inline long long read() {
    long long sign = 1;
    long long x = 0;
    char ch;
    while (!isdigit(ch = getchar()))
        if (ch == '-') sign = -1;
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * sign;
}

inline void wonl() { putchar('\n'); }

inline void ww(long long k) {
    if (k < 0) putchar('-'), k *= -1;
    char ch[20];
    int num = 0;
    while (k) ch[++num] = k % 10, k /= 10;
    if (num == 0) ch[++num] = 0;
    while (num) putchar(ch[num--] + '0');
}

const int N = 1e6 + 4;

template <typename T, typename... V>
inline void wonl(T t, V... v) {
    ww(t);
    if (sizeof...(v)) putchar(' ');
    wonl(v...);
}

int main() {
    int t = 1;
    t = read();
    int arr[t], mx = 0;
    for (int i = 0; i < t; i++) {
        arr[i] = read();
        if (arr[i] > mx) mx = arr[i];
    }

    // Checkers inserted after reading input and determining the maximum value.
    check_high_input_range(mx);
    check_frequent_prime_checks(t, mx);

    vector<bool> nos(mx + 1, 1);
    for (int i = 2; i * i <= mx; i++) {
        if (nos[i]) {
            for (int j = i * i; j <= mx; j += i) {
                if (nos[j]) nos[j] = 0;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= mx; i++) {
        if (nos[i]) primes.push_back(i);
    }

    // Check the size of the prime collection
    check_large_prime_collection(primes);

    for (int i = 0; i < t; i++) {
        vector<int>::iterator it;
        it = upper_bound(primes.begin(), primes.end(), arr[i]);
        int x = (int)sqrt(arr[i]);
        vector<int>::iterator it2;
        it2 = upper_bound(primes.begin(), primes.end(), x);
        int ans = it - it2;
        wonl(ans + 1);
    }
    
    return 0;
}