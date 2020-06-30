#include <regex>
#include"cinema.h"
#include<limits>//to manage user should enter only integer

bool checkNumeric(istream& input, int min, int max, int& property) //Check if an input is a valid int, and within the given range
{
	input >> property;
	if (input.fail())
	{
		throw new exception();
	}
	else {
		// if the input is outside of the valid range throw 101 as an error so we can pick it up outside the function
		if (property <= min || property >= max)
			throw 101;
	}
	return true;
}

bool isValidTimeString(string input) //validate a string to ensure it meets the desired time format
{
	const regex timeRegex("^(0[0-9]|1[0-9]|2[0-3]|[0-9]):[0-5][0-9]$");
	return regex_match(input, timeRegex);
}

bool checkNumeric(istream& input, int min, int max, double& property) //Check if an input is a valid double, and within the given range
{
	input >> property;
	if (input.fail())
	{
		throw new exception();
	}
	else {
		// if the input is outside of the valid range throw 101 as an error so we can pick it up outside the function
		if (property<min || property>max)
			throw 101;
	}
	return true;
}

int main()
{
	cinema c;
	int optionSelected;
	do	//loop to run the program continuously 
	{

		cout << "1. Display Total no of tickets avail.\n";
		cout << "2. Display Total cost takings for movie.\n";
		cout << "3. Print All Records.\n";
		cout << "4. Add movie.\n";
		cout << "5. Remove movie.\n";
		cout << "6. Sell ticket.\n";
		cout << "7. Save Movie Names to File.\n";
		cout << "8. Quit\n";
		cout << "Enter Your Choice: ";

		try					// exception handling
		{
			cin >> optionSelected;
			if (cin.fail()) {
				throw new exception();
			}
		}
		catch (...)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid option" << endl << endl;
			continue;
		}
		switch (optionSelected)
		{

		case 1:
		{
			c.printTotalNoOfTicketsRemaining();		// calling the function from cinema.h
			break;
		}
		case 2:
		{
			c.totalTakings();		// calling the function from cinema.h
			break;
		}
		case 3:
		{
			c.display();		// calling the function from cinema.h
			break;
		}
		case 4:
		{
			string name;
			string time;
			double adultPrice;
			double childPrice;
			int durationInMinutes;
			int screenNo;
			int availableSeats;
			cin.ignore();
			cout << "Enter Name of the movie: ";
			cin >> name;
			bool isValidTime = false;
			// Keep requesting the user input, until a valid input is provided
			while (!isValidTime) {
				cout << "Enter time(HH:MM): ";
				cin >> time;
				//check the user input with the isValidTimeString function
				isValidTime = isValidTimeString(time);
				if (isValidTimeString(time))
					isValidTime = true;
				else
					cout << "\nPlease enter a valid time in the format HH:MM" << endl << endl;
			}
			// Keep requesting the user input, until a valid input is provided
			bool validAdultPrice = false;
			while (!validAdultPrice) {
				cout << "Enter Adult Ticket Price - Max Value 10: ";
				try {
					//check the user input with the checkNumeric function
					validAdultPrice = checkNumeric(cin, 0, 10, adultPrice);
				}
				//Catch exceptions with specifice error codes
				catch (int errCode)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					string errorMessage = "";
					// A value outside the range has been entered
					if (errCode == 101)
						errorMessage = "Please enter a value between 0 and 10";
					else
						errorMessage = "Please enter a valid price";

					cout << "\n" + errorMessage << endl << endl;
				}
				//Catch all other exceptions
				catch (...)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nPlease enter a valid price" << endl << endl;
				}
			}
			// Keep requesting the user input, until a valid input is provided
			bool validChildPrice = false;
			while (!validChildPrice) {
				cout << "Enter Child Ticket Price - Max Value 10: ";
				try {
					//check the user input with the checkNumeric function
					validChildPrice = checkNumeric(cin, 0, 10, childPrice);
				}
				//Catch exceptions with specifice error codes
				catch (int errCode)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					string errorMessage = "";
					if (errCode == 101)
						errorMessage = "Please enter a value between 0 and 10";
					else
						errorMessage = "Please enter a valid price";

					cout << "\n" + errorMessage << endl << endl;
				}
				//Catch all other exceptions
				catch (...)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nPlease enter a valid price" << endl << endl;
				}
			}
			bool validDurationInMinutes = false;
			// Keep requesting the user input, until a valid input is provided
			while (!validDurationInMinutes) {
				cout << "Enter Movie Duration in minutes - Max Time is 200 minutes: ";
				try {
					validDurationInMinutes = checkNumeric(cin, 0, 200, durationInMinutes);
				}
				//Catch exceptions with specifice error codes
				catch (int errCode)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					string errorMessage = "";
					if (errCode == 101)
						errorMessage = "Please enter a value between 0 and 200 minutes";
					else
						errorMessage = "Please enter a valid duration";

					cout << "\n" + errorMessage << endl << endl;
				}
				//Catch all other exceptions
				catch (...)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nPlease enter a valid duration" << endl << endl;
				}
			}

			bool validScreenNo = false;
			// Keep requesting the user input, until a valid input is provided
			while (!validScreenNo) {
				cout << "Enter Screen Number - Screen 0 - Screen 14: ";
				try {
					validScreenNo = checkNumeric(cin, 0, 15, screenNo);
				}
				//Catch exceptions with specifice error codes
				catch (int errCode)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					string errorMessage = "";
					if (errCode == 101)
						errorMessage = "Please enter a value between 0 and 14";
					else
						errorMessage = "Please enter a valid screen number";

					cout << "\n" + errorMessage << endl << endl;
				}
				//Catch all other exceptions
				catch (...)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nPlease enter a valid screen number" << endl << endl;
				}
			}

			bool validAvailableSeats = false;
			// Keep requesting the user input, until a valid input is provided
			while (!validAvailableSeats) {
				cout << "Enter Available Seat Limit - Max Seating is 267: ";
				try {
					validAvailableSeats = checkNumeric(cin, 0, 267, availableSeats);
				}
				//Catch exceptions with specifice error codes
				catch (int errCode)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					string errorMessage = "";
					if (errCode == 101)
						errorMessage = "Please enter a value between 0 and 267";
					else
						errorMessage = " nPlease enter a valid limit for available seats ";

					cout << "\n" + errorMessage << endl << endl;
				}
				//Catch all other exceptions
				catch (...)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nPlease enter a valid limit for available seats" << endl << endl;
				}
			}
			
			//Create a new screening object and add it to the movies list
			screening* temp = new screening(availableSeats, name, time, adultPrice, childPrice, durationInMinutes, screenNo);				// calling the constructor from movie.h to add movie
			c.addMovie(temp);
			cout << "****Movie Added Successfully****\n\n";
			break;
		}
		case 5:
		{
			string name;
			string time;
			int screenNo;
			cin.ignore();
			cout << "Enter Name of the movie: ";
			getline(cin, name);
			cout << "Enter time(HH:MM): ";
			getline(cin, time);
			cout << "Enter Screen Number: ";
			cin >> screenNo;
			screening* temp = new screening(name, time, screenNo);	// calling the constructor from screening.h
			c.removeMovie(temp);						// calling the function from cinema.h

			break;
		}
		case 6:
		{
			cout << "We have following movies to be sold\n";
			for (int i = 0; i < c.getNoOfMovies(); i++)				// getting all movies
			{
				cout << i << ". " << c.get(i)->getName() << endl;
			}
			cout << "Enter your choice: ";
			int op;
			cin >> op;
			while (op < 0 || op >= c.getNoOfMovies())
			{
				cout << "Select Valid Choice :";
				cin >> op;
			}

			screening* selectedMovie = c.get(op);

			cout << "We have " << selectedMovie->getTotalAvailableTickets() << " tickets available for " << selectedMovie->getName() << endl;		// getting name of selected movie


			bool isValidSale = false;

			// Keep requesting the user input, until a valid input is provided
			while (!isValidSale)
			{
				int adultTicketsToSell = 0;
				int childTicketsToSell = 0;
				cout << "Enter no of adult tickets to sell: ";
				cin >> adultTicketsToSell;
				// If there is not enough tickets, show an error and get the user to re-enter
				if (adultTicketsToSell > selectedMovie->getRemainingTickets()) {
					cout << "Not enough tickets available for this movie." << endl << endl;
					continue;
				}
				cout << "Enter no of child tickets to sell: ";
				cin >> childTicketsToSell;
				int totalTicketsToSell = adultTicketsToSell + childTicketsToSell;
				//ensure they are trying to buy at least one ticket
				if (totalTicketsToSell < 1)
					cout << "At least one ticket must be purchased." << endl << endl;
				else
				{
					// If there is not enough tickets, show an error and get the user to re-enter
					if (totalTicketsToSell > selectedMovie->getTotalAvailableTickets()) {
						cout << "Not enough tickets available for this movie." << endl << endl;
					}
					else {
						//Call the functions to update the ticket counts
						selectedMovie->sellAdultTicket(adultTicketsToSell);
						selectedMovie->sellChildTicket(childTicketsToSell);
						isValidSale = true;
						
						//calculate the total price and print it
						double totalPrice = (selectedMovie->getAdultPrice() * adultTicketsToSell) + (selectedMovie->getChildPrice() * childTicketsToSell);
						cout << "Tickets Purchased. Total Sale Price: \x9C" << setprecision(2) << fixed << totalPrice << endl << endl;

					}
				}
			}
			break;
		}
		case 7:
		{
			c.saveMoviesToFile();
		}
		default:
		{
			cout << "Invalid Selection\n" << endl;
		}
		}
	} while (optionSelected != 8);
}
