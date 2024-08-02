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
	public:
	int minSwaps(vector<int>& nums){
		int answer {}, ones_number {}, zeros_number {}, sliding_zeros {}, sliding_ones {};
		ones_number = accumulate(nums.begin(), nums.end(), 0);
		zeros_number = nums.size()-ones_number;

		for(int start {}; start < nums.size(); start++){
			if(start+zeros_number >= nums.size()){
				break;
			} 

			int current_window = accumulate(nums.begin()+start, nums.begin()+start+zeros_number, 0);
			sliding_zeros = max(sliding_zeros, zeros_number-current_window);
			sliding_ones = max(sliding_ones, ones_number - current_window);
			cout << current_window << ',' << sliding_ones << ',' << sliding_zeros << '\n';
		}
		return min(sliding_ones , sliding_zeros);
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

	vector<vector<int>> tests = {
		{0,1,0,1,1,0,0},
		{0,1,1,1,0,0,1,1,0},
		{1,1,0,0,1}
	};

	vector<int> answers = {
		1,
		2,
		0
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->minSwaps(tests[i]);
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
