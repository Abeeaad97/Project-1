#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include "MedicalRecord.h"
#include "Baby.h"

using namespace std;


int main() {
	try {
		{
			// test only the Baby class
			Baby babyTest("Testname", 1000);
			assert(babyTest.getName() == "Testname");
			assert(babyTest.getWeight() == 1000);
		}

		{   // test full code with a small data file
			MedicalRecord MR;
			MR.buildMedicalRecordfromDatafile("baby_data_small.txt"); // build a medical record from the file of baby names and weights\

			int nBirths = MR.numberOfBirths();
			cout << "Number of births: " << nBirths << endl;
			assert(nBirths == 10);

			int nEmma = MR.numberOfBabiesWithName("Emma");
			cout << "Number of babies with name Emma: " << nEmma << endl;
			assert(nEmma == 2);

			int nLow = MR.numberOfBabiesWithLowBirthWeight();
			cout << "Number of babies with low birth weight: " << nLow << endl;
			assert(nLow == 2);

			string mostPopularName = MR.mostPopularName();
			cout << "Most popular baby name: " << mostPopularName << endl;
			assert (mostPopularName == "Sophia");
		}

		{   // test full code with a large data file
			MedicalRecord MR;
			MR.buildMedicalRecordfromDatafile("baby_data_large.txt"); // build a medical record from the file of baby names and weights\

			int nBirths = MR.numberOfBirths();
			cout << "Number of births: " << nBirths << endl;
			assert (nBirths == 199604);

			int nEva = MR.numberOfBabiesWithName("Eva");
			cout << "Number of babies with name Eva: " << nEva << endl;
			assert (nEva == 566);

			int nLow = MR.numberOfBabiesWithLowBirthWeight();
			cout << "Number of babies with low birth weight: " << nLow << endl;
			assert (nLow == 15980);

			string mostPopularName = MR.mostPopularName();
			cout << "Most popular baby name: " << mostPopularName << endl;
			assert (mostPopularName == "Emma");
		}
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}

	// system("pause");
}