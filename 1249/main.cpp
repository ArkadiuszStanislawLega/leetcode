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
	string minRemoveToMakeValid(string s){
		int open {};
		for(int i {}; i < s.size(); i++){
			if(s[i] == '('){
				open++;
				continue;
			}

			if(s[i] == ')'){
				if(open == 0){
					s.erase(i, 1);
					i--;
					continue;
				}

				open--;
			}
		}

		for(int i = s.size()-1; i >= 0 && open > 0; i--){
			if(s[i]  == '('){
				s.erase(i,1);
				open--;
			}
		}
		return s;
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
	string answer {};
	double elapsed_time {};

	vector<string> tests = {
		"lee(t(c)o)de)",
		"a)b(c)d",
		"))((",
		"())()((("
	};

	vector<string> answers = {
		"lee(t(c)o)de",
		"ab(c)d",
		"",
		"()()"
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->minRemoveToMakeValid(tests[i]);
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
