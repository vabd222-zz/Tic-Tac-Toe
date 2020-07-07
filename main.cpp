
# include <iostream>
# include <string>

using namespace std;

/*
   This program succesfully allows two players to play tic tac toe on a 4 x 4 board.
*/


// Function checks if the user values correspond to values on the board, ie: user value is between 1 and 16
bool check1(int user_pick);

// Function to make sure user is not allowed to choose a spot on the board that is preoccupied
bool check2(int user_pick, string myarray[][4]);

// Function uses the two functions above and makes sure user input passes both conditions stated in the functions above
int user_input(string myarray[][4]);

// Function outputs the 4x4 board with all the values to the screen
void display_table(string myarray[][4]);

// Function allows user x to take a turn
int xturn(string myarray[][4]);

//Function allows user o to take a turn
int oturn(string myarray[][4]);

// Function checks if there is a winner in the horizontal row where user placed their value
bool horizontal(int row, string xo, string myarray[][4]);

// Function checks if there is a winner in the vertical row where user placed their value
bool vertical(int column, string xo, string myarray[][4]);

// Function checks if there is a winner diagonally where user placed their value
bool diagonal(int column, string xo, string myarray[][4]);

// Function restarts the game by repopulating the array with number from 1 to 16
void restart(string myarray[][4]);

// Function checks if a user won in any of the 3 directions either horizontal, diagonal, vertical
bool check_winner(bool x, bool y, bool z);




bool check1(int user_pick)
{
	//Variabale declarations
	bool output = false;

	if (user_pick >= 1 && user_pick <= 16)
	{
		output = true;
	}


	return output;
}

bool check2(int user_pick, string myarray[][4])
{
	//Variabale declarations
	string s = to_string(user_pick);
	bool output = false;



	for (int j = 0;j < 4;j++)
	{
		for (int i = 0; i < 4; i++)
		{

			if (myarray[j][i]==s)
			{
				output = true;

			}
		}
	}

	return output;

}

void display_table(string myarray[][4])
{

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << myarray[j][i] << "\t\t\t";
		}

		cout << endl;
	}

}

int user_input(string myarray[][4])
{
	//Variabale declarations
	int user_pick;

	//asking the user for input
	cout << "Enter the spot (WARNING: Do not Enter a String):  ";
	cin >> user_pick;
	cout << endl;

	bool c1 = check1(user_pick);
	bool c2 = check2(user_pick, myarray);


	while ((c1 == false) || (c2 == false))
	{

		cout << "\nInvalid Input" << endl;
		cout << "Enter the spot: ";
		cin >> user_pick;


		c1 = check1(user_pick);
		c2 = check2(user_pick, myarray);

	}
	return user_pick;

}

int xturn(string myarray[][4])
{
	//Variable Declarations
	int row; int coloumn;


	cout << "Player X turn, ";

	//asking the user for input and then checking the input
	int user_pick = user_input(myarray);
	string s = to_string(user_pick);

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (myarray[j][i] == s)
			{
				myarray[j][i] = "X";
				row = j;
				coloumn = i;
			}
		}

		cout << endl;
	}
	return row + 10 * coloumn;
}

int oturn(string myarray[][4])
{
	//Variable Declarations
	int row; int coloumn;

	cout << "Player O turn, ";

	//asking the user for input and then checking the input
	int user_pick = user_input(myarray);
	string s = to_string(user_pick);

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (myarray[j][i] == s)
			{
				myarray[j][i] = "O";
				row = j;
				coloumn = i;
			}
		}

		cout << endl;
	}
	return row + 10 * coloumn;
}

bool horizontal(int row, string xo, string myarray[][4])
{
	//Variable Declarations
	int counter =0;
	bool htl = false;

	//checking all the horizontal values to find the winner
	for (int i = 0; i < 4; i++)
	{
		if (myarray[row][i] == xo)
		{
			counter++;
		}

	}

	if (counter == 4)
	{
		htl = true;
	}

	return htl;
}

bool vertical(int column, string xo, string myarray[][4])
{
	//Variable Declarations
	int counter = 0;
	bool vtl = false;

	//checking all vertical values to find the winner
	for (int i = 0; i < 4; i++)
	{
		if (myarray[i][column] == xo)
		{
			counter++;
		}

	}

	if (counter == 4)
	{
		vtl = true;
	}

	return vtl;
}

bool diagonal(int row, int column, string xo, string myarray[][4])
{
	//Variable Declarations
	int counter = 0;
	bool dgl = false;

	//Checking the diagonal to find the winner
	if (row == column)
	{
		for (int i = 0; i < 4; i++)
		{
			if (myarray[i][i] == xo)
			{
				counter++;
			}
		}

		if (counter == 4)
		{
			dgl = true;
		}


	}

	else
	{
		int j = 3;
		for (int i = 0; i < 4;i++)
		{

			if (myarray[j][i] == xo)
			{
				counter++;
			}
			j--;
		}
		if (counter == 4)
		{
			dgl = true;
		}



	}

	return dgl;
}

void restart( string myarray[][4])
{
	//Variable Declarations
	int increment = 0;;
	int number = 0;

	// Populating the array with number from 1 to 16
	for (int j = 0; j < 4;j++)
	{
		for (int i = 0; i < 4; i++)
		{
			number = number+1;
			myarray[j][i] = std::to_string(number);
		}

	}



}

