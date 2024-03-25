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
	vector<int> findDisapprearedNumbers(vector<int>& nums){
		vector<int> answer {};
		set<int> counter{};
		for(int& i : nums){
			counter.insert(i);
		}
		
	
		set<int>::iterator it = counter.begin();
		for(int i {1}; i <= nums.size(); i++){
			if(it == counter.end()){
				answer.push_back(i);
				continue;
			}

			if(i == *it){
				it++;
				continue;
			}

			if(i != *it){
				answer.push_back(i);
			}
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
	vector<int> answer {};
	double elapsed_time {};

	vector<vector<int>> tests = {
		{4,3,2,7,8,2,3,1},
		{1,1},
		{2,2},
		{1,1,2,2}
	};

	vector<vector<int>> answers = {
		{5,6},
		{2},
		{1},
		{3,4}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findDisapprearedNumbers(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		print_vector<int>(answers[i]);
		cout << "\n\trecived value: ";
		print_vector<int>(answer);
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