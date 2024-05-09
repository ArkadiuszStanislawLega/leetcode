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
	vector<string> findRelativeRanks(vector<int>& score){
		vector<string> answer (score.size());
		vector<pair<int, int>> counter {};

		for(int i {}; i < score.size(); i++){
			counter.push_back({score[i], i});
		}
		sort(counter.rbegin(), counter.rend());

		for(int i {}; i < score.size(); i++){
			if(i < 1){
				answer[counter[i].second] = "Gold Medal";
				continue;
			}

			if(i < 2){
				answer[counter[i].second] = "Silver Medal";
				continue;
			}

			if(i < 3){
				answer[counter[i].second] = "Bronze Medal";
				continue;
			}

			answer[counter[i].second] = to_string(i+1);
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
	vector<string> answer {};
	double elapsed_time {};

	vector<vector<int>> tests = {
		{5,4,3,2,1},
		{10,3,8,9,4}
	};

	vector<vector<string>> answers = {
		{"Gold Medal","Silver Medal","Bronze Medal","4","5"},
		{"Gold Medal","5","Bronze Medal","Silver Medal","4"}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findRelativeRanks(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		print_vector(answers[i]);
		cout << "\n\trecived value: ";
		print_vector(answer);
		cout << '\n';

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		//assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
