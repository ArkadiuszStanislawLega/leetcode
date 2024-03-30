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
	int subarrayWithKDistinct(vector<int>& nums, int k){
		int answer {};
		bool isBreak {};
		set<int> counter {};
		for(int current_size {k}; current_size <= nums.size(); current_size++){
			for(int i {}; i < nums.size(); i++){
				int max = i+current_size-1;

				if(max > nums.size()-1){
					break;
				}

				for(int j {i}; j <= max; j++){
					if(counter.insert(nums[j]).second && counter.size() > k){
						isBreak = true;
						break;
					}
				}

				if(!isBreak && k == counter.size()){
					answer++;
				}

				counter.clear();
				isBreak = false;
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

	vector<pair<vector<int>, int>> tests = {
		{{1,2,1,2,3}, 2},
		{{1,2,1,3,4}, 3},
		{{1,2}, 1},
		{{2,1,2,1,2}, 2},
	};

	vector<int> answers = {
		7,
		3,
		2,
		10,
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->subarrayWithKDistinct(tests[i].first, tests[i].second);
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
