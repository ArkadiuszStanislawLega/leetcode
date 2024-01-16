#include <climits>
#include <iostream>
#include <iterator>
#include <numeric>
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
	bool closeStrings(string word1, string word2){
		if(word1.size() != word2.size())
			return false;

        	vector<int> counter1(26), counter2(26);

		for(int i {}; i < word2.size(); i++){
			counter1[word1[i]-'a']++;
			counter2[word2[i]-'a']++;
		}

		for(int i {}; i < 26; i++) {
			if((counter1[i] == 0 && counter2[i] != 0) || (counter1[i] == 0 && counter2[i] != 0) ){
				return false;
			}
        	}

		std::sort(counter1.begin(), counter1.end());
        	std::sort(counter2.begin(), counter2.end());

        	return counter1 == counter2;
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
	bool answer {};
	double elapsed_time {};

	vector<pair<string, string>> tests = {
		{"abc", "bca"},
		{"a", "aa"},
		{"cabbba","abbccc"},
		{"cabbba", "aabbss"}
	};

	vector<bool> answers = {
		true,
		false,
		true,
		false
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->closeStrings(tests[i].first, tests[i].second);
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
