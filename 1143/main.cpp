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
	int lengestCommonSubsequence(string text1, string text2){
		vector<vector<int>> counter = vector<vector<int>>(text1.size()+1, vector<int> (text2.size()+1));
		for(int i {1}; i <= text1.size(); i++){
			for(int j {1}; j <= text2.size(); j++){
				counter[i][j] = text1[i-1] == text2[j-1] ? 
									counter[i-1][j-1]+1 : 
									max(counter[i-1][j], counter[i][j-1]);
			}
		}
		return counter[text1.size()][text2.size()];
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

	vector<pair<string, string>>tests = {
		{"abcde", "ace"},
		{"abc", "abc"},
		{"abc", "def"},
		{"ezupkr", "ubmrapg"}
	};

	vector<int> answers = {
		3,
		3,
		0,
		2
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->lengestCommonSubsequence(tests[i].first, tests[i].second);
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
