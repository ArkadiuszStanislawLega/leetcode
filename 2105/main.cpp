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
	int minimumRefill(vector<int>& plants, int capacityA, int capacityB){
		int 	answer {}, 
			alice_water {capacityA}, 
			bob_water {capacityB}, 
			index_a {}, 
			index_b {};

		index_b = plants.size()-1;

		while(index_a < index_b){
			if(alice_water < plants[index_a]){
				answer++;
				alice_water = capacityA;
			}

			if(bob_water < plants[index_b]){
				answer++;
				bob_water = capacityB;
			}

			alice_water -= plants[index_a];
			bob_water -= plants[index_b];

			index_a++;
			index_b--;
		}

		if(plants.size()%2 && max(alice_water, bob_water) < plants[index_a]){
				return ++answer;
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

	vector<vector<int>> tests = {
		{2,2,3,3},
		{2,2,3,3},
		{5},
		{2,2,5,2,2}
	};

	vector<pair<int, int>> tests2 = {
		{5, 5},
		{3, 4},
		{10,8},
		{5,5}
	};

	vector<int> answers = {
		1,
		2,
		0,
		1
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->minimumRefill(tests[i], tests2[i].first, tests2[i].second);
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
