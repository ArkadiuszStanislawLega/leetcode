#include <climits>
#include <iostream>
#include <iterator>
#include <ratio>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>
#include <tgmath.h>
#include <queue>
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
	int futrthestBuilding(vector<int>& heights, int bricks, int ladders){
		int i {}, diff {}; 

		priority_queue<int> p;

		for(; i< heights.size()-1; i++){
			cout << p.size() << ' ' << bricks << ' ' << ladders << '\n';
			diff = heights[i+1]-heights[i];

			if(diff <= 0){
				continue;
			}
			
			bricks -= diff;
			p.push(diff);

			if(bricks < 0){
				bricks += p.top();
				p.pop();
				ladders--;
			} 

			if(ladders < 0) break;
		}

        	return i;
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

	vector<vector<int>> tests = {
		{4,2,7,6,9,14,12},
		{4,12,2,7,3,18,20,3,19},
		{14,3,19,3},
		{1,5,1,2,3,4,10000}
	};

	vector<pair<int, int>> tests_args = {
		{5, 1},
		{10, 2},
		{17, 0},
		{4, 1}
	};

	vector<int> answers = {
		4,
		7,
		3,
		5
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->futrthestBuilding(tests[i], tests_args[i].first, tests_args[i].second);
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
