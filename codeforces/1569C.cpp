#include <bits/stdc++.h>
#define LL int long long
#define NMAX 200000
#define mod 998244353
using namespace std;

void calculate_factorial(vector<int>& factorial) {
  factorial[0] = 1;
  for (LL i = 1; i <= NMAX; i++) {
    factorial[i] = (factorial[i - 1] * i) % mod;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  vector<int> factorial(NMAX);
  calculate_factorial(factorial);
  while (t--) {
    int n, max_val = -1, smax_val = -1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > max_val) {
        smax_val = max_val;
        max_val = a[i];
      } else if (a[i] > smax_val && a[i] != max_val) {
        smax_val = a[i];
      }
    }
    int max_count = count(a.begin(), a.end(), max_val);
    if (max_count > 1) {
      cout << factorial[n] << endl;
    } else if ((max_val - smax_val) > 1) {
      cout << 0 << endl;
    } else {
      /**
       * max_val - smax_val == 1
       * 2 2 3 is !nice
       * 2 3 2 is nice
       * thus, we need to find, n! - total(!nice)
       * !nice is basically when there are no (max_val - 1) values to the right of max_val
      */
    }
  }
  return 0;
}