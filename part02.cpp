// Kumar Dheeraj - VXC7Y1 -
// Chapter 09 - Part 2 Drill

#include "std_lib_facilities.h"

struct Date
{
	Date(int y, int m, int d);
	void add_day(int n);
	int y, m, d;
};

ostream& operator<<(ostream& os, const Date& d){
	return os << "(" << d.y << "," << d.m << "," << d.d << ")";
}

Date::Date(int yy, int mm, int dd)
{
	int yearMin(1900), yearMax(3000);
	if (yy < yearMin || yy > yearMax)
		cout << "Invalid year." << endl;
	if (mm < 1 || mm > 12)
		cout << "Invalid month." << endl;
	if (dd < 1 || dd > 31)
		cout << "Invalid day." << endl;
	else{
		y = yy; m = mm; d = dd;
	}
}

void Date::add_day(int n){
	//if d += n is more than 31, make it 1, else return d
	if (d += n > 31){
		d = 1;
		++m;
	}
}

// driver function
int main()
{
	Date today( 1978, 6, 31 );
	Date tomorrow( today );

	tomorrow.add_day(1);

	cout << today << endl;
	cout << tomorrow << endl;

	//check invalid date
	Date invalidDate{ 1000, 55, 1000 };

	return 0;
}