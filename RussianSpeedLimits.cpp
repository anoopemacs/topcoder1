// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Rumor has it that Russians don't obey speed limits. That may be because
the speed limits are sometimes specified implicitly in Russia.
More specifically, every road in a city has a default speed
limit of 60 kilometers per hour, and usually doesn't have any road
signs to remind drivers of that. Analogously, every road outside the city
has a default speed limit of 90 kilometers per hour.
The speed limit can still be specified with
road signs, like '30' or '95'. There is also a special road sign,
'start of default speed limit zone', that tells you that the default speed limit is now in place. The signs are sometimes also used to remind
drivers of the current speed limit, so you can meet several same signs in a row.
To summarize, one should pay attention to the following road signs
to monitor the speed limit changes:

Speed limit X - marks the start of a zone with speed limit X kilometers per hour.
Start of default speed limit zone - marks the start of a zone with the default speed limit, either 60 if inside a city or 90 if outside.
City boundary - means the default speed limit changes from 60 to 90 or vice versa. If
you are inside a special speed limit zone, this zone also ends, so the speed limit always becomes equal to the new default.

Given the list of road signs you met on your way as a vector <string> signs
(in the order you met them), return the current speed limit. Each element of
signs will be either a positive integer number X without leading zeros,
denoting the sign 'Speed limit X', a string "default" denoting the
sign 'start of default speed limit zone', or a string "city", denoting the sign
'city boundary' (quotes for clarity only). You start your journey inside a city, and outside any special speed
limit zone.


DEFINITION
Class:RussianSpeedLimits
Method:getCurrentLimit
Parameters:vector <string>
Returns:int
Method signature:int getCurrentLimit(vector <string> signs)


CONSTRAINTS
-signs will contain between 1 and 50 elements, inclusive.
-Each element of signs will be "default", "city" or a positive integer without leading zeros, between 1 and 100, inclusive (quotes for clarity only).


EXAMPLES

0)
{"80"}

Returns: 80

On highways, speed limits may be above the default value.

1)
{"40", "70", "default", "20", "50"}

Returns: 50

The limits are specified in the order you meet them, so you're interested in the last one.

2)
{"40", "70", "default"}

Returns: 60

The default limit is still 60.

3)
{"40", "80", "city"}

Returns: 90

The first "city" means we've left the city, thus the 90 limit.

4)
{"city", "60"}

Returns: 60

Speed limits can be overridden outside the city too.

5)
{"city", "50", "default"}

Returns: 90

The default value changes when outside the city.

6)
{"city", "city", "city", "city"}

Returns: 60

You've crossed four city boundaries.  The first time, you left a city.  Then, you entered a city.  Then, you left that city.  Finally, you entered another city.

7)
{"20", "city", "city", "50", "60"}

Returns: 60

The default speed limit may be specified with a usual sign.

*/
// END CUT HERE
#line 105 "RussianSpeedLimits.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class RussianSpeedLimits {
public:
  int prs (string s) {
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }

  int getCurrentLimit(vector <string> signs) {
    int ret = 60;
    bool inside_city = true;
    for (int i = 0; i != signs.size(); ++i) {
      if (signs[i] == "city") {
	inside_city = !inside_city;
	ret = (inside_city == true)? 60 : 90;
      }
      else if (signs[i] == "default") {
	ret = (inside_city == true)? 60 : 90;
      }
      else {
	ret = prs (signs[i]);
      }
    }
    return ret;
  }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing RussianSpeedLimits (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456559178;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RussianSpeedLimits _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string signs[] = {"80"};
				_expected = 80;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}
			case 1:
			{
				string signs[] = {"40", "70", "default", "20", "50"};
				_expected = 50;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}
			case 2:
			{
				string signs[] = {"40", "70", "default"};
				_expected = 60;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}
			case 3:
			{
				string signs[] = {"40", "80", "city"};
				_expected = 90;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}
			case 4:
			{
				string signs[] = {"city", "60"};
				_expected = 60;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}
			case 5:
			{
				string signs[] = {"city", "50", "default"};
				_expected = 90;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}
			case 6:
			{
				string signs[] = {"city", "city", "city", "city"};
				_expected = 60;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}
			case 7:
			{
				string signs[] = {"20", "city", "city", "50", "60"};
				_expected = 60;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}
			/*case 8:
			{
				string signs[] = ;
				_expected = ;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string signs[] = ;
				_expected = ;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string signs[] = ;
				_expected = ;
				_received = _obj.getCurrentLimit(vector <string>(signs, signs+sizeof(signs)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
