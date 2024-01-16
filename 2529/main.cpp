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
	private:
	vector<int> _nums {};

	int getIndex(int target = 0, bool lower = false){
		int mid {}, answer {}, low {}, high {};
		
		high = this->_nums.size()-1;
		answer = this->_nums.size();

		if(!lower){
			while(low<= high){
				mid = low + (high-low)/2;
			
				if(this->_nums[mid] > target){
					answer = mid;
					high = mid-1;
					continue;
				}
				low = mid+1;
			}
			return answer;
		}

		while(low <= high){
			mid = low + (high-low)/2;
			if(this->_nums[mid] >= target){
				answer = mid;
				high = mid-1;
				continue;
			}
			
			low = mid+1;
		}
		return answer;
	}
	
	public:
	int maximumCount(vector<int>& nums){
		int minIndex {}, maxIndex{};
		this->_nums = nums;

		minIndex = getIndex(true);
		maxIndex = getIndex(false);

		if(minIndex == maxIndex){
			return max(this->_nums.size()-minIndex, this->_nums.size()-maxIndex);
		}

		return max(minIndex, (int)(this->_nums.size()-maxIndex));
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
		{-2,-1,-1,1,2,3},
		{-3,-2,-1,0,0,1,2},
		{5,20,66,1314}
	};

	vector<int> answers = {
		3,
		3,
		4
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->maximumCount(tests[i]);
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
