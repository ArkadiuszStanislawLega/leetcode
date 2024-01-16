#include <climits>
#include <iostream>
#include <iterator>
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
	void dfs(TreeNode *root, vector<int>& leaves){
		if(!root)
			return;

		if(!root->right && !root->left)
			leaves.push_back(root->val);

		dfs(root->left, leaves);
		dfs(root->right, leaves);
	}

	public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2){
		vector<int> leaves1 {}, 
			    leaves2 {};

		dfs(root1, leaves1);
		dfs(root2, leaves2);

		return leaves1 == leaves2;
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

	vector<vector<vector<int>>> tests = {

		{{3,5,1,6,2,9,8,nullptr,nullptr,7,4}, {3,5,1,6,7,4,2,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,9,8}},
		{{1,2,3}, {1,3,2}}
	};

	vector<int> answers = {
		true,
	16
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->numberOfArithmeticSlices(tests[i]);
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
