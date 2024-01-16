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

	int memoization(int i, vector<int>& counter){
		if(counter[i] != -1){
			return counter[i];
		}

		counter[i] = memoization(i-1, counter) + memoization(i-2, counter) + memoization(i-3, counter);
		return counter[i];
	}

	public:
	int tribrnacci(int n){
		if(n < 1) return 0;
		if(n < 3) return 1;

		vector<int> counter (n+1, -1);
		counter[0] = 0;
		counter[1] = 1;
		counter[2] = 1;

	return memoization(n, counter);
	}
};

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<int> tests = {
		4,
		25
	};

	vector<int> answers = {
		4,
		1389537
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->tribrnacci(tests.at(i));
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
