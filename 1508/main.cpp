#include <climits>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ratio>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>
#include <tgmath.h>
#include <set>
#include <stack>
using namespace std;
using namespace std::chrono;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	private:
		const int MOD = 1e9+7;
	public:
	int rangeSum(vector<int>& nums, int n, int left, int right){
		int answer {};
		vector<int> subs {};
		for(int start {}; start < nums.size(); start++){
			for(int end {start+1}; end <= nums.size(); end++){
				subs.push_back(accumulate(nums.begin()+start, nums.begin()+end, 0));
      			}
		}
		sort(subs.begin(), subs.end());
		for(int i {left-1}; i <= right-1; i++){
			answer = (answer+subs[i])%MOD;
		}

		return answer;
	}
};

template <typename T>
void print_vector(vector<T>& v){
	cout << '{';
	for(const T &i: v){
		cout << i << ',';
	}
	cout << "\b}";
}

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<pair<vector<int>, int>> tests = {
		{{1,2,3,4}, 4 },
		{{1,2,3},4},
		{{1,2,3,4},4}
	};
	vector<pair<int, int>>tests2 = {
		{1,5},
		{3,4},
		{1,10}
	};

	vector<int> answers = {
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->rangeSum(tests[i].first, tests[i].second, tests2[i].first, tests2[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers[i] << "\n\trecived value: " << answer << '\n';

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
