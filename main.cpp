#include <climits>
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
	string _s {};
	int _k {};

	vector<vector<int>> _counter {};

	int getLength(int lettersNumber){
		if(lettersNumber == 1) 
			return 1;

		if(lettersNumber < 10)
			return 2;

		if(lettersNumber < 100)
			return 3;

		return 4;
	}

	void findCharacterSeries(int i, int j){
		int counter {}, reduceAbout {};
		reduceAbout = j;

		for(int end = i; end < this->_s.size() && reduceAbout >= 0; end++){
			if(this->_s[end] != this->_s[i]){
				reduceAbout--;
				continue;
			}

			counter++;
			this->_counter[i][j] = min(this->_counter[i][j], getLength(counter) + this->_counter[end+1][reduceAbout]);
		}
	}

	public:

	int getLenghtOfOptimalCompression(string s, int k){
		this->_s = s;
		this->_k = k;

		this->_counter = vector<vector<int>> (this->_s.size()+1, vector<int> (this->_k+1));

		for(int i = this->_s.size()-1; i >= 0; i--){
			for(int j {}; j <= this->_k; j++){
				this->_counter[i][j] = j > 0 ? this->_counter[i+1][j-1] : INT_MAX;
				findCharacterSeries(i, j);
			}
		}

		return this->_counter[0][k];
	}
};

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<pair<string, int>> tests = {
		{"aaabcccd", 2},
		{"aabbaa", 2},
		{"aaaaaaaaaaa", 0}
	};

	vector<int> answers = {
		4, 
		2,
		3
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->getLenghtOfOptimalCompression(tests.at(i).first, tests.at(i).second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers.at(i) << "\n\trecived value: " << answer ;

		assert(answer == answers.at(i));

		elapsed_time = duration<double, milli>(end-start).count(); 
		cout << "\nelapsed time " << elapsed_time << "ms -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
