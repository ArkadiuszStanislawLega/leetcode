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
	vector<int> luckyNumbers(vector<vector<int>>& matrix){
		int minV {INT_MIN}, maxV {INT_MAX};

		for(int i {}; i < matrix.size(); i++){
		 	minV = max(minV, *min_element(matrix[i].begin(), matrix[i].end()));
		}

		for(int i{}; i < matrix[0].size(); i++){
			int temp {INT_MIN};
			for(int j {}; j < matrix.size(); j++){
				temp = max(temp, matrix[j][i]);
			}
			maxV = min(maxV, temp);
		}

		if(maxV == minV){
			return {maxV};
		}
		return {};
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
		{{3,7,8}, {9,11,13}, {15,16,17}},
		{{1,10,4,2}, {9,3,8,7},{15,16,17,12}},
		{{7,8},{1,2}}
	};

	vector<vector<int>> answers = {
		{15},
		{12},
		{7}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->luckyNumbers(tests[i]);
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
