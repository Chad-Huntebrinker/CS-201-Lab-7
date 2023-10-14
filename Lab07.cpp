// Chad Huntebrinker
// crh92d@umsystem.edu
// 10/8/20
// CS201L Lab 07

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

double GetMiles();
double GetGallons();
double GetMPG(vector<double> miles, vector<double> gallons);

int main() {

	vector<double> miles;
	vector<double> gallons;
	double userMiles, userGallons, totalMPG;
	char userInput;
	/*
	A do...while loop that will continue until the user enters q.
	Once he or she enters q, the program will quit and will show the total MPG
	*/
	do {
		try {
			userMiles = GetMiles();
			userGallons = GetGallons();
			miles.push_back(userMiles);
			gallons.push_back(userGallons);
		}

		//This catches any runtime_error thrown in the GetMiles or the GetGallons function

		catch (runtime_error error) {
			cout << error.what() << endl;
		}
		//This catches any error thrown, just in case.
		catch (...) {
			cout << "Something went wrong." << endl;
		}
		cout << "Would you like to enter another tank?" << endl;
		cout << "To continue, press any key besides q. To quit, enter q." << endl;
		cin >> userInput;
		userInput = toupper(userInput);
	} while (userInput != 'Q');
	
	try {
		totalMPG = GetMPG(miles, gallons);
		cout << "The total MPG for all trips listed is: " << totalMPG << " mpg" << endl;
	}

	//This catches any runtime_error thrown in the GetMPG function

	catch (runtime_error error) {
		cout << error.what();
	}
	//This catches any error thrown, just in case.
	catch (...) {
		cout << "Something went wrong." << endl;
	}
	return 0;
}

/*
The GetMiles function allows the user to enter in the number of miles traveled.
If the miles is less than 0, a runtime error is thrown and the main program handles it.
If there is an error, whatever the user enters is discarded and the user is then given the choice to start again. 
*/
double GetMiles() {
	double userInput;
		cout << "Please enter the number of miles traveled." << endl;
		cin >> userInput;
		if (userInput < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw runtime_error("Miles cannot be less than 0.");
		}
		return userInput;
}

/*
The GetGallons function allows the user to enter in the number of gallons used.
If the gallons is less than 0, a runtime error is thrown and the main program handles it.
If there is an error, whatever the user enters is discarded for both the GetGallons function and the GetMiles function.
The user is then given the choice to start again.
*/
double GetGallons() {
	double userInput;
		cout << "Please enter the number of gallons used." << endl;
		cin >> userInput;
		
		if (userInput < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw runtime_error("Gallons cannot be less than 0.");
		}
		return userInput;
}

/*
The GetMPG function calculates the total MPG in all the entered trips.
If either the miles vector or the gallons vector has nothing in it, then a runtime error is thrown and
the main program handles it.
If an error is thrown, then the main program will output the sentence in quotes on line 126.
*/
double GetMPG(vector<double> miles, vector<double> gallons) {
	double totalMPG = 0, numOfMiles, numOfGallons, temp;
	int totalTrips = 0;
	if (miles.size() == 0 || gallons.size() == 0) {
		throw runtime_error("No values recorded. MPG is nan.");
	}
	for (int i = 0; i < miles.size(); ++i) {
		numOfMiles = miles.at(i);
		numOfGallons = gallons.at(i);
		temp = (numOfMiles / numOfGallons);
		totalMPG = temp + totalMPG;
		++totalTrips;
	}
	totalMPG = (totalMPG / totalTrips);
	return totalMPG;
}