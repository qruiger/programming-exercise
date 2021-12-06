#include <bits/stdc++.h>
#define LL int long long
using namespace std;

LL part_one(LL a[], LL n) {
  LL ans = 0;
  for (LL i = 1; i < n; i++) {
    ans = a[i] > a[i - 1] ? ans + 1 : ans;
  }
  return ans;
}

LL part_two(LL a[], LL n) {
  LL previous_sum = a[0] + a[1] + a[2], current_sum = 0, ans = 0;
  for (LL i = 1; i < n - 2; i++) {
    current_sum = a[i] + a[i + 1] + a[i + 2];
    ans = current_sum > previous_sum ? ans + 1 : ans;
    previous_sum = current_sum;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  fin.open("1.in");
  while (fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  input.pop_back();
  LL a[input.size() + 5];
  for (LL i = 0; i < input.size(); i++) {
    a[i] = stoll(input[i]);
  }
  cout << "part_one = " << part_one(a, input.size()) << endl;
  cout << "part_two = " << part_two(a, input.size()) << endl;
  return 0;
}
