#include"my_time.h"
#include<iostream>
my_time::my_time() {
	this->hours = this->minutes = 0;
}
my_time::my_time(int h, int m) {
	this->hours = h;
	this->minutes = m;
}

my_time::my_time(const my_time& t)
{
	this->hours = t.hours;
	this->minutes = t.minutes;
}

void my_time::add_min(int m) {
	this->minutes += m;
}
void my_time::add_hour(int h) {
	this->hours += h;
}
void my_time::reset(int h, int m) {
	this->hours = this->minutes = 0;
}

my_time my_time::operator+(const my_time& t)
{
	my_time sum = my_time::sum(t);
	return sum;
}

my_time my_time::operator-(const my_time& t)
{
	my_time final;
	final.hours = this->hours - t.hours;
	final.minutes = this->minutes - t.minutes;
	return final;
}



double my_time::operator/(const my_time& t) const
{
	return (this->hours * 60 + this->minutes) / ((t.hours * 60 + t.minutes) * 1.0);
}

my_time my_time::sum(const my_time& t) const
{
	my_time sum;
	sum.minutes += t.minutes;
	sum.hours = this->hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

void my_time::show()const {
	std::cout << hours << " hours " << minutes << " minutes" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const my_time& t)
{
	// TODO: 在此处插入 return 语句
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
