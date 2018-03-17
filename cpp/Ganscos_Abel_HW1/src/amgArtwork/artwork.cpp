#include "artwork.h"
using namespace std;

/**
 * This is the default constructor
 * @postcondition (A new Artwork object has been created.)
 */
Artwork::Artwork(){
}

/**
 * This is the common constructor.
 * @param id2 Value to be used for the id property
 * @param artist2 Value to be used for the artist property
 * @param year2 Value to be used for the year property
 * @param location2 Value to be used for the location property
 * @precondition  (year is a positive integer)
 * @postcondition (Postcondition: A new Artwork object has been created.)
 */
Artwork::Artwork(string id2, string artist2, int year2, string location2){
	id = id2;
	artist = artist2;
	year = year2;
	location = location2;
}

/**
 * This is the deconstructor
 */
Artwork::~Artwork(){
}

/**
 * This is the public setter for id
 * @param a Value to be set for the id property
 * @precondition  (String value that is not empty/null)
 * @postcondition (The value of the id property is set)
 */
void Artwork::SetId(string a){
	id = a;
}

/**
 * This is the public setter for artist
 * @param a Value to be set for the artist property
 * @precondition  (String value that is not empty/null)
 * @postcondition (The value of the artist property is set)
 */
void Artwork::SetArtist(string a){
	artist = a;
}

/**
 * This is the public setter for year
 * @param a Value to be set for the year property
 * @precondition  (Integer value that is not negative)
 * @postcondition (The value of the year property is set)
 */
void Artwork::SetYear(int a){
	year = a;
}

/**
 * This is the public setter for location
 * @param a Value to be set for the location property
 * @precondition  (String value that is not empty/null)
 * @postcondition (The value of the location property is set)
 */
void Artwork::SetLocation(string a){
	location = a;
}

/**
 * @return Value of the id property
 * @precondition  (id property exists and is not empty/null)
 * @postcondition (Value of the id property is returned)
 */
string Artwork::GetId(){
	return id;
}

/**
 * @return Value of the artist property
 * @precondition  (artist property exists and is not empty/null)
 * @postcondition (Value of the artist property is returned)
 */
string Artwork::GetArtist(){
	return artist;
}

/**
 * @return Value of the year property
 * @precondition  (year property exists and is not negative)
 * @postcondition (Value of the year property is returned)
 */
int Artwork::GetYear(){
	return year;
}

/**
 * @return Value of the location property
 * @precondition  (location property exists and is not empty/null)
 * @postcondition (Value of the location property is returned)
 */
string Artwork::GetLocation(){
	return location;
}

/**
 * This method prints all the properties of the Artwork object
 * @output        (Properties of the object)
 * @precondition  (Artwork object exists)
 * @postcondition (Artwork information is printed)
 */
void Artwork::DumpData(){
	cout << "ID      : " << id << endl;
    cout << "Artist  : " << artist << endl;
    cout << "Year    : " << year << endl;
    cout << "Location: " << location << endl;
}

