// Kumar Dheeraj - VXC7Y1 -
// Chapter 09 - Part 5 Drill 

#include "std_lib_facilities.h"

enum class Month{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date{
    public:
	Date(int y, Month m, int d);

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

	
	int day() const { return d; }
	Month month() const { return m; }
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
    // adding date 
	if ((d += n) > 31){
		d = 1;
		int nextM = int(m) + 1;
		if (nextM > 12){
			add_month(1);
		}
		else
			m = Month(nextM);
	}
}

void Date::add_month(int n)
{
    // for adding month
	int nextM = 0;
	if ((nextM = int(m) + n) > 12){
		m = Month::jan;
		add_year(1);
	}
	else
		m = Month(nextM);
}

void Date::add_year(int n){
    // for adding year
	y += n;
	if (y > 3000){
		cout << "It is not the year 3000; busted" << endl;
		y -= n;
	}
}


// driver function
int main()
{
	Date today(1978, Month::jan, 30);
	Date tomorrow(today);

	tomorrow.add_day(1);
	cout << tomorrow << endl;
	tomorrow.add_month(1);
	cout << tomorrow << endl;
	tomorrow.add_year(5);
	cout << tomorrow << endl;


	cout << "\n" << today << endl;
	cout << tomorrow << endl;

	//check invalid date
	Date invalidDate{ 1000, Month::dec, 100 };
	return 0;
}