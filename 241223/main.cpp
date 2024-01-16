#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;


class Solution {


	public:
		int minOperation(string s){
			int cost {};
			for(int i {}; i < s.size(); i++){
				if(s[i]-'0' == i%2)
					cost++;
			}
			return min(cost, (int)s.size() - cost);
		}
};

int main (int argc, char *argv[]) {
	Solution *s = new Solution();

	vector<string> tests = {
		"0100", "10", "1111", "10010100"
	};

	vector<int> answers = {1, 0, 2, 3};

	auto time_start = high_resolution_clock::now();

	for(int i {}; i < tests.size(); i++){
		cout << "test " << i+1 << " ";
		assert(s->minOperation(tests.at(i))==answers.at(i));
		cout << "paassed\n";
	}

	auto time_stop = high_resolution_clock::now();
	auto time_counter = duration_cast<microseconds> (time_start - time_start);

	cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
