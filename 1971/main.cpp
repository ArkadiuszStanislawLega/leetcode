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
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
		if(n == 1 ){ return true; }
		vector<bool> visited (n, false);
		bool isVisitedVertex {true};

		visited[source] = true;

		while(isVisitedVertex){
			isVisitedVertex = false;
			for(const vector<int>& edge : edges){
				if(visited[edge[0]] != visited[edge[1]]){
					visited[edge[0]] = true;
					visited[edge[1]] = true;
					isVisitedVertex = true;
				}

				if(visited[destination]){
					return true;
				}
			}
		}
		return false;
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
	bool answer {};
	double elapsed_time {};

	vector<pair<int, vector<vector<int>>>> tests = {
		{3,{{0,1},{1,2},{2,0}}},
		{6,{{0,1},{0,2},{3,5},{5,4},{4,3}}},
		{10,{{4,3},{1,4},{4,8},{1,7},{6,4},{7,4},{4,0},{0,9},{5,4}}},
	};

	vector<pair<int, int>> tests1 = {
		{0,2},
		{0,5},
		{5,9}
	};

	vector<bool> answers = {
		true,
		false,
		true,
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->validPath(tests[i].first, tests[i].second, tests1[i].first, tests1[i].second);
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
