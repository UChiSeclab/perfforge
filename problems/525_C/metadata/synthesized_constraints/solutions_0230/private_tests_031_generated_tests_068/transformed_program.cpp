#include <bits/stdc++.h>
using namespace std;

// Phase 3: Implementing Checkers
void check_large_range_invariant(int max_length, int min_length) {
    if ((max_length - min_length) > 1000000) { // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered due to large range of stick lengths!" << endl;
        abort();
    }
}

void check_max_length_frequency_invariant(int max_length, long long frequency) {
    if (max_length == 1000000 && frequency > 10000) { // Arbitrary frequency threshold
        cerr << "Warning: Performance bottleneck condition triggered due to high frequency of max length sticks!" << endl;
        abort();
    }
}

void check_unmatched_sticks_invariant(const long long cnt[], int size) {
    int unmatched_count = 0;
    for (int i = 0; i <= size; ++i) {
        if (cnt[i] % 2 != 0) {
            unmatched_count++;
        }
    }
    if (unmatched_count > 50000) { // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered due to many unmatched sticks!" << endl;
        abort();
    }
}

void check_imbalance_invariant(const long long cnt[], int size) {
    int imbalance_count = 0;
    for (int i = 0; i <= size; ++i) {
        if (cnt[i] % 4 != 0) {
            imbalance_count++;
        }
    }
    if (imbalance_count > 50000) { // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered due to imbalance in pairable sticks!" << endl;
        abort();
    }
}

int main() {
    long long cnt[1000010] = {0};
    long long n, a, ma = -1;
    long long ans = 0, last = 0;
    cin >> n;
    long long min_length = 1000001; // Initialize to be higher than max possible length
    for (long long i = 0; i < n; ++i) {
        cin >> a;
        if (a > ma) ma = a;
        if (a < min_length) min_length = a;
        cnt[a]++;
    }

    // Phase 4: Place checkers after input processing
    check_large_range_invariant(ma, min_length);
    check_max_length_frequency_invariant(ma, cnt[ma]);
    check_unmatched_sticks_invariant(cnt, 1000000);
    check_imbalance_invariant(cnt, 1000000);

    for (long long i = ma; i >= 1; --i) {
        if ((cnt[i] % 2 == 1) && (cnt[i - 1])) {
            --cnt[i];
            ++cnt[i - 1];
        } else if ((cnt[i] % 2 == 1) && !cnt[i - 1]) {
            --cnt[i];
        }
    }
    ans += ((cnt[ma] / 4) * ma * ma);
    cnt[ma] %= 4;
    last = (cnt[ma] ? ma : 0);
    for (long long i = ma - 1; i >= 1; --i) {
        if (cnt[last] && cnt[i] >= 2) {
            ans += (i * last);
            cnt[i] -= 2;
            cnt[last] -= 2;
        }
        ans += ((cnt[i] / 4) * i * i);
        cnt[i] %= 4;
        last = (cnt[i] ? i : last);
    }
    cout << ans << endl;
    return 0;
}