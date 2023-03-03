/*
Created by: Robert Duncan
File Name: playlist.cpp
Support files: Queue.h, LinkedList.h, MyString.h
Date Created: November 29, 2022
Date Last Modified: March 2, 2023

This script was my own personal rendition of making a playlist type file in c++.
This project was completed for my end of term project for my Data Structures class. 
While this file does not play audio and more so is just a collection of data, my goal 
was to take most or all of the information learned through the semester and incorporate
it into one big project. There are certainly still some flaws to this code and some things
that could be further refined. 

*/

#include <iostream>
#include <chrono>
#include <stack>
#include <string.h>
#include "MyString.h"
#include "LinkedList.h"
#include "Queue.h"
#include <string>
#include <math.h>

using namespace std;

#define RETURN return 0;

void skip_lines(int N) { for (int i = 0; i < N; i++) cout << endl; }

// Prints the Menu for the playlist maker
void menu(void) {
	cout << "Please choose from the following options:" << endl;
	cout << "1. Add New Song" << endl;
	cout << "2. View Playlist as it Currently Stands" << endl;
	cout << "3. Dequeue Song Currently Queued" << endl;
	cout << "4. Done Making The Playlist" << endl;
}

// Hash Function for the band names to ensure no collision 
int bandhashing17(string band) {
	int result = 0;
	for (int i = 0; i < band.length(); i++) {
		band[i] = tolower(band[i]);
		result += int(band[i]);
	}
	int hash = pow(result, 3);
	hash = hash % 17;
	hash = abs(hash);
	return hash;
}
/* 
The following three hash functions are defined as to ensure there is no collision 
amongst the albu names for each band respecitvely, as there was collision with the use of only one, 
two more hash functions needed to be defined.
*/
int albumhashing17(string album) {
	int result = 0;
	for (int i = 0; i < album.length(); i++) {
		album[i] = tolower(album[i]);
		result += int(album[i]);
	}
	int hash = pow(result, 3);
	hash = hash % 17;
	hash = abs(hash);
	return hash;
}

int albumhashing31(string album) {
	int result = 0;
	for (int i = 0; i < album.length(); i++) {
		album[i] = tolower(album[i]);
		result += int(album[i]);
	}
	int hash = pow(result, 3);
	hash = hash % 31;
	hash = abs(hash);
	return hash;
}
int albumhashing43(string album) {
	int result = 0;
	for (int i = 0; i < album.length(); i++) {
		album[i] = tolower(album[i]);
		result += int(album[i]);
	}
	int hash = pow(result, 2);
	hash = hash % 43;
	hash = abs(hash);
	return hash;
}

