#include <climits>
#include <cstdio>
#include <exception>
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
	vector<int> relativeSortArray(vector<int> arr1, vector<int> arr2){
		vector<int> answer {}, tail{}, a1 (1001), a2 (1001);

		for(const int &i : arr1){
			a1[i]++;
		}
		for(const int &i : arr2){
			a2[i]++;
		}

		for(int i {}; i < arr2.size(); i++){
			int current = arr2[i];
			while(a2[current] > 0 || a1[current] > 0){
				a2[current]--;
				a1[current]--;
				answer.push_back(current);
			}
		}

		for(int i {}; i < a1.size(); i++){
			if(a1[i] > 0){
				while(a1[i] > 0){
					answer.push_back(i);
					a1[i]--;
				}
			}
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

	vector<pair<vector<int>,vector<int>>> tests = {
		{{2,3,1,3,2,4,6,7,9,2,19},{2,1,4,3,9,6}},
		{{28,6,22,8,44,17},{22,28,8,6}},
	};

	vector<vector<int>> answers = {
		{2,2,2,1,4,3,3,9,6,7,19},
		{22,28,8,6,17,44}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->relativeSortArray(tests[i].first, tests[i].second);
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
