#include <climits>
#include <iostream>
#include <iterator>
#include <memory>
#include <ratio>
#include <string>
#include <tuple>
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
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2){
		vector<vector<int>> answer {};
		map<int, int> counter {};
		for(auto i : items1){
			counter[i[0]] += i[1];
		}
		for(auto i : items2){
			counter[i[0]] += i[1];
		}
		//sort(counter.begin(), counter.end(), [&](pair<int, int> a, pair<int, int> b) {return a.first > b.second; });
		for(auto i : counter){
			answer.push_back({i.first, i.second});
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

	vector<pair<vector<vector<int>>, vector<vector<int>>>> tests = {
		{{{1,1},{4,5},{3,8}},{{3,1},{1,5}}},
		{{{1,1},{3,2},{2,3}},{{2,1},{3,2},{1,3}}},
		{{{1,3},{2,2}},{{7,1},{2,2},{1,4}}}
	};

	vector<vector<vector<int>>> answers = {
		{{1,6},{3,9},{4,5}},
		{{1,4},{2,4},{3,4}},
		{{1,7},{2,4},{7,1}}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->mergeSimilarItems(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		for(auto j : answers[i]){
			print_vector<int>(j);
		}
		cout << "\n\trecived value: ";
		for(auto j : answer){
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
