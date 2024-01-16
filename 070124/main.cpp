#include <climits>
#include <iostream>
#include <iterator>
#include <ratio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>
#include <tgmath.h>

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
	int numberOfArithmeticSlices(vector<int>& nums){
		vector<unordered_map<long, int>> counter (nums.size());
		int answer {};

		for(int current {}; current < nums.size(); current++){
			for(int previous {}; previous < current; previous++){
				long difference = (long)nums[current] - nums[previous];

				if(difference > INT_MAX || difference <= INT_MIN){
					continue;
				}

				if(counter[previous].find(difference) != counter[previous].end()){
					answer += counter[previous][difference];
					counter[current][difference] += counter[previous][difference];
				}

				counter[current][difference] += 1;
			}
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
		{2,4,6,8,10},
		{7,7,7,7,7}
	};

	vector<int> answers = {
		7,
	16
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->numberOfArithmeticSlices(tests[i]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers.at(i) << "\n\trecived value: " << answer;

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
