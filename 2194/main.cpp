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
	vector<string> cellsInRange(string s){
		vector<string> answer {};
		char row_start = s[1], 
			row_end = s[4],
			col_start = s[0], 
			col_end = s[3];

		for(; col_start <= col_end; col_start++){	
			for(row_start = s[1]; row_start <= row_end; row_start++){
				answer.push_back(string(1, col_start)+row_start);
			}
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
void print_vector_s(vector<string>& v){
	cout << '{';
	for(const string &i: v){
		cout << i << ',';
	}
	cout << "\b}";
}

int main (int argc, char *argv[]) {
	vector<string> answer {};
	double elapsed_time {};

	vector<string> tests = {
		"K1:L2",
		"A1:F1"
	};

	vector<vector<string>> answers = {
		{"K1", "K2", "L1", "L2"},
		{"A1", "B1", "C1", "D1", "E1", "F1"}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->cellsInRange(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		print_vector_s(answers[i]);
		cout << "\n\trecived value: ";
		print_vector_s(answer);
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
