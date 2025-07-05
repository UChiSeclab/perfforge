#include <bits/stdc++.h>
using namespace std;

int nod(int n) {
    int x = 0;
    int iteration_count = 0;
    for (int i = 3; i * i <= n; i++) {
        iteration_count++;
        if (n % i == 0) x += 2;
    }

    // Check for excessive odd divisor calculations
    check_odd_divisor_invariant(n, iteration_count);

    int k = sqrt(n);
    if (k * k == n)
        return x;
    else
        return x + 1;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int cnt = 0;
        int cnto = 0;
        int original_n;
        cin >> original_n;

        // Check for large composite numbers
        check_large_composite_invariant(original_n);

        int n = original_n;

        if (n == 1) {
            cout << "FastestFinger\n";
        } else if (n == 2) {
            cout << "Ashishgup\n";
        } else {
            if (n % 2 == 1)
                cout << "Ashishgup\n";
            else {
                while (n % 2 == 0) {
                    cnt++;
                    n = n / 2;
                }
                
                // Check for excessive division by 2
                check_power_of_two_invariant(cnt);

                cnto = nod(n);
                if ((cnt == 1 && cnto == 1) || n == 1)
                    cout << "FastestFinger\n";
                else
                    cout << "Ashishgup\n";
            }
        }
    }
    return 0;
}