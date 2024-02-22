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
	int findJudge(int n, vector<vector<int>>& trust){
		if(trust.size() == 0){
			if(n == 1){
				return n;
			}

			if(n > 1){
				return -1;
			}
		}

		map<int, vector<int>> counter {};
		int c {};

		for(auto& i : trust){
			counter[i[0]].push_back(i[1]);
		}

		for(auto& i : counter.begin()->second){
			for(auto& [key, value] : counter){
				if(find(value.begin(), value.end(), i) != value.end()){
					c++;
				}
			}

			if(c == n-1 && counter.find(i) == counter.end()){
				return i;
			}
			c = 0;
		}
		return -1;
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
	int answer {};
	double elapsed_time {};

	vector<pair<int, vector<vector<int>>>> tests = {
		{2, {{1,2}}},
		{3, {{1,3}, {2,3}}},
		{3, {{1,3}, {2,3}, {3,1}}},
		{4, {{1,3},{1,4},{2,3},{2,4},{4,3}}},
		{3, {{1,2},{2,3}}},
		{2, {}},
		{1, {}},
		{4, {{1,3},{1,4},{2,3}}},
	};

	vector<int> answers = {
		2,
		3,
		-1,
		3,
		-1,
		-1,
		1,
		-1
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findJudge(tests[i].first, tests[i].second);
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
