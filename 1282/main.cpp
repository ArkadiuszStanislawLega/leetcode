#include <climits>
#include <iostream>
#include <iterator>
#include <new>
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
	vector<vector<int>> groupThePeople(vector<int>& groupSizes){
		vector<vector<int>> answer {};
		map<int, vector<int>> counter {};
		for(int i {}; i < groupSizes.size(); i++){
			counter[groupSizes[i]].push_back(i);
		}

		map<int, vector<int>>::iterator it = counter.begin();
		while(it!=counter.end()){
			while(it->second.size() > it->first){
				answer.push_back(vector<int>(it->second.begin(), it->second.begin()+it->first));
				it->second.erase(it->second.begin(), it->second.begin()+it->first);
			}
			answer.push_back(vector<int>(it->second.begin(), it->second.end()));
			it->second.erase(it->second.begin(), it->second.end());
			it++;
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
	vector<vector<int>> answer {};
	double elapsed_time {};

	vector<vector<int>> tests = {
	{3,3,3,3,3,1,3},
		{2,1,3,3,3,2}
	};

	vector<vector<vector<int>>> answers = {
		{{5},{0,1,2},{3,4,6}},
		{{1},{0,5},{2,3,4}},
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->groupThePeople(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		for(auto v : answers[i]){
			print_vector<int>(v);
		}
		cout << "\n\trecived value: ";
		for(auto i : answer){
			print_vector(i);
		}
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
