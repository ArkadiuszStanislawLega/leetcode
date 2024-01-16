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
	public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches){
		vector<vector<int>> answer (2);
		unordered_map<int, int> counter {};

		for(int i {0}; i < matches.size(); i++){
			counter[matches[i][0]]+=0;
			counter[matches[i][1]]++;
		}

		for(auto const& [key, val] : counter){
			if(val == 0){
				answer[0].push_back(key);
				continue;
			}

			if(val == 1){
				answer[1].push_back(key);
			}
		}

		sort(answer[0].begin(), answer[0].end());
		sort(answer[1].begin(), answer[1].end());

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
	vector<vector<int>> answer {};
	double elapsed_time {};

	vector<vector<vector<int>>> tests = {
		{{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}},
		{{2,3},{1,3},{5,4},{6,4}}
	};

	vector<vector<vector<int>>> answers = {
		{{1,2,10},{4,5,7,8}},
		{{1,2,5,6},{}}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findWinners(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		print_vector(answers[i][0]);
		print_vector(answers[i][1]);
		cout << "\n\trecived value: ";
		print_vector(answer[0]);
		print_vector(answer[1]);
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
