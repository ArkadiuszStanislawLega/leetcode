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
	vector<vector<int>> _grid {};
	int _answer {};

	void checkUp(int& row, int& column){
		if(row == 0){
			this->_answer++;
			return;
		}
		if(!this->_grid[row-1][column]) { 
			this->_answer++;
		} 

	}
	void checkDown(int& row, int& column){
		if(row == this->_grid.size()-1){
			this->_answer++;
			return;
		}
		if(!this->_grid[row+1][column]){ 
			this->_answer++;
		}

	}
	void checkRight(int& row, int& column){
		if(column == this->_grid[row].size()-1){
			this->_answer++;
			return;
		}
		if(!this->_grid[row][column+1]){
			this->_answer++;
		}

	}
	void checkLeft(int& row, int& column){
		if(column == 0){
			this->_answer++;
			return;
		}
		if(!this->_grid[row][column-1]){ 
			this->_answer++;
		}
	}

	public:
	int islandPerimeter(vector<vector<int>>& grid){
		this->_grid = grid;

		for(int row {}; row < grid.size(); row++){
			for(int column {}; column < grid[row].size(); column++){
				if(grid[row][column] == 1){
					this->checkUp(row, column);
					this->checkDown(row, column);
					this->checkLeft(row, column);
					this->checkRight(row, column);
				}
			}
		}
		return this->_answer;
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

	vector<vector<vector<int>>> tests = {
		{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}},
		{{1}},
		{{1,0}}
	};

	vector<int> answers = {
		16,
		4,
		4
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->islandPerimeter(tests[i]);
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
