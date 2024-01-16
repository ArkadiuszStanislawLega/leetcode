#include <iostream>
#include <iterator>
#include <ratio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>
#include <tgmath.h>

using namespace std;
using namespace std::chrono;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

struct Job {
	int start_time;
	int end_time;
	int profit;
	Job() : start_time(0), end_time(0), profit(0) {}
	Job(int startTime, int endTime, int prof) : start_time(startTime), end_time(endTime), profit(prof) {}
}; 


class Solution {
private:
	vector<Job> _jobs {};
	vector<int> _counter {};
	vector<int> _start_time {};
	int _max_size {};

	static bool isJobStartsFaster(Job a, Job b){
		return a.start_time < b.start_time;
	}

	int memoization(int i){
		if( i >= this->_max_size){
			return 0;
	}

		if(this->_counter[i] != -1){
			return this->_counter[i];
		}
		vector<int>::iterator before_job_end_time = lower_bound(this->_start_time.begin(), this->_start_time.end(), this->_jobs[i].end_time);
		int next_index = before_job_end_time - this->_start_time.begin();

		this->_counter[i] = max(this->_jobs[i].profit + memoization(next_index), memoization(i+1));
		return this->_counter[i];
	}


public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
		this->_counter = vector<int> (startTime.size()+1, -1);
		this->_max_size = startTime.size();
		this->_start_time = startTime;

		for(int i {}; i < startTime.size(); i++){
			this->_jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
		}
		sort(this->_jobs.begin(), this->_jobs.end(), isJobStartsFaster);
		sort(this->_start_time.begin(), this->_start_time.end());

		return memoization(0);
	}	
};

void print_vector(vector<int>& v){
	cout << '{';
	for(const int &i: v){
		cout << i << ',';
	}
	cout << "\b}";
}

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<vector<vector<int>>> tests = {
		{{1,2,3,3}, {3,4,5,6}, {50,10,40,70}},
		{{1,2,3,4,6}, {3,5,10,6,9}, {20,20,100,70,60}},
		{{1,1,1}, {2,3,4}, {5,6,4}}
	};

	vector<int> answers = {
		120,
		150,
		6
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->jobScheduling(tests[i][0],tests[i][1], tests[i][2]);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers.at(i) << "\n\trecived value: " << answer;


		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		//assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
