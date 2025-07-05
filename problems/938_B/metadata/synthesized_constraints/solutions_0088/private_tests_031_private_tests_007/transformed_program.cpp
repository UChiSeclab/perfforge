#include <bits/stdc++.h>
using namespace std;
long long int a[2000000];

void check_large_separation(int leftPos, int rightPos) {
    if ((rightPos - leftPos) > 100000) { // arbitrary large threshold
        cerr << "Warning: Performance bottleneck condition triggered - Large separation between prizes!" << endl;
        abort();
    }
}

void check_far_from_start(int firstPrize, int lastPrize) {
    if (firstPrize > 500000 || lastPrize < 500000) { // arbitrary center point
        cerr << "Warning: Performance bottleneck condition triggered - Prizes far from start positions!" << endl;
        abort();
    }
}

void check_sparse_distribution(vector<int>& prizes) {
    for (size_t i = 1; i < prizes.size(); ++i) {
        if ((prizes[i] - prizes[i - 1]) > 100000) { // arbitrary sparse threshold
            cerr << "Warning: Performance bottleneck condition triggered - Sparse distribution of prizes!" << endl;
            abort();
        }
    }
}

int main() {
    long long int n;
    cin >> n;
    
    vector<int> prizes(n);
    for (long long int j = 0; j < n; j++) {
        long long int num;
        cin >> num;
        prizes[j] = num;
        a[num] = -1;
    }
    
    // Insert performance checks
    check_large_separation(prizes.front(), prizes.back());
    check_far_from_start(prizes.front(), prizes.back());
    check_sparse_distribution(prizes);
    
    long long int r = 1, m = 1000000;
    long long int t = 0, i = 0;
    
    while (i < n) {
        t++;
        if (a[++r] == -1) i++;
        if (a[--m] == -1) i++;
    }
    
    cout << t;
    return 0;
}