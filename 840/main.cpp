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

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	private: 
	vector<vector<int>> _grid;
	bool is_numbers_in_subgrid_valid(int x, int y){
		set<int> unique; 
		for(int i {x}; i < x+3; i++){
			for(int j {y}; j < y+3; j++){
				int current_number = this->_grid[i][j];
				if(current_number > 9 || current_number == 0){
					return false;
				} 

				if(!unique.insert(current_number).second){
					return false;
				}
			}	
		}
		return unique.size() == 9;
	}

	bool is_column_and_rows_eq(int x, int y){
		vector<int> counter (6);

		counter[0] = this->_grid[x][y] + this->_grid[x+1][y] + this->_grid[x+2][y];
		counter[1] = this->_grid[x][y+1] + this->_grid[x+1][y+1] + this->_grid[x+2][y+1];
		counter[2] = this->_grid[x][y+2] + this->_grid[x+1][y+2] + this->_grid[x+2][y+2];

		counter[3] = this->_grid[x][y] + this->_grid[x][y+1] + this->_grid[x][y+2];
		counter[4] = this->_grid[x+1][y] + this->_grid[x+1][y+1] + this->_grid[x+1][y+2];
		counter[5] = this->_grid[x+2][y] + this->_grid[x+2][y+1] + this->_grid[x+2][y+2];
			
		for(int i {1}; i < counter.size(); i++){
			if(counter[i] != counter[i-1]){
				return false;
			}
		}	
		return true;
	}

	public:
	int numMagicSquaresInside(vector<vector<int>>& grid){
		this->_grid = grid;
		int answer {}, val {};

		if(grid.size() < 3){
			return 0;
		}

		for(int x {}; x < grid.size(); x++){
			for(int y {}; y < grid.size(); y++){
				if(y+3 > grid.size() || x+3 > grid.size()){
					continue;
				}

				if(!is_numbers_in_subgrid_valid(x, y)){
					continue;
				}

				if (is_column_and_rows_eq(x, y)){
					answer++;
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

	vector<vector<vector<int>>> tests = {
		{{4,3,8,4},{9,5,1,9},{2,7,6,2}},
		{{8}},
		{{4,7,8},{9,5,1},{2,3,6}},
		{{5,5,5},{5,5,5},{5,5,5}},
		{{10,3,5},{1,6,11},{7,9,2}},
		{{7,0,5},{2,4,6},{3,8,1}}
	};

	vector<int> answers = {
		1,
		0,
		0,
		0,
		0,
		0
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->numMagicSquaresInside(tests[i]);
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
