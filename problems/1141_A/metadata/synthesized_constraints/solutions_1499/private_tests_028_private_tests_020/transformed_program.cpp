#include <bits/stdc++.h>
using namespace std;

// Invariant checkers
void check_high_initial_ratio(int n, int m) {
    if (m / n > 1000000) { // Arbitrary large threshold for ratio
        cerr << "Warning: High initial ratio condition triggered!" << endl;
        abort();
    }
}

void check_high_divisibility(int n, int m) {
    int c = m / n;
    int twoCount = 0, threeCount = 0;
    
    while (c % 2 == 0) {
        c /= 2;
        twoCount++;
    }
    while (c % 3 == 0) {
        c /= 3;
        threeCount++;
    }
    
    if (twoCount > 20 || threeCount > 20) { // Arbitrary threshold for divisibility
        cerr << "Warning: High divisibility condition triggered!" << endl;
        abort();
    }
}

void check_large_queue_size(size_t queueSize) {
    if (queueSize > 100000) { // Arbitrary large threshold for queue size
        cerr << "Warning: Large queue size condition triggered!" << endl;
        abort();
    }
}

int calcu(int a, int b) {
    if (b == a) return 0;
    if (b == 0 || a == 0) return -1;
    if (b % a) return -1;
    
    check_high_initial_ratio(a, b); // High initial ratio check

    int c = b / a;
    if (c % 2 && c % 3) return -1;

    check_high_divisibility(a, b); // High divisibility check

    queue<int> que;
    bool finish = false;
    int times = 0;
    que.push(c);

    while (!finish) {
        int len = que.size();
        
        check_large_queue_size(len); // Large queue size check

        for (int i = 0; i < len; i++) {
            int n = que.front();
            que.pop();
            if (n == 1) return times;
            if (!(n % 2)) que.push(n / 2);
            if (!(n % 3)) que.push(n / 3);
        }
        times++;
        if (que.empty()) {
            finish = true;
        }
    }
    return -1;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << calcu(a, b);
    return 0;
}