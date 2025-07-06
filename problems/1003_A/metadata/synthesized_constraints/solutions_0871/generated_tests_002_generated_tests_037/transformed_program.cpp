#include <bits/stdc++.h>
using namespace std;

// Function to check if the frequency of any element is too high
void check_repeated_element_count(int n, const vector<int>& v) {
    unordered_map<int, int> frequency;
    for (int coin : v) {
        frequency[coin]++;
        if (frequency[coin] > n / 2) {
            cerr << "Warning: Performance bottleneck condition triggered due to high frequency of duplicate elements!" << endl;
            abort();
        }
    }
}

// Function to check if there is a high density of duplicates
void check_high_density_of_duplicates(const vector<int>& v) {
    unordered_set<int> unique_elements(v.begin(), v.end());
    if (unique_elements.size() < v.size() / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to high density of duplicates!" << endl;
        abort();
    }
}

// Function to check inefficient counting mechanism
void check_inefficient_counting_mechanism(const vector<int>& v) {
    unordered_map<int, int> frequency;
    for (int coin : v) {
        frequency[coin]++;
    }
    for (auto& entry : frequency) {
        if (entry.second > v.size() / 2) {
            cerr << "Warning: Performance bottleneck condition triggered by inefficient counting mechanism!" << endl;
            abort();
        }
    }
}

int main() {
    long long n, a, max, x;
    cin >> n;
    vector<int> v;
    long long temp;
    max = 1;
    while (n-- > 0) {
        cin >> temp;
        v.push_back(temp);
    }
    
    // Insert performance checks after reading inputs
    check_repeated_element_count(v.size(), v);
    check_high_density_of_duplicates(v);
    check_inefficient_counting_mechanism(v);

    for (auto x : v) {
        a = count(v.begin(), v.end(), x);
        if (a > max) {
            max = a;
        }
    }
    cout << max;
    return 0;
}