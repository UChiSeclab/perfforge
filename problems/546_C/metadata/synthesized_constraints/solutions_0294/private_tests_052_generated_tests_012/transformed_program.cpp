#include <bits/stdc++.h>
using namespace std;

// Checker functions to detect performance bottlenecks
void check_repetitive_state(int counter) {
    if (counter > 100) { // Example threshold for detecting potential infinite cycle
        cerr << "Warning: Performance bottleneck condition triggered - game potentially in a repetitive state!" << endl;
        abort();
    }
}

void check_high_iterations(int counter) {
    if (counter > 100) { // Example threshold for detecting too many iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive number of fights!" << endl;
        abort();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) {
        int n;
        cin >> n;
        deque<int> A, B;
        for (int i = 1; i <= 2; i++) {
            int sizee = 0;
            cin >> sizee;
            if (i == 1) {
                for (int j = 0; j < sizee; j++) {
                    int ele;
                    cin >> ele;
                    A.push_back(ele);
                }
            } else {
                for (int j = 0; j < sizee; j++) {
                    int ele;
                    cin >> ele;
                    B.push_back(ele);
                }
            }
        }
        int times = 10000000;
        int counter = 0;
        while (times-- && A.size() && B.size()) {
            if (A.front() < B.front()) {
                B.push_back(A.front());
                B.push_back(B.front());
                A.pop_front();
                B.pop_front();
            } else if (A.front() > B.front()) {
                A.push_back(B.front());
                A.push_back(A.front());
                A.pop_front();
                B.pop_front();
            } else {
                break;
            }
            counter++;
            // Check for repetitive game state and high iterations
            check_repetitive_state(counter);
            check_high_iterations(counter);
        }
        if (A.size() && B.size() && counter == 10000000)
            cout << -1;
        else {
            cout << counter << " ";
            if (A.size())
                cout << 1;
            else
                cout << 2;
        }
    }
    return 0;
}