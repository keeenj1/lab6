#include <iostream>
#include <exception>
using namespace std;

class TimeException : public out_of_range {
public:
	TimeException(int h, int m, int s) : out_of_range("invalid time") {
		this->h = h;
		this->m = m;
		this->s = s;
	}
	int h, m, s;
};

class Time {
private:
	int hours, minutes, seconds;
public:
	Time() {}
	Time(int h, int m, int s) {
		if (h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0) {
			throw TimeException(h, m, s);
		}
		hours = h;
		minutes = m;
		seconds = s;
	}
	void print() const {
		cout << "Current time: " << hours << "h " << minutes << "m " << seconds << "s" << endl;
	}
};

int main() {
	try {
		Time t1(16, 30, 15);
		t1.print();

		Time t2(16, 30, 60);
		t2.print();
	} catch (const TimeException& ex) {
		cerr << "Caught exception: " << ex.what() << endl;
		cerr << "Invalid time: " << ex.h << "h " << ex.m << "m " << ex.s << "s" << endl;
	}
	return 0;
}