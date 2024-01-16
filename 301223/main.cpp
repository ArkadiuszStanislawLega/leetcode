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
	int memoization(int n, vector<int>& counter){
		if(n <= 1)
			return 1;

		if(counter[n] != -1)
			return counter[n];

		counter[n] = memoization(n-1, counter) + memoization(n-2, counter);
		return counter[n];
	}


	public:
	int climbingStairs(int n){
		vector<int> counter (n+1, -1);
		return memoization(n, counter);
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
