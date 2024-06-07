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
	string replaceWords(vector<string>& dictionary, string sentence){
		string temp {};
		int shortest_word {INT_MAX}, longest_word {INT_MIN};
		for(auto &w : dictionary){
			shortest_word = min(shortest_word, (int)w.size());
			longest_word = max(longest_word, (int)w.size());
		}

		for(int i {}; i < sentence.size(); i++){
			temp += sentence[i];

			if(temp.size() >= shortest_word && temp.size() <= longest_word){
				for(auto &w : dictionary){
					if(temp == w){
						i++;
						while(sentence[i] != ' ' && i < sentence.size() ){
							sentence.erase(sentence.begin()+i);
						}
					}
				}
			}

		if(sentence[i] == ' '){
				temp = "";
			}
		}

		return sentence;
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

	vector<pair<vector<string>, string>> tests = {
		{{"cat","bat","rat"}, "the cattle was rattled by the battery"},
		{{"a","b","c"}, "aadsfasf absbs bbab cadsfafs"}
	};

	vector<string> answers = {
		"the cat was rat by the bat",
		"a a b c"
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->replaceWords(tests[i].first, tests[i].second);
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
