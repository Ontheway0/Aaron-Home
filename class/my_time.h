#pragma once
#include<iostream>
class my_time {
private:
	int hours;
	int minutes;
public:
	my_time();
	my_time(const my_time& t);
	my_time(int h, int m = 0);
	
	void add_min(int m);
	void add_hour(int h);
	void reset(int h = 0, int m = 0);
	

	my_time sum(const my_time& t) const;
	void show()const;

	my_time operator+(const my_time& t);
	my_time operator-(const my_time& t);

	template <typename T>
	my_time operator*(const T &t);
	template <typename T>
	friend my_time operator*(const T& m_x, const my_time& t);
	double operator/(const my_time& t) const;
	friend std::ostream& operator<<(std::ostream& os, const my_time& t);
};

template<typename T>
inline my_time my_time::operator*(const T &t)
{
	my_time final;
	final.hours = this->hours * t;
	final.minutes = this->hours * t;
	return final;
}

template<typename T>
inline my_time operator*(const T& m_x, const my_time& t)
{
	my_time final;
	final.hours = t.hours * m_x;
	final.minutes = t.minutes *m_x;

	return final;
}
