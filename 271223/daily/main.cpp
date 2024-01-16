#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;


class Solution {
	private:
		int _answer, _preview;

		string _colors;

		vector<int> _neededTime;

		void increaseAnswer(int current){
			if(this->_neededTime[this->_preview] >= this->_neededTime[current]){
				this->_answer += this->_neededTime[current];
				return;
			} 
			this->_answer += this->_neededTime[this->_preview];
			this->_preview = current;
		}
		
	public:
		int minCost(string colors, vector<int>& neededTime){
			this->_answer = 0;
			this->_preview = 0;
			this->_colors = colors;
			this->_neededTime = neededTime;

			for(int i {1}; i < this->_colors.size(); i++){
				if(this->_colors[i] == this->_colors[this->_preview]){
					increaseAnswer(i);
					continue;
				} 
								
				this->_preview = i;
			}
			return this->_answer;
		}
};

int main (int argc, char *argv[]) {
	Solution *s = new Solution();
	
	vector<pair<string, vector<int>>> tests = {
		{"abaac", {1,2,3,4,5}},
		{"abc", {1,2,3}},
		{"aabaa", {1,2,3,4,1}}
	};

	vector<int> answers = {3,0,2};

	auto time_start = high_resolution_clock::now();

	for(int i {}; i < tests.size(); i++){
		cout << "test " << i+1 << " ";
		int answer = s->minCost(tests.at(i).first, tests.at(i).second);
		cout << "should be: " << answers.at(i) << ", is: " << answer << '\n';
		assert(answer == answers.at(i));
		cout << "paassed\n";
	}

	auto time_stop = high_resolution_clock::now();
	auto time_counter = duration_cast<microseconds> (time_start - time_start);

	cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
