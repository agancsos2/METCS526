#include "artworkManagement.h"
using namespace std;

/**
 * This method is used to retrieve the index of the selected Artwork
 * @param id Artwork id to look up
 * @return Index of the selected Artwork
 * @precondition  (id is a non empty/null string and an Artwork collection exists)
 * @postcondition (Index of the Artwork is returned)
 */
int ArtworkManagement::IndexOfArtwork(string id){
	for(int i = 0; i < objects.size(); i++){
		if(objects[i].GetId() == id){
			return i;
		}
	}
	return -1;
}

/**
 * This method displays information about an artwork
 * @output        (Information about the artwork)
 * @precondition  (An artwork with the specific id exists)
 * @postcondition (Information is displayed)
 */
void ArtworkManagement::GetArtworkInformation(){
	cout << "Please enter id of Artwork: " << endl;
	cin >> artworkId;
	if(IndexOfArtwork(artworkId) != -1){
		Artwork tempArtwork = objects[IndexOfArtwork(artworkId)];
		tempArtwork.DumpData();
	}
	else{
		cout << "Error!  Artwork does not exist..." << endl;
	}
}

/**
 * This method updates an artwork with the new location details
 * @output        (Information about the artwork)
 * @precondition  (An artwork with the specific id exists)
 * @postcondition (Information is displayed with the new location)
 */
void ArtworkManagement::UpdateArtworkLocation(){
    cout << "Please enter id of Artwork: " << endl;
    cin >> artworkId;
    if(IndexOfArtwork(artworkId) != -1){
        Artwork tempArtwork = objects[IndexOfArtwork(artworkId)];
		cout << "Please enter new location: ";
		cin >> artworkLocation;
		tempArtwork.SetLocation(artworkLocation);
		tempArtwork.DumpData();
    }   
    else{
        cout << "Error!  Artwork does not exist..." << endl;
    }   
}

/**
 * This method goes through the closing process and exists the utility
 * @output        (Exit message)
 * @precondition  (Utility is running)
 * @postcondition (Utility is closed)
 */
void ArtworkManagement::QuitUtility(){
	cout << AMGString("").PadRight(80,"-") << endl;
	cout << "Thank you for using ArtworkManagement.  Goodbye!" << endl;
	exit(0);
}

/**
 * This method lists all the artwork in the collection
 * @output        (List of all the Artwork objects)
 * @precondition  (List is not empty)
 * @postcondition (List of objects is displayed)
 */
void ArtworkManagement::BrowseArtwork(){
	for(int i = 0; i < objects.size(); i++){
		cout << AMGString("").PadRight(80,"#") << endl;
		objects[i].DumpData();
       	cout << AMGString("").PadRight(80,"#") << endl;
	}
}

/**
 * This method prints the menu options for the utility
 * @output        (Options for the utility)
 * @precondition  (Utility is running and wants input)
 * @postcondition (Performs operations based on option)
 */
void ArtworkManagement::PrintMenu(){
	cout << endl;
	cout << AMGString("").PadRight(80,"-") << endl;
	cout << "Choose an option:" << endl;
	cout << "1. Artwork Information" << endl;
	cout << "2. Update location" << endl;
	cout << "3. Exit" << endl;
	cin >> option;
	PerformOperation();
    cout << AMGString("").PadRight(80,"-") << endl;
}

ArtworkManagement::ArtworkManagement(){
	option = "0";
	inputFile = "";
	artworkId = "";
	artworkLocation = "";
}

ArtworkManagement::~ArtworkManagement(){
}

void ArtworkManagement::SetOption(string a){
	option = a;
}

void ArtworkManagement::SetInputFile(string a){
	inputFile = a;
}

void ArtworkManagement::SetArtworkId(string a){
	artworkId = a;
}

void ArtworkManagement::SetArtworkLocation(string a){
	artworkLocation = a;
}

string ArtworkManagement::GetOption(){
	return option;
}

string ArtworkManagement::GetInputFile(){
	return inputFile;
}

string ArtworkManagement::GetArtworkId(){
	return artworkId;
}

string ArtworkManagement::GetArtworkLocation(){
	return artworkLocation;
}

/**
 * This method retrieves the artwork collection from a file
 * @precondition  (Utility is running and the input file exists)
 * @postcondition (Artwork records are retrieved in memory)
 */
void ArtworkManagement::LoadData(){
	if(AMGSystem().FileExists(inputFile)){
		string rawData = "";
		try{
			rawData = AMGSystem(inputFile).ReadFile();
			vector<string> rawRecords = AMGString(rawData).SplitByLine(); // Split the raw data into records using the build in String split method		
			// Loop through raw records
			for(int i = 0; i < rawRecords.size(); i++){
				// Check if record is of a valid format
				if(AMGString(rawRecords[i]).Split(",").size() == 4){
					// Create new Artwork reference
					vector<string> comps = AMGString(rawRecords[i]).Split(",");
					string tempId = AMGString(comps[0]).Strip();
					string tempArtist = AMGString(comps[1]).Strip();
					int tempYear = atoi(string(AMGString(comps[2]).Strip()).c_str());
					string tempLocation = AMGString(comps[3]).Strip();
					Artwork tempArtwork = Artwork();
					tempArtwork.SetId(tempId);
					tempArtwork.SetArtist(tempArtist);
					tempArtwork.SetYear(tempYear);
					tempArtwork.SetLocation(tempLocation);
					objects.push_back(tempArtwork); // Add to Artwork collection
				}
			}
		}
		catch(exception &e){
		}
	}
	else{
		cout << "Error!  Input file does not exist...." << endl;
	}
}

/**
 * This method is a wrapper for all the operations
 * @precondition  (An operation mode was selected)
 * @postcondition (The specific operation is performed)
 */
void ArtworkManagement::PerformOperation(){
	// Use switch statements as this is typically best practice in software design
	switch(atoi(option.c_str())){
		case 1:
			GetArtworkInformation();
			break;
		case 2:
			UpdateArtworkLocation();
			break;
		case 3:
			QuitUtility();
			break;
		case 1138:
			BrowseArtwork();
			break;
		default:
			cout << "Error!  Option not supported..." << endl;
			break;
	}
}

void ArtworkManagement::Run(){
	while(option != "3"){
		PrintMenu();
	}
}

