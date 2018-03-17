#ifndef __ARTWORKMANAGEMENT_H_INCLUDED__
#define __ARTWORKMANAGEMENT_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include "artwork.h"
#include "../amgCommon/amgString.h"
#include "../amgCommon/amgSystem.h"
using namespace std;

/**
 * This is the session class used for the command-line utility
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 * @precondition  (Utility exists on a Windows/non-Windows environment with Java 1.8 or newer)
 * @postcondition (Results needed for homework 1 are displayed)
 */
class ArtworkManagement{
    private:
    	string option;            // Used as the operation mode selection
    	string inputFile;         // Path for the input file
    	string artworkId;         // ID of the Artwork
    	string artworkLocation;   // Location of the Artwork
		vector <Artwork> objects; // Collection of Artwork objects
		int IndexOfArtwork(string id);
		void GetArtworkInformation();
		void UpdateArtworkLocation();	
		void QuitUtility();
		void BrowseArtwork();
		void PrintMenu();
    public:
        ArtworkManagement();
        ~ArtworkManagement();
		void SetOption(string a);
		void SetInputFile(string a);
		void SetArtworkId(string a);
		void SetArtworkLocation(string a);
		string GetOption();
		string GetInputFile();
		string GetArtworkId();
		string GetArtworkLocation();
		void Run();
		void LoadData();
		void PerformOperation();
};

#endif
