#include <climits>
#include <iostream>
#include <iterator>
#include <ratio>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <map>
#include <tgmath.h>
#include <set>
#include <stack>
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

class Solution {
	class Meeting{
		public:
		int start {}, end {};
		bool is_finshed {}, is_started {};

		Meeting(){}
		Meeting(int _start, int _end){
			this->start = _start;
			this->end = _end;
		}

		void makeDelay(){
			this->start++;
			this->end++;
		}

	};

	class Room{
		public:
		int counter {}, number {};
		bool is_occupied {};
		Meeting* meeting {};

		Room(int _number){
			this->number = _number;
		}

		void startMeeting(Meeting* meeting){
			if(!is_occupied){
				this->meeting = meeting;
				this->is_occupied = true;
				this->counter++;
				this->meeting->is_started = true;
			}
		}

		void endMeeting(){
			if(this->is_occupied){
				this->meeting->is_finshed = true;
			}
		}
	}; 

	private:
	int _counter_finished_meetings {};
	pair<int, int> _max { INT_MIN, INT_MIN};
	vector<Room> _rooms {};
	vector<Meeting *> _meetings {};

	void makeRooms(int& roomsNumber){
		for(int i {}; i < roomsNumber; i++){
			this->_rooms.push_back(Room (i));
		}
	}

	void makeMeetings(vector<vector<int>>& meetings){
		for(const vector<int>& i :  meetings){
			this->_meetings.push_back(new Meeting(i[0], i[1]));
		}
	}

	void updateMax(pair<int, int> pretendent){
		if(this->_max.second < pretendent.second ){
			this->_max = {pretendent.first, pretendent.second};
		}

		if(this->_max.second == pretendent.second && this->_max.first > pretendent.first) {
			this->_max = pretendent;
		}

	}

	void updateRooms(int& time){
		for(Room& r : this->_rooms){
			if(r.is_occupied && time == r.meeting->end){
				r.meeting->is_finshed = true;
				r.is_occupied = false;
				this->_counter_finished_meetings++;
			}

			if(!r.is_occupied){
				for(Meeting* m : this->_meetings){
					if(!m->is_started && !m->is_finshed && m->start == time){
						r.startMeeting(m);
						updateMax({r.number, r.counter});
						break;
					}
				}
			}

		}
	}

	void updateMeetings(int& time){
		for(Meeting * m : this->_meetings){
			if(!m->is_started && !m->is_finshed && time == m->start){
				m->makeDelay();
			}
		}
	}

	bool isFinishedLoop(){
		return this->_counter_finished_meetings == this->_meetings.size();
	}

	void mainLoop(){
		int time {};
		while(!this->isFinishedLoop()){
			updateRooms(time);
			updateMeetings(time);
			time++;
		}
	}

	public:
	int mostBooked(int n, vector<vector<int>>& meetings){
		makeRooms(n);
		makeMeetings(meetings);
		mainLoop();

		return this->_max.first;
	}
};

template <typename T>
void print_vector(vector<T>& v){
	cout << '{';
	for(const T &i: v){
		cout << i << ',';
	}
	cout << "\b}";
}

int main (int argc, char *argv[]) {
	int answer {};
	double elapsed_time {};

	vector<pair<int, vector<vector<int>>>> tests = {
		{2,{{0,10}, {1,5}, {2,7}, {3,4}}},
		{3,{{1,20}, {2,10}, {3,5}, {4,9}, {6,8}}}
	};

	vector<int> answers = {
		0,
		1
	};

	for(int i {}; i < tests.size(); i++){
		Solution *s = new Solution();

		auto start = high_resolution_clock::now();
		answer = s->mostBooked(tests[i].first, tests[i].second);
		auto end = high_resolution_clock::now();

		cout << "test " << i+1 << "\n\ttarget value: " << answers[i] << "\n\trecived value: " << answer << '\n';

		elapsed_time = duration<double, milli>(end-start).count();
		cout << "\nelapsed time " << elapsed_time << "ms";

		assert(answer == answers.at(i));
		cout << " -> passed\n";
	}

	//auto time_counter = duration_cast<microseconds> (time_start - time_start);
	//cout << time_counter.count() << "ms " << sizeof(Solution) << '\n';

	return 0;
}
