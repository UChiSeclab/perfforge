#include <bits/stdc++.h>
using namespace std;

void check_net_movement(int net_x, int net_y, int a, int b) {
    if (net_x == 0 && net_y == 0 && (a != 0 || b != 0)) {
        cerr << "Warning: Performance bottleneck condition triggered - net movement is zero but target is non-zero." << endl;
        abort();
    }
}

void check_far_target(int net_x, int net_y, int a, int b) {
    if ((net_x != 0 || net_y != 0) && ((a % net_x != 0) || (b % net_y != 0))) {
        cerr << "Warning: Performance bottleneck condition triggered - net movement doesn't divide target evenly." << endl;
        abort();
    }
}

void check_oscillation(const string& str) {
    if (str.find('U') != string::npos && str.find('D') != string::npos && str.size() == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - oscillating movement pattern detected." << endl;
        abort();
    }
    if (str.find('L') != string::npos && str.find('R') != string::npos && str.size() == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - oscillating movement pattern detected." << endl;
        abort();
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int s = (abs(a) + abs(b));
    if (s == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    string str;
    cin >> str;

    // Calculate net movement in one cycle of the command string
    int x = 0, y = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'U') y++;
        if (str[i] == 'D') y--;
        if (str[i] == 'R') x++;
        if (str[i] == 'L') x--;
    }
    int net_x = x, net_y = y;

    // Insert checks
    check_net_movement(net_x, net_y, a, b);
    check_far_target(net_x, net_y, a, b);
    check_oscillation(str);

    int t = abs(x) + abs(y);
    int v;
    if (t == 0) {
        v = t;
    } else {
        v = s / t;
    }
    v = max(v - 110, 0);
    x *= v;
    y *= v;
    for (int j = 0; j < 10100100; j++) {
        int i = j % str.size();
        if (x == a && y == b) {
            cout << "Yes" << endl;
            return 0;
        }
        if (str[i] == 'U') y++;
        if (str[i] == 'D') y--;
        if (str[i] == 'R') x++;
        if (str[i] == 'L') x--;
    }
    cout << "No" << endl;
}