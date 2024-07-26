#include <climits>
#include <cmath>
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
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold ){
		int answer {}, fewestReachableCount {n};
		vector<vector<int>> counter (n, vector<int>(n, INT_MAX));

		for(auto point : edges){
			counter[point[0]][point[1]] = point[2];
			counter[point[1]][point[0]] = point[2];
		}

		for(auto point : edges){
			for(int i {}; i < n; i++){
				for(int j {}; j < n; j++){
					if(i == point[0] && j == point[0]){
						counter[i][j] = 0;
						continue;
					}
					if(counter[i][point[0]] != INT_MAX && counter[point[1]][j] != INT_MAX){
						counter[i][j] = min(counter[i][j], counter[i][point[0]] + counter[point[1]][j]);
					}
				}
			}
		}

		for (int i {}; i < n; i++) {
		    int reachableCount = 0;
		    for (int j {}; j < n; j++) {
			if (i == j) {
			    continue;
			}  

			if (counter[i][j] < INT_MAX && counter[i][j] < distanceThreshold) {
			    reachableCount++;
			}
		    }

		    if (reachableCount < fewestReachableCount) {
			fewestReachableCount = reachableCount;
			answer = i;
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

	vector<vector<vector<int>>> tests = {
		{{0,1,3},{1,2,1},{1,3,4},{2,3,1}},
		{{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}},
	};

	vector<pair<int, int>> tests2 = {
		{4,4},
		{5,2}
	};

	vector<int> answers = {
		3,
		0
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findTheCity(tests2[i].first, tests[i], tests2[i].second);
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
