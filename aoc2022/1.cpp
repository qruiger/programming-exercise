#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
using namespace std;

int part_one(vector<vector<int>> a) {
  int ans = -1;
  for (auto row : a) {
    int sum = 0;
    for (auto el : row) {
      sum += el;
    }
    ans = sum > ans ? sum : ans;
  }
  return ans; 
}

int part_two(vector<vector<int>> a) {
  vector<int> ans_arr(a.size());
  for (auto row : a) {
    int sum = 0;
    for (auto el : row) {
      sum += el;
    }
    ans_arr.push_back(sum);
  }
  sort(ans_arr.begin(), ans_arr.end(), greater<int>());
  int ans = accumulate(ans_arr.begin(), ans_arr.begin() + 3, 0);
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
  vector<vector<int>> a;
  vector<int> b;
  for (int i = 0; i < input.size(); i++) {
    if (!input[i].empty()) {
      b.push_back(stoi(input[i]));
    } else {
      a.push_back(b);
      b.clear();
    }
  }
  cout << "part_one = " << part_one(a) << endl;
  cout << "part_two = " << part_two(a) << endl;
  return 0;
}