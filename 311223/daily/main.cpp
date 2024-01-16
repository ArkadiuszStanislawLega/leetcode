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
	int maxLenghtBetweenEqualCharacters(string s){
		int answer {-1};

		for(int i {}; i < s.size()-1; i++){
			for (int j = i + 1; j < s.size(); j++) {
				if(s[i] == s[j]){
					answer = max(answer, j-i - 1);

				}
			}
		}

		return answer;
	}
};

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<string> tests = {
		"aa",
		"abca",
		"cbyxz",
		"scayofdzca"
	};

	vector<int> answers = {
		0,
		2,
		-1,
		6
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->maxLenghtBetweenEqualCharacters(tests.at(i));
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers.at(i) << "\n\trecived value: " << answer ;

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
