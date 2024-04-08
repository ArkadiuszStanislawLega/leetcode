#include <climits>
#include <iostream>
#include <iterator>
#include <queue>
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
	int countStudents(vector<int>& students, vector<int>& sandwiches){
		int sandwitchNotEaten {};
		queue<int>studentsQueue {};
		stack<int>sandwichesStack {};

		for(int i {}; i < students.size(); i++){
			studentsQueue.push(students[i]);
			sandwichesStack.push(sandwiches[sandwiches.size() -i- 1]);
		}

		while(sandwitchNotEaten < students.size() && !studentsQueue.empty()){
			if(studentsQueue.front() == sandwichesStack.top()){
				studentsQueue.pop();
				sandwichesStack.pop();
				sandwitchNotEaten = 0;
				continue;
			}
			studentsQueue.push(studentsQueue.front());
			studentsQueue.pop();

			sandwitchNotEaten++;
		}

		return studentsQueue.size();
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

	vector<pair<vector<int>, vector<int>>> tests = {
		{{1,1,0,0},{0,1,0,1}},
		{{1,1,1,0,0,1},{1,0,0,0,1,1}},
	};

	vector<int> answers = {
		0, 
		3
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->countStudents(tests[i].first, tests[i].second);
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
