#include <iostream>
#include <ratio>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;


class Solution {
	private:

	public:
	bool makeEqual(vector<string>& words){
		int counter [26] {};
		for(const string &s: words){
			for(const char &c: s){
				counter[c-'a']++;
			}
		}

		for(const int& i: counter){
			if(i%words.size()!=0)
				return false;
		}
		return true;
	}
};

int main (int argc, char *argv[]) {
	bool answer {};
	double elapsed_time {};

	vector<vector<string>> tests = {
		{"abc","aabc","bc"},
		{"ab","a"},
	};

	vector<bool> answers = {
		true,
		false,
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->makeEqual(tests.at(i));
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers.at(i) << "\n\trecived value: " << answer ;

		assert(answer == answers.at(i));

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
