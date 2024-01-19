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
	int minFallingPathSum(vector<vector<int>>& matrix){
		    int matrixSize {}, rowSize {}, up {}, leftDown {}, rightDown {};
		vector<vector<int>> counter {};

		matrixSize = matrix.size();
		rowSize = matrix.at(0).size();

		counter = vector<vector<int>> (matrixSize, vector<int> (rowSize, 0));

		for(int i {}; i < rowSize; i++){
			counter[0][i] = matrix[0][i];
		}

		for(int i {1}; i < matrixSize; i++){
			for(int j {}; j < rowSize; j++){ 
				leftDown = INT_MAX;
				rightDown = INT_MAX;

				up = matrix[i][j] + counter[i-1][j];

				if(j-1 >= 0){
					leftDown = matrix[i][j] + counter[i-1][j-1];
				}
				if(j+1 < rowSize){
					rightDown = matrix[i][j] + counter[i-1][j+1];
				}

				counter[i][j] = min(up, min(leftDown,rightDown));
			}
		}

		return *min_element(counter[matrixSize-1].begin(), counter[matrixSize-1].end());
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

	vector<vector<vector<int>>> tests = {
		{{2,1,3},{6,5,4},{7,8,9}},
		{{-19,57},{-40,-5}}
	};

	vector<int> answers = {
		13,
		-59
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->minFallingPathSum(tests[i]);
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
