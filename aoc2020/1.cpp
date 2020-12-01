#include <bits/stdc++.h>
#define LL int long long
using namespace std;

LL part_one(LL a[], LL n, LL expected_sum) {
  LL left = 0;
  LL right = n - 1;
  while (left <= right) {
    LL current_sum = a[left] + a[right];
    if (current_sum == expected_sum) {
      return a[left] * a[right];
    } else if (current_sum > expected_sum) {
      right--;
    } else {
      left++;
    }
  }
  return -1;
}

LL part_two(LL a[], LL n, LL expected_sum) {
  for (LL i = 0; i < n - 2; i++) {
    LL left = i + 1;
    LL right = n - 1;
    while (left < right) {
      LL current_sum = a[left] + a[right] + a[i];
      if (current_sum == expected_sum) {
        return a[left] * a[right] * a[i];
      } else if (current_sum > expected_sum) {
        right--;
      } else {
        left++;
      }
    }
  }
  return -1;
}

int main () {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  fin.open("1.in");
  while(fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  input.pop_back();
  LL a[input.size() + 5];
  for (LL i = 0; i < input.size(); i++) {
    a[i] = stoll(input[i]);
  }
  sort(a, a + input.size());
  cout << "part_one = " << part_one(a, input.size(), 2020) << endl;
  cout << "part_two = " << part_two(a, input.size(), 2020) << endl;
  return 0;
}
