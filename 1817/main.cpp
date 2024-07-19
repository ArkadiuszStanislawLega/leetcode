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
#include <unordered_set>
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
	vector<int> findingUsersActiveMinutes(vector<vector<int>>& minutes, int k){
		vector<int> answer (k);
		unordered_map<int, unordered_set<int>> counter {};
		for(auto &i : minutes){
			counter[i[0]].insert(i[1]);
		}
		for(auto i : counter){
			answer[i.second.size()-1]++;
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

	vector<pair<vector<vector<int>>,int>> tests = {
		{{{0,5},{1,2},{0,2},{0,5},{1,3}},5},
		{{{1,1},{2,2},{2,3}},4}
	};

	vector<vector<int>> answers = {
		{0,2,0,0,0},
		{1,1,0,0}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findingUsersActiveMinutes(tests[i].first,tests[i].second);
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
