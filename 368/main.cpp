#include <climits>
#include <iostream>
#include <iterator>
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
	vector<int> largestDivisibleSubset(vector<int>& nums){
		set<int> dp;
		dp.insert(nums[0]);
		for(int i {1}; i < nums.size(); i++){
			for(int j {}; j < nums.size(); j++){
				cout << nums[i] << ' ' << nums[j] << '\n';
				if(nums[j] % nums[i] == 0){
					dp.insert(nums[i]);
				}
			}
		}
		vector<int> v {};
		auto it = dp.end();
		it--;
		while (!dp.empty()) {
			v.push_back(*it);
			it--;
			dp.erase(--dp.end());
		}
		return v;
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
	vector<int> answer {};
	double elapsed_time {};

	vector<vector<int>> tests = {
		{1,2,3},
		{1,2,4,8}
	};

	vector<vector<int>> answers = {
		{1,2},
		{1,2,4,8}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->largestDivisibleSubset(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		print_vector<int>(answers[i]);
		cout << "\n\trecived value: ";
		print_vector<int>(answer);
		cout << '\n';

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
