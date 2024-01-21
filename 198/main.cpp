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

class Solution {
	public:
	int rob(vector<int>& nums){
		if(nums.size() <= 1)
			return nums.back();

		if(nums.size() == 2)
			return max(nums[0], nums[1]);

		vector<int> dp (nums.size()+1);
		dp[1] = nums[0];
		dp[2] = nums[1];

		for (int i {3}; i <= nums.size(); i++){
			dp[i] = max(dp[i-2], dp[i-3]) + nums[i - 1];
		}
		return max(dp[nums.size()], dp[nums.size()-1]);
	}
};

void print_vector(vector<int>& v){
	cout << '{';
	for(const int &i: v){
		cout << i << ',';
	}
	cout << "\b}";
}

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<vector<int>> tests = {
		{1,2,3,1},
		{2,7,9,3,1}
	};

	vector<int> answers = {
		4,
		12
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->rob(tests[i]);
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
/*
        vector<int> evens {}, odds {};

		for(int i {}; i < nums.size(); i++){
			if(i%2){
				odds.push_back(nums[i]);
				continue;
			} 
			evens.push_back(nums[i]);
		}
		return max(accumulate(evens.begin(), evens.end(), 0), accumulate(odds.begin(), odds.end(), 0));

*/

