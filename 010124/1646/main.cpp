#include <iostream>
#include <ratio>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>

using namespace std;
using namespace std::chrono;


class Solution {
public:	
	int getMaximumGenerated(int n){
		if(n < 2) return n;
		
		vector<int> counter (n+1);
		counter[1] = 1;

		for(int i {2}; i <= n; i++){
			if(i%2) counter[i] = counter[i/2] + counter[i/2+1];
			else counter[i] = counter[i/2];
		}

		return counter[n];
	}

};

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<int> tests = {
		7, 
		2,
		3
	};

	vector<int> answers = {
		3,
		1,
		2
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->getMaximumGenerated(tests.at(i));
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
