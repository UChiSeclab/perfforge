#include <bits/stdc++.h>
using namespace std;

// Function: Checks for infinite loop with no progress
void check_infinite_loop_condition(long long x, long long y, long long a, long long b, long long mx, long long my) {
    if ((x == 0 && mx == 0) || (y == 0 && my == 0)) {
        cerr << "Warning: Infinite loop with no progress towards target!" << endl;
        abort();
    }
}

// Function: Checks for redundant moves causing no net displacement
void check_redundant_moves(const string &s) {
    int lr_balance = 0, ud_balance = 0;
    for (char c : s) {
        if (c == 'L') lr_balance++;
        if (c == 'R') lr_balance--;
        if (c == 'U') ud_balance++;
        if (c == 'D') ud_balance--;
    }
    if (lr_balance == 0 && ud_balance == 0) {
        cerr << "Warning: Command sequence results in no net displacement!" << endl;
        abort();
    }
}

// Function: Checks if a large multiplier would be necessary to reach the target
void check_large_multiplier_condition(long long a, long long b, long long mx, long long my) {
    if (std::abs(a) > std::abs(mx * 100) || std::abs(b) > std::abs(my * 100)) {
        cerr << "Warning: Large multiplier required for reaching target position!" << endl;
        abort();
    }
}

int main() {
    long long a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    // Use checker for redundant moves
    check_redundant_moves(s);

    long long x = 0, y = 0;
    for (int i = 0; i < s.size(); i++) {
        if (x == a && y == b) {
            cout << "Yes\n";
            return 0;
        }
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
    }
    
    long long mx = x, my = y;
    check_infinite_loop_condition(x, y, a, b, mx, my);

    if (x * a < 0 && y * b < 0) {
        cout << "No\n";
        return 0;
    }

    check_large_multiplier_condition(a, b, mx, my);

    long long t, x1 = 0, y1 = 0;
    if (x != 0) x1 = a / x;
    if (y != 0) y1 = b / y;

    if (x * a > 0 && y * b > 0) {
        t = min(x1, y1);
        x += x * (t - 10000);
        y += y * (t - 10000);
    } else if (x * a > 0) {
        x += (x1 - 10000) * x;
        y += (x1 - 10000) * y;
    } else if (y * b > 0) {
        x += (y1 - 10000) * x;
        y += (y1 - 10000) * y;
    }

    int z = 10000;
    while (z--)
        for (int i = 0; i < s.size(); i++) {
            if (x == a && y == b) {
                cout << "Yes\n";
                return 0;
            }
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;
            if (s[i] == 'L') x--;
            if (s[i] == 'R') x++;
        }
    
    cout << "No\n";
}