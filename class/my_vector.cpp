#include"my_vector.h"
#include<cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace my_vector_np {
	const double Rad_to_deg = 45.0 / atan(1.0);

	void my_vector::set_default()
	{
		m_x = m_y = m_mag = m_ang = 0.0;
		m_mode = RECT;
	}

	void my_vector::set_m_mag() {
		m_mag = sqrt(m_x * m_x + m_y * m_y);
	}
	void my_vector::set_m_ang() {
		if (m_x == 0 && m_y == 0)
			m_ang = 0.0;
		m_ang = atan2(m_y, m_x);
	}

	void my_vector::set_m_x()
	{
		m_x = m_mag * cos(m_ang);
	}

	void my_vector::set_m_y()
	{
		m_y = m_mag * sin(m_ang);
	}

	my_vector::my_vector()
	{
		set_default();
	}

	my_vector::my_vector(const double& n1, const double& n2, Mode form)
	{
		reset(n1, n2, form);
	}

	void my_vector::reset(const double& n1, const double& n2, Mode form)
	{
		m_mode = form;
		if (m_mode == RECT) {
			m_x = n1;
			m_y = n2;
			set_m_mag();
			set_m_ang();
		}
		else if (m_mode == POL) {
			m_mag = n1;
			m_ang = n2;
			set_m_x();
			set_m_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to my_vector() -- ";
			cout << "vector set to 0\n";
			set_default();
		}
	}

	
	std::ostream& operator<<(std::ostream& os, const my_vector& v)
	{
		// TODO: 在此处插入 return 语句
		if (v.m_mode == my_vector::RECT) {
			os << "(x, y) = (" << v.m_x << ", " << v.m_y << ")\n";
		}
		else if (v.m_mode == my_vector::RECT) {
			os << "(m, a) = (" << v.m_mag << ", " << v.m_ang * Rad_to_deg << ")\n";
		}
		return os;
	}

}