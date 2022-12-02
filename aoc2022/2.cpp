#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int match_score(char ops, char self) {
  if (self == ops) return 3;
  if (self == 'A') { if (ops == 'C') return 6; return 0; }
  if (self == 'B') { if (ops == 'A') return 6; return 0; }
  if (self == 'C') { if (ops == 'B') return 6; return 0; }
  return -1;
}

int part_one(vector<string> input, map<char, int> base_score) {
  int ans = 0;
  for (auto it : input) ans += base_score[it[2]] + match_score(it[0], it[2] - 23);
  return ans;
}

char select(char ops, char self) {
  if (self == 'X') {
    if (ops == 'A') return 'C';
    if (ops == 'B') return 'A';
    if (ops == 'C') return 'B';
  }
  if (self == 'Z') {
    if (ops == 'A') return 'B';
    if (ops == 'B') return 'C';
    if (ops == 'C') return 'A';
  }
  return ops;
}

int part_two(vector<string> input, map<char, int> base_score) {
  int ans = 0;
  for (auto it : input) {
    char new_self = select(it[0], it[2]);
    ans += base_score[new_self + 23] + match_score(it[0], new_self);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  fin.open("2.in");
  while (fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  input.pop_back();
  map<char,int>base_score {{'X', 1}, {'Y', 2}, {'Z', 3}};
  cout << "part_one = " << part_one(input, base_score) << endl;
  cout << "part_two = " << part_two(input, base_score) << endl;
  return 0;
}