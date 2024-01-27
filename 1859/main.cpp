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
	public:
	string sortSentence(string s){
		string answer {}, temp {};
	 	vector<string> container (count(s.begin(), s.end(), ' ')+1);
		int index {};

		for(int i {}; i < s.size(); i++){
			if(s[i] != ' '){
				temp += s[i];
				continue;
			}

			index = (temp.back()-'0')-1;
			temp.pop_back();
			container[index] = temp;
			temp.clear();
		}

		index = (temp.back()-'0')-1;
		temp.pop_back();
		container[index] = temp;

		for(const string& s : container){
			answer += s + ' ';
		}

		answer.pop_back();

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
	string answer {};
	double elapsed_time {};

	vector<string> tests = {
		"is2 sentence4 This1 a3",
		"Myself2 Me1 I4 and3"
	};

	vector<string> answers = {
		"This is a sentence",
		"Me Myself and I"
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->sortSentence(tests[i]);
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
