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
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    int answer{};
    sort(boxTypes.begin(), boxTypes.end(),
         [&](vector<int> a, vector<int> b) { return a[1] > b[1]; });

    for (auto &v : boxTypes) {
      if (v[0] < truckSize) {
        answer += v[0] * v[1];
        truckSize -= v[0];
        continue;
      }
      answer += truckSize * v[1];
      return answer;
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
  int answer{};
  double elapsed_time{};

  vector<pair<vector<vector<int>>, int>> tests = {
      {{{1, 3}, {2, 2}, {3, 1}}, 4}, {{{5, 10}, {2, 5}, {4, 7}, {3, 9}}, 10}};

  vector<int> answers = {8, 91};

  for (int i{}; i < tests.size(); i++) {
    Solution *s = new Solution();

    auto start = high_resolution_clock::now();
    answer = s->maximumUnits(tests[i].first, tests[i].second);
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
