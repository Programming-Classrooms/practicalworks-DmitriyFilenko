#include "Fraction.hpp"


/*==========================================================================
======================== Методы поиска НОК и НОД ===========================
==========================================================================*/

int32_t findGCD(int32_t a, int32_t b)
{
	const double EPS = 0.001;
	if (a < b) {
		return findGCD(b, a);
	}

	if (fabs(b) < EPS) {
		return a;
	}

	else {
		return (findGCD(b, a - floor(a / b) * b));
	}
}

int32_t findLCM(int32_t a, int32_t b)
{
	return ((a * b) / findGCD(a, b));
}

/*===========================================================================
============================ Конструкторы ===================================
===========================================================================*/

Fraction::Fraction(int32_t nrhs, int32_t drhs){
	numerator = nrhs;
	if (drhs <= 0) {
		throw std::invalid_argument(" Denominator must be more than zero!\n");
	}
	denominator = drhs;
	this->reduct();
}

Fraction::Fraction(const Fraction& rhs) : numerator(rhs.numerator), denominator(rhs.denominator) {};

/*===========================================================================
============================== Деструктор ===================================
===========================================================================*/

Fraction::~Fraction() {};



/*===========================================================================
========================== Сокращение дроби =================================
===========================================================================*/

Fraction& Fraction::reduct() {
	if (this->numerator < 0) {
		this->numerator *= -1;
	int32_t nod = findGCD(this->numerator, this->denominator);
	this->numerator /= nod;
	this->denominator /= nod;
	this->numerator *= -1;
	}
	else {
	int32_t nod = findGCD(this->numerator, this->denominator);
	this->numerator /= nod;
	this->denominator /= nod;
	}
	return *this;
}

/*===========================================================================
================================ Геттеры ====================================
===========================================================================*/

int32_t Fraction::getNum() {
	return this->numerator;
}

int32_t Fraction::getDenum() {
	return this->denominator;
}

/*===========================================================================
================================ Сеттеры ====================================
===========================================================================*/

void Fraction::setNum(int32_t rhs) {
	this->numerator = rhs;
}

void Fraction::setDenum(int32_t rhs) {
	if (rhs <= 0) {
		throw std::invalid_argument(" Denominator must be more than zero!\n");
	}
	this->denominator = rhs;
}

/*===========================================================================
=========================== Бинарные операторы ==============================
===========================================================================*/

Fraction Fraction::operator+(const Fraction& rhs) {
	Fraction cpy(*this);
	int32_t LCMdenominators = findLCM(cpy.denominator, rhs.denominator);
	int32_t thisMultiplier = LCMdenominators / cpy.denominator;
	int32_t rhsMultiplier = LCMdenominators / rhs.denominator;

	cpy.numerator *= thisMultiplier;
	cpy.denominator *= thisMultiplier;

	Fraction temp(rhs);	
	temp.numerator *= rhsMultiplier;
	temp.denominator *= rhsMultiplier;

	cpy.numerator += temp.numerator;
	cpy.reduct();
	return cpy;
}

Fraction Fraction::operator+(const int32_t rhs) {
	Fraction cpy(*this);
	Fraction fractRhs(1, 1);
	fractRhs.numerator *= rhs;
	return cpy + fractRhs;
}



Fraction Fraction::operator-(const Fraction& rhs) {
	Fraction cpy(*this);
	int32_t LCMdenominators = findLCM(cpy.denominator, rhs.denominator);
	int32_t thisMultiplier = LCMdenominators / cpy.denominator;
	int32_t rhsMultiplier = LCMdenominators / rhs.denominator;

	cpy.numerator *= thisMultiplier;
	cpy.denominator *= thisMultiplier;

	Fraction temp(rhs);
	temp.numerator *= rhsMultiplier;
	temp.denominator *= rhsMultiplier;
	
	cpy.numerator -= temp.numerator;
	cpy.reduct();
	return cpy;
}

Fraction Fraction::operator-(const int32_t rhs) {
	Fraction cpy(*this);
	Fraction fractRhs(1, 1);
	fractRhs.numerator *= rhs;
	return cpy - fractRhs;
}	
// *
Fraction Fraction::operator*(const Fraction& rhs) {
	Fraction cpy(*this);
	cpy.denominator *= rhs.denominator;
	cpy.numerator *= rhs.numerator;
	cpy.reduct();
	return cpy;
}

Fraction Fraction::operator*(const int32_t rhs) {
	Fraction cpy(*this);
	cpy.numerator *= rhs;
	cpy.reduct();
	return cpy;
}
// /
Fraction Fraction::operator/(Fraction& rhs) {
	Fraction cpy(*this);
	cpy = cpy * (!rhs);
	rhs = !rhs;
	return cpy;
}

Fraction Fraction::operator/(const int32_t rhs) {
	Fraction cpy(*this);
	Fraction divider(rhs, 1);
	cpy = cpy / divider;
	return cpy;
}

