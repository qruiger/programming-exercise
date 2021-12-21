#include <bits/stdc++.h>
#define LL int long long
using namespace std;

pair<int, int> solve(vector<pair<string, char>> input) {
  pair<int, int> ans(0, 0);
  string opening = "([<{";
  string closing = ")]>}";
  unordered_map<char, int> corrupt_score = {
      {')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
  unordered_map<char, int> incomplete_score = {
      {')', 1}, {']', 2}, {'}', 3}, {'>', 4}};
  vector<LL> scores;
  for (int i = 0; i < input.size(); i++) {
    stack<char> stack;
    for (int j = 0; j < input[i].first.size(); j++) {
      if (opening.find(input[i].first[j]) != -1) {
        stack.push(input[i].first[j]);
      } else {
        int pos = closing.find(input[i].first[j]);
        char eq_opening = opening[pos];
        if (stack.top() == eq_opening) {
          stack.pop();
        } else {
          input[i].second = 'c';
          ans.first += corrupt_score[input[i].first[j]];
          break;
        }
      }
    }
    input[i].second = input[i].second == 'x' ? 'i' : input[i].second;
  }
  for (int i = 0; i < input.size(); i++) {
    if (input[i].second == 'i') {
      stack<char> stack;
      LL current_score = 0;
      for (int j = 0; j < input[i].first.size(); j++) {
        if (opening.find(input[i].first[j]) != -1) {
          stack.push(input[i].first[j]);
        } else {
          int pos = closing.find(input[i].first[j]);
          char eq_opening = opening[pos];
          if (stack.top() == eq_opening) {
            stack.pop();
          }
        }
      }
      while (!stack.empty()) {
        int pos = opening.find(stack.top());
        char eq_closing = closing[pos];
        current_score = (current_score * 5) + incomplete_score[eq_closing];
        stack.pop();
      }
      scores.push_back(current_score);
    }
  }
  sort(scores.begin(), scores.end());
  ans.second = scores[scores.size() / 2];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<pair<string, char>> input;
  fin.open("10.in");
  while (fin) {
    string line;
    getline(fin, line);
    if (line != "") {
      input.push_back(make_pair(line, 'x'));
    }
  }
  pair<int, int> ans = solve(input);
  cout << "part_one = " << ans.first << endl;
  cout << "part_two = " << ans.second << endl;
  return 0;
}