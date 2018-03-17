#include "amgSystem.h"
using namespace std;

/**
 * This is the default constructor.
 * @postcondition (A new AMGSystem object has been created.)
 */	
AMGSystem::AMGSystem(){
}

/**
 * This is the deconstructor
 */
AMGSystem::~AMGSystem(){
}

/**
 * This is another constructor that sets the source path
 * @param src Full path for a source location
 * @precondition  (The path location exists or can be created)
 * @postcondition (A new AMGSystem object is created with the source location)
 */
AMGSystem::AMGSystem(string src){
	source = src;
}

/**
 * This is the public setter for the source path location
 * @param s Full path for a source location
 * @precondition  (The path location exists)
 * @postcondition (The value of the source location is set)
 */
void AMGSystem::SetSource(string s){
	source = s;
}

/**
 * This is the public getter for the source path location
 * @return        (Value of the source path location)
 * @precondition  (The value of the source path is not empty/null)
 * @postcondition (The value of the source path is returned)
 */
string AMGSystem::GetSource(){
	return source;
}

/**
 * This is the public setter for the target path location
 * @param t Full path for a target location
 * @precondition  (The path location exists )
 * @postcondition (The value of the target location is set)
 */
void AMGSystem::SetTarget(string t){
	target = t;
}

/**
 * This is the public getter for the target path location
 * @return        (Value of the target path location)
 * @precondition  (The value of the target path is not empty/null)
 * @postcondition (The value of the target path is returned)
 */
string AMGSystem::GetTarget(){
	return target;
}

/**
 * This is another constructor that sets the source path and target path
 * @param src Full path for a source location
 * @param tar Full path for a parent target location
 * @precondition  (The source path location exists and the target location is accessible)
 * @postcondition (A new AMGSystem object is created with the source and target locations)
 */	
AMGSystem::AMGSystem(string src,string tar){
	source = src;
	target = tar;
}

/**
 * This method checks if the location exists
 * @param path    Full path for a location on the system
 * @return        (True if exists, false if not)
 * @precondition  (The value of the path is not empty/null)
 * @postcondition (Boolean value if the path exists on the system)
 */
bool AMGSystem::FileExists(string path){
	if(FILE *file = fopen(path.c_str(), "r")){
        fclose(file);
        return true;
    } 
	else{
        return false;
    }   
}

/**
 * This method reads text from the source path location
 * @return        (Text from the source file)
 * @precondition  (The source location exists and can be read)
 * @postcondition (Text from the file)
 */
string  AMGSystem::ReadFile(){
	string mFinal = "";
	string buffer = "";
	if(source != ""){
		if(FileExists(source)){
			ifstream file(source.c_str());
			if(file.is_open()){
				while(getline(file,buffer)){
					mFinal += ("\n" + buffer);
				}
				file.close();
				return mFinal;
			}
			else{
				throw invalid_argument("Failed to open source file path...");
			}
		}
		else{
			throw invalid_argument("Source file path does not exists...");
		}
	}
	else{
		throw invalid_argument("Source file path is empty...");
	}
	return "";
}

/**
 * This method writes some data to the target location
 * @param data    Text to be written tot he file
 * @return        (True if successful, false if not)
 * @precondition  (The value of the path is not empty/null and can be written to)
 * @postcondition (The text has been written to the target location
 */
void AMGSystem::WriteFile(string data){
	if(target != ""){
		ofstream file(target.c_str());
		if(file.is_open()){
			file << data << endl;
			file.close();
		}
		else{
			throw invalid_argument("Failed to open target file path...");
		}
	}
	else{
		throw invalid_argument("Target file path is empty...");
	}
}
