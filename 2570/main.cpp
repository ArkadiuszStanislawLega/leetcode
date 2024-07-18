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
	vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2){
		map<int, int> counter {}; 
		vector<vector<int>> answer {};
		for(auto &a : nums1){
			counter[a[0]] += a[1];
		}
		for(auto &a : nums2){
			counter[a[0]] += a[1];
		}

		for(const pair<int, int>& p : counter){
			answer.push_back({p.first, p.second});
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

	vector<pair<vector<vector<int>>,vector<vector<int>>>> tests = {
		{{}, {}},
		{{}, {}}
	};

	vector<vector<vector<int>>> answers = {
		{},
		{}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->mergeArrays(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		for(auto &a : answers){
			cout << '{' << a[0]  << ',' << a[1] << '}' << ','; 
		}
		cout << '\n';
		cout << "\n\trecived value: ";
		for(auto &a : answer){
			cout << '{' << a[0]  << ',' << a[1] << '}' << ','; 
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
