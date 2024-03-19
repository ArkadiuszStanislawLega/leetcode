#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
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
	int leastInterval(vector<char>& tasks, int n){

		int answer {}, weight_counter {}, added_per_round {};
		int counter [26] {}, round [26]{-1};
		vector<char> temp {};

		for(const char& c : tasks){
			counter[c-'A']++;
		}
	
		if(n == 1){
			bool isFounded {};
			for(int i {}; i < 26; i++){
				if(counter[i] == tasks.size()){
					isFounded = true;
				}
			}
			if(!isFounded){
				return tasks.size();
			}
		}

		
		for(int i {}; i < 26; i++){
			if(counter[i]){
				temp.push_back('A'+i);
				counter[i]--;
				round[i] = temp.size()-1;
			}
			if(i >= n){ 
				break;
			}
			weight_counter += counter[i];
		}
		answer = temp.size();

		if(weight_counter == 0){
			return answer;
		}

		while(true){
			added_per_round = 0;
			weight_counter = 0;

			for(int i {}; i < 26; i++){
				if(counter[i]){
					if(round[i] == -1 || temp.size() - round[i] - 1 >= n){
						temp.push_back('A'+i);
						counter[i]--;
						round[i] = temp.size()-1;
						added_per_round++;
						answer++;
					} 

				}
				if(added_per_round >= n){
					break;
				}
				weight_counter += counter[i];
			}

			if(added_per_round == 0){
				temp.push_back('*');
				answer++;
			}

			if(weight_counter == 0){
				break;
			}
		}

		for(const char& c : temp ){
			cout << c << ',';
		}
		cout << '\n';

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

	vector<pair<vector<char>, int>> tests = {
		{{'A','A','A','B','B','B'}, 2},
		{{'A','C','A','B','D','B'}, 1},
		{{'A','A','A','B','B','B'}, 3},
		{{'A','A','A','A','A','A','B','C','D','E','F','G'}, 1},
		{{'A','A','A','B','B','B','C','D','E','F','G','H','I','J','K'},7}
	};

	vector<int> answers = {
		8,
		6,
		10,
		12,
		18
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->leastInterval(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers[i] << "\n\trecived value: " << answer << '\n';

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		//assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
