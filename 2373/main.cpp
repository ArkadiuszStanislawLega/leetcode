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
	vector<vector<int>> largestLocal(vector<vector<int>>& grid){
		int gridSize {}, l{}, k{};
		vector<vector<int>> answer;

		gridSize = grid.begin()->size()-2;
		answer = vector<vector<int>>(gridSize, vector<int>(gridSize, 0));

		for(int i {}; i < gridSize; i++){
			for(int j {}; j < gridSize; j++){

				for(int x {i}; x < i+3; x++){
					for(int y {j}; y < j+3; y++){
						answer[k][l] = max(answer[k][l], grid[x][y]);	
					}
				}
				l++;
			}
			k++;
			l=0;
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
	vector<vector<int>> answer {};
	double elapsed_time {};

	vector<vector<vector<int>>> tests = {
		{{9,9,8,1}, {5,6,2,6}, {8,2,6,4}, {6,2,2,2}},
		{{1,1,1,1,1}, {1,1,1,1,1}, {1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1}},
	};

	vector<vector<vector<int>>> answers = {
		{{9,9},{8,6}},
		{{2,2,2},{2,2,2},{2,2,2}}
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->largestLocal(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: ";
		for(int j {}; j < answers[i].size(); j++){
			print_vector<int>(answers[i][j]);
		}
		cout << "\n\trecived value: ";
		for(int j{}; j < answer.size(); j++){
			print_vector<int>(answer[j]);
		}
		cout << '\n';

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
