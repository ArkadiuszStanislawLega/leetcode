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
	vector<vector<int>> _grid;
	vector<pair<int, int>> _direction = {
		{1,0},{0,1},{-1,0},{0,-1}
	};
	int recurcive(int current_gold, int start_x, int start_y){
		if(start_x >= this->_grid[start_y].size() || start_x < 0 || start_y < 0 || start_y >= this->_grid.size() || !this->_grid[start_y][start_x]) {
			return 0;
		}
		current_gold += this->_grid[start_y][start_x];

		vector<int> counter;
		
		for(pair<int,int>& i : this->_direction){
			counter.push_back(current_gold+recurcive(current_gold, start_x+i.first, start_y+i.second));
			cout << counter.back() << '\n';
		}
		
		vector<int>::iterator max = max_element(counter.begin(), counter.end());
		int index = distance(counter.begin(), max);

		cout << index << '\n';
		
		this->_grid[start_y+this->_direction[index].first][start_x+this->_direction[index].second] = 0;

		return *max;

	}
	public:
	int getMaximumGold(vector<vector<int>>& grid){
		this->_grid = grid;
		int answer {};
		for(int y {}; y < grid.size(); y++){
			for(int x {}; x < grid[y].size(); x++){
				answer = max(answer, recurcive(0, y, x));
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
		{{0,6,0},{5,8,7},{0,9,0}},
		{{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,1,20}}
	};

	vector<int> answers = {
		24,
		28
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->getMaximumGold(tests[i]);
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
