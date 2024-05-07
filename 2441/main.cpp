#include <climits>
#include <iostream>
#include <iterator>
#include <new>
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
	int findMaxK(vector<int>& nums){
		int i {}, j {};
		sort(nums.begin(), nums.end());
		j = nums.size()-1;

		while(i < j && nums[i] < 0 && nums[j] > 0){
			if(abs(nums[i]) == nums[j]) return nums[j];
			if(abs(nums[i]) > nums[j]) i++;
			else j--;
		}
		return -1;
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
		{-1, 2, -3, 3},
		{-1, 10, 6, 7, -7, 1},
		{-10, 8,6,7,-2,-3},
		{-30,34,1,32,26,-9,-30,22,-49,29,48,47,38,4,43,12,-1,-8,11,-37,32,40,9,15,-34,-34,-16,-5,26,-44,-36,-13,-16,10,39,-17,-22,17,-16},
		{-9,-43,24,-23,-16,-30,-38,-30},
		{-49,8,19,-39,37,22,-39,4,37,8,20,-2,-4,-5,14,-14,-27,24,30,3,-12,19,22,28,-3,-6,6,22,37,27,16,27,-6,-49,31,29}
	};

	vector<int> answers = {
		3,
		7,
		-1,
		34,
		-1,
		27
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findMaxK(tests[i]);
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
