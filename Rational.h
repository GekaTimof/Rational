#ifndef _RATIONAL
#define _RATIONAL

#include <iostream>
using namespace std;

class Rational {
	// функции, доступные для пользователя
public:
// значения

	// числитель
	int numer;
	// знаменатель
	int denom;

// ввод данных

	// входные данные 0
	Rational();

	// входные данные 1
	Rational(int n);

	// входные данные 2
	Rational(int n, int d);


// вывод-вывода данных

	// ввод дроби
	friend istream& operator >>(istream& in, Rational& r);

	// вывод дроби
	friend ostream& operator <<(ostream& out, const Rational& r);


// математические операции

	// оператор добавления
	Rational& operator +=(const Rational& r);

	// операция сложения
	Rational operator +(const Rational& r) const;

	// оператор отрицания
	Rational operator -() const;

	// оператор уменьшения
	Rational& operator -=(const Rational& r);

	// оператор вычетания
	Rational operator -(const Rational& r) const;

	// оператор домножения
	Rational& operator *=(const Rational& r);

	// оператор умножения
	Rational operator *(const Rational& r) const;

	// оператор разделения
	Rational& operator /=(const Rational& r);

	// оператор деления
	Rational operator /(const Rational& r) const;


// инкремент

	// операторы инкремента
	Rational& operator ++(); // префикс
	Rational operator ++(int); // постфикс


// логические операции

	// равно
	bool operator ==(const Rational& r) const;

	// неравно
	bool operator !=(const Rational& r) const;

	// больше
	bool operator >(const Rational& r) const;

	// больше или равно
	bool operator >=(const Rational& r) const;

	// меньше
	bool operator <(const Rational& r) const;

	// меньше или равно
	bool operator <=(const Rational& r) const;


// преобразование типов

	// преобразование в целое число
	operator int() const;

// преоброзование в дробное число
	operator double() const;


	// функции, недоступные для пользователя
private:

// упрощение дроби

	// функция упрощения дроби
	Rational simplification(Rational r) const;

};

// обратное преобразование типов

	// преобразование из целого
Rational rat(int elem);

// преоброзование из дробного числа
Rational rat(double elem);				// не готова

#endif