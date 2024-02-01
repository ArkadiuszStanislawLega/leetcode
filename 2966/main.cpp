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
	vector<vector<int>> divideArray(vector<int>& nums, int k){
		vector<vector<int>> answer{};
        	sort(nums.begin(), nums.end());
		for (auto it = nums.begin(); it != nums.end(); it += 3) {
			if (	*(it+1) - *it <= k && 
				*(it+2) - *(it+1) <= k && 
				*(it+2) - *it <= k ) {
					answer.push_back({*it, *(it+1), *(it+2)});
					continue;
			}
			return {};
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
	vector<vector<int>> answer {};
	double elapsed_time {};

	vector<pair<vector<int>, int>> tests = {
		{{1,3,4,8,7,9,3,5,1}, 2},
		{{1,3,3,2,7,3},3},
	};

	vector<vector<vector<int>>> answers = {
		{{1,1,3},{3,4,5},{7,8,9}},
		{},
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->divideArray(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		for(auto& a : answers[i]){
			print_vector<int>(a);
		}
		cout << "\n\trecived value: ";
		for(auto& a : answer){
			print_vector<int>(a);
		}
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
