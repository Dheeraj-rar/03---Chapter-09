// Kumar Dheeraj - VXC7Y1 -
// Chapter 09 - Part 3 Drill 

#include "std_lib_facilities.h"

class Date{
    public:
	Date(int y, int m, int d);

	void add_day(int n);

    int day() const { return d; }
	int month() const { return m; }
	int year() const { return y; }

    private:
	int y, m, d;
};

ostream& operator<<(ostream& os, const Date& d){
	
    return os << "(" << d.year() << "," << d.month() << "," << d.day() << ")";
}

Date::Date(int yy, int mm, int dd){

	int yearMin(1900), yearMax(3000);
	if (yy < yearMin || yy > yearMax)
		cout << "Invalid year.";
	if (mm < 1 || mm > 12)
		cout << "Invalid month.";
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

	//invalid date
	Date invalidDate{ 1000, 27, 100 };


	return 0;
}