bool check_winner(bool x, bool y, bool z)
{
	//Variable Declarations
	bool check_winner = false;

	//Checking if any player got a tic tac toe in either vertical, horizontal or diagonal directions
	if (x || y || z)
	{
		check_winner = true;
	}

	return check_winner;
}

void tic_tac_toe_simulator(string myarray[][4], int c, string yes_no)
{
	//Variable Declartions
	int cont = 0;
	int counter = 0;
	int number, row, column;
	int number_of_turns = 0;
	int total_tries = 0;
	bool htl, vtl, dgl,winner,tie = false;

	//Runing all different functions to create the game
	while ((yes_no!="no"))
	{
		if (c % 2 == 0)
		{

			number = xturn(myarray);
			row = number % 10;
			column = number / 10;
			display_table(myarray);

			htl = horizontal(row, "X", myarray);
			vtl = vertical(column, "X", myarray);
			dgl = diagonal(row, column, "X", myarray);

			winner = check_winner(htl, vtl, dgl); number_of_turns;
			if (winner == true)
			{
				cout << "Player x wins the game" << endl;


				cout << "DO YOU WANT TO PLAY ANOTHER GAME: " << endl;
				cin >> yes_no;
				cout << endl;

				if (yes_no == "yes")
				{
					restart(myarray);
					display_table(myarray);
				}
				c++;
				tic_tac_toe_simulator(myarray, c, yes_no);
			}
			number = oturn(myarray);
			row = number % 10;
			column = number / 10;
			display_table(myarray);

			htl = horizontal(row, "O", myarray);
			vtl = vertical(column, "O", myarray);
			dgl = diagonal(row, column, "O", myarray);

			winner = check_winner(htl, vtl, dgl); number_of_turns++;

			if (winner == true)
			{
				cout << "Player o wins the game" << endl;

				cout << "DO YOU WANT TO PLAY ANOTHER GAME: " << endl;
				cin >> yes_no;
				cout << endl;

				if (yes_no == "yes")
				{
					restart(myarray);
					display_table(myarray);
				}
				c++;
				tic_tac_toe_simulator(myarray, c, yes_no);
			}

			if (winner == false && number_of_turns == 16)
			{
				cout << "THE GAME IS A TIE" << endl;
				tie = true;

				cout << "DO YOU WANT TO PLAY ANOTHER GAME: " << endl;
				cin >> yes_no;
				cout << endl;

				if (yes_no == "yes")
				{
					restart(myarray);
					display_table(myarray);
				}
				c++;
			}


			if (winner == false && tie == false)
			{
				tic_tac_toe_simulator(myarray, c, yes_no);
			}
		}


		else if(c%2!=0)
		{
			number = oturn(myarray);
			row = number % 10;
			column = number / 10;
			display_table(myarray);

			htl = horizontal(row, "O", myarray);
			vtl = vertical(column, "O", myarray);
			dgl = diagonal(row, column, "O", myarray);

			winner = check_winner(htl, vtl, dgl); number_of_turns++;

			if (winner == true)
			{
				cout << "Player o wins the game" << endl;

				cout << "DO YOU WANT TO PLAY ANOTHER GAME: " << endl;
				cin >> yes_no;
				cout << endl;

				if (yes_no == "yes")
				{
					restart(myarray);
					display_table(myarray);
				}
				c++;
				tic_tac_toe_simulator(myarray, c, yes_no);


			}
			number = xturn(myarray);
			row = number % 10;
			column = number / 10;
			display_table(myarray);

			htl = horizontal(row, "X", myarray);
			vtl = vertical(column, "X", myarray);
			dgl = diagonal(row, column, "X", myarray);

			winner = check_winner(htl, vtl, dgl); number_of_turns++;

			if (winner == false && number_of_turns == 16)
			{
				cout << "THE GAME IS A TIME" << endl;
				tie = true;

				cout << "DO YOU WANT TO PLAY ANOTHER GAME: " << endl;
				cin >> yes_no;
				cout << endl;

				if (yes_no == "yes")
				{
					restart(myarray);
					display_table(myarray);
				}
				c++;
				tic_tac_toe_simulator(myarray, c, yes_no);
			}
			if (winner == true)
			{
				cout << "Player x wins the game" << endl;

				cout << "DO YOU WANT TO PLAY ANOTHER GAME: " << endl;
				cin >> yes_no;
				cout << endl;

				if (yes_no == "yes")
				{
					restart(myarray);
				}
				c++;
				tic_tac_toe_simulator(myarray, c, yes_no);
			}

			if (winner == false && tie == false)
			{
				tic_tac_toe_simulator(myarray, c, yes_no);
			}
		}


		cout << "DO YOU WANT TO PLAY ANOTHER GAME: " << endl;
		cin >> yes_no;
		cout << endl;

		if (yes_no == "yes")
		{
			restart(myarray);
			display_table(myarray);
		}

	}


}

int main()
{
	//Variable Declarations
	string myarray[4][4];//Declaring a 2d 4x4 array
	string yes_no = "yes";
	int c = 0;

	//staring the game
	cout << "\n\t\t\t\t******WELCOME-TO-TIC-TAC-TOE*******\n" << endl;
	restart(myarray);
	display_table(myarray);
	tic_tac_toe_simulator(myarray, c, yes_no);
}