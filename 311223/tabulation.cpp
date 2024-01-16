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
	int tribrnacci(int n){
		if(n <= 1)
			return 0;

		if(n <= 3){
			return 1;
		}

		vector<int> counter (n+1);
		counter[1] = 1;
		counter[2] = 1;

		for(int i {3}; i <= n; i++){
			counter[i] = counter[i-1] + counter[i-2] + counter[i-3];
		}

		return counter[n];
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
