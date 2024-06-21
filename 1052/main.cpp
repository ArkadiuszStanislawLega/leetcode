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
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes){
		int answer {}, round_sum {};
		vector<int> counter (3, 0);
		for(int i {}; i < customers.size(); i++){
			int last_index = i+minutes-1;
			if (last_index >= customers.size()){
				break;
			}

			vector<int> temp (3);
			temp[1] = i;
			for(int j {i}; j <= last_index ; j++){
				round_sum += customers[j];

				if (j == last_index){
					temp[2] = j;

					if(counter[0] < round_sum){
						temp[0] = round_sum;
						counter = vector<int>(temp);
					}
					round_sum = 0;
				}
			}
		}

		for(int i {}; i < counter[1]; i++){
			if(grumpy[i]){
				continue;
			}
			answer += customers[i];
		}
		answer += counter[0];
		for(int i {counter[2]+1}; i < customers.size(); i++){
			answer+= customers[i];
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
		{{1,0,1,2,1,1,7,5}, {0,1,0,1,0,1,0,1}}
	};

	vector<int> test2 = {
		3
	};

	vector<int> answers = {
		16
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->maxSatisfied(tests[i][0], tests[i][1], test2[i]);
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
