#include <bits/stdc++.h>
using namespace std;

// Checker for high disparity in welfare
void check_high_disparity(int maxWelfare, const vector<int>& welfares) {
    int sum = 0;
    for (int welfare : welfares) {
        sum += welfare;
    }
    double averageWelfare = static_cast<double>(sum) / welfares.size();
    
    if (maxWelfare > 2 * averageWelfare) { // Arbitrary threshold: max is more than twice the average
        cerr << "Warning: High disparity in welfare detected!" << endl;
        abort();
    }
}

// Checker for uneven distribution of welfare
void check_uneven_distribution(const vector<int>& welfares) {
    int countLow = 0;
    for (int welfare : welfares) {
        if (welfare < 0.1 * *max_element(welfares.begin(), welfares.end())) { // Arbitrary threshold for "low"
            countLow++;
        }
    }
    
    if (countLow > 0.9 * welfares.size()) { // If more than 90% of welfares are low
        cerr << "Warning: Uneven distribution of welfare detected!" << endl;
        abort();
    }
}

int main() {
    int n, counter = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the welfare list
    sort(a.begin(), a.end());
    
    // Add checkers before the costly loop
    check_high_disparity(a.back(), a); // Check for high disparity
    check_uneven_distribution(a); // Check for uneven distribution
    
    for (int i = 0; i < a.size(); ++i) {
        while (a[i] < a[a.size() - 1]) {
            ++counter;
            a[i]++;
        }
    }
    
    cout << counter;
}