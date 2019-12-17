#pragma once
#include <string>
class qfunc
{
public:
	qfunc();
	virtual ~qfunc();
	void setExpandedForm(double a, double b, double c);
	void setVertexForm(double a, double p, double q);
	void setFactoredForm(double a, double x1, double x2);

	void expandedToVertex();
	void expandedToFactored();
	void vertexToExpanded();
	void vertexToFactored();
	void factoredToExpanded();
	void factoredToVertex();

	std::string getExpandedForm();
	std::string getVertexForm();
	std::string getFactoredForm();
private:
	double a, b, c, p, q, x1, x2;
};
