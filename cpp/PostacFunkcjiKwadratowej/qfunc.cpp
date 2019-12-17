#include "qfunc.h"
#include <cmath>
#include <string>
#include <sstream>

qfunc::qfunc()
	: a(0), b(0), c(0), p(0), q(0), x1(0), x2(0)
{
}


qfunc::~qfunc()
{
}

void qfunc::setExpandedForm(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void qfunc::setVertexForm(double a, double p, double q)
{
	this->a = a;
	this->p = p;
	this->q = q;
}

void qfunc::setFactoredForm(double a, double x1, double x2)
{
	this->a = a;
	this->x1 = x1;
	this->x2 = x2;
}

void qfunc::expandedToVertex()
{
	p = -b / (2 * a);
	double delta = pow(b, 2.0) - 4 * a * c;
	q = -delta / (4 * a);
}

void qfunc::expandedToFactored()
{
	double delta = pow(b, 2) - 4 * a * c;
	if (delta > 0) {
		x1 = (-b - sqrt(delta)) / 2 * a;
		x2 = (-b + sqrt(delta)) / 2 * a;
	} 
	else if (delta == 0) {
		x1 = -b / (2 * a);
	} else {}
}

void qfunc::vertexToExpanded()
{
	b = -2 * a * p;
	c = (a * pow(p, 2)) + q;
}

void qfunc::vertexToFactored()
{
	vertexToExpanded();
	expandedToFactored();
}

void qfunc::factoredToExpanded()
{
	b = -a * (x1 + x2);
	c = a * x1 * x2;
}

void qfunc::factoredToVertex()
{
	factoredToExpanded();
	expandedToVertex();
}

std::string qfunc::getExpandedForm()
{
	std::stringstream ss;
	if (a != 0 && b != 0 && c != 0)
		ss << std::showpos << "f(x) = " << a << "x^2" << b << "x" << c;
	else if (a != 0 && b == 0 && c != 0)
		ss << std::showpos << "f(x) = " << a << "x^2" << c;
	else if (a != 0 && b != 0 && c == 0)
		ss << std::showpos << "f(x) = " << a << "x^2" << b << "x";
	else
		ss << std::showpos << "f(x) = " << a << "x^2";

	std::string expandedForm = ss.str();
	return expandedForm;
}

std::string qfunc::getVertexForm()
{
	std::stringstream ss;
	if (p != 0 && q != 0)
		ss << std::showpos << "f(x) = " << a << "(x" << -p << ")^2" << q;
	else if (p != 0 && q == 0)
		ss << std::showpos << "f(x) = " << a << "(x" << -p << ")^2";
	else if (p == 0 && q != 0)
		ss << std::showpos << "f(x) = " << a << "x^2" << q;
	else
		ss << std::showpos << "f(x) = " << a << "x^2";

	std::string vertexForm = ss.str();
	return vertexForm;
}

std::string qfunc::getFactoredForm()
{
	std::stringstream ss;
	if (x1 != 0 && x2 != 0)
		ss << std::showpos << a << "(x" << -x1 << ")(x" << -x2 << ")";
	else if (x1 != 0 && x2 == 0)
		ss << std::showpos << a << "(x" << -x1 << ")^2";
	else
		ss << std::showpos << a << "x^2";

	std::string factoredForm = ss.str();
	return factoredForm;
}
