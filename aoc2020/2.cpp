#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#define LL int long long
using namespace std;

bool part_one(string password,
              LL min_occurence,
              LL max_occurence,
              char required_character) {
  LL required_character_count = 0, ans = 0;
  for (LL j = 0; j < password.length(); j++) {
    if (password[j] == required_character) {
      required_character_count++;
    }
    if ((required_character_count > max_occurence) ||
        ((required_character_count < min_occurence) &&
         ((password.length() - (j + 1)) <
          (min_occurence - required_character_count)))) {
      return false;
    }
  }
  return true;
}

pair<LL, LL> solve(vector<string> input) {
  pair<LL, LL> ans(0, 0);
  vector<string> current_input;
  for (LL i = 0; i < input.size(); i++) {
    split(current_input, input[i], boost::is_any_of(" "));
    vector<string> temp;
    split(temp, current_input[0], boost::is_any_of("-"));
    LL first_number = stoll(temp[0]);
    LL second_number = stoll(temp[1]);
    char required_character = current_input[1][0];
    string password = current_input[2];
    // part one
    ans.first =
        part_one(password, first_number, second_number, required_character)
            ? ans.first + 1
            : ans.first;
    // part two
    if (((password[first_number - 1] == required_character) &&
         (password[second_number - 1] != required_character)) ||
        ((password[second_number - 1] == required_character) &&
         (password[first_number - 1] != required_character))) {
      ans.second++;
    }
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
  pair<LL, LL> ans;
  ans = solve(input);
  cout << "part_one = " << ans.first << endl;
  cout << "part_two = " << ans.second << endl;
  return 0;
}