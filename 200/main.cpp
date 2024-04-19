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
	vector<vector<char>> _grid {};
	vector<vector<int>> _connection_map {};
	int _answer {};

	bool isUpConnected(int row, int column){
		int curr_row = row-1;
		if(curr_row < 0){
			return false;
		}

		if(this->_connection_map[curr_row][column]){
			if(this->_connection_map[curr_row][column] < this->_answer){
				this->_answer =  this->_connection_map[curr_row][column];
			}
			this->_connection_map[row][column] = this->_connection_map[curr_row][column];
			return true;
		}

		return false;

	}
	bool isDownConnected(int row, int column){
		int curr_row = row+1;
		if(curr_row >= this->_grid.size()){
			return false;
		}
		if(this->_connection_map[curr_row][column]){
			if(this->_connection_map[curr_row][column] < this->_answer){
				this->_answer =  this->_connection_map[curr_row][column];
			}
			this->_connection_map[row][column] = this->_connection_map[curr_row][column];
			return true;
		}

		return false;

	}
	bool isRightConnected(int row, int column){
		int curr_column = column+1;
		if(curr_column >= this->_grid[row].size()){
			return false;
		}

		if(this->_connection_map[row][curr_column]){
			if(this->_connection_map[row][curr_column] < this->_answer){
				this->_answer = this->_connection_map[row][curr_column];
			}
			this->_connection_map[row][column] =  this->_connection_map[row][curr_column];
			return true;
		}

		return false;


	}
	bool isLeftConnected(int row, int column){
		int curr_column = column-1;
		if(curr_column < 0){
			return false;
		}

		if(this->_connection_map[row][curr_column]){
			if(this->_connection_map[row][curr_column] < this->_answer){
				this->_answer =  this->_connection_map[row][curr_column];
			}
			this->_connection_map[row][column] = this->_connection_map[row][curr_column];
			return true;
		}

		return false;



	}
	public:
	int numIslands(vector<vector<char>>& grid){
		bool left{}, right{}, down{}, up{};
		this->_grid = grid;
		this->_connection_map = vector<vector<int>> (grid.size(), vector<int>(grid[0].size()));

		for(int row {}; row < this->_grid.size(); row++){
			for(int column {}; column < this->_grid[row].size(); column++){
				if(this->_grid[row][column] == '1'){
					left = isLeftConnected(row, column);
					right = isRightConnected(row, column);
					up = isUpConnected(row, column);
					down = isDownConnected(row, column);

					if(!left && !right && !down && !up){
						this->_connection_map[row][column] = ++this->_answer;
					}
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

	vector<vector<vector<char>>> tests = {
		{
			{'1','1','1','1','0'},
			{'1','1','0','1','0'},
			{'1','1','0','0','0'},
			{'0','0','0','0','0'}
		},
		{
			{'1','1','0','0','0'},
			{'1','1','0','0','0'},
			{'0','0','1','0','0'},
			{'0','0','0','1','1'}
		},
		{
			{'1','1','1'},
			{'0','1','0'},
			{'1','1','1'}
		},
		{
			{'1','1','1','1','1','1'},
			{'1','0','0','0','0','1'},
			{'1','0','1','1','0','1'},
			{'1','0','0','0','0','1'},
			{'1','1','1','1','1','1'}
		}
	};

	vector<int> answers = {
		1,
		3,
		1,
		2
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->numIslands(tests[i]);
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
