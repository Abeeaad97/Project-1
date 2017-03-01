#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() //default constructor 
	{  
		weight = 0;

		name = " ";
	};

	Baby(string s, int w) //constructor
	{
		name = s;
		weight = w;
	}

	// a "getter" method
	int getWeight() 
	{
		return weight;
	}

	// a "getter" method
	string getName() 
	{
		return name;
	}

private:
	string name;
	int weight;
};
