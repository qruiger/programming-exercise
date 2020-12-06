#include <bits/stdc++.h>
#define LL int long long
using namespace std;

pair<LL, LL> solve(vector<string> input) {
  pair<LL, LL> ans;
  vector<string> current_input;
  for (LL i = 0; i < input.size(); i++) {
    if (!input[i].empty()) {
      current_input.push_back(input[i]);
    }
    if (input[i].empty() || i == (input.size() - 1)) {
      unordered_map<char, LL> checker;
      for (LL j = 0; j < current_input.size(); j++) {
        for (LL k = 0; k < current_input[j].size(); k++) {
          checker[current_input[j][k]]++;
        }
      }
      for (auto it : checker) {
        ans.first = it.second ? ++ans.first : ans.first;
        ans.second =
            (it.second == current_input.size()) ? ++ans.second : ans.second;
      }
      current_input.clear();
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  fin.open("6.in");
  vector<string> input;
  while (fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  input.pop_back();
  pair<LL, LL> ans = solve(input);
  cout << "part_one = " << ans.first << endl;
  cout << "part_two = " << ans.second << endl;
  return 0;
}