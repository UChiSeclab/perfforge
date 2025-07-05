#include <bits/stdc++.h>
using namespace std;
vector<long long> digits;

// Checkers for performance bottlenecks
void check_binary_search_depth(long long iterations) {
    if (iterations > 300) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive binary search iterations!" << endl;
        abort();
    }
}

void check_iterative_complexity(long long countBitsMid) {
    if (countBitsMid > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high iterative complexity within blocks!" << endl;
        abort();
    }
}

void check_bit_length_frequency(long long bitCountCalls) {
    if (bitCountCalls > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of bit length calculations!" << endl;
        abort();
    }
}

long long countBits(long long x) {
    return (long long)ceil(log10(x + 1));
}

pair<long long, long long> BS(long long k) {
    long long l = 0, r = 1000000000, Sum = 0;
    long long iterations = 0; // Track binary search iterations
    long long bitCountCalls = 0; // Track countBits calls

    while (l != r) {
        long long mid = (l + r + 1) / 2;
        long long sum = 0;
        long long cur = 9, cum = 9;
        ++iterations;

        for (long long i = 1; i < countBits(mid); i++) {
            ++bitCountCalls;
            sum += i * ((cur * (cur + 1)) / 2 + cur * (mid - cum));
            cur *= 10;
            cum += cur;
        }

        check_iterative_complexity(countBits(mid)); // Check inside the loop

        cum -= cur;
        sum += countBits(mid) * ((mid - cum) * (mid - cum + 1)) / 2;
        if (sum >= k)
            r = mid - 1;
        else
            l = mid;
        Sum = sum;
    }

    check_binary_search_depth(iterations); // Check once binary search is complete
    check_bit_length_frequency(bitCountCalls); // Check frequency of countBits

    long long sum = 0;
    long long cur = 9, cum = 9;
    for (long long i = 1; i < countBits(l); i++) {
        sum += i * ((cur * (cur + 1)) / 2 + cur * (l - cum));
        cur *= 10;
        cum += cur;
    }
    cum -= cur;
    sum += countBits(l) * ((l - cum) * (l - cum + 1)) / 2;
    return {l, sum};
}

long long K_Digit(long long x, long long i) {
    string s;
    while (x != 0) {
        s += (x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    if (i - 1 >= 0 && i - 1 <= s.length() - 1)
        return (long long)(s[i - 1] - '0');
    else
        return 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    digits.push_back(0);
    long long ten = 1;
    for (long long i = 1; i < 18; i++) {
        digits.push_back(9ll * ten * i);
        ten *= 10ll;
    }
    for (long long i = 1; i < 18; i++) digits[i] += digits[i - 1];
    long long q;
    cin >> q;
    for (long long u = 0; u < q; u++) {
        long long k;
        cin >> k;
        long long l = BS(k).first;
        long long sum = BS(k).second;
        k -= sum;
        long long r =
            lower_bound(digits.begin(), digits.end(), k) - 1 - digits.begin();
        if (r >= 0) k -= digits[r];
        long long before = k / (r + 1);
        if (r >= 1) {
            long long index = k % (r + 1);
            if (index == 0) {
                index = r + 1;
                before--;
            }
            before += (long long)pow(10, r);
            cout << K_Digit(before, index) << endl;
        } else
            cout << before << endl;
    }
    return 0;
}