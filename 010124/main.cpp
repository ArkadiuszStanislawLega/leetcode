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
	unordered_map<int, vector<TreeNode*>> memo {};
public:	
	vector<TreeNode*> allPossibleFBT(int n){
		if(n&0) 
			return {};

		if(n == 1)
			return {new TreeNode()};

		if(memo.find(n) != memo.end())
			return memo[n];
		
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
		memo[n] = res;
		return memo[n];
	}

};

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<int> tests = {
		7, 
		2,
		3
	};

	vector<int> answers = {
		3,
		1,
		2
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->getMaximumGenerated(tests.at(i));
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers.at(i) << "\n\trecived value: " << answer ;

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
