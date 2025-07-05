#include <bits/stdc++.h>

int cmp(const void *p, const void *q) {
    return ((*((long long int *)p)) - (*((long long int *)q)));
}

// Check for high number of operations with small increment steps
void check_high_operations_with_small_increments(int contiguous_count, int k) {
    if (k > 100000 && contiguous_count < 10) { // Arbitrary threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered - high operations with small steps!" << endl;
        abort();
    }
}

// Check for high frequency of equal elements near median
void check_high_frequency_of_equal_elements(int contiguous_count, int n) {
    if (contiguous_count > n / 10) { // Arbitrary threshold, e.g., more than 10% of the array
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of equal elements!" << endl;
        abort();
    }
}

// Check for large k relative to array size
void check_large_k_relative_to_n(int k, int n) {
    if (k > n * 10000) { // Arbitrary threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered - large k relative to n!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    qsort(arr, n, sizeof(long long int), cmp);
    
    int c = (n / 2);
    int d = (n / 2);

    // Check for the condition: high frequency of equal elements near median
    while (d < n && arr[c] == arr[d]) {
        d++;
    }
    d--;
    
    // Calculate the contiguous count of equal elements
    int contiguous_count = d - c + 1;
    
    // Perform checks at appropriate points
    check_high_frequency_of_equal_elements(contiguous_count, n);
    check_large_k_relative_to_n(k, n);
    
    long long int ans = arr[n / 2];
    
    while (k > 0) {
        if ((d - c + 1) > k) {
            break;
        }
        
        k -= (d - c + 1);
        arr[n / 2]++;
        d++;

        // Check for high number of operations with small increment steps
        check_high_operations_with_small_increments(d - c + 1, k);
        
        while (d < n && arr[d] == arr[n / 2]) {
            d++;
        }
        d--;
    }
    
    printf("%lld\n", arr[n / 2]);
}