/*===========================================================================
============================ Унарный минус ==================================
===========================================================================*/

Fraction Fraction::operator-() const
{
	return Fraction( - (this->numerator), this->denominator);
}

/*===========================================================================
========================= Операторы сравнения ===============================
===========================================================================*/


bool Fraction::operator==(const Fraction& rhs) const{
	Fraction copyThis(*this);
	Fraction cpy(rhs);
	return (copyThis.toDouble() == cpy.toDouble());
}
bool Fraction::operator==(const int32_t rhs) {
	return (this->toDouble() == rhs);
}
bool Fraction::operator!=(const Fraction& rhs)
{
	return !(*this == rhs);
}

bool Fraction::operator>(const Fraction& rhs) {
	Fraction cpy(rhs);
	return (this->toDouble() > cpy.toDouble());
}
bool Fraction::operator>(const int32_t rhs) {
	return (this->toDouble() > rhs);
}
bool Fraction::operator<(const Fraction& rhs){
	Fraction cpy(rhs);
	return (this->toDouble() < cpy.toDouble());
}
bool Fraction::operator<(const int32_t rhs) {
	return (this->toDouble() < rhs);
}
bool Fraction::operator>=(const Fraction& rhs) {
	Fraction cpy(rhs);
	return (this->toDouble() >= cpy.toDouble());
}
bool Fraction::operator>=(const int32_t rhs) {
	return (this->toDouble() >= rhs);
}
bool Fraction::operator<=(const Fraction& rhs) {
	Fraction cpy(rhs);
	return (this->toDouble() <= cpy.toDouble());
}
bool Fraction::operator<=(const int32_t rhs) {
	return (this->toDouble() <= rhs);
}

/*===========================================================================
========================= Инкрементирование =================================
===========================================================================*/

Fraction Fraction::operator++(int32_t rhs) { // Postfix
	Fraction cpy(*this);
	*this = *this + 1;
	this->reduct();
	return cpy;
}
Fraction& Fraction::operator++() { // Prefix
	*this = *this + 1;
	this->reduct();
	return *this;
}


/*===========================================================================
========================= Декриментирование =================================
===========================================================================*/

Fraction Fraction::operator--(int32_t) { // Postfix
Fraction cpy(*this);
	*this = *this - 1;
	this->reduct();
	return cpy;
}
Fraction& Fraction::operator--(){ // Prefix
	*this = *this - 1;
	this->reduct();
	return *this;
}


/*===========================================================================
============================ Обратная дробь =================================
===========================================================================*/

Fraction Fraction::operator!() {
	if (numerator <= 0) {
		throw std::invalid_argument(" Denominator must be more than zero!\n");
	}
	std::swap(this->denominator, this->numerator);
	return *this;
}

/*===========================================================================
========================= Операторы ввода/вывода ============================
===========================================================================*/

std::ostream& operator<<(std::ostream& out, const Fraction& rhs) {
	Fraction copy(rhs);
	if (copy.numerator == 0) {
		out << "0";
	}
	else if (copy.numerator == copy.denominator) {
		out << copy.numerator;
	}
	else {
	out  << copy.numerator << '/' << copy.denominator;
	}

	return out;
}

std::istream& operator>> (std::istream& in, Fraction& rhs) {
	char c = 0;

	in >> rhs.numerator;
	in >> c;
	in >> rhs.denominator;
	if (c != '/') {
		throw std::invalid_argument(" Incorrect input format!(Must be like X/Y using / symbol)");
	}
	return in;
}

/*===========================================================================
========================= Преобразование в Double ===========================
===========================================================================*/

double Fraction::toDouble() {
	return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
}

/*===========================================================================
========================= Оператор присваивания =============================
===========================================================================*/

Fraction& Fraction::operator=(const Fraction& rhs) {
	if (this != &rhs) {
		this->numerator = rhs.numerator;
		this->denominator = rhs.denominator;
		this->reduct();
	}
	return *this;
}

/*===========================================================================
==================== Составные операторы присваивания =======================
===========================================================================*/

Fraction& Fraction::operator+=(const Fraction& rhs) {
	if (this != &rhs) {
		this->numerator += rhs.numerator;
		this->denominator = rhs.denominator;
		this->reduct();
	}
	return *this;
}

// -=
Fraction& Fraction::operator-=(const Fraction& rhs) {
	if (this != &rhs) {
		this->numerator -= rhs.numerator;
		this->denominator = rhs.denominator;
		this->reduct();
	}
	return *this;
}

// *=
Fraction& Fraction::operator*=(const Fraction& rhs) {
	if (this != &rhs) {
		this->numerator *= rhs.numerator;
		this->denominator = rhs.denominator;
		this->reduct();
	}
	return *this;
}

// /=
Fraction& Fraction::operator/=(const Fraction& rhs) {
	if (this != &rhs) {
		this->numerator /= rhs.numerator;
		this->denominator = rhs.denominator;
		this->reduct();
	}
	return *this;
}