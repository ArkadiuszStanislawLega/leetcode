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
		int i2 {}, counter {};
		for(int i {}; i < text1.size(); i++){

			for(int j {i2}; j < text2.size(); j++){
				if(text1[i] == text2[j]){
					counter++;
					i2 = j+1;
					break;
				}
			}
		}
		return counter;
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
		{"ezupkr", "ubmrapg"},
		{"oxcpqrsvwf", "shmtulqrypy"}
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
