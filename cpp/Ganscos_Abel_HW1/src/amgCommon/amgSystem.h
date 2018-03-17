#ifndef __AMGSYSTEM_H_INCLUDED__  
#define __AMGSYSTEM_H_INCLUDED__ 

#include <string>
#include <vector>
#include <fstream>
using namespace std;

/**
 * This class offers custom system operations
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 * This class is a custom class that I built for a personal project and can be found at
 * https://github.com/agancsos/java/blob/master/JavaETL/src/AMGSystem.java
 */
class AMGSystem{
	private:
        string source;
        string target;
	public:
		AMGSystem();
		~AMGSystem();
		AMGSystem(string src);
		AMGSystem(string src,string tar);
		string ReadFile();
		void WriteFile(string data);
		bool FileExists(string path);
		void SetSource(string s);
		string GetSource();
		void SetTarget(string t);
		string GetTarget();
};

#endif
