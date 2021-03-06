// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  You own a lot of guitars, and each guitar has a unique serial number.  You want to be able to  look up serial numbers quickly, so you decide to sort the entire list as follows.

  Each serial number consists of uppercase letters ('A' - 'Z') and digits ('0' - '9'). To see if serial number A comes before serial number B, use the following steps:

  If A and B have a different length, the one with the shortest length comes first.
  Else if sum_of_digits(A) differs from sum_of_digits(B) (where sum_of_digits(X) returns the sum of all digits in string X), the one with the lowest sum comes first.
  Else compare them alphabetically, where digits come before letters.

  Given a vector <string> serialNumbers, return a vector <string> with the ordered list of serial numbers in increasing order.

  DEFINITION
  Class:SerialNumbers
  Method:sortSerials
  Parameters:vector <string>
  Returns:vector <string>
  Method signature:vector <string> sortSerials(vector <string> serialNumbers)


  CONSTRAINTS
  -serialNumbers will contain between 1 and 50 elements, inclusive.
  -Each element of serialNumbers will contain between 1 and 50 characters, inclusive.
  -serialNumbers will only contain uppercase letters ('A' - 'Z') and digits ('0' - '9').
  -All elements of serialNumbers will be distinct.


  EXAMPLES

  0)
  {"ABCD","145C","A","A910","Z321"}

  Returns: {"A", "ABCD", "Z321", "145C", "A910" }

  The first serial is "A" because it has the shortest length. All others have length 4, but "ABCD" has the lowest sum. Next lowest is "Z321", and finally "A910" comes before "145C" because "A" comes before the "1" (they both have sum = 10)

  1)
  {"Z19", "Z20"}

  Returns: {"Z20", "Z19" }

  1+9 > 2+0, so "Z20" comes first.

  2)
  {"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"}

  Returns: {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" }



  3)
  {"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"}

  Returns: {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" }



*/
// END CUT HERE
#line 62 "SerialNumbers.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class SerialNumbers {
public:
  ///// ?????? which ones must be static and why???
  static int prs (char s) {
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }
  static bool lcmp (string a, string b) { //sum cmp
    return (a.length() < b.length());
  }
  static bool digit (char c) {
    return isdigit (c);
  }
  static bool scmp (string a, string b) { // sum of digs cmp
    int as = 0, bs = 0;
    for (int i = 0; i != a.size(); ++i) {
      if (digit (a[i]))
	as += prs (a[i]);
    }
    for (int i = 0; i != b.size(); ++i) {
      if (digit (b[i]))
	bs += prs (b[i]);
    }
    return (as < bs);
  }
  vector <string> sortSerials(vector <string> sn) { // sn = serial numbers
    stable_sort (sn.begin(), sn.end());
    stable_sort (sn.begin(), sn.end(), scmp);
    stable_sort (sn.begin(), sn.end(), lcmp);
    return sn;
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
      cout << "Testing SerialNumbers (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456402368;
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
      SerialNumbers _obj;
      vector <string> _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string serialNumbers[] = {"ABCD","145C","A","A910","Z321"};
	    string __expected[] = {"A", "ABCD", "Z321", "145C", "A910" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
	  }
	case 1:
	  {
	    string serialNumbers[] = {"Z19", "Z20"};
	    string __expected[] = {"Z20", "Z19" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
	  }
	case 2:
	  {
	    string serialNumbers[] = {"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"};
	    string __expected[] = {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
	  }
	case 3:
	  {
	    string serialNumbers[] = {"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"};
	    string __expected[] = {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
	  }
	  /*case 4:
	    {
	    string serialNumbers[] = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
	    }*/
	  /*case 5:
	    {
	    string serialNumbers[] = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
	    }*/
	  /*case 6:
	    {
	    string serialNumbers[] = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
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
	  cout << "           Expected: {";
	  for (unsigned i = 0; i < _expected.size(); i++)
	    {
	      if (i) cout << ",";
	      cout << " \"" << _expected[i] << "\"";
	    }
	  cout << " }" << endl;
	  cout << "           Received: {";
	  for (unsigned i = 0; i < _received.size(); i++)
	    {
	      if (i) cout << ",";
	      cout << " \"" << _received[i] << "\"";
	    }
	  cout << " }" << endl;
	}
    }
}

// END CUT HERE
