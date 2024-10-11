#pragma once
#include<iostream>
namespace my_vector_np{
	class my_vector
	{
	private:
		enum Mode{RECT, POL};
	// RECT for rectangular, POL for Polar modes
		double m_x;
		double m_y;

		double m_mag;
		double m_ang;

		Mode m_mode;
	// private methods for setting values
		void set_default();
		void set_m_mag();
		void set_m_ang();
		void set_m_x();
		void set_m_y();
		
	public:
		my_vector();
		my_vector(const double &n1, const double& n2, Mode form = RECT);
		void reset(const double &n1, const double& n2, Mode form = RECT);
		~my_vector(){}
	// report attribute' value
		double x_val()const 
			{ return m_x; }
		double y_val()const 
			{ return m_y; }
		double mag_val()const 
			{ return m_mag; }
		double ang_val()const 
			{ return m_ang; }
	// set active mode
		void rect_mode() 
			{ m_mode = RECT; }
		void polar_mode() 
			{ m_mode = POL; }
	// operator overloading
		my_vector operator+(const my_vector& b) const 
			{ return my_vector(m_x + b.m_x, m_y + b.m_y); }
		my_vector operator-(const my_vector& b) const 
			{ return my_vector(m_x - b.m_x, m_y - b.m_y); }
		my_vector operator-() const
			{ return my_vector(-this->m_x, -this->m_y); }
		my_vector operator*(const double& n) const 
			{ return my_vector(n * m_x, n * m_y); }
	// friends
		friend my_vector operator*(const double& n, const my_vector& a) 
			{ return my_vector(n * a.m_x, n * a.m_y); }
		friend std::ostream&
			operator<<(std::ostream& os, const my_vector& v);
	};
}