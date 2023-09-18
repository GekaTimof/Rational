#include <iostream>
#include "Rational.h"
#include "NOD_Euclid_algorithm.h"

using namespace std;

			// ввод данных

// 0 аргументов на входе
Rational::Rational() {
	numer;
	denom;
};

// 1 аргумент на входе
Rational::Rational(int n) {
	numer = n;
	denom = 1;
};

// 2 аргумента на входе
Rational::Rational(int n, int d) {
	// сокращаем вводимую дробь, деля на НОД
	int nod = NOD(n, d);
	numer = n / nod;
	denom = d / nod;
};


			// вывод-вывода данных

// ввод дроби
istream& operator >>(istream& in, Rational& r) {
	in >> r.numer >> r.denom;
	return in;
}

// вывод дроби
ostream& operator <<(ostream& out, const Rational& r) {
	out << r.numer << "/" << r.denom;
	return out;
}


			// математические операции

// операция добавления
Rational& Rational::operator +=(const Rational& r) {
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	*this = simplification(*this);
	return *this;
};

// операция сложения
Rational Rational::operator +(const Rational& r) const {
	Rational res(*this);
	return simplification( res += r);
}

// оператор отрицания
Rational Rational::operator -() const {
	Rational r(-numer, denom);
	return simplification( r);
}

// оператор уменьшения
Rational& Rational::operator -=(const Rational& r) {
	*this = simplification(*this);
	return (*this += (-r));
}

// оператор вычетания
Rational Rational::operator -(const Rational& r) const {
	Rational res(*this);
	return simplification( res -= r);
}

// оператор домножения
Rational& Rational::operator *=(const Rational& r) {
	numer *= r.numer;
	denom *= r.denom;
	*this = simplification(*this);
	return *this;
}

// оператор умножения
Rational Rational::operator *(const Rational& r) const {
	Rational res(*this);
	return simplification( res *= r);
}

// оператор разделения
Rational& Rational::operator /=(const Rational& r) {
	numer *= r.denom;
	denom *= r.numer;
	*this = simplification(*this);
	return *this;
}

// оператор деления
Rational Rational::operator /(const Rational& r) const {
	Rational res(*this);
	return simplification( res /= r);
}


			// инкремент

// оператор инкремента
Rational& Rational::operator ++()
{
	numer += denom;
	return *this;
}
Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}


			// логические операции

// равно
bool Rational::operator ==(const Rational& r) const {
	return (numer * r.denom == r.numer * denom);
}

// неравно
bool Rational::operator !=(const Rational& r) const {
	return !(*this == r);
}

// больше
bool Rational::operator >(const Rational& r) const {
	return (numer * r.denom > r.numer * denom);
}

// больше или равно
bool Rational::operator >=(const Rational& r) const {
	return (numer * r.denom >= r.numer * denom);
}

// меньше
bool Rational::operator <(const Rational& r) const {
	return (numer * r.denom < r.numer * denom);
}

// меньше или равно
bool Rational::operator <=(const Rational& r) const {
	return (numer * r.denom <= r.numer * denom);
}


			// упрощение дроби

// функция упрощения дроби
Rational Rational::simplification(Rational r) const {
	// ищем наименьший общий делитель
	int nod = NOD(r.numer, r.denom);
	Rational re_r(r.numer / nod, r.denom / nod);
	return re_r;
}


			// преобразование типов

// преобразование в целое число
Rational::operator int() const {
	return numer / denom;
}

// преоброзование в дробное число
Rational::operator double() const {
	return ((double)numer) / denom;
}


			// обратное преобразование типов

// преобразование из целого
Rational rat(int elem) {
	Rational r(elem);
	return r;
}

// преоброзование из дробного числа
Rational rat(double elem) {
	Rational r(0);
	return r;
}

