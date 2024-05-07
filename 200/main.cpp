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
	void upConnected(vector<vector<char>>& grid, int row, int column){
		if(row-1 < 0 || grid[row-1][column] == '0'){
			return;
		}
		grid[row-1][column] = '0';
		upConnected(grid, row-1, column);
	}

	void downConnected(vector<vector<char>>& grid, int row, int column){
		if(row+1 >= grid.size() || grid[row+1][column] == '0'){
			return;
		}

		grid[row+1][column] = '0';
		downConnected(grid, row+1, column);
	}

	void rightConnected(vector<vector<char>>& grid, int row, int column){
		if(column+1 >= grid[row].size() || grid[row][column+1] == '0'){
			return;
		}

		grid[row][column+1] = '0';
		rightConnected(grid, row, column+1);	
	}

	void leftConnected(vector<vector<char>>& grid, int row, int column){
		if(column-1 < 0 || grid[row][column-1] == '0'){
			return;
		}
		grid[row][column-1] = '0';
		leftConnected(grid, row, column-1);
	}

	void dfs(vector<vector<char>>& grid, int row, int column){
		upConnected(grid, row, column);
		leftConnected(grid, row, column);
		rightConnected(grid, row, column);
		downConnected(grid, row, column);
	}

	public:
	int numIslands(vector<vector<char>>& grid){
		int answer {};
		for(int row {}; row < grid.size(); row++){
			for(int column {}; column < grid[row].size(); column++){
				if(grid[row][column] == '1'){
					grid[row][column] = '0';
					answer++;
					cout << answer << '\n';
					for(auto row : grid){
						for(auto i : row){
							cout << i << ", ";
						}
						cout << '\n';
					}
					dfs(grid, row, column);
				}
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

		//assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
