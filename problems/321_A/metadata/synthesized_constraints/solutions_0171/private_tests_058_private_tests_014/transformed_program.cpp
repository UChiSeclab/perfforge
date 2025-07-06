#include <bits/stdc++.h>
using namespace std;

long long a, b;
int n;
long long xx = 0, yy = 0;
char s[1024];
char cc[7] = "RULD";
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int get(char c) {
    for (int i = 0; i < 4; i++) {
        if (cc[i] == c) return i;
    }
    return -1; // To ensure function returns something
}

void check_zero_movement_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - zero cumulative movement vector!" << endl;
        abort();
    }
}

void check_large_multiplier_range_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large multiplier range!" << endl;
        abort();
    }
}

void check_frequent_translation_calls_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent get() calls!" << endl;
        abort();
    }
}

void check(long long mul) {
    int i;
    long long x = xx * mul;
    long long y = yy * mul;
    if (x == a && y == b) {
        puts("Yes");
        exit(0);
    }
    for (i = 0; i < n; i++) {
        int id = get(s[i]);
        x += dx[id];
        y += dy[id];
        if (x == a && y == b) {
            puts("Yes");
            exit(0);
        }
    }
}

int main() {
    int i, j, k;
    cin >> a >> b;
    scanf("%s", s);
    n = strlen(s);

    for (i = 0; i < n; i++) {
        int id = get(s[i]);
        xx += dx[id];
        yy += dy[id];
    }

    // Check for zero movement vector invariant
    check_zero_movement_invariant(xx == 0 && yy == 0);

    if (xx == 0 && yy == 0) {
        check(0);
    } else {
        long long tmp;
        if (xx) {
            tmp = a / xx;
            // Check for large multiplier range invariant
            check_large_multiplier_range_invariant(tmp > 5000 || tmp < -5000);
            for (long long ha = max(0ll, tmp - 5000); ha <= tmp + 5000; ha++)
                check(ha);
        }
        if (yy) {
            tmp = b / yy;
            // Check for large multiplier range invariant
            check_large_multiplier_range_invariant(tmp > 5000 || tmp < -5000);
            for (long long ha = max(0ll, tmp - 5000); ha <= tmp + 5000; ha++)
                check(ha);
        }
    }

    // Check for frequent get() calls invariant
    check_frequent_translation_calls_invariant(n > 50); // Arbitrary threshold for illustration

    puts("No");
    return 0;
}