#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_frequent_sorting(int n, int sortCount) {
    if (n > 80 && sortCount > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting on large array" << endl;
        abort();
    }
}

void check_nested_loop_complexity(int n, int trainingSessions) {
    if (n > 80 && trainingSessions > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive training sessions in nested loops" << endl;
        abort();
    }
}

void check_low_rank_diversity(int n, const vector<long long>& a) {
    int lowRankCount = count(a.begin(), a.end(), 1);
    if (lowRankCount > (n / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered - high count of low rank soldiers" << endl;
        abort();
    }
}

int main() {
    vector<long long> a;
    long long temp, n, k;
    int ans = 0;
    cin >> n >> k;
    while (n--) {
        cin >> temp;
        a.push_back(temp);
    }
    int i, j;
    int ss = a.size();
    
    // Perform initial checks
    check_low_rank_diversity(ss, a);
    
    int sortCount = 0;
    int trainingSessions = 0;

    while (a[0] < k) {
        ++ans;
        ++trainingSessions;
        
        for (i = 0; i < ss; ++i) {
            for (j = i; j + 1 < ss && a[j] == a[j + 1] && a[j] != k; ++j)
                ;
            ++a[j];
            i = j;
            sort(a.begin(), a.end());
            ++sortCount;
        }
        
        // Check after each round of training and sorting
        check_frequent_sorting(ss, sortCount);
        check_nested_loop_complexity(ss, trainingSessions);
    }

    cout << ans << endl;
    a.clear();
    return 0;
}