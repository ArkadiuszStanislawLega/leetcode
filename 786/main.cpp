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
	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k){
		vector<pair<float, vector<int>>> answer {};
		for(int i {}; i < arr.size(); i++){
			for(int j {i+1}; j < arr.size(); j++){
				answer.push_back({(float)arr[i]/(float)arr[j], {arr[i], arr[j]}});
			}
		}

		sort(answer.begin(), answer.end());
		return answer[k-1].second;
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

	vector<pair<vector<int>, int>> tests = {
		{{1,2,3,5},3},
		{{1,7},1}
	};

	vector<vector<int>> answers = {
		{2,5},
		{1,7}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->kthSmallestPrimeFraction(tests[i].first, tests[i].second);
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
