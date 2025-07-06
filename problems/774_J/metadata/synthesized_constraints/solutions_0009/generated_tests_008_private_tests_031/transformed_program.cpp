void check_k_comparison_invariant(int n, int k, int questionMarkCount) {
       if (k < n / 10 && questionMarkCount > 0) {  // Example threshold
           cerr << "Warning: Performance bottleneck due to frequent k comparison with many '?' characters." << endl;
           abort();
       }
   }