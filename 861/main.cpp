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
	int matrixScore(vector<vector<int>>& grid){
		int answer {}, zerosCounter {};
		for(int i {}; i < grid.size(); i++){
			if(!grid[i][0]){
				for(int j {}; j < grid[i].size(); j++){
					grid[i][j] = !grid[i][j] ? 1 : 0;
				}
			}
		}

		for(int i{1}; i < grid[0].size(); i++){
            zerosCounter = 0;
            for(int j{}; j < grid.size(); j++){
                if(!grid[j][i]){
                    zerosCounter++;
                }
            }

            if(zerosCounter > grid.size()-zerosCounter){
				for(int j {}; j < grid.size(); j++){
					grid[j][i] = !grid[j][i] ? 1 : 0;
				}
            }
		}

        for(const vector<int>& i : grid){
            for(int j {}; j < i.size(); j++){
                answer += i[j] << (i.size() - j - 1);
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
		{{0,0,1,1},{1,0,1,0},{1,1,0,0}},
		{{0}},
		{{0,1},{1,1}}
	};

	vector<int> answers = {
		39,
		1,
		5
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->matrixScore(tests[i]);
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
