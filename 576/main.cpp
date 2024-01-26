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
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
		const int MODULO = 1e9 + 7;
		int answer {};
		vector<vector<int>> counter (m, vector<int> (n));
		counter[startRow][startColumn] = 1;
		
		for(int move {1}; move <= maxMove; move++){
			vector<vector<int>> temp = vector<vector<int>> (m, vector<int> (n));

			for(int row {}; row < m; row++){
				for(int column {}; column < n; column++){
					if(row == m-1) 
						answer = (answer + counter[row][column])%MODULO;
					if(column == n-1)
						answer = (answer + counter[row][column])%MODULO;
					if(row == 0)
						answer = (answer + counter[row][column])%MODULO;
					if(column == 0 )
						answer = (answer + counter[row][column])%MODULO;

					temp[row][column] = (
						((row > 0 ? counter[row-1][column] : 0) + (row < m-1 ? counter[row+1][column] : 0)) % MODULO + 
						((column > 0 ? counter[row][column-1] : 0) + (column < n-1 ? counter[row][column+1] : 0)) % MODULO ) 
					% MODULO;
				}
			}
			counter = temp;
		}
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
	int answer {};
	double elapsed_time {};

	vector<vector<int>> tests = {
		{2,2,2,0,0},
		{1,3,3,0,1},
		{8,7,16,1,5}
	};

	vector<int> answers = {
		6,
		12,
		102984580
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findPaths(tests[i][0],tests[i][1],tests[i][2],tests[i][3],tests[i][4]);
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
