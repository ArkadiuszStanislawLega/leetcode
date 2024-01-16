#include <iostream>
#include <ratio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>

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
	unordered_map<int, vector<TreeNode*>> memoization {};
public:
	vector<TreeNode*> allPossibleFBT(int n){
		if(n&0) 
			return {};

		if(n == 1)
			return { new TreeNode()};

		if(memoization.find(n) != memoization.end())
			return memoization[n];

		vector<TreeNode*> res {};
		for(int i {1}; i < n; i += 2){
			vector<TreeNode*> left = allPossibleFBT(i);
			vector<TreeNode*> right = allPossibleFBT(n-i-1);

			for(auto l : left){
				for(auto r : right){
					res.push_back(new TreeNode(0, l, r));
				}
			}
		}
		return memoization[n] = res;

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
	vector<vector<int>> answer {};
	double elapsed_time {};

	vector<vector<int>> tests = {
		{1,3,4,1,2,3,1},
		{1,2,3,4}
	};

	vector<vector<vector<int>>> answers = {
		{{1,3,4,2},{1,3},{1}},
		{{4,3,2,1}}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findMatrix(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		for(auto &i : answers.at(i)){
			print_vector(i);
		}

		cout << "\n\trecived value: ";

		for(auto &i : answer){
			print_vector(i);
		}

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		//assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
