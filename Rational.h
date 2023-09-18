#ifndef _RATIONAL
#define _RATIONAL

#include <iostream>
using namespace std;

class Rational {
	// �������, ��������� ��� ������������
public:
// ��������

	// ���������
	int numer;
	// �����������
	int denom;

// ���� ������

	// ������� ������ 0
	Rational();

	// ������� ������ 1
	Rational(int n);

	// ������� ������ 2
	Rational(int n, int d);


// �����-������ ������

	// ���� �����
	friend istream& operator >>(istream& in, Rational& r);

	// ����� �����
	friend ostream& operator <<(ostream& out, const Rational& r);


// �������������� ��������

	// �������� ����������
	Rational& operator +=(const Rational& r);

	// �������� ��������
	Rational operator +(const Rational& r) const;

	// �������� ���������
	Rational operator -() const;

	// �������� ����������
	Rational& operator -=(const Rational& r);

	// �������� ���������
	Rational operator -(const Rational& r) const;

	// �������� ����������
	Rational& operator *=(const Rational& r);

	// �������� ���������
	Rational operator *(const Rational& r) const;

	// �������� ����������
	Rational& operator /=(const Rational& r);

	// �������� �������
	Rational operator /(const Rational& r) const;


// ���������

	// ��������� ����������
	Rational& operator ++(); // �������
	Rational operator ++(int); // ��������


// ���������� ��������

	// �����
	bool operator ==(const Rational& r) const;

	// �������
	bool operator !=(const Rational& r) const;

	// ������
	bool operator >(const Rational& r) const;

	// ������ ��� �����
	bool operator >=(const Rational& r) const;

	// ������
	bool operator <(const Rational& r) const;

	// ������ ��� �����
	bool operator <=(const Rational& r) const;


// �������������� �����

	// �������������� � ����� �����
	operator int() const;

// �������������� � ������� �����
	operator double() const;


	// �������, ����������� ��� ������������
private:

// ��������� �����

	// ������� ��������� �����
	Rational simplification(Rational r) const;

};

// �������� �������������� �����

	// �������������� �� ������
Rational rat(int elem);

// �������������� �� �������� �����
Rational rat(double elem);				// �� ������

#endif