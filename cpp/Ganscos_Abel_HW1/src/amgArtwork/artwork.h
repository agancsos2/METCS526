#ifndef __ARTWORK_H_INCLUDED__
#define __ARTWORK_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 *	This class is meant to hold Artwork instance details used in the rest of the utility
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 */
class Artwork{
    private:
		string id; // unique id number
 		string artist; // the name of the artist, if known
		int    year; // the year when the artwork was created, if known
		string location; // current location of the artwork, such as gallery, storeroom, or loan
    public:
        Artwork();
		Artwork(string id2, string artist2, int year2, string location2);
        ~Artwork();
		void SetId(string a);
		void SetArtist(string a);
		void SetYear(int a);
		void SetLocation(string a);
		string GetId();
		string GetArtist();
		int GetYear();
		string GetLocation();
		void DumpData();
};

#endif
