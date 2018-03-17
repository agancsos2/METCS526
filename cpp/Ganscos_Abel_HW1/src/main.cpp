#include <iostream>
#include "./amgCommon/amgString.h"
#include "./amgArtwork/artworkManagement.h"
using namespace std;

/**
 * This method is displayed as a help menu for non-interactive options
 * @precondition  (Utility has been with the help switch)
 * @postcondition (Details of the utility are displayed in the system console)
 */
void HelpMenu(){
	cout << AMGString("").PadLeft(80,"=") << endl;
	cout << "* Name   : MET CS 526 Homework 1" << endl;
	cout << "* Author : Abel Gancsos" << endl;
	cout << "* Version: v. 1.0.0" << endl;
	cout << "* Flags:" << endl;
	cout << "	* -o        : Operation mode (1-Artwork information | 2-Update location)" << endl;
	cout << "	* -f        : Full path to the input file for override purposes" << endl;
	cout << "	* -id       : Id of the artwork to view/update" << endl;
    cout << "    * -location: Location of the artwork to update" << endl;
    cout << AMGString("").PadLeft(80,"=") << endl;
}

/**
 * This is the main program used for the command-line utility
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 * @precondition  (Utility exists on a Windows/non-Windows environment with Java 1.8 or newer)
 * @postcondition (Results needed for homework 1 are displayed)
 */
int main(int argc, char **argv){

	bool help = false;
	ArtworkManagement session = ArtworkManagement();

	// Batch mode -> Working in automation, this proves to be priceless
	if((argc - 1) > 0){
		// Loop through command-line paramters to configure the utility
		for(int i = 0; i < argc; i++){
			if(string(argv[i]) == "-h"){
				help = true;
			}
			else if(string(argv[i]) == "-o"){
				session.SetOption(string(argv[i + 1]));
			}
			else if(string(argv[i]) == "-f"){
				session.SetInputFile(string(argv[i + 1]));
			}
			else if(string(argv[i]) == "-id"){
				session.SetArtworkId(string(argv[i + 1]));
			}
			else if(string(argv[i]) == "-location"){
				session.SetArtworkLocation(string(argv[i + 1]));
			}
		}

		if(help){
			HelpMenu();
		}

		// Validate user input
		else{
			if(session.GetInputFile() != "" && session.GetArtworkId() != ""){
				if(session.GetOption() == "3" && session.GetArtworkLocation() != ""){
					session.LoadData();
					session.PerformOperation();
				}
				else{
					cout << "Update operation must have a new location..." << endl;
				}
			}
			else{
				cout << "Operation and artwork id cannot be blank..." << endl;
			}
		}
	}
	// Interactive mode
	else{
		session.SetInputFile("artwork_info.txt");
		session.LoadData();
		session.Run();	
	}
	return 0;
}
