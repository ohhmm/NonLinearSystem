#include <iostream>
using namespace std;

// TODO : #include <openmind/omnn/math/System.h>
#include <omnn/math/System.h>
using namespace omnn::math;

int main(int argc, char **argv) {
	cout << "Hello System:\n";

	DECL_VA(a);
	DECL_VA(b);
	auto equation1 = a - 8 - b;
	auto equation2 = a + b - 21;

	cout << "Equation 1: " << equation1 << endl;
	cout << "Equation 2: " << equation2 << endl;

	System s;
	s << equation1;
	s << equation2;

	auto solutions_a = s.Solve(a);
	cout << "Solutions " << a << ':' << endl;
	for(auto& solution: solutions_a)
	    cout << '\t' << solution << endl;


    cout << "\n\nHello Features!\n";
    cout << "\n\nHello expressions!\n";
    auto t = equation1.LogicAnd(equation2);
    cout << "Expression t: " << t << endl
        << "\nHello Multivalue expressions!\n"
        << "Expressed a from expression t is  a = " << t(a) << endl
        << "±1 = " << Valuable::MergeOr(1, -1) << endl
        << "±7 = " << Valuable::MergeOr(7, -7) << endl
        << " 8 or -7 = " << Valuable::MergeOr(8, -7) << endl
        ;
    

	return 0;
}