int main() {

	// Linked List Containing all of the bands available
	LinkedList<string>Bands;
	Bands.postpend_node("I Prevail", "1");
	Bands.postpend_node("Beartooth", "2");
	Bands.postpend_node("Dayseeker", "3");
	Bands.postpend_node("We Came As Romans", "4");
	Bands.postpend_node("Wage War", "5");

	// Linked List containing the Albums for the band I Prevail
	LinkedList<string>IP;
	IP.postpend_node("Heart vs Mind", "1");
	IP.postpend_node("Lifelines", "2");
	IP.postpend_node("Trauma", "3");
	IP.postpend_node("True Power", "4");
	// Lines 94 - 146 include Linked Lists that contain the songs for each I Prevail Album
	LinkedList<string>HeartvsMind;
	HeartvsMind.postpend_node("Heart vs Mind", "1");
	HeartvsMind.postpend_node("Crossroads", "2");
	HeartvsMind.postpend_node("Love, Lust and Liars", "3");
	HeartvsMind.postpend_node("Face Your Demons", "4");
	HeartvsMind.postpend_node("The Enemy", "5");
	HeartvsMind.postpend_node("My Heart I Surrender", "6");
	HeartvsMind.postpend_node("Deceivers", "7");
	LinkedList<string>Lifelines;
	Lifelines.postpend_node("Scars", "1");
	Lifelines.postpend_node("Stuck In Your Head", "2");
	Lifelines.postpend_node("Lifelines", "3");
	Lifelines.postpend_node("Come and Get It", "4");
	Lifelines.postpend_node("Chaos", "5");
	Lifelines.postpend_node("Alone", "6");
	Lifelines.postpend_node("Outcast", "7");
	Lifelines.postpend_node("Rise", "8");
	Lifelines.postpend_node("Already Dead", "9");
	Lifelines.postpend_node("Pull The Plug", "10");
	Lifelines.postpend_node("One More Time", "11");
	Lifelines.postpend_node("My Heart I Surrender", "12");
	Lifelines.postpend_node("Worst Part of Me", "13");
	LinkedList<string>Trauma;
	Trauma.postpend_node("Bow Down", "1");
	Trauma.postpend_node("Paranoid", "2");
	Trauma.postpend_node("Every Time You Leave", "3");
	Trauma.postpend_node("Rise Above It", "4");
	Trauma.postpend_node("Breaking Down", "5");
	Trauma.postpend_node("D.O.A.", "6");
	Trauma.postpend_node("Gasoline", "7");
	Trauma.postpend_node("Hurricane", "8");
	Trauma.postpend_node("Let Me Be Sad", "9");
	Trauma.postpend_node("Low", "10");
	Trauma.postpend_node("Goodbye", "11");
	Trauma.postpend_node("Deadweight", "12");
	Trauma.postpend_node("I Dont Belong Here", "13");
	LinkedList<string>TruePower;
	TruePower.postpend_node("0:00", "1");
	TruePower.postpend_node("Theres Fear In Letting Go", "2");
	TruePower.postpend_node("Body Bag", "3");
	TruePower.postpend_node("Self-Destruction", "4");
	TruePower.postpend_node("Bad Things", "5");
	TruePower.postpend_node("Fake", "6");
	TruePower.postpend_node("Judgment Day", "7");
	TruePower.postpend_node("FWYTYK", "8");
	TruePower.postpend_node("Deep End", "9");
	TruePower.postpend_node("Long Live The King", "10");
	TruePower.postpend_node("Choke", "11");
	TruePower.postpend_node("The Negative", "12");
	TruePower.postpend_node("Closure", "13");
	TruePower.postpend_node("Visceral", "14");
	TruePower.postpend_node("Doomed", "15");

	// Linked list containing all of the Albums for the band Wage War
	LinkedList<string>WageWar;
	WageWar.postpend_node("Blueprints", "1");
	WageWar.postpend_node("Deadweight", "2");
	WageWar.postpend_node("Pressure", "3");
	WageWar.postpend_node("Manic", "4");
	// Lines 155 - 204 are Linked Lists containing the songs for each album by Wage War
	LinkedList<string>Blueprints;
	Blueprints.postpend_node("Hollow", "1");
	Blueprints.postpend_node("Twenty One", "2");
	Blueprints.postpend_node("Alive", "3");
	Blueprints.postpend_node("Blueprints", "4");
	Blueprints.postpend_node("Youngblood", "5");
	Blueprints.postpend_node("The River", "6");
	Blueprints.postpend_node("Deadlocked", "7");
	Blueprints.postpend_node("Enemy", "8");
	Blueprints.postpend_node("Spineless", "9");
	Blueprints.postpend_node("Visceral", "10");
	Blueprints.postpend_node("Doomed", "11");
	LinkedList<string>Deadweight;
	Deadweight.postpend_node("Two Years", "1");
	Deadweight.postpend_node("Southbound", "2");
	Deadweight.postpend_node("Dont Let Me Fade Away", "3");
	Deadweight.postpend_node("Stitch", "4");
	Deadweight.postpend_node("Witness", "5");
	Deadweight.postpend_node("Deadweight", "6");
	Deadweight.postpend_node("Gravity", "7");
	Deadweight.postpend_node("Never Enough", "8");
	Deadweight.postpend_node("Indestructible", "9");
	Deadweight.postpend_node("Disdain", "10");
	Deadweight.postpend_node("My Grave Is Mine To Dig", "11");
	Deadweight.postpend_node("Johnny Cash", "12");
	LinkedList<string>Pressure;
	Pressure.postpend_node("Who I Am", "1");
	Pressure.postpend_node("Prison", "2");
	Pressure.postpend_node("Grave", "3");
	Pressure.postpend_node("Ghost", "4");
	Pressure.postpend_node("Me Against Myself", "5");
	Pressure.postpend_node("Hurt", "6");
	Pressure.postpend_node("Low", "7");
	Pressure.postpend_node("The Line", "8");
	Pressure.postpend_node("Fury", "9");
	Pressure.postpend_node("Forget My Name", "10");
	Pressure.postpend_node("Take The Fight", "11");
	Pressure.postpend_node("Will We Ever Learn", "12");
	LinkedList<string>Manic;
	Manic.postpend_node("Relapse", "1");
	Manic.postpend_node("Teeth", "2");
	Manic.postpend_node("Manic", "3");
	Manic.postpend_node("High Horse", "4");
	Manic.postpend_node("Circle The Drain", "5");
	Manic.postpend_node("Godspeed", "6");
	Manic.postpend_node("Death Roll", "7");
	Manic.postpend_node("Slow Burn", "8");
	Manic.postpend_node("Never Said Goodbye", "9");
	Manic.postpend_node("True Colors", "10");
	Manic.postpend_node("If Tomorrow Never Comes", "11");

	// Linked List Containing all of the albums for the band Beartooth
	LinkedList<string>Beartooth;
	Beartooth.postpend_node("Disgusting", "1");
	Beartooth.postpend_node("Aggressive", "2");
	Beartooth.postpend_node("Disease", "3");
	Beartooth.postpend_node("Below", "4");
	// Lines 213 - 264 are Linked Lists containing the songs on each album for the band Beartooth
	LinkedList<string>Disgusting;
	Disgusting.postpend_node("The Lines", "1");
	Disgusting.postpend_node("Beating in Lips", "2");
	Disgusting.postpend_node("Body Bag", "3");
	Disgusting.postpend_node("In Between", "4");
	Disgusting.postpend_node("Relapsing", "5");
	Disgusting.postpend_node("Ignorance Is Bliss", "6");
	Disgusting.postpend_node("I Have A Problem", "7");
	Disgusting.postpend_node("One More", "8");
	Disgusting.postpend_node("Me In My Own Head", "9");
	Disgusting.postpend_node("Keep Your American Dream", "10");
	Disgusting.postpend_node("Dead", "11");
	Disgusting.postpend_node("Sick And Disgusting", "12");
	LinkedList<string>Aggressive;
	Aggressive.postpend_node("Aggressive", "1");
	Aggressive.postpend_node("Hated", "2");
	Aggressive.postpend_node("Loser", "3");
	Aggressive.postpend_node("Fair Weather Friend", "4");
	Aggressive.postpend_node("Burnout", "5");
	Aggressive.postpend_node("Sick Of Me", "6");
	Aggressive.postpend_node("Censored", "7");
	Aggressive.postpend_node("Always Dead", "8");
	Aggressive.postpend_node("However You Want It Said", "9");
	Aggressive.postpend_node("Find a Way", "10");
	Aggressive.postpend_node("Rock Is Dead", "11");
	Aggressive.postpend_node("King of Anything", "12");
	LinkedList<string>Disease;
	Disease.postpend_node("Greatness or Death", "1");
	Disease.postpend_node("Disease", "2");
	Disease.postpend_node("Fire", "3");
	Disease.postpend_node("You Never Know", "4");
	Disease.postpend_node("Bad Listener", "5");
	Disease.postpend_node("Afterall", "6");
	Disease.postpend_node("Manipulation", "7");
	Disease.postpend_node("Enemy", "8");
	Disease.postpend_node("Believe", "9");
	Disease.postpend_node("Infection", "10");
	Disease.postpend_node("Used and Abused", "11");
	Disease.postpend_node("Clever", "12");
	LinkedList<string>Below;
	Below.postpend_node("Below", "1");
	Below.postpend_node("Devastation", "2");
	Below.postpend_node("The Past Is Dead", "3");
	Below.postpend_node("Fed Up", "4");
	Below.postpend_node("Dominate", "5");
	Below.postpend_node("No Return", "6");
	Below.postpend_node("Phantom Pain", "7");
	Below.postpend_node("Skin", "8");
	Below.postpend_node("Hell of it", "9");
	Below.postpend_node("I Wont Give it Up", "10");
	Below.postpend_node("The Answer", "11");
	Below.postpend_node("The Last Riff", "12");

	// Linked List containing the albums for the band Dayseeker
	LinkedList<string>Dayseeker;
	Dayseeker.postpend_node("What It Means To Be Defeated", "1");
	Dayseeker.postpend_node("Origin", "2");
	Dayseeker.postpend_node("Dreaming Is Sinking Waking Is Rising", "3");
	Dayseeker.postpend_node("Sleeptalk", "4");
	// Lines 273 - 318 contain Linked Lists containing the songs for the albums for the band Dayseeker
	LinkedList<string>WhatItMeansToBeDefeated;
	WhatItMeansToBeDefeated.postpend_node("Black Earth", "1");
	WhatItMeansToBeDefeated.postpend_node("Collision, Survive", "2");
	WhatItMeansToBeDefeated.postpend_node("What It Means To Be Defeated", "3");
	WhatItMeansToBeDefeated.postpend_node("Incinerate", "4");
	WhatItMeansToBeDefeated.postpend_node("Hollow Shell", "5");
	WhatItMeansToBeDefeated.postpend_node("Dead Man", "6");
	WhatItMeansToBeDefeated.postpend_node("Resurrect", "7");
	WhatItMeansToBeDefeated.postpend_node("The Home We Built", "8");
	WhatItMeansToBeDefeated.postpend_node("Sleep In The Sea", "9");
	WhatItMeansToBeDefeated.postpend_node("The Quiet Disconnect", "10");
	LinkedList<string>Origin;
	Origin.postpend_node("The Naill In Our Coffin", "1");
	Origin.postpend_node("A Cancer Uncontained", "2");
	Origin.postpend_node("Dead To The World: Alive In My Eyes", "3");
	Origin.postpend_node("The Earth Will Turn", "4");
	Origin.postpend_node("Origin", "5");
	Origin.postpend_node("THe Burning of Bridges", "6");
	Origin.postpend_node("Spotless Mind", "7");
	Origin.postpend_node("The World Was Quiet", "8");
	Origin.postpend_node("A God Without a Face", "9");
	Origin.postpend_node("Never See the Sun Rise", "10");
	LinkedList<string>DreamingIsSinkingWakingIsRising;
	DreamingIsSinkingWakingIsRising.postpend_node("Dreaming is Sinking", "1");
	DreamingIsSinkingWakingIsRising.postpend_node("Vultures", "2");
	DreamingIsSinkingWakingIsRising.postpend_node("Cold, Dark Winter", "3");
	DreamingIsSinkingWakingIsRising.postpend_node("Abandon", "4");
	DreamingIsSinkingWakingIsRising.postpend_node("Sleep In The Sea Pt 2", "5");
	DreamingIsSinkingWakingIsRising.postpend_node("Six Feet Under", "6");
	DreamingIsSinkingWakingIsRising.postpend_node("Hanging by a Thread", "7");
	DreamingIsSinkingWakingIsRising.postpend_node("Desolate", "8");
	DreamingIsSinkingWakingIsRising.postpend_node("Carved From Stone", "9");
	DreamingIsSinkingWakingIsRising.postpend_node("Come Hell or High Water", "10");
	DreamingIsSinkingWakingIsRising.postpend_node("Counterpart", "11");
	DreamingIsSinkingWakingIsRising.postpend_node("Waking is Rising", "12");
	LinkedList<string>Sleeptalk;
	Sleeptalk.postpend_node("Drunk", "1");
	Sleeptalk.postpend_node("Crooked Soul", "2");
	Sleeptalk.postpend_node("Burial Plot", "3");
	Sleeptalk.postpend_node("Sleeptalk", "4");
	Sleeptalk.postpend_node("The Embers Glow", "5");
	Sleeptalk.postpend_node("The Color Black", "6");
	Sleeptalk.postpend_node("Already Numb", "7");
	Sleeptalk.postpend_node("Gates of Ivory", "8");
	Sleeptalk.postpend_node("Staring to be Empty", "9");
	Sleeptalk.postpend_node("Crash and Burn", "10");

	// Linked List containing the albums for the band We Came As Romans
	LinkedList<string>WCAR;
	WCAR.postpend_node("To Plant A Seed", "1");
	WCAR.postpend_node("To Understand What We've Grown To Be", "2");
	WCAR.postpend_node("Tracing Back Roots", "3");
	WCAR.postpend_node("We Came As Romans", "4");
	WCAR.postpend_node("Cold Like War", "5");
	WCAR.postpend_node("Darkbloom", "6");
	// Lines 329 - 397 contain the songs for the albums by We Came As Romans
	LinkedList<string>ToPlantASeed;
	ToPlantASeed.postpend_node("To Plant a Seed", "1");
	ToPlantASeed.postpend_node("Broken Statues", "2");
	ToPlantASeed.postpend_node("Intentions", "3");
	ToPlantASeed.postpend_node("Roads That Dont End and Views That Never Cease", "4");
	ToPlantASeed.postpend_node("Dreams", "5");
	ToPlantASeed.postpend_node("We Are The Reasons", "6");
	ToPlantASeed.postpend_node("Beliefs", "7");
	ToPlantASeed.postpend_node("I Will Not Reap Destruction", "8");
	ToPlantASeed.postpend_node("Searching, Seeking, Reaching, Always", "9");
	ToPlantASeed.postpend_node("An Ever-Growing Wonder", "10");
	LinkedList<string>ToUnderstandWhatWeveGrownToBe;
	ToUnderstandWhatWeveGrownToBe.postpend_node("Mis/understadning", "1");
	ToUnderstandWhatWeveGrownToBe.postpend_node("Everything As Planned", "2");
	ToUnderstandWhatWeveGrownToBe.postpend_node("What I wished I Never Had", "3");
	ToUnderstandWhatWeveGrownToBe.postpend_node("Cast The First Stone", "4");
	ToUnderstandWhatWeveGrownToBe.postpend_node("The Way That We Have Been", "5");
	ToUnderstandWhatWeveGrownToBe.postpend_node("A War Inside", "6");
	ToUnderstandWhatWeveGrownToBe.postpend_node("Stay Inspired", "7");
	ToUnderstandWhatWeveGrownToBe.postpend_node("Just Keep Breathing", "8");
	ToUnderstandWhatWeveGrownToBe.postpend_node("Views That Never Cease, To Keep Me From Myself", "9");
	ToUnderstandWhatWeveGrownToBe.postpend_node("What My Heard Held", "10");
	ToUnderstandWhatWeveGrownToBe.postpend_node("I Cant Make Your Decisions For You", "11");
	ToUnderstandWhatWeveGrownToBe.postpend_node("Understanding What Weve Grown To Be", "12");
	LinkedList<string>TracingBackRoots;
	TracingBackRoots.postpend_node("Tracing Back Roots", "1");
	TracingBackRoots.postpend_node("Fade Away", "2");
	TracingBackRoots.postpend_node("I Survive", "3");
	TracingBackRoots.postpend_node("Ghosts", "4");
	TracingBackRoots.postpend_node("Present, Futures and Past", "5");
	TracingBackRoots.postpend_node("Never Let Me Go", "6");
	TracingBackRoots.postpend_node("Hope", "7");
	TracingBackRoots.postpend_node("Tell Me Now", "8");
	TracingBackRoots.postpend_node("A Moment", "9");
	TracingBackRoots.postpend_node("I Am Free", "10");
	TracingBackRoots.postpend_node("Through the Darkest Dark and Brightest Bright", "11");
	LinkedList<string>WeCameAsRomans;
	WeCameAsRomans.postpend_node("Regenerate", "1");
	WeCameAsRomans.postpend_node("Who Will Pray", "2");
	WeCameAsRomans.postpend_node("The World I Used to Know", "3");
	WeCameAsRomans.postpend_node("Memories", "4");
	WeCameAsRomans.postpend_node("Tear It Down", "5");
	WeCameAsRomans.postpend_node("Blur", "6");
	WeCameAsRomans.postpend_node("Savior of the Week", "7");
	WeCameAsRomans.postpend_node("Flatline", "8");
	WeCameAsRomans.postpend_node("Defiance", "9");
	WeCameAsRomans.postpend_node("12:30", "10");
	LinkedList<string>ColdLikeWar;
	ColdLikeWar.postpend_node("Vultures With Clipped Wings", "1");
	ColdLikeWar.postpend_node("Cold Like War", "2");
	ColdLikeWar.postpend_node("Two Hands", "3");
	ColdLikeWar.postpend_node("Lost in the Moment", "4");
	ColdLikeWar.postpend_node("Foreign Fire", "5");
	ColdLikeWar.postpend_node("Wasted Age", "6");
	ColdLikeWar.postpend_node("Encoder", "7");
	ColdLikeWar.postpend_node("If There's Nothing to See", "8");
	ColdLikeWar.postpend_node("Promise Me", "9");
	ColdLikeWar.postpend_node("Learning To Survive", "10");
	LinkedList<string>Darkbloom;
	Darkbloom.postpend_node("Darkbloom", "1");
	Darkbloom.postpend_node("Plagued", "2");
	Darkbloom.postpend_node("Black Hole", "3");
	Darkbloom.postpend_node("Daggers", "4");
	Darkbloom.postpend_node("Golden", "5");
	Darkbloom.postpend_node("One More Day", "6");
	Darkbloom.postpend_node("Doublespeak", "7");
	Darkbloom.postpend_node("The Anchor", "8");
	Darkbloom.postpend_node("Holding the Embers", "9");
	Darkbloom.postpend_node("Promise You", "10");


	/*
	In the following lines (410 - 452), these arrays are to represent hash tables
	that will aid in the proper calling of functions for specific Linked Lists.
	For Example the array named 'bands' contains all of the bands held at the index in which
	the band name is hashed to. Ex. 'Wage War' when hashed using the bandhasing17 function results in 0
	thus the string for the band 'Wage War' is located at index 0 of the bands array. These arrays are traversed to
	find the proper string which will then lead to the calling of the function to print the appropriate material
	inside the 'do-while' loop
	*/
	// band hash 17
	string bands[50];
	bands[0] = "Wage War";
	bands[9] = "We Came As Romans";
	bands[2] = "I Prevail";
	bands[16] = "Beartooth";
	bands[6] = "Dayseeker";

	// album hash 17
	string IPrevail[15];
	IPrevail[11] = "Heart vs Mind";
	IPrevail[10] = "Lifelines";
	IPrevail[13] = "Trauma";
	IPrevail[0] = "True Power";

	// album hash 17
	string WW[16];
	WW[2] = "Blueprints";
	WW[15] = "Deadweight";
	WW[6] = "Pressure";
	WW[14] = "Manic";

	// album hash 31
	string BTooth[24];
	BTooth[2] = "Disgusting";
	BTooth[4] = "Aggressive";
	BTooth[23] = "Disease";
	BTooth[8] = "Below";

	// album hash 43
	string DaySeek[41];
	DaySeek[40] = "What It Means To Be Defeated";
	DaySeek[9] = "Origin";
	DaySeek[16] = "Dreaming Is Sinking Waking Is Rising";
	DaySeek[17] = "Sleeptalk";

	// album hash 43
	string Romans[41];
	Romans[16] = "To Plant A Seed";
	Romans[0] = "To Understand What We've Grown To Be";
	Romans[40] = "Tracing Back Roots";
	Romans[1] = "We Came As Romans";
	Romans[24] = "Cold Like War";
	Romans[38] = "Darkbloom";


	// PLEASE REFER TO THE INITIAL COMMENTS ON LINES 457 - 490 TO SEE THE STRUCTURE THAT IS USED
	// THROUGHOUT THE ENTIRETY OF USER_SELECT == 1
	char keep_adding = 'Y'; // Initialize the keep adding variable to 'Y' as to stay within the 'do-while' loop
	cout << "Welcome to the playlist maker!" << endl;
	cout << endl;
	Queue<string>playlist; // Initialization of our playlist which will be a queue
	do {
		// The user will select on of the numerical options from the menu which will be used to traverse through
		// one of four 'if' statements and follow through until the 'if' statement is complete. 
		menu();
		char user_select;
		cout << endl;
		cin >> user_select;
		cout << endl;
		if (user_select == '1') {
			// User will type in the band name which will be hashed down, and then the user will be taken to the appropriate
			// 'if' or 'else-if' statement
			cout << "You want to add a new song, Great! Please choose from the following bands: " << endl;
			Bands.print_bands();
			cout << endl;
			string band_choice;
			getline(cin >> ws, band_choice);
			cout << endl;
			cout << "Great, you chose " << band_choice << " lets look at their albums" << endl;
			int value = bandhashing17(band_choice);
			// if the hash value returns the index in which Wage War is included
			if (bands[value] == "Wage War") {
				// user will type in the album name which will be hashed down, and then the user will be taken to the 
				//appropriate 'if' or 'else-if' statement
				WageWar.print_albums();
				cout << endl;
				cout << "Which album would you like to see songs from?" << endl;
				cout << endl;
				string album_choice;
				getline(cin >> ws, album_choice);
				cout << endl;
				cout << "Great lets see songs from " << album_choice << " by " << band_choice << endl;
				int alb_val = albumhashing17(album_choice);
				if (WW[alb_val] == "Blueprints") {
					Blueprints.print_songs();
					// once the user is inside the album, the songs will be listed, the user will then
					// type the song name they want, then the song name and band will be concatenated into a new
					// string that will be added to the queue
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (WW[alb_val] == "Deadweight") {
					Deadweight.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (WW[alb_val] == "Pressure") {
					Pressure.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (WW[alb_val] == "Manic") {
					Manic.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
			}
			else if (bands[value] == "We Came As Romans") {
				WCAR.print_albums();
				cout << endl;
				cout << "Which album would you like to see songs from?" << endl;
				cout << endl;
				string album_choice;
				getline(cin >> ws, album_choice);
				cout << endl;
				cout << "Great lets see songs from " << album_choice << " by " << band_choice << endl;
				int alb_val = albumhashing43(album_choice);
				if (Romans[alb_val] == "To Plant A Seed") {
					ToPlantASeed.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (Romans[alb_val] == "To Understand What We've Grown To Be") {
					ToUnderstandWhatWeveGrownToBe.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (Romans[alb_val] == "Tracing Back Roots") {
					TracingBackRoots.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (Romans[alb_val] == "We Came As Romans") {
					WeCameAsRomans.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (Romans[alb_val] == "Cold Like War") {
					ColdLikeWar.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (Romans[alb_val] == "Darkbloom") {
					Darkbloom.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
			}
			else if (bands[value] == "I Prevail") {
				IP.print_albums();
				cout << endl;
				cout << "Which album would you like to see songs from?" << endl;
				cout << endl;
				string album_choice;
				getline(cin >> ws, album_choice);
				cout << endl;
				cout << "Great lets see songs from " << album_choice << " by " << band_choice << endl;
				int alb_val = albumhashing17(album_choice);
				if (IPrevail[alb_val] == "Heart vs Mind") {
					HeartvsMind.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (IPrevail[alb_val] == "Lifelines") {
					Lifelines.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (IPrevail[alb_val] == "Trauma") {
					Trauma.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (IPrevail[alb_val] == "True Power") {
					TruePower.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
			}
			else if (bands[value] == "Beartooth") {
				Beartooth.print_albums();
				cout << endl;
				cout << "Which album would you like to see songs from?" << endl;
				cout << endl;
				string album_choice;
				getline(cin >> ws, album_choice);
				cout << endl;
				cout << "Great lets see songs from " << album_choice << " by " << band_choice << endl;
				int alb_val = albumhashing31(album_choice);
				if (BTooth[alb_val] == "Disgusting") {
					Disgusting.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (BTooth[alb_val] == "Aggressive") {
					Aggressive.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (BTooth[alb_val] == "Disease") {
					Disease.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (BTooth[alb_val] == "Below") {
					Below.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
			}
			else if (bands[value] == "Dayseeker") {
				Dayseeker.print_albums();
				cout << endl;
				cout << "Which album would you like to see songs from?" << endl;
				cout << endl;
				string album_choice;
				getline(cin >> ws, album_choice);
				cout << endl;
				cout << "Great lets see songs from " << album_choice << " by " << band_choice << endl;
				int alb_val = albumhashing43(album_choice);
				if (DaySeek[alb_val] == "What It Means To Be Defeated") {
					WhatItMeansToBeDefeated.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (DaySeek[alb_val] == "Origin") {
					Origin.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (DaySeek[alb_val] == "Dreaming Is Sinking Waking Is Rising") {
					DreamingIsSinkingWakingIsRising.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
				else if (DaySeek[alb_val] == "Sleeptalk") {
					Sleeptalk.print_songs();
					cout << endl;
					cout << "Which song would you like to add to your playlist?" << endl;
					cout << endl;
					string song_choice;
					getline(cin >> ws, song_choice);
					cout << endl;
					cout << "Okay great! Now adding " << song_choice << " from the album " << album_choice << " by " << band_choice << endl;
					cout << endl;
					string added_song = song_choice + " by " + band_choice;
					playlist.enqueue(added_song);
				}
			}
		}
		// if the user were to select option 2, they will be taken here where they 
		// can see their playlist as it currently stands
		else if (user_select == '2') {
		cout << endl;
			cout << "Lets Take a look at your playlist so far" << endl;
			cout << playlist << endl;
			skip_lines(2);
			cout << "Looking Good!" << endl;
			cout << endl;
		}
		// If the user wanted to get rid of a song on the queue they would select option 3, 
		// in this statement, the song at the front of the queue will be dequeued
		else if (user_select == '3') {
			cout << endl;
			cout << "Lets go ahead and get rid of the song currently queued" << endl;
			cout << endl;
			playlist.dequeue();
			cout << endl;
		}
		// once the user is completed making their playlist, it will print and they will be exited out 
		// of the program
		else if (user_select == '4') {
		cout << endl;
			cout << "All Done with your Playlist? Let's check it out!" << endl;
			cout << playlist << endl;
			cout << endl;
			cout << "Happy Listening!" << endl;
			keep_adding = 'N';
		}
	} while (keep_adding == 'Y');

	return 0;
}