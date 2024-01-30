#include <cctype>
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
	private:
	int makeCalculation(int a, int b, char c){
		switch (c) {
			case '+':
				return a+b;
			case '-':
				return a-b;
			case '*':
				return a*b;
			case '/':
				return a/b;
		}
		return 0;
	}

	public:
	int evalRPN(vector<string>& v){
		vector<int> counter {};
		for(const string& s : v){
			if(s == "+" || s == "-" || s == "*" || s == "/"){
				counter[counter.size()-2] = makeCalculation(counter[counter.size()-2], counter.back(), s[0]);
				counter.pop_back();
				continue;
			}

			counter.push_back(stoi(s));
		}
		return counter.back();
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

	vector<vector<string>> tests = {
		{"2","1","+","3","*"},
		{"4","13","5","/","+"},
		{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
	};

	vector<int> answers = {
		9,
		6,
		22
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->evalRPN(tests[i]);
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
