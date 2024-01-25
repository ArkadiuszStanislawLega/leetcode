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
	vector<int> findWordsContaining(vector<string>& words, char x){
		vector<int> answer {};
		for(int i {}; i < words.size(); i++){
			for(const char& c : words[i]){
				if(c == x){
					answer.push_back(i);
					break;
				}
			}
		}
		return answer;
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
	vector<int> answer {};
	double elapsed_time {};

	vector<pair<vector<string>, char>> tests = {
		{{"leet", "code"},'e'}, 
		{{"abc", "bcd", "aaaa", "cbc"},'a'},
		{{"abc", "bcd", "aaaa", "cbc"},'z'}
	};

	vector<vector<int>> answers = {
		{0,1},
		{0,2},
		{}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findWordsContaining(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		print_vector(answers[i]);
		cout << "\n\trecived value: ";
		print_vector(answer);
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
