#include <iostream>
#include "Rational.h"
#include "NOD_Euclid_algorithm.h"

using namespace std;
// Start program hear
int main(void) {
	setlocale(LC_ALL, "Russian");

	// �������� 
	Rational a(6, 12), b(3, 6), res;
	res = a / b;

	// ��������
	//cout << a;
	// cout << rat(3);
	//cout << double(a);
	//cout << (a >= b);
	//cout <<a.numer << "  " << a.denom;
	//cout << res.numer << "  " << res.denom;
}