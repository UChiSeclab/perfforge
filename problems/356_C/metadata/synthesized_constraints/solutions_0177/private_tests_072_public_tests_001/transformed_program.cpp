#include <bits/stdc++.h>
using namespace std;

// Checkers for the performance-characterizing invariants
void check_high_ones_twos(int ones, int twos, int threes, int fours) {
    if (ones > 2 * threes && twos > 2 * fours) {
        cerr << "Warning: High count of ones and twos relative to threes and fours!" << endl;
        abort();
    }
}

void check_remainder_ones_twos(int ones, int twos, int threes, int fours) {
    if (ones % 3 != 0 && threes + fours <= ones / 3) {
        cerr << "Warning: Remainder ones after distribution could cause inefficiency!" << endl;
        abort();
    }
}

void check_remainder_twos(int twos, int threes, int fours) {
    if (twos % 3 != 0 && threes + fours < 2 * twos / 3) {
        cerr << "Warning: Remainder twos after distribution could cause inefficiency!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    map<int, int> cnt;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ++cnt[a];
    }
    int ones = cnt[1], twos = cnt[2], threes = cnt[3], fours = cnt[4];
    int ans = 0;

    // Insert invariant checks after reading inputs
    check_high_ones_twos(ones, twos, threes, fours);

    if (ones >= twos) {
        ans += twos;
        threes += twos;
        ones -= twos;
        twos = 0;
    } else {
        ans += ones;
        threes += ones;
        twos -= ones;
        ones = 0;
    }

    // Insert invariant checks after redistribution logic
    check_remainder_ones_twos(ones, twos, threes, fours);

    if (ones) {
        ans += ones / 3 * 2;
        threes += ones / 3;
        ones = ones % 3;
        if (ones <= threes) {
            ans += ones;
            ones = 0;
        } else if (ones == 2 && fours >= 1) {
            ans += 2;
        } else if (ones == 1 && fours >= 2) {
            ans += 2;
        } else {
            ans = -1;
        }
    } else if (twos) {
        ans += twos / 3 * 2;
        threes += twos / 3 * 2;
        twos %= 3;
        
        // Insert invariant check for twos after potential remainder
        check_remainder_twos(twos, threes, fours);
        
        if (twos == 1) {
            if (fours) {
                ans += 1;
                twos = 0;
            } else if (threes >= 2) {
                ans += 2;
                twos = 0;
            } else {
                ans = -1;
            }
        } else if (twos == 2) {
            ans += 2;
            twos = 0;
        }
    }
    printf("%d\n", ans);
}