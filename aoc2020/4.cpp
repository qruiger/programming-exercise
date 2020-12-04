#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#define LL int long long
using namespace std;

bool part_one(vector<string> passport, vector<string> compulsory_fields) {
  unordered_map<string, bool> checker;
  for (LL i = 0; i < passport.size(); i++) {
    vector<string> field;
    split(field, passport[i], boost::is_any_of(":"));
    checker[field[0]] = true;
  }
  for (LL i = 0; i < compulsory_fields.size(); i++) {
    if (!checker[compulsory_fields[i]]) {
      return false;
    }
  }
  return true;
}

bool len_min_max_violated(string field, LL min, LL max, LL min_len) {
  if (field.length() < min_len || stoll(field) < min || stoll(field) > max) {
    return true;
  }
  return false;
}

bool part_two(vector<string> passport, vector<string> compulsory_fields) {
  unordered_map<string, string> checker;
  bool invalid;
  for (LL i = 0; i < passport.size(); i++) {
    vector<string> field;
    split(field, passport[i], boost::is_any_of(":"));
    checker[field[0]] = field[1];
  }

  for (LL i = 0; i < compulsory_fields.size(); i++) {
    invalid = false;
    if (checker.find(compulsory_fields[i]) == checker.end()) {
      return false;
    } else {
      if (compulsory_fields[i] == "byr") {
        invalid =
            len_min_max_violated(checker[compulsory_fields[i]], 1920, 2002, 4);
      } else if (compulsory_fields[i] == "iyr") {
        invalid =
            len_min_max_violated(checker[compulsory_fields[i]], 2010, 2020, 4);
      } else if (compulsory_fields[i] == "eyr") {
        invalid =
            len_min_max_violated(checker[compulsory_fields[i]], 2020, 2030, 4);
      } else if (compulsory_fields[i] == "hcl") {
        string value = checker[compulsory_fields[i]];
        if (value[0] != '#' || value.length() != 7) {
          invalid = true;
        }
        if (!invalid) {
          for (LL j = 1; j <= 6; j++) {
            LL ascii = (LL)value[j];
            if (!((ascii >= 48 && ascii <= 57) ||
                  (ascii >= 97 && ascii <= 102))) {
              invalid = true;
            }
          }
        }
      } else if (compulsory_fields[i] == "hgt") {
        string value = checker[compulsory_fields[i]];
        string units = value.substr(value.length() - 2);
        if (units == "cm") {
          LL number = stoll(value.substr(0, 3));
          if (number < 150 || number > 193) {
            invalid = true;
          }
        } else if (units == "in") {
          LL number = stoll(value.substr(0, 2));
          if (number < 59 || number > 76) {
            invalid = true;
          }
        } else {
          invalid = true;
        }
      } else if (compulsory_fields[i] == "ecl") {
        string value = checker[compulsory_fields[i]];
        vector<string> allowed_fields = {"amb", "blu", "brn", "gry",
                                         "grn", "hzl", "oth"};
        bool value_exists = false;
        for (LL j = 0; j < allowed_fields.size(); j++) {
          if (allowed_fields[j] == value) {
            value_exists = true;
            break;
          }
        }
        if (!value_exists) {
          invalid = true;
        }
      } else if (compulsory_fields[i] == "pid") {
        string value = checker[compulsory_fields[i]];
        if (value.length() != 9) {
          invalid = true;
        }
        if (!invalid) {
          for (LL j = 0; j < value.size(); j++) {
            LL ascii = (LL)value[j];
            if (!(ascii >= 48 && ascii <= 57)) {
              invalid = true;
              break;
            }
          }
        }
      }
    }
    if (invalid) {
      return false;
    }
  }
  return true;
}

pair<LL, LL> solve(vector<string> input) {
  vector<string> passport;
  vector<string> compulsory_fields = {"byr", "iyr", "eyr", "hgt",
                                      "hcl", "ecl", "pid"};
  pair<LL, LL> ans(0, 0);

  for (LL i = 0; i < input.size(); i++) {
    if (!input[i].empty()) {
      vector<string> input_split;
      split(input_split, input[i], boost::is_any_of(" "));
      passport.insert(passport.end(), input_split.begin(), input_split.end());
    } else {
      ans.first =
          part_one(passport, compulsory_fields) ? ans.first + 1 : ans.first;
      ans.second =
          part_two(passport, compulsory_fields) ? ans.second + 1 : ans.second;
      passport.clear();
    }
    if (i == input.size() - 1) {
      ans.first =
          part_one(passport, compulsory_fields) ? ans.first + 1 : ans.first;
      ans.second =
          part_two(passport, compulsory_fields) ? ans.second + 1 : ans.second;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  fin.open("4.in");
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