#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>

using namespace std;
using namespace std::chrono;


class Solution {


	public:
		bool isPathCrossing(string path){
			unordered_set<string> visited {};
			map<char, pair<int, int>> world_sides = {
				{'N', { 0, 1} }, 
				{'S', { 0, -1}},
				{'W', { -1, 0}},
				{'E', { 1, 0}}
			};

			int current_x {}, current_y {};
			string key {};
			
			key = to_string(current_x) + ',' + to_string(current_y);
			visited.insert(key);

			for(const char &c : path){	
				current_x += world_sides[c].first;
				current_y += world_sides[c].second;

				key = to_string(current_x) + ',' + to_string(current_y);

				if(visited.find(key) == visited.end())
					visited.insert(key);
				else 
					return true;
				
			}
	
			return false;
	}
};

int main (int argc, char *argv[]) {
	Solution *s = new Solution();

	vector<string> tests = {
		"NES", "NESWW"
	};

	vector<bool> answers = {false, true};

	auto time_start = high_resolution_clock::now();
	for(int i {}; i < tests.size(); i++){
		cout << "test " << i+1 << " ";
		assert(s->isPathCrossing(tests.at(i))==answers.at(i));
		cout << "paassed\n";
	}
	auto time_stop = high_resolution_clock::now();
	auto time_counter = duration_cast<microseconds> (time_start - time_start);
cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
