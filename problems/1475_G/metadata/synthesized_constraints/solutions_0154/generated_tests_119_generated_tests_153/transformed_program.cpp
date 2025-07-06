#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 2 * 1e5 + 5;
int dp[maxN];

// Phase 3: Checker functions
void check_large_value_processing(int maxValue) {
    if (maxValue > 199000) { // Arbitrary threshold close to the upper limit of 200,000
        cerr << "Warning: Performance bottleneck condition triggered - large value processing!" << endl;
        abort();
    }
}

void check_high_frequency_elements(int n, int frequencyThreshold) {
    if (n > frequencyThreshold) { // Assuming frequency threshold based on array size
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of specific elements!" << endl;
        abort();
    }
}

void check_maximal_range_of_values(int minValue, int maxValue) {
    if ((maxValue - minValue) > 198000) { // Arbitrary range close to the maximum span of values
        cerr << "Warning: Performance bottleneck condition triggered - maximal range of values!" << endl;
        abort();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
    us t;
    cin >> t;
	
    while(t--){
        int n;
        cin >> n;
		
        int data[n];
        for(int x = 0; x < n; x++){
            cin >> data[x];
        }

        // Phase 4: Insert checks after input
        int maxValue = *max_element(data, data + n);
        int minValue = *min_element(data, data + n);
        check_large_value_processing(maxValue);
        check_maximal_range_of_values(minValue, maxValue);

        fill(dp, dp + maxN, 0);
		
        for(int x = 0; x < n; x++){
            dp[data[x]]++;
        }

        // Check for high frequency of specific elements
        int frequencyThreshold = 200; // Example threshold
        for(int x = 0; x < n; x++) {
            check_high_frequency_elements(dp[data[x]], frequencyThreshold);
        }

        int ans = 0;
        for(int x = 1; x <= 200000; x++){
            int best = dp[x];
            for(int y = 1; y * y <= x; y++){
                if(x % y == 0){
                    if(x / y != x) best = max(best, dp[x] + dp[x / y]);
                    if(x / y != y){
                        best = max(best, dp[x] + dp[y]);
                    }
                }
            }
            dp[x] = best;
            ans = max(ans, dp[x]);
        }
		
        cout << n - ans << "\n";
    }
	
    return 0;
}