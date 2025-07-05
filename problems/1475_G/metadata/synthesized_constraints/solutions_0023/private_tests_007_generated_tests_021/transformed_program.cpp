#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef vector<LL> 		VL;
#define si(n) cin>>n
#define dout(n) cout<<n<<"\n"
#define DRT() int t; si(t); while(t--)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

const int N = 2e5 + 10;
LL score[N];

// Checker function for small elements
void check_small_elements_invariant(const VL& arr) {
    int smallElementCount = count_if(arr.begin(), arr.end(), [](LL x) { return x <= 10; });
    if (smallElementCount > arr.size() / 2) {
        cerr << "Warning: small_elements_invariant triggered - too many small elements!" << endl;
        abort();
    }
}

// Checker function for repeated elements
void check_repeated_elements_invariant(const VL& arr) {
    unordered_map<LL, int> elementCount;
    for (const auto& elem : arr) {
        elementCount[elem]++;
        if (elementCount[elem] > 1) {
            cerr << "Warning: repeated_elements_invariant triggered - repeated elements detected!" << endl;
            abort();
        }
    }
}

// Checker function for high factor count
void check_high_factor_count_invariant(const VL& arr) {
    for (const auto& elem : arr) {
        int factorCount = 0;
        for (LL j = elem; j < N; j += elem) {
            factorCount++;
            if (factorCount > 100) {  // Arbitrary threshold for example purposes
                cerr << "Warning: high_factor_count_invariant triggered - too many factors!" << endl;
                abort();
            }
        }
    }
}

int main(){
    off;
    DRT(){
        memset(score, 0, sizeof(score));
        LL n; cin >> n;
        VL arr(n);
        rep(i,0,n){
            cin >> arr[i];
        }

        // Insert checks after reading input
        check_small_elements_invariant(arr);
        check_repeated_elements_invariant(arr);
        check_high_factor_count_invariant(arr);

        sort(ALL(arr), greater<LL>());
        LL ans = 0;
        rep(i,0,n){
            LL mm = 0;
            LL can = 1;
            if(i-1 >= 0 && arr[i] == arr[i-1])
                can = 0;
            if(can)
            for(LL j=arr[i]; j < N; j+= arr[i]){
                mm = max(mm, score[j]);
            }
            score[arr[i]] = max(score[arr[i]], mm);
            score[arr[i]]++;
            ans = max(ans, score[arr[i]]);
        }
        dout(n - ans);
    }
    return 0;
}