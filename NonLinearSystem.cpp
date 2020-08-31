#include <iostream>
using namespace std;

#include <openmind/omnn/math/System.h>
using namespace omnn::math;

auto Length(const auto& x1, const auto& y1,
        const auto& x2, const auto& y2)
{
    return ((x2-x1).sq() + (y2-y1).sq()).Sqrt();
}
auto GeronTriangleSquare(const auto& x1, const auto& y1,
        const auto& x2, const auto& y2,
        const auto& x3, const auto& y3)
{
    auto l1 = Length(x1, y1, x2, y2);
    auto l2 = Length(x3, y3, x2, y2);
    auto l3 = Length(x1, y1, x3, y3);
    auto perimeter = l1+l2+l3;
    auto hp = perimeter / 2;
    return (hp * (hp-l1) * (hp-l2)*(hp-l3)).Sqrt();
}

auto PointInTriangle(const auto& x, const auto& y,
        const auto& x1, const auto& y1,
        const auto& x2, const auto& y2,
        const auto& x3, const auto& y3)
{
    auto sq1 = GeronTriangleSquare(x,y,x1,y1,x2,y2);
    auto sq2 = GeronTriangleSquare(x,y,x3,y3,x2,y2);
    auto sq3 = GeronTriangleSquare(x,y,x1,y1,x3,y3);
    auto sq = GeronTriangleSquare(x1,y1,x2,y2,x3,y3);
    return sq.IfEq(sq1+sq2+sq3, true, false);
}

int main(int argc, char **argv) {
	cout << "Hello System:\n";
	System s;

	DECL_VA(x1); DECL_VA(y1);
	DECL_VA(x2); DECL_VA(y2);
	DECL_VA(x3); DECL_VA(y3);
	DECL_VA(R); // Radius
	DECL_VA(Pin); // Center point is in triangle (1 or 0)
	DECL_VA(Probability); // Probability that center point is in triangle

	auto equation = (x1.Sq() + y1.Sq()).Equals(R);
	s << equation;
    cout << "Equation 1: " << equation << endl;

	equation = (x2.Sq() + y2.Sq()).Equals(R);
	s << equation;
	cout << "Equation 2: " << equation << endl;

	equation = (x3.Sq() + y3.Sq()).Equals(R);
	s << equation;
	cout << "Equation 3: " << equation << endl;

    auto pointInTrianglePredEq = PointInTriangle(0,0,x1,y1,x2,y2,x3,y3);
    auto inFormula = pointInTrianglePredEq.Equals(true);
    auto both100percent = inFormula.LogicOr(pointInTrianglePredEq.Equals(false));
    equation = Probability.Equals(inFormula / both100percent);
    s << equation;
    cout << "Equation 4 (probability): " << equation << endl;

	auto solutions = s.Solve(Probability);
	cout << "Solutions " << Probability << ':' << endl;
	for(auto& solution: solutions)
	    cout << '\t' << solution << endl;

	return 0;
}
