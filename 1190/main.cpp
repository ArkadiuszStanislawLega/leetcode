#include <algorithm>
#include <cassert>
#include <chrono>
#include <climits>
#include <iostream>
#include <iterator>
#include <map>
#include <ratio>
#include <set>
#include <stack>
#include <string>
#include <tgmath.h>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using namespace std::chrono;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  string reverseParentheses(string s) {
    string answer{};
    stack<int> counter{};

    for (const char &c : s) {
      switch (c) {
      case '(':
        counter.push(answer.size());
        break;

      case ')':
        reverse(answer.begin() + counter.top(), answer.end());
        counter.pop();
        break;

      default:
        answer += c;
        break;
      }
    }
    return answer;
  }
};

template <typename T> void print_vector(vector<T> &v) {
  cout << '{';
  for (const T &i : v) {
    cout << i << ',';
  }
  cout << "\b}";
}

int main(int argc, char *argv[]) {
  string answer{};
  double elapsed_time{};

  vector<string> tests = {"(abcd)", "(u(love)i)", "(ed(et(oc))el)"};

  vector<string> answers = {"dcba", "iloveu", "leetcode"};

  for (int i{}; i < tests.size(); i++) {
    Solution *s = new Solution();

    auto start = high_resolution_clock::now();
    answer = s->reverseParentheses(tests[i]);
    auto end = high_resolution_clock::now();

    cout << "test " << i + 1 << "\n\ttarget value: " << answers[i]
         << "\n\trecived value: " << answer << '\n';

    elapsed_time = duration<double, milli>(end - start).count();
    cout << "\nelapsed time " << elapsed_time << "ms";

    assert(answer == answers.at(i));
    cout << " -> passed\n";
  }

  // auto time_counter = duration_cast<microseconds> (time_start - time_start);
  // cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

  return 0;
}
