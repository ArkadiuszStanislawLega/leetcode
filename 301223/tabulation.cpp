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
	int climbingStairs(int n){
		if(!n)
			return 0;

		if(n == 1)
			return 1;

		vector<int> answer (n+1);
		answer[0] = 1;
		answer[1] = 1;
		for(int i {2}; i <= n; i++){
			answer[i] = answer[i-1] + answer[i-2];
		}
		return answer[n];
	}
};

int main (int argc, char *argv[]) {
	bool answer {};
	double elapsed_time {};

	vector<int> tests = {
		2, 3
	};

	vector<int> answers = {
		2,
		3
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->climbingStairs(tests.at(i));
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
