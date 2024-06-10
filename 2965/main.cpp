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
	vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
		vector<int> answer (2), counter {};
		int minimum {INT_MAX}, maximum {INT_MIN}, size {};
		size = grid.size();
		counter = vector<int> ((size*size)+1);

		for(vector<int> i : grid){
			for(const int& j : i){
				counter[j]++;
				minimum = min(minimum, j);
				maximum = max(maximum, j);
			}
		}
		cout << minimum << '\n';
		if(minimum > 1){
			answer[1] = minimum-1;
		}

		for(; minimum <= maximum; minimum++){
			if(counter[minimum] >= 2){
				answer[0] = minimum;
			}

			if(counter[minimum] == 0){
				answer[1] = minimum;
			}
		}

		if(answer[1] == 0){
			answer[1] = minimum;
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

	vector<vector<vector<int>>> tests = {
		{{1,3}, {2,2}},
		{{9,1,7}, {8,9,2},{3,4,6}},
		{{2,2},{3,4}}
	};

	vector<vector<int>> answers = {
		{2,4},
		{9,5},
		{2,1}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findMissingAndRepeatedValues(tests[i]);
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
