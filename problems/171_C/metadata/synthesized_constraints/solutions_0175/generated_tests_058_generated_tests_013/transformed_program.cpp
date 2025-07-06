#include <bits/stdc++.h>
using namespace std;

// Checker function to detect potential performance bottlenecks due to high iteration counts
void check_max_iterations_invariant(int n) {
    if (n == 100) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum iterations reached!" << endl;
        abort();
    }
}

int main(int argc, char* argv[]) {
    int n;
    vector<int> vi;
    cin >> n;

    // Place the check after reading the first input to preemptively catch the slow condition
    check_max_iterations_invariant(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vi.push_back(a);
        sum += a * (i + 1);
    }
    cout << sum;
    return 0;
}