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
	private:
	vector<vector<char>> _board {};
	set<pair<int,int>> _used {};
	int _i {};
	string _word {};

	bool isValid(int v, int c){
		if(this->_used.insert({v,c}).second){
			this->_i++;
			return true;
		}
		return false;
	}

	bool isLookingLetter(int v, int c){
		return this->_word[this->_i] == this->_board[v][c];
	}

	bool isFoundOnTheRight(int v, int c){
		return c+1 < this->_board[v].size() && this->isLookingLetter(v, c+1) && isValid(v, c+1);
	}

	bool isFoundOnTheBottom(int v, int c){
		return v+1 < this->_board.size() && this->isLookingLetter(v+1, c) && isValid(v+1, c);
	}

	bool isFoundOnTheLeft(int v, int c){
		return c > 0 && this->isLookingLetter(v, c-1) && isValid(v, c-1);
	}

	bool isFoundOnTheTop(int v, int c){
		return v > 0 && this->isLookingLetter(v-1, c)&& isValid(v-1, c);
	}

	public:
	bool exist(vector<vector<char>>& board, string word){
		this->_board = board;
		this->_word = word;
		for(int v {}; v < board.size(); v++){
			for(int c {}; c < board[v].size(); c++){
				if(this->_i >= word.size()){
					return true;
				}

				if(this->isLookingLetter(v, c) && isValid(v, c)) continue;
				if(isFoundOnTheRight(v, c)) continue;
				if(isFoundOnTheBottom(v, c)) continue;
				if(isFoundOnTheLeft(v, c)) continue;
				if(isFoundOnTheTop(v, c)) continue;
			}
		}
		return this->_i >= word.size();
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
	bool answer {};
	double elapsed_time {};

	vector<pair<vector<vector<char>>, string>> tests = {
		{{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}},"ABCCED"},
		{{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}},"SEE"},
		{{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}},"ABCB"},
		{{{'a','b'},{'c','d'}}, "acdb"}
	};

	vector<bool> answers = {
		true,
		true,
		false,
		true
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->exist(tests[i].first, tests[i].second);
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
