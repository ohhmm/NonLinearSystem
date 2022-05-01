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
    auto $equation2 = a + b - 21;

	cout << "Equation 1: " << equation1 << endl;
	cout << "Equation 2: " << $equation2 << endl;

	System s;
	s << equation1;
	s << $equation2;

	cout << "\nSolving..." << endl;
	auto solutions_a = s.Solve(a);
	cout << "Solutions " << a << ':' << endl;
	for(auto& solution: solutions_a)
	    cout << '\t' << solution << endl;


    cout << "\n\nHello Features!\n";
    cout << "\n\nHello expressions!\n";
    auto t = equation1.LogicAnd($equation2);
    cout << "Expression t: " << t << endl
    << "\nHello Multivalue expressions!\n";
    
    auto $11_or_$7 = Valuable::MergeOr(11, 7);
    
    cout << "Expressed a from expression t is  a = " << t(a) << endl
        << "±1 = " << Valuable::MergeOr(1, -1) << endl
        << "±7 = " << Valuable::MergeOr(7, -7) << endl
        << "\n 11 or 7  =  " << $11_or_$7 << endl
        << endl
        ;

    cout << "Distinct values of $11_or_$7 are as follows:" << endl;
    for(auto& value: $11_or_$7.Distinct()){
        cout << ' ' << value;
    }
    cout<< endl
    ;

	return 0;
}
