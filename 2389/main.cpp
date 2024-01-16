#include <climits>
#include <iostream>
#include <iterator>
#include <ratio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>
#include <tgmath.h>
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
	private: 

	public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries){
		vector<int> 	answer {}, 
				temp (nums.size());

		sort(nums.begin(), nums.end());
		temp[0] = nums[0];

		for(int i {1}; i < nums.size(); i++ ){
			temp[i] = temp[i-1] + nums[i];
		}

		for(const int& i : queries){
			int it = upper_bound(temp.begin(), temp.end(),i) - temp.begin();
			answer.push_back(it);
		}

		return answer;
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
	vector<int> answer {};
	double elapsed_time {};

	vector<pair<vector<int>, vector<int>>> tests = {
		{{4,5,2,1},{3,10,21}},
		{{2,3,4,5},{1}}
	};

	vector<vector<int>> answers = {
		{2,3,4},
		{0}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->answerQueries(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		print_vector(answers[i]);
		cout << "\n\trecived value: ";
		print_vector(answer);

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
