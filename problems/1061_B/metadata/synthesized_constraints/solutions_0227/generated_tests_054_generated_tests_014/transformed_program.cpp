void check_variance_invariant(const vector<long long>& v) {
       long long min_height = *min_element(v.begin(), v.end());
       long long max_height = *max_element(v.begin(), v.end());
       if ((max_height - min_height) > 100) { // Arbitrary large variance threshold
           cerr << "Warning: Performance bottleneck condition triggered - high variance in block heights!" << endl;
           abort();
       }
   }