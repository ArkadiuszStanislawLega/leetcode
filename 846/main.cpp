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
	bool isNStraightHand(vector<int>& hand, int groupSize){
		if(hand.size()%groupSize > 0){
			return false;
		}

		if(groupSize == 1){
			return true;
		}

		sort(hand.begin(), hand.end());
		int temp {}, counter {}, i {}; 

		while(hand.size()){
			temp = *hand.begin();
			counter = 1;
			i = 0;

			hand.erase(hand.begin());

			while(counter < groupSize && i < hand.size()){
				if(hand[i] == temp+1){
					temp = hand[i];
					hand.erase(hand.begin()+i);
					counter++;
					i--;
				} 
				i++;
			}
			if(counter != groupSize){
				return false;
			}
		}
		return true;
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
	bool answer {};
	double elapsed_time {};

	vector<pair<vector<int>, int>> tests = {
		{{1,2,3,6,2,3,4,7,8}, 3},
		{{1,2,3,4,5},4}
	};

	vector<bool> answers = {
		true,
		false
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->isNStraightHand(tests[i].first, tests[i].second);
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
