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

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
	vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k){
		sort(score.begin(), score.end(), [&](vector<int> x, vector<int> y){ return x[k] > y[k];});
		return score;
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

	vector<pair<vector<vector<int>>,int>> tests = {
		{{{10,6,9,1}, {7,5,11,2}, {4,8,3,15}}, 2},
		{{{3,4},{5,6}},0}
	};

	vector<vector<vector<int>>> answers = {
		{{7,5,11,2},{10,6,9,1},{4,8,3,15}},
		{{5,6},{3,4}}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->sortTheStudents(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		for(auto &j: answers[i]){
			print_vector<int>(j);
		}
		cout << "\n\trecived value: ";
		for(auto &j: answer){
			print_vector<int>(j);
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
