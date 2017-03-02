#pragma once
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "Baby.h"


using namespace std;

struct Node;
Baby bab;
Node * n;


class MedicalRecord {
public:
	// default constructor
	MedicalRecord() 
	{
		sData = new Baby[total];
	}

	// destructor
	~MedicalRecord() 
	{
		delete[] sData;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName()
	{
		int count = 0;
		int prev = 0;
		string totalName;

		for (int i = 0; i < numB; i++)
		{
			for (int j = 0; j < numB; j++)
			{
				if (sData[i].getName() == sData[j].getName())
					count++;
			}
			if (count > prev)
			{
				totalName = sData[i].getName();
				prev = count;
				count = 0;
			}	
		}
		
		return totalName;
		
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() 
	{
		return numB;
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() 
	{
		int low_Weight = 0;
		int low = 2500;
		for (int i = 0; i < numB; i++)
		{
			if (sData[i].getWeight() < low)
			{
				low_Weight++;
			}
		}
		return low_Weight;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) 
	{
		int sameName = 0;
		
		for (int i = 0; i < numB; i++)
		{
			if (sData[i].getName() == s)
				sameName++;
		}
		return sameName;
	}

private:
	Baby * sData;
	int numB = 0;
	int total;
	// update the data structure with information contained in Baby object
	void addEntry(Baby b)
	{
		sData[numB] = b;
		numB++;
	}

	
		
};
