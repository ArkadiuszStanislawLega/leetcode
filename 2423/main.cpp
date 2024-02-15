#include <climits>
#include <iostream>
#include <iterator>
#include <ratio>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
	public:
	bool equalFrequency(string word){
		vector<int> counter (26), temp {};
		int minE {INT_MAX}, maxE {INT_MIN};
		set<int> set {};

		for(const char& c : word){
			counter[c-'a']++;
		}

		for(int i {}; i < 26; i++){
			for(int i {}; i < counter.size(); i++){
				temp.push_back(counter[i]);
			}

			if(temp[i] <= 0){
				continue;
			}

			temp[i] -= 1;

			for(const int& t : temp){
				if (t) {
					set.insert(t);
				}
			}

			if(set.size() == 1)
				return true;

			set.clear();
			temp.clear();
		}
		return false;
		//return *minMax.first != *minMax.second;
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

	vector<string> tests = {
		"abcc",
		"aazz",
		"bac",
		"aca",
		"abbcc",
		"ddaccb",
		"cbbd"
	};

	vector<bool> answers = {
		true,
		false,
		true,
		true,
		true,
		false,
		true
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->equalFrequency(tests[i]);
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
