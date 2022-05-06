// Kumar Dheeraj - VXC7Y1 -
// Chapter 09 - Part 4 Drill 

#include "std_lib_facilities.h"

enum class Month{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date{
    public:
	Date(int y, Month m, int d);

	void add_day(int n);

	Month month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }

    private:
	int y, d;
	Month m;
};


ostream& operator<<(ostream& os, const Date& d){
	return os << "(" << d.year() << "," << int(d.month()) << "," << d.day() << ")";
}

Date::Date(int yy, Month mm, int dd){
    
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
		int nextM = int(m) + 1;		// and you get a c cast
		if (nextM > 12){
			m = Month::jan;
			if (++y > 3000)
				cout << "It is not the year 3000; busted" << endl;
		}
		else
			m = Month(nextM);			//and you get a c cast
	}
}

// driver function
int main(){
	//c casting...c casting everywhere!

	Date today( 1978, Month::dec, 31 );
	Date tomorrow( today );

	tomorrow.add_day(1);

	cout << today << endl;
	cout << tomorrow << endl;

	//invalid date
	Date invalidDate{ 1000, Month::dec, 100 };

	return 0;
}