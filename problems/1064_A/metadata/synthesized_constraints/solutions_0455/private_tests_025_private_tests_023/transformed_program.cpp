#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int answer = 1e9 + 7;

void read() { 
    cin >> a >> b >> c; 
}

// Performance invariant checkers
void check_small_sticks_invariant(int a, int b, int c) {
    if (a <= 10 && b <= 10 && c <= 10) {
        cerr << "Warning: Performance bottleneck condition triggered - Small initial stick lengths causing extensive iteration!" << endl;
        abort();
    }
}

void check_similar_sticks_invariant(int a, int b, int c) {
    if (abs(a - b) <= 5 && abs(b - c) <= 5 && abs(c - a) <= 5) {
        cerr << "Warning: Performance bottleneck condition triggered - Similar stick lengths causing large search space exploration!" << endl;
        abort();
    }
}

int main() {
    read();
    
    // Place invariant checks after reading inputs
    check_small_sticks_invariant(a, b, c);
    check_similar_sticks_invariant(a, b, c);
    
    if (b > a && b > c) swap(b, c);
    if (c > a && c > b) swap(a, c);
    
    for (int i = a; i <= 400; i++)
        for (int j = b; j <= i; j++)
            for (int k = c; k <= i; k++) {
                if (i < j + k) 
                    answer = min(answer, i - a + j - b + k - c);
            }
    
    cout << answer;
}