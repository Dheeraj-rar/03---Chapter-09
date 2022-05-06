// Kumar Dheeraj - VXC7Y1 -
// Chapter 09 - Part 1 Drill

#include "std_lib_facilities.h"

struct Date
{
	Date(int y, int m, int d);
	int y,m,d;

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
		cout << "Invalid Date." << endl;
	else{
		y = yy; m = mm; d = dd;
	}
}

void add_day(Date& dd, int n){
	//increase dd by n days
	dd.d += n;
}

// driver function
int main(){
	Date today( 1978, 6, 25 );
	Date tomorrow( today );

	add_day(tomorrow, 1);

	cout << today << endl;
	cout << tomorrow << endl;

	//check invalid date
	Date invalidDate{ 1200, 55, 100 };

	keep_window_open();
	return 0;
}