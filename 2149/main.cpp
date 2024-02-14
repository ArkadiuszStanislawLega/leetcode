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
	vector<int> rearrangeArray(vector<int>& nums){
		int pos {}, neg {1};
		vector<int> answer (nums.size());

		for(int i {}; i < nums.size(); i++){
			if(nums[i] > 0){
				answer[pos] = nums[i];
				pos += 2;
				continue;
			}

			answer[neg] = nums[i];
			neg += 2;
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
	vector<int> answer {};
	double elapsed_time {};

	vector<vector<int>> tests = {
		{3,1,-2,-5,2,-4},
		{-1,1}
	};

	vector<vector<int>> answers = {
		{3,-2,1,-5,2,-4},
		{1,-1}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->rearrangeArray(tests[i]);
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
