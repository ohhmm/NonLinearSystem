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

	return 0;
}
