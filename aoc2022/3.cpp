#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int get_final_ans(vector<char> ans_v) {
  int ans = 0;
  for (auto it : ans_v) {
    if (it >= 97) {
      ans += (int)it - 96;
    } else if (it >= 65) {
      ans += (int)it - 38;
    }
  }
  return ans;
}

int part_one(vector<string> input) {
  int ans = 0;
  vector<char> ans_v;
  for (int i = 0; i < input.size(); i++) {
    int j = 0, k = (input[i].size() / 2) ;
    unordered_map<char, int> store1, store2;
    while (j < input[i].size() / 2) {
      store1[input[i][j++]]++;
      store2[input[i][k++]]++;
    }
    for (auto it : store1) {
      if (store2[it.first]) {
        ans_v.push_back(it.first);
      }
    }
  }
  for (auto it : ans_v) {
    if (it >= 97) {
      ans += (int)it - 96;
    } else if (it >= 65) {
      ans += (int)it - 38;
    }
  }
  return get_final_ans(ans_v);
}

int part_two(vector<string> input) {
  int ans = 0;
  vector<char> ans_v;
  for (int i = 0; i < input.size(); i+=3) {
    unordered_map<char, int> store1, store2, store3;
    for (auto it : input[i]) store1[it]++;
    for (auto it : input[i+1]) store2[it]++;
    for (auto it : input[i+2]) store3[it]++;
    for (auto it : store1) {
      if (store2[it.first] && store3[it.first]) {
        ans_v.push_back(it.first);
      }
    }
  }
  return get_final_ans(ans_v);
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  fin.open("3.in");
  while (fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  input.pop_back();
  cout << "part_one = " << part_one(input) << endl;
  cout << "part_two = " << part_two(input) << endl;
  return 0;
}