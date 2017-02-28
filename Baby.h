#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() {  // default constructor
	};

	Baby(string s, int w) { // constructor
		// TO BE COMPLETED
	}

	// a "getter" method
	int getWeight() {
		return -1; // TO BE COMPLETED
	}

	// a "getter" method
	string getName() {
		return "COMPLETE ME"; // TO BE COMPLETED
	}

private:
	string name;
	int weight;
};