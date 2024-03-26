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
	int firstMissingPossitive(vector<int>& nums){
		int answer {1}, max {};
		set<int> temp{};

		for(const int& i : nums){
			if(i > 0){
				temp.insert(i);
			}
		}

		if(temp.size() <= 1){
			if(temp.size() == 0 || *temp.begin() != 1){
				return 1;
			}

			if(*temp.begin() == 1){
				return 2;
			}
		}

		max = *temp.rbegin();
		for(; answer < max; answer++){
			if(temp.find(answer) == temp.end()){
				return answer;
			}
		}
		return ++answer;
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

	vector<vector<int>> tests = {
		{1,2,0},
		{3,4,-1,1},
		{7,8,9,11,12},
		{1,2,2,1,3,1,0,4,0},
		{1},
		{2},
		{1,100}
	};

	vector<int> answers = {
		3,
		2,
		1,
		5,
		2,
		1,
		2
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->firstMissingPossitive(tests[i]);
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
