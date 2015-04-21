/***************************************************************
*Author: Matthew Ksiazek                                       *
*Date 04/13/2015                                               *
*Description: Creates, maintains and outputs .txt file to      *
* Dropbox for easy retrieval                                   */

// shoppingList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

void displayMenu();
int getChoice();
void createList();
void viewList();
void appendList();
void removeList();
void textList();


int _tmain(int argc, _TCHAR* argv[])
{
	int choice;
	do
	{
		displayMenu();
		choice = getChoice();

		switch (choice)
		{
		case 1:
			createList();
			break;
		case 2:
			viewList();
			break;
		case 3:
			appendList();
			break;
		case 4:
			removeList();
			break;
		case 5:
			printList();
			break;
		case 6:
			cout << "Exiting program";
			return 0;
		default:
			cout << "Error. Please enter a number 1-5";
		}
	} while (x != 6);
	return 0;
}

void displayMenu()
{
	system("cls"); //Clear the screen
	cout << "Welcome to the shopping list\n";
	cout << "What would you like to do?\n"
		 << "1.) Create a new list\n2.) View from the list\n"
		 << "3.) Append to the list\n4.) Remove the list\n5.)"
		 << "Text the list to the phone\n6.) Exit\n";
}


int getChoice()
{
	int choice;

	cin >> choice;
	while (choice < 1 || choice > 7)
	{
		cout << "The only valid choices are 1-4. Please re-enter. ";
		cin >> choice;
	}
	return choice;
}

void createList()
{
	string items;
	ofstream outputFile;
	outputFile.open("C:\\Users\\Matt Ksiazek\\Dropbox\\list.txt");

	//Now ask user what to add to list
	int addToList;

	cout << "How many items would you like to add to the list?" << endl;
	cin >> addToList;
	
	//loop once for each item to add
		for (int count = 1; count <= addToList; count++)
		{
			// get the item 
			cout << "What is item " << count << " ?";
			cin >> items;

			//write the items to the file
			outputFile << items << endl;
		}


	//close the file
	outputFile.close();
}

void viewList()
{
	ifstream inputFile;
	string item;

	//attempt to open file

	inputFile.open("C:\\Users\\Matt Ksiazek\\Dropbox\\list.txt");

	//if the file opened successfully
	if (inputFile)
	{
		while (inputFile >> item) //boolean test to read from file
			cout << item << endl << endl;

		inputFile.close();
	}
	else // the file could not be opened or found
	{
		cout << "Error opening the file.\n";
	}
}

void appendList()
{
	string items;
	string addToNewList;
	ifstream inputFile;
	inputFile.open("C:\\Users\\Matt Ksiazek\\Dropbox\\list.txt");
	ofstream outputFile;
	outputFile.open("C:\\Users\\Matt Ksiazek\\Dropbox\\temp.txt"); //Used to create temporary file holding old list.txt entries
	if (inputFile.is_open)
	{
		while (getline(in, items))
		  {
		    cout << items << endl;
		  }
	}
	else // the file could not be opened or found
	{
		cout << "Error opening the file.\n";
	}

	//Now ask user what to add to list
	int addToList;

	cout << "How many items would you like to add to the list?" << endl;
	cin >> addToList;

	//loop once for each item to add
	for (int count = 1; count <= addToList; count++)
	{
		// get the item 
		cout << "What is item " << count << " ?" << endl;
		cin >> items;

		//write the items to the file
		outputFile << items << endl;
	}

	// delete the original file
	remove ("/C:\\Users\\Matt Ksiazek\\Dropbox\\list.txt");
	// rename old to new
	rename("C:\\Users\\Matt Ksiazek\\Dropbox\\temp.txt", "C:\\Users\\Matt Ksiazek\\Dropbox\\list.txt");

	//close the file
	outputFile.close();
}

void removeList()
{
	cout << "Removelist";
	/*string line, deleteThing;
	cout << "What would you like to delete?" << endl;
	cin >> deleteThing;

	ifstream inputFile; 
	inputFile.open("C:\\Users\\Matt Ksiazek\\Dropbox\\list.txt");
	ofstream outputFile;
	outputFile.open("C:\\Users\\Matt Ksiazek\\Dropbox\\temp.txt");
	
	


	while (getline(in, line))
	{
		if (line != deleteThing)
			outputFile << line; endl;
	{
		inputFile.close();
		outputFile.close();
		// delete the original file
		remove("C:\\Users\\Matt Ksiazek\\Dropbox\\list.txt");
		// rename old to new
		rename("C:\\Users\\Matt Ksiazek\\Dropbox\\temp.txt", "C:\\Users\\Matt Ksiazek\\Dropbox\\list.txt");

		// all done!
		return 0;*/
}

void textList()
{
	cout << "This is texting a list"; // This is still a work in progress
}
