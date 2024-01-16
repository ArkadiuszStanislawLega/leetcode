#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;


class Solution {


	public:
		int maxScore(string s){
			int answer {}, zeros {}, ones {};

			for (size_t i {1}; i < s.size(); i++) {
				zeros = count(s.begin(), s.begin()+i, '0');
				ones = count(s.begin()+i, s.end(), '1');

				answer = max(answer, zeros + ones);
			}

			return answer;

	}
};

int main (int argc, char *argv[]) {
	Solution *s = new Solution();

	vector<string> tests = {
		"011101", "00111", "1111"
	};

	vector<int> answers = {5, 5, 3};

	auto time_start = high_resolution_clock::now();
	for(int i {}; i < tests.size(); i++){
		cout << "test " << i+1 << " ";
		assert(s->maxScore(tests.at(i))==answers.at(i));
		cout << "paassed\n";
	}
	auto time_stop = high_resolution_clock::now();
	auto time_counter = duration_cast<microseconds> (time_start - time_start);
	cout << time_counter.count() << "ms\n";

	return 0;
}
