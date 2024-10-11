#include<iostream>
#include"my_time.h"
#include"my_vector.h"
void main_my_time();
void main_my_vector();
int main() {
	
	return 0;
}

void main_my_time()
{
	using std::cout;

	my_time planning;

	my_time coding(2, 40);
	my_time fixing(5, 55);
	my_time total;
	cout << "Planning time = ";
	planning.show();


	cout << "coding time = ";
	coding.show();

	cout << "fixing time = ";
	fixing.show();

	total = coding + fixing;
	cout << "coding.sum(fixing) = ";
	cout << total << std::endl;


	total = coding + 0.6 * fixing;
	cout << "coding + operator(0.6, fixing) = ";
	cout << total << std::endl;

	cout << "coding / fixing * 0.6 = " << coding / (fixing * 0.6) << std::endl;

	total = coding - fixing;
	cout << "coding.jian(fixing) = ";
	cout << total << std::endl;
}

void main_my_vector()
{
	using namespace my_vector_np;

	
}
