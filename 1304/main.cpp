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
	vector<int> sumZero(int n){
        	vector<int> answer {};
		bool is_odd {n%2 == 1};
		int i {1}, half {n/2};

		while (i <= half){
			answer.push_back(i*(-1));
			i++;
		}
		i--;
		if(is_odd){
			answer.push_back(0);
		}
		while(i > 0){
			answer.push_back(i);
			i--;
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

	vector<int> tests = {
		5,
		3,
		1
	};

	vector<vector<int>> answers = {
		{-7,-1,1,3,4},
		{-1,0,1},
		{0}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->sumZero(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		print_vector<int>(answers[i]);
		cout << "\n\trecived value: ";
		print_vector<int>(answer);
		cout << '\n';

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

	//	assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
