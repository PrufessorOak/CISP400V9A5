// NAME  : Yevgeniy Lankin
// CLASS : CISP 400, Online
// Assignment #: A5
// PURPOSE : Test program for class Complex.h and functions defined in Complex.cpp
//           To show my understand of operation overloading.
// Software Change (Modifications) Record
// date         what               who
// 10/29/2015   created program    Yev

#include "Complex.h" // Complex class definition

int main()
{
	Complex x,
		y(4.3, 8.2),
		z(3.3, 1.1),
		k,
		l,
		m(0, 0.1);

	// demonstrating overloaded >>
	cout << "Enter a complex number in the form: (a, b) for Complex object k.\n";
	cin >> k;
	// check if complex number was properly typed. "input validation"
	while (k == 0)
	{
		cin.clear(); // unset failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
		cout << "Enter a complex number in the form: (a, b) for Complex object k.\n";
		cin >> k;
	};

	cout << "\nThe existing Complex objects are:\n";

	// demonstrating overloaded <<
	cout << "(Performing << operator overloading.)";
	cout << "\nx: " << x << "\ny: " << y << "\nz: " << z << "\nk: " << k << "\nl: " << l << "\nm: " << m << '\n';

	// demonstrating overloaded + and =
	cout << "\nPerforming +, = and << operators overloading.";
	x = y + z;
	cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';

	// demonstrating overloaded - and =
	cout << "\nPerforming -, = and << operators overloading.";
	x = y - z;
	cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';

	// demonstrating overloaded * and =
	cout << "\nPerforming *, = and << operators overloading.";
	x = y * z;
	cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

	cout << "Performing /, = and << operators overloading.";
	x = y / z;
	cout << "\nx = y / z:\n" << x << " = " << y << " / " << z << '\n';

	//This is a divide by zero situation
	cout << "\nPerforming /, = and << operators overloading with divisor is (0, 0).";
	x = y / l;
	cout << "\nx = y / l:\n" << x << " = " << y << " / " << l << '\n';

	//This is a divide by a close to zero situation
	cout << "\nPerforming /, = and << operators overloading with divisor is (0, 0.1).";
	x = y / m;
	cout << "\nx = y / m:\n" << x << " = " << y << " / " << m << '\n';

	// demonstrating overloaded !=
	cout << "\nPerforming != and << operators overloading.\n"
		<< "check x != k\n";
	if (x != k) cout << x << " != " << k << '\n';

	// demonstrating overloaded ==
	cout << "\n\nPerforming =, == and << operators overloading." << endl
		<< "assign k to x by using x = k statement." << endl
		<< "check x == k" << endl;
	x = k;
	if (x == k) cout << x << " == " << k << '\n';

	return 0;
} // end main
