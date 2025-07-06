#include <bits/stdc++.h>
using namespace std;

int flag = 0;
int recursion_calls = 0; // To track the number of recursive calls
int recursion_depth = 0; // To track current recursion depth

void check_excessive_recursion(int callCount) {
    if (callCount > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive exploration!" << endl;
        abort();
    }
}

void check_recursion_depth(int depth) {
    if (depth > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - deep recursion for unreachable values!" << endl;
        abort();
    }
}

void recursion(int x, int depth) {
    recursion_calls++;
    check_excessive_recursion(recursion_calls); // Check for excessive recursion calls
    check_recursion_depth(depth); // Check for excessive recursion depth

    if (x == 0) {
        if (flag == 0) cout << "YES" << endl;
        flag++;
        return;
    } else if (x < 0) {
        return;
    } else {
        recursion(x - 3, depth + 1);
        recursion(x - 7, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int x;
        flag = 0;
        recursion_calls = 0; // Reset call count for each test case
        cin >> x;
        recursion(x, 0); // Initialize recursion with depth 0
        if (flag == 0) cout << "NO" << endl;
    }
    return 0;
}