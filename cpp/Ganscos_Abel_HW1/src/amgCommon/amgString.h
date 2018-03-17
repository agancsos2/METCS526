#ifndef __AMGSTRING_H_INCLUDED__  
#define __AMGSTRING_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * This class helps manipulate strings
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 * This class is a custom class that I built for a personal project and can be found at
 * https://github.com/agancsos/java/blob/master/JavaETL/src/AMGString.java
 */
class AMGString{
	private:
		string str;
	public:
		AMGString();
		AMGString(string st);
		~AMGString();
		string PadRight(int len, string pad);
		string PadLeft(int len, string pad);
		vector<string>Split(string delim);
		vector<string>SplitByLine();
		string ReplaceAll(string search,string replace);
		string Strip();
		bool Contains(string search);
};

#endif
