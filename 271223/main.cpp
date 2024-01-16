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
	public:

	string reversePrefix(string word, char ch){
		reverse(word.begin(), word.begin() + (word.find(ch)+1));
		return word;
	}
};

int main (int argc, char *argv[]) {
	string answer {};
	double elapsed_time {};

	vector<pair<string, char>> tests = {
		{"abcdefd", 'd'},
		{"xyxzxe", 'z'},
		{"abcd", 'z'}
	};

	vector<string> answers = {
		"dcbaefd", 
		"zxyxxe",
		"abcd"
	};
	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->reversePrefix(tests.at(i).first, tests.at(i).second);
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
