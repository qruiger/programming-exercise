#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;

pair<int, int> solve(vector<int> numbers, vector<vector<vector<int>>> boards) {
  pair<int, int> ans(0, 0);
  unordered_map<int, bool> winner_boards;
  vector<vector<vector<int>>> row_col_tracker;
  vector<vector<vector<int>>> marker;
  for (int i = 0; i < boards.size(); i++) {
    vector<int> initial_state(5, 0);
    vector<vector<int>> row_col;
    row_col.push_back(initial_state);
    row_col.push_back(initial_state);
    row_col_tracker.push_back(row_col);
    vector<vector<int>> board_marker;
    for (int j = 0; j < 5; j++) {
      board_marker.push_back(initial_state);
    }
    marker.push_back(board_marker);
  }
  for (int i = 0; i < numbers.size(); i++) {
    for (int board = 0; board < boards.size(); board++) {
      for (int board_row = 0; board_row < 5; board_row++) {
        for (int board_col = 0; board_col < 5; board_col++) {
          if (boards[board][board_row][board_col] == numbers[i]) {
            row_col_tracker[board][0][board_row]++;
            row_col_tracker[board][1][board_col]++;
            marker[board][board_row][board_col]++;
          }
        }
      }
      for (int j = 0; j < 5; j++) {
        int win = -1;
        if (row_col_tracker[board][0][j] == 5) {
          win = 0;
        } else if (row_col_tracker[board][1][j] == 5) {
          win = 1;
        }
        if (win > -1 && !winner_boards[board]) {
          int unmarked_sum = 0;
          for (int board_row = 0; board_row < 5; board_row++) {
            if (win == 0 && board_row == j) {
              continue;
            }
            for (int board_col = 0; board_col < 5; board_col++) {
              if (win == 1 && board_col == j) {
                continue;
              }
              if (marker[board][board_row][board_col] == 0) {
                unmarked_sum += boards[board][board_row][board_col];
              }
            }
          }
          if (winner_boards.size() == 1) {
            ans.first = unmarked_sum * numbers[i];
          }
          if (winner_boards.size() == boards.size()) {
            ans.second = unmarked_sum * numbers[i];
          }
          winner_boards[board] = true;
        }
      }
    }
  }
  return ans;
}

void remove_empty_strings(vector<string>& vec) {
  vec.erase(remove_if(vec.begin(), vec.end(), [](string s) { return s == ""; }),
            vec.end());
}

vector<int> vector_string_to_int(vector<string> vec) {
  vector<int> vec_i;
  for (auto it : vec) {
    vec_i.push_back(stoi(it));
  }
  return vec_i;
}

vector<vector<vector<int>>> get_boards(vector<string> input) {
  vector<vector<vector<int>>> boards;
  vector<vector<int>> board;
  for (int input_it = 1; input_it < input.size(); input_it++) {
    if (input[input_it] == "" || input_it == input.size() - 1) {
      if (board.size()) {
        boards.push_back(board);
      }
      board.clear();
    } else {
      vector<string> board_row;
      split(board_row, input[input_it], boost::is_any_of(" "));
      remove_empty_strings(board_row);
      board.push_back(vector_string_to_int(board_row));
    }
  }
  return boards;
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<string> input;
  ifstream fin;
  fin.open("4.in");
  while (fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  vector<string> raw_numbers;
  split(raw_numbers, input[0], boost::is_any_of(","));
  vector<int> numbers = vector_string_to_int(raw_numbers);
  vector<vector<vector<int>>> boards = get_boards(input);
  pair<int, int> ans = solve(numbers, boards);
  cout << "part_one = " << ans.first << endl;
  cout << "part_two = " << ans.second << endl;
  return 0;
}