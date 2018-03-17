#include "amgString.h"

/**
 * This is the default constructor
 * @postcondition (A new AMGString object has been created.)
 */
AMGString::AMGString(){
	str = "";
}

/**
 * This is the common constructor
 * @param str Value to set for the class
 * @precondition  (There is a string that is not empty/null)
 * @postcondition (A new AMGString object has been created from the new string) 
 */
AMGString::AMGString(string st){
	str = st;
}

/**
 * This is the deconstructor
 */
AMGString::~AMGString(){
}

/**
 * This method pads a string
 * @param len Length of the pad
 * @param pad String to use for padding
 * @return Left-padded string
 * @precondition  (The value property of the class is not empty/null)
 * @postcondition (A new left-padded string from the value string)
 */
string AMGString::PadRight(int len, string pad){
	if(str.length() > len){
		return str.substr(0,len);
	}
	else{
		string mFinal = "";
		for(int i = str.length(); i < len; i++){
			mFinal += pad;
		}
		return (str + mFinal);
	}
}

/**
 * This method pads a string
 * @param len Length of the pad
 * @param pad String to use for padding
 * @return Right-padded string
 * @precondition  (The value property of the class is not empty/null)
 * @postcondition (A new right-padded string from the value string)
 */
string AMGString::PadLeft(int len, string pad){
    if(str.length() > len){
        return str.substr(0,len);
    }
    else{
        string mFinal = "";
        for(int i = str.length(); i < len; i++){
            mFinal += pad;
        }
        return (mFinal + str);
    }
}

/**
 * This method splits the string
 * @param delim Text to split the string by
 * @return String collection 
 * @precondition  (The value property of the class is not empty/null)
 * @postcondition (String has been split based on the split filter)
 */
vector<string> AMGString::Split(string delim){
	vector<string> mfinal;
	string buffer = "";
	for(int i = 0; i < str.length(); i++){
		if(buffer == delim || string(1,str[i]) == delim){
			mfinal.push_back(buffer);
			buffer = "";
		}
		else{
        	buffer += string(1,str[i]);
		}
	}
	if(buffer != ""){
		mfinal.push_back(buffer);
	}
	return mfinal;
}

/**
 * This method splits the string into lines
 * @return String collection split by lines
 * @precondition  (The value property of the class is not empty/null)
 * @postcondition (String has been split by lines)
 */
vector<string> AMGString::SplitByLine(){
	vector<string> mFinal;
	string buffer = "";
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '\0' || str[i] == '\n'){
			mFinal.push_back(buffer);
			buffer = "";
		}
		else{
        	buffer += string(1,str[i]);
		}
	}
	if(buffer != ""){
		mFinal.push_back(buffer);
	}
	return mFinal;
}

/**
 * This method replaces all occurrences of a string
 * @param search String to search for
 * @param replace String to replace with
 * @return String that has been modified accorrding to replace filter
 * @precondition  (The value property of the class is not empty/null)
 * @postcondition (A new string with the replaced text)
 */
string AMGString::ReplaceAll(const string search, const string replace){
	size_t start = 0;
	while((start = str.find(search, start)) != string::npos){
		str.replace(start,search.length(),replace);
		start += replace.length();	
	}
	return str;
}

/**
 * This method strips all whitespace
 * @return String that has no whitespace
 * @precondition  (The value property of the class is not empty/null)
 * @postcondition (Whitespace characters have been removed)
 */
string AMGString::Strip(){
	string mFinal = str;
	mFinal = AMGString(mFinal).ReplaceAll("\n","");
	return mFinal;
}

/**
 * This method checks if the string contains a specific text
 * @param search Text to look for
 * @return True if it contains the search text, false if not
 * @precondition  (The value property of the class is not empty/null)
 * @postcondition (Text contains text or not)
 */
bool AMGString::Contains(string search){
	if(AMGString(str).ReplaceAll(search,"") != str){
		return true;
	}
	return false;
}
