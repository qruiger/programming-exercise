#include <bits/stdc++.h>
#define LL int long long
using namespace std;

LL part_one(vector<string> input, LL right_shift, LL down_shift) {
  LL ans = 0;
  for (LL row = down_shift, col = right_shift; row < input.size();
       row += down_shift) {
    if (input[row][col] == '#') {
      ans++;
    }
    col += right_shift;
    if (col > (input[row].size() - 1)) {
      col %= input[row].size();
    }
  }
  return ans;
}

LL part_two(vector<string> input, LL part_one_ans) {
  LL ans = part_one_ans;
  vector<pair<LL, LL>> slopes;
  slopes.push_back(make_pair(1, 1));
  slopes.push_back(make_pair(5, 1));
  slopes.push_back(make_pair(7, 1));
  slopes.push_back(make_pair(1, 2));

  for (auto it = slopes.begin(); it != slopes.end(); it++) {
    ans *= part_one(input, it->first, it->second);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  fin.open("3.in");
  vector<string> input;
  while (fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  input.pop_back();

  LL part_one_ans = part_one(input, 3, 1);
  cout << "part_one = " << part_one_ans << endl;
  cout << "part_two = " << part_two(input, part_one_ans) << endl;
  return 0;
}