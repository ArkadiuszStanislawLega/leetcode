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

	int findContentChildren(vector<int>& g, vector<int>& s){
		int answer{}, children_index {}, size_index {};

		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		while(children_index < g.size() && size_index < s.size()){
			if(g[children_index] <= s[size_index]){
				answer++;
				children_index++;
			}
			size_index++;
		}
		return answer;
	}

};

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<pair<vector<int>, vector<int>>> tests = {
		{{1,2,3},{1,1}},
		{{1,2},{1,2,3}},
		{{1,2,3},{3}},
	};

	vector<int> answers = {
		1,
		2,
		1
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->findContentChildren(tests.at(i).first, tests.at(i).second);
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
