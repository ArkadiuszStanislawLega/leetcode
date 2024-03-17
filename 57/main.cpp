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
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
		vector<vector<int>> answer {};
		int n {}, i {};

		n = intervals.size();

		while(i < n && intervals[i][1] < newInterval[0]){
			answer.push_back(intervals[i]);
			i++;
		}

		while(i < n && intervals[i][0] <= newInterval[1]){
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
			i++;
		}

		answer.push_back(newInterval);

		while(i < n){
			answer.push_back(intervals[i]);
			i++;
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

	vector<pair<vector<vector<int>>, vector<int>>> tests = {
		{{{1,3},{6,9}},{2,5}},
		{{{1,2},{3,5},{6,7},{8,10},{12,16}},{4,8}}
	};

	vector<vector<vector<int>>> answers = {
		{{1,5},{6,9}},
		{{1,2},{3,10},{12,16}},
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->insert(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: {";
		for(auto v : answers[i]){
			print_vector<int>(v);
		}
		cout << "}\n\trecived value: {";
		for(auto v : answer){
			print_vector<int>(v);
		}
		cout << "}\n";

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		//assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
