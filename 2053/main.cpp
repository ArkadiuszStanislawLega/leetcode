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
	string kthDistinct(vector<string>& arr, int k){
		map<string, int> freq {};
		for(auto s : arr){
			freq[s]++;
		}

		for(auto s : arr) {
			if(freq[s] == 1){
				k--;
			}

			if(k == 0){
				return s;
			}
		}
		return "";
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
	string answer {};
	double elapsed_time {};

	vector<pair<vector<string>, int>> tests = {
		{{"d","b","c","b","c","a"},2},
		{{"aaa","aa","a"}, 1}, 
		{{"a","b","a"},3},
		{{"y","napli","jfqjc","mbl","oeush"},3}, 
		{{"jqrd","k","miy","svuwg","uv","yttn","bxu","nymzu","dpane","x","mb","zm","ae","ihwtn","kouej","y","zt","h","udx","h","imi","zombs","l","hvt","uor","kzi","tzm","kde","ml","hmvz","hriuy","lav","hlvw","fnnj","bdkh","hu","tuuob","uc","no","qo","ku","foe"},27}
	};

	vector<string> answers = {
		"a",
		"aaa",
		"",
		"jfqjc",
		"ml"
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->kthDistinct(tests[i].first, tests[i].second);
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
