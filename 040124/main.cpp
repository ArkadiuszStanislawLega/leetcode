#include <iostream>
#include <ratio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>
#include <tgmath.h>

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
private:
	vector<vector<int>> _counter;

	int memoization(int i, int n){
		if(n == 0){
			return 1;
		}

		if(this->_counter[i][n] != -1){
			return this->_counter[i][n];
		}
		
		int counter {};
		for(int j {i}; j < 5; j++){
			counter += memoization(j, n-1);
		}

		return this->_counter[i][n] = counter;
		
	}
public:
    	int countVowelStrings(int n) {
		this->_counter = vector<vector<int>> (5, vector<int>(n+1, -1));
		return memoization(0, n);
    	}
};

void print_vector(vector<int>& v){
	cout << '{';
	for(const int &i: v){
		cout << i << ',';
	}
	cout << "\b}";
}

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<int> tests = {
		1,
		2,
		33
	};

	vector<int> answers = {
		5, 
		15,
		66045
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->countVowelStrings(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers.at(i) << "\n\trecived value: " << answer;


		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
