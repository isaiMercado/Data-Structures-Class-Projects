/*
 * 235 midterm 1 -- spring june 4
 * File:   main.cpp
 * Author: misaie
 *
 * Created on June 4, 2014, 8:42 AM
 */

#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include <ctime>


#include <fstream>

using namespace std;

void menu(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB);
void CreateRoster(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB);
void ViewRoster(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB);
void ShuffleRoster(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB);
void CreateTeams(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB);
void ViewTeams(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB);
void UserPlay(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB);
void AutoPlay(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB);



int main(int argc, char** argv)
{
	srand(time(0));

	LinkedList Roster;
	LinkedList TeamA;
	LinkedList TeamB;

	menu(Roster, TeamA, TeamB);

	return 0;
}


void menu(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB)
{


	string option = "";
	int control = 3242;
	while (control == 3242)
	{
		cout << "Choose one option " << endl;

		cout << "1. Create Roster" << endl;
		cout << "2. View Roster" << endl;
		cout << "3. Shuffle Roster" << endl;
		cout << "4. Create Teams" << endl;
		cout << "5. View Teams" << endl;
		cout << "6. User Play" << endl;
		cout << "7. Auto Play" << endl;
		cout << "8. Quit" << endl;
		getline(cin, option);
		//cin >> option;

		if (option == "1") { CreateRoster(Roster, TeamA, TeamB); }
		if (option == "2") { ViewRoster(Roster, TeamA, TeamB); }
		if (option == "3") { ShuffleRoster(Roster, TeamA, TeamB); }
		if (option == "4") { CreateTeams(Roster, TeamA, TeamB); }
		if (option == "5") { ViewTeams(Roster, TeamA, TeamB); }
		if (option == "6") { UserPlay(Roster, TeamA, TeamB); }
		if (option == "7") { AutoPlay(Roster, TeamA, TeamB); }
		if (option == "8") { exit(0); }



	}
}

void CreateRoster(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB)
{
	string filename;
	cout << "Enter name of file to create Roster " << endl;
	getline(cin, filename);
	//cin >> filename;

	filename = filename + ".txt";
	string name;
	int strength;
	int speed;

	fstream file(filename.c_str());
	if (file.fail() == true)
	{
		cout << "That file does not exist. " << endl;
		menu(Roster, TeamA, TeamB);
	}


	while (file.eof() == false)
	{
		//cout << "inside while " << endl;
		file >> name;
		file >> strength;
		file >> speed;
		cout << "name is " << name << endl;
		cout << "strength is " << strength << endl;
		cout << "speed is " << speed << endl;
		Roster.insertTail(name, strength, speed);
	}
	cout << endl;
	cout << "That file was added to the list. " << endl;
	cout << endl;

}


void ViewRoster(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB)
{
	if (Roster.size() == 0)
	{
		cout << endl;
		cout << "Roster Empty " << endl;
		cout << endl;
		menu(Roster, TeamA, TeamB);
	}


	if (Roster.size() != 0)
	{
		cout << endl;
		Roster.getlist();
		cout << endl;
	}
}


void ShuffleRoster(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB)
{
	Roster.randomshuffle();
	cout << endl;
	Roster.getlist();
	cout << endl;
}


void CreateTeams(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB)
{
	if (Roster.size() > 4)
	{
		cout << endl;
		cout << "Team were created " << endl;
		cout << endl;

		string name = "";
		int strength = 0;
		int speed = 0;

		int control = 0;
		int size = (Roster.size() / 2);
		for (int i = 0; i < size; i++)
		{
			name = Roster.getName(control);
			strength = Roster.getStrength(control);
			speed = Roster.getSpeed(control);

			Roster.remove(Roster.getName(control));
			TeamA.insertTail(name, strength, speed);

			name = Roster.getName(control);
			strength = Roster.getStrength(control);
			speed = Roster.getSpeed(control);

			Roster.remove(Roster.getName(control));
			TeamB.insertTail(name, strength, speed);
		}
	}
	else


		if (Roster.size() < 4)
		{
			cout << endl;
			cout << "You do not have enough players in Roster. " << endl;
			cout << endl;
		}

}


void ViewTeams(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB)
{
	if (TeamA.size() != 0)
	{
		cout << endl;
		cout << "Team A: " << endl;
		cout << endl;
		for (int A = 0; A < TeamA.size(); A++)
		{
			cout << A + 1 << TeamA.getName(A) << " " << TeamA.getStrength(A) << " " << TeamA.getSpeed(A) << endl;
		}
		cout << endl;
		cout << "Team B: " << endl;
		cout << endl;
		for (int B = 0; B < TeamB.size(); B++)
		{
			cout << B + 1 << TeamB.getName(B) << " " << TeamB.getStrength(B) << " " << TeamB.getSpeed(B) << endl;
		}
		cout << endl;
	}
	else

		if (TeamA.size() == 0)
		{
			cout << endl;
			cout << "Your teams are empty. " << endl;
			cout << endl;

		}

}


void UserPlay(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB)
{
	int whilelo = 0;
	if (TeamA.size() >= 2 && TeamB.size() >= 2)
	{
		while (TeamA.size() != 1 && TeamB.size() != 1)
		{
			whilelo++;
			cout << "while " << whilelo << " times" << endl;

			bool T = true;

			if (T == true)
			{


				int indexA = 0;
				int indexB = 0;
				int indexB2 = 0;

				cout << endl;
				cout << "Team A TURN " << endl;
				cout << endl;

				bool rep = true;
				while (rep == true)
				{
					string teamA = "";

					cout << "Choose who will run and break Team B's link. " << endl;
					cout << endl;
					TeamA.getlist();
					cout << endl;
					getline(cin, teamA);
					//cin >> teamA;

					for (int i = 0; i < TeamA.size(); i++)
					{
						if (teamA == TeamA.getName(i))
						{
							indexA = i;
							rep = false;
						}
					}
				} // while question


				bool rep2 = true;
				while (rep2 == true)
				{
					string teamB = "";
					cout << "Choose whose person's link on Team B, you want to break. " << endl;
					cout << endl;
					TeamB.getlist();
					cout << endl;
					getline(cin, teamB);
					//cin >> teamB;

					for (int i = 0; i < TeamB.size(); i++)
					{
						if (teamB == TeamB.getName(i))
						{
							indexB = i;
							rep2 = false;
						}
					}
				} // while question


				cout << "Player of Team A selected is: " << endl;
				cout << TeamA.getName(indexA) << " has strength " << TeamA.getStrength(indexA) << " and speed " << TeamA.getSpeed(indexA) << endl;
				int ForceA = TeamA.getStrength(indexA) + TeamA.getSpeed(indexA);
				cout << "Force is its strength added to its speed which is " << ForceA << endl;

				int ForceB = 0;
				if (indexB != TeamB.size() - 1)
				{
					cout << "Player selected is not the last in the link... Players of Team B are: " << endl;
					cout << TeamB.getName(indexB) << " has strength " << TeamB.getStrength(indexB) << endl;
					cout << TeamB.getName(indexB + 1) << " has strength " << TeamB.getStrength(indexB + 1) << endl;
					ForceB = TeamB.getStrength(indexB) + TeamB.getStrength(indexB + 1);
					cout << "Force is both strengths added together. Force of link is " << ForceB << endl;
					indexB2 = indexB + 1;

					if (ForceA >= ForceB)
					{
						cout << "Force of running player was greater than the Force of the link, " << endl;
						cout << "so Team A gets the strongest player of team B. " << endl;

						int great_stre = 0;
						int indexBstrong = 0;
						for (int i = 0; i < TeamB.size(); i++)
						{
							if (great_stre < TeamB.getStrength(i))
							{
								great_stre = TeamB.getStrength(i);
								indexBstrong = i;
							}

						}

						string name = "";
						int strength = 0;
						int speed = 0;

						name = TeamB.getName(indexBstrong);
						strength = TeamB.getStrength(indexBstrong);
						speed = TeamB.getSpeed(indexBstrong);

						TeamB.remove(name);

						TeamA.insertAfter(name, strength, speed, TeamA.getName(indexA));

					}

					if (ForceA < ForceB)
					{
						cout << "Force of running player is less than the Force of the link, " << endl;
						cout << "so he becomes part of the linking team. " << endl;

						string name = "";
						int strength = 0;
						int speed = 0;

						name = TeamA.getName(indexA);
						strength = TeamA.getStrength(indexA);
						speed = TeamA.getSpeed(indexA);

						TeamA.remove(name);

						TeamB.insertAfter(name, strength, speed, TeamB.getName(indexB));
					}
				}
				else

					if (indexB == TeamB.size() - 1)
					{
						cout << "Player selected is the last person of Team B... Players of linking team are: " << endl;
						cout << TeamB.getName(indexB) << " has strength " << TeamB.getStrength(indexB) << endl;
						cout << TeamB.getName(indexB - 1) << " has strength " << TeamB.getStrength(indexB - 1) << endl;
						ForceB = TeamB.getStrength(indexB) + TeamB.getStrength(indexB - 1);
						cout << "Force is both strengths added together. Force of link is " << ForceB << endl;
						indexB2 = indexB - 1;


						if (ForceA >= ForceB)
						{
							cout << "Force of running player was greater than the Force of the link, " << endl;
							cout << "so Team A gets the strongest player of team B. " << endl;

							int great_stre = 0;
							int indexBstrong = 0;
							for (int i = 0; i < TeamB.size(); i++)
							{
								if (great_stre < TeamB.getStrength(i))
								{
									great_stre = TeamB.getStrength(i);
									indexBstrong = i;
								}

							}

							string name = "";
							int strength = 0;
							int speed = 0;

							name = TeamB.getName(indexBstrong);
							strength = TeamB.getStrength(indexBstrong);
							speed = TeamB.getSpeed(indexBstrong);

							TeamB.remove(name);

							TeamA.insertAfter(name, strength, speed, TeamA.getName(indexA));


						}

						if (ForceA < ForceB)
						{
							cout << "Force of running player is less than the Force of the link, " << endl;
							cout << "so he becomes part of the linking team. " << endl;

							string name = "";
							int strength = 0;
							int speed = 0;

							name = TeamA.getName(indexA);
							strength = TeamA.getStrength(indexA);
							speed = TeamA.getSpeed(indexA);

							TeamA.remove(name);

							TeamB.insertAfter(name, strength, speed, TeamB.getName(indexB));


						}
					}
				T = false;
				cout << " T is " << T << endl;
				cout << " A size is " << TeamA.size() << endl;
				cout << " B size is " << TeamB.size() << endl;

			}// part Team A





			if (T == false)
			{
				// ViewTeams(Roster, TeamA, TeamB);

				int indexA = 0;
				int indexB = 0;
				int indexB2 = 0;

				cout << endl;
				cout << "Team B TURN " << endl;
				cout << endl;

				bool rep = true;
				while (rep == true)
				{
					string teamA = "";

					cout << "Choose who will run and break Team A's link. " << endl;
					cout << endl;
					TeamB.getlist();
					cout << endl;
					getline(cin, teamA);
					//cin >> teamA;

					for (int i = 0; i < TeamB.size(); i++)
					{
						if (teamA == TeamB.getName(i))
						{
							indexA = i;
							rep = false;
						}
					}
				} // while question


				bool rep2 = true;
				while (rep2 == true)
				{
					string teamB = "";
					cout << "Choose whose person's link on Team A, you want to break. " << endl;
					cout << endl;
					TeamA.getlist();
					cout << endl;
					getline(cin, teamB);
					//cin >> teamB;

					for (int i = 0; i < TeamA.size(); i++)
					{
						if (teamB == TeamA.getName(i))
						{
							indexB = i;
							rep2 = false;
						}
					}
				} // while question


				cout << "Player of Team B selected is: " << endl;
				cout << TeamB.getName(indexA) << " has strength " << TeamB.getStrength(indexA) << " and speed " << TeamB.getSpeed(indexA) << endl;
				int ForceA = TeamB.getStrength(indexA) + TeamB.getSpeed(indexA);
				cout << "Force is its strength added to its speed which is " << ForceA << endl;

				int ForceB = 0;
				if (indexB != TeamA.size() - 1)
				{
					cout << "Player selected is not the last in the link... Players of Team A are: " << endl;
					cout << TeamA.getName(indexB) << " has strength " << TeamA.getStrength(indexB) << endl;
					cout << TeamA.getName(indexB + 1) << " has strength " << TeamA.getStrength(indexB + 1) << endl;
					ForceB = TeamA.getStrength(indexB) + TeamA.getStrength(indexB + 1);
					cout << "Force is both strengths added together. Force of link is " << ForceB << endl;
					indexB2 = indexB + 1;
					if (ForceA >= ForceB)
					{
						cout << "Force of running player was greater than the Force of the link, " << endl;
						cout << "so Team B gets the strongest player of team A. " << endl;

						int great_stre = 0;
						int indexBstrong = 0;
						for (int i = 0; i < TeamA.size(); i++)
						{
							if (great_stre < TeamA.getStrength(i))
							{
								great_stre = TeamA.getStrength(i);
								indexBstrong = i;
							}

						}

						string name = "";
						int strength = 0;
						int speed = 0;

						name = TeamA.getName(indexBstrong);
						strength = TeamA.getStrength(indexBstrong);
						speed = TeamA.getSpeed(indexBstrong);

						TeamA.remove(name);

						TeamB.insertAfter(name, strength, speed, TeamB.getName(indexA));

					}

					if (ForceA < ForceB)
					{
						cout << "Force of running player is less than the Force of the link, " << endl;
						cout << "so he becomes part of the linking team. " << endl;

						string name = "";
						int strength = 0;
						int speed = 0;

						name = TeamB.getName(indexA);
						strength = TeamB.getStrength(indexA);
						speed = TeamB.getSpeed(indexA);

						TeamB.remove(name);

						TeamA.insertAfter(name, strength, speed, TeamA.getName(indexB));
					}
				}
				else

					if (indexB == TeamA.size() - 1)
					{
						cout << "Player selected is the last person of Team A... Players of linking team are: " << endl;
						cout << TeamA.getName(indexB) << " has strength " << TeamA.getStrength(indexB) << endl;
						cout << TeamA.getName(indexB - 1) << " has strength " << TeamA.getStrength(indexB - 1) << endl;
						ForceB = TeamA.getStrength(indexB) + TeamA.getStrength(indexB - 1);
						cout << "Force is both strengths added together. Force of link is " << ForceB << endl;
						indexB2 = indexB - 1;


						if (ForceA >= ForceB)
						{
							cout << "Force of running player was greater than the Force of the link, " << endl;
							cout << "so Team B gets the strongest player of team A. " << endl;

							int great_stre = 0;
							int indexBstrong = 0;
							for (int i = 0; i < TeamA.size(); i++)
							{
								if (great_stre < TeamA.getStrength(i))
								{
									great_stre = TeamA.getStrength(i);
									indexBstrong = i;
								}

							}

							string name = "";
							int strength = 0;
							int speed = 0;

							name = TeamA.getName(indexBstrong);
							strength = TeamA.getStrength(indexBstrong);
							speed = TeamA.getSpeed(indexBstrong);

							TeamA.remove(name);

							TeamB.insertAfter(name, strength, speed, TeamB.getName(indexA));


						}

						if (ForceA < ForceB)
						{
							cout << "Force of running player is less than the Force of the link, " << endl;
							cout << "so he becomes part of the linking team. " << endl;

							string name = "";
							int strength = 0;
							int speed = 0;

							name = TeamB.getName(indexA);
							strength = TeamB.getStrength(indexA);
							speed = TeamB.getSpeed(indexA);

							TeamB.remove(name);

							TeamA.insertAfter(name, strength, speed, TeamA.getName(indexB));


						}
					}
				T = true;
				//cout << " T is " << T << endl;
				//cout << " A size is " << TeamA.size() << endl;
				//cout << " B size is " << TeamB.size() << endl;
			}// part Team B

			//ViewTeams( Roster, TeamA, TeamB);
			//cout << "end of while " << endl;

		}// game while

		if (TeamA.size() == 1) { cout << "\n\nTeam B won !!! \n" << endl; }
		if (TeamB.size() == 1) { cout << "\n\nTeam A won !!! \n" << endl; }

	}
	else


		if (TeamA.size() < 2)
		{
			cout << endl;
			cout << "You do not have enough players in your Teams. " << endl;
			cout << endl;

		}

}



void AutoPlay(LinkedList& Roster, LinkedList& TeamA, LinkedList& TeamB)
{
	int whilelo = 0;
	if (TeamA.size() >= 2 && TeamB.size() >= 2)
	{
		while (TeamA.size() != 1 && TeamB.size() != 1)
		{
			whilelo++;
			cout << "while " << whilelo << " times" << endl;

			bool T = true;

			if (T == true)
			{


				int indexA = rand() % TeamA.size();
				int indexB = rand() % TeamB.size();
				int indexB2 = 0;

				cout << endl;
				cout << "Team A TURN " << endl;
				cout << endl;

				//bool rep = true;
				// while ( rep == true)
				//{
				//string teamA;

				cout << "Choose who will run and break Team B's link. " << endl;
				cout << endl;
				TeamA.getlist();
				cout << endl;

				cout << "Computer selected player " << TeamA.getName(indexA) << endl;

				//getline (cin, teamA);
				//cin >> teamA;

				//for (int i = 0 ; i < TeamA.size() ; i++)
				//{
				// if ( teamA == TeamA.getName(i)) 
				//{
				//    indexA = i;
				//    rep = false;
				//}
				// }
				// } // while question


				//bool rep2 = true;
				//while ( rep2 == true)
				//{
				// string teamB;
				cout << "Choose whose person's link on Team B, you want to break. " << endl;
				cout << endl;
				TeamB.getlist();
				cout << endl;

				cout << "Computer selected player " << TeamB.getName(indexB) << endl;
				// getline (cin, teamB);
				//cin >> teamB;

				//for (int i = 0 ; i < TeamB.size() ; i++)
				//{
				//   if ( teamB == TeamB.getName(i)) 
				//  {
				//      indexB = i;
				//     rep2 = false;
				// }
				// }
				// } // while question


				cout << "Player of Team A selected is: " << endl;
				cout << TeamA.getName(indexA) << " has strength " << TeamA.getStrength(indexA) << " and speed " << TeamA.getSpeed(indexA) << endl;
				int ForceA = TeamA.getStrength(indexA) + TeamA.getSpeed(indexA);
				cout << "Force is its strength added to its speed which is " << ForceA << endl;

				int ForceB = 0;
				if (indexB != TeamB.size() - 1)
				{
					cout << "Player selected is not the last in the link... Players of Team B are: " << endl;
					cout << TeamB.getName(indexB) << " has strength " << TeamB.getStrength(indexB) << endl;
					cout << TeamB.getName(indexB + 1) << " has strength " << TeamB.getStrength(indexB + 1) << endl;
					ForceB = TeamB.getStrength(indexB) + TeamB.getStrength(indexB + 1);
					cout << "Force is both strengths added together. Force of link is " << ForceB << endl;
					indexB2 = indexB + 1;

					if (ForceA >= ForceB)
					{
						cout << "Force of running player was greater than the Force of the link, " << endl;
						cout << "so Team A gets the strongest player of team B. " << endl;

						int great_stre = 0;
						int indexBstrong = 0;
						for (int i = 0; i < TeamB.size(); i++)
						{
							if (great_stre < TeamB.getStrength(i))
							{
								great_stre = TeamB.getStrength(i);
								indexBstrong = i;
							}

						}

						string name = "";
						int strength = 0;
						int speed = 0;

						name = TeamB.getName(indexBstrong);
						strength = TeamB.getStrength(indexBstrong);
						speed = TeamB.getSpeed(indexBstrong);

						TeamB.remove(name);

						TeamA.insertAfter(name, strength, speed, TeamA.getName(indexA));

					}

					if (ForceA < ForceB)
					{
						cout << "Force of running player is less than the Force of the link, " << endl;
						cout << "so he becomes part of the linking team. " << endl;

						string name = "";
						int strength = 0;
						int speed = 0;

						name = TeamA.getName(indexA);
						strength = TeamA.getStrength(indexA);
						speed = TeamA.getSpeed(indexA);

						TeamA.remove(name);

						TeamB.insertAfter(name, strength, speed, TeamB.getName(indexB));
					}
				}
				else

					if (indexB == TeamB.size() - 1)
					{
						cout << "Player selected is the last person of Team B... Players of linking team are: " << endl;
						cout << TeamB.getName(indexB) << " has strength " << TeamB.getStrength(indexB) << endl;
						cout << TeamB.getName(indexB - 1) << " has strength " << TeamB.getStrength(indexB - 1) << endl;
						ForceB = TeamB.getStrength(indexB) + TeamB.getStrength(indexB - 1);
						cout << "Force is both strengths added together. Force of link is " << ForceB << endl;
						indexB2 = indexB - 1;


						if (ForceA >= ForceB)
						{
							cout << "Force of running player was greater than the Force of the link, " << endl;
							cout << "so Team A gets the strongest player of team B. " << endl;

							int great_stre = 0;
							int indexBstrong = 0;
							for (int i = 0; i < TeamB.size(); i++)
							{
								if (great_stre < TeamB.getStrength(i))
								{
									great_stre = TeamB.getStrength(i);
									indexBstrong = i;
								}

							}

							string name = "";
							int strength = 0;
							int speed = 0;

							name = TeamB.getName(indexBstrong);
							strength = TeamB.getStrength(indexBstrong);
							speed = TeamB.getSpeed(indexBstrong);

							TeamB.remove(name);

							TeamA.insertAfter(name, strength, speed, TeamA.getName(indexA));


						}

						if (ForceA < ForceB)
						{
							cout << "Force of running player is less than the Force of the link, " << endl;
							cout << "so he becomes part of the linking team. " << endl;

							string name = "";
							int strength = 0;
							int speed = 0;

							name = TeamA.getName(indexA);
							strength = TeamA.getStrength(indexA);
							speed = TeamA.getSpeed(indexA);

							TeamA.remove(name);

							TeamB.insertAfter(name, strength, speed, TeamB.getName(indexB));


						}
					}
				T = false;
				cout << " T is " << T << endl;
				cout << " A size is " << TeamA.size() << endl;
				cout << " B size is " << TeamB.size() << endl;

			}// part Team A


			if (TeamA.size() == 1 || TeamB.size() == 1) { break; }


			if (T == false)
			{
				// ViewTeams(Roster, TeamA, TeamB);

				int indexA = rand() % TeamB.size();
				int indexB = rand() % TeamA.size();
				int indexB2 = 0;

				cout << endl;
				cout << "Team B TURN " << endl;
				cout << endl;

				//bool rep = true;
				//while ( rep == true)
				//{
				//string teamA;

				cout << "Choose who will run and break Team A's link. " << endl;
				cout << endl;
				TeamB.getlist();
				cout << endl;

				cout << "Computer selected player " << TeamB.getName(indexA) << endl;

				//getline (cin, teamA);
				//cin >> teamA;

				// for (int i = 0 ; i < TeamB.size() ; i++)
				//{
				//    if ( teamA == TeamB.getName(i)) 
				//    {
				//        indexA = i;
				//       rep = false;
				//   }
				// }
				// } // while question


				// bool rep2 = true;
				//while ( rep2 == true)
				// {
				//string teamB;
				cout << "Choose whose person's link on Team A, you want to break. " << endl;
				cout << endl;
				TeamA.getlist();
				cout << endl;

				cout << "Computer selected player " << TeamA.getName(indexB) << endl;

				//getline (cin, teamB);
				//cin >> teamB;

				//for (int i = 0 ; i < TeamA.size() ; i++)
				// {
				//    if ( teamB == TeamA.getName(i)) 
				//    {
				//       indexB = i;
				//       rep2 = false;
				//   }
				// }
				// } // while question


				cout << "Player of Team B selected is: " << endl;
				cout << TeamB.getName(indexA) << " has strength " << TeamB.getStrength(indexA) << " and speed " << TeamB.getSpeed(indexA) << endl;
				int ForceA = TeamB.getStrength(indexA) + TeamB.getSpeed(indexA);
				cout << "Force is its strength added to its speed which is " << ForceA << endl;

				int ForceB = 0;
				if (indexB != TeamA.size() - 1)
				{
					cout << "Player selected is not the last in the link... Players of Team A are: " << endl;
					cout << TeamA.getName(indexB) << " has strength " << TeamA.getStrength(indexB) << endl;
					cout << TeamA.getName(indexB + 1) << " has strength " << TeamA.getStrength(indexB + 1) << endl;
					ForceB = TeamA.getStrength(indexB) + TeamA.getStrength(indexB + 1);
					cout << "Force is both strengths added together. Force of link is " << ForceB << endl;
					indexB2 = indexB + 1;
					if (ForceA >= ForceB)
					{
						cout << "Force of running player was greater than the Force of the link, " << endl;
						cout << "so Team B gets the strongest player of team A. " << endl;

						int great_stre = 0;
						int indexBstrong = 0;
						for (int i = 0; i < TeamA.size(); i++)
						{
							if (great_stre < TeamA.getStrength(i))
							{
								great_stre = TeamA.getStrength(i);
								indexBstrong = i;
							}

						}

						string name = "";
						int strength = 0;
						int speed = 0;

						name = TeamA.getName(indexBstrong);
						strength = TeamA.getStrength(indexBstrong);
						speed = TeamA.getSpeed(indexBstrong);

						TeamA.remove(name);

						TeamB.insertAfter(name, strength, speed, TeamB.getName(indexA));

					}

					if (ForceA < ForceB)
					{
						cout << "Force of running player is less than the Force of the link, " << endl;
						cout << "so he becomes part of the linking team. " << endl;

						string name = "";
						int strength = 0;
						int speed = 0;

						name = TeamB.getName(indexA);
						strength = TeamB.getStrength(indexA);
						speed = TeamB.getSpeed(indexA);

						TeamB.remove(name);

						TeamA.insertAfter(name, strength, speed, TeamA.getName(indexB));
					}
				}
				else

					if (indexB == TeamA.size() - 1)
					{
						cout << "Player selected is the last person of Team A... Players of linking team are: " << endl;
						cout << TeamA.getName(indexB) << " has strength " << TeamA.getStrength(indexB) << endl;
						cout << TeamA.getName(indexB - 1) << " has strength " << TeamA.getStrength(indexB - 1) << endl;
						ForceB = TeamA.getStrength(indexB) + TeamA.getStrength(indexB - 1);
						cout << "Force is both strengths added together. Force of link is " << ForceB << endl;
						indexB2 = indexB - 1;


						if (ForceA >= ForceB)
						{
							cout << "Force of running player was greater than the Force of the link, " << endl;
							cout << "so Team B gets the strongest player of team A. " << endl;

							int great_stre = 0;
							int indexBstrong = 0;
							for (int i = 0; i < TeamA.size(); i++)
							{
								if (great_stre < TeamA.getStrength(i))
								{
									great_stre = TeamA.getStrength(i);
									indexBstrong = i;
								}

							}

							string name = "";
							int strength = 0;
							int speed = 0;

							name = TeamA.getName(indexBstrong);
							strength = TeamA.getStrength(indexBstrong);
							speed = TeamA.getSpeed(indexBstrong);

							TeamA.remove(name);

							TeamB.insertAfter(name, strength, speed, TeamB.getName(indexA));


						}

						if (ForceA < ForceB)
						{
							cout << "Force of running player is less than the Force of the link, " << endl;
							cout << "so he becomes part of the linking team. " << endl;

							string name = "";
							int strength = 0;
							int speed = 0;

							name = TeamB.getName(indexA);
							strength = TeamB.getStrength(indexA);
							speed = TeamB.getSpeed(indexA);

							TeamB.remove(name);

							TeamA.insertAfter(name, strength, speed, TeamA.getName(indexB));


						}
					}
				T = true;
				cout << " T is " << T << endl;
				cout << " A size is " << TeamA.size() << endl;
				cout << " B size is " << TeamB.size() << endl;
			}// part Team B

			ViewTeams(Roster, TeamA, TeamB);
			cout << "end of while " << endl;

		}// game while

		if (TeamA.size() == 1) { cout << "\n\nTeam B won !!! \n" << endl; }
		if (TeamB.size() == 1) { cout << "\n\nTeam A won !!! \n" << endl; }

	}
	else


		if (TeamA.size() < 2)
		{
			cout << endl;
			cout << "You do not have enough players in your Teams. " << endl;
			cout << endl;

		}

}


/*

Option 6 – User Play
The functionality of this option is as follows:
1. The names of the Persons on Team A are displayed to the user and the user is prompted to pick a name from Team
*  A.
2. The names of the Persons on Team B are then displayed to the user and the user is prompted to pick a name from
* Team B. This is the name of the Person whose link to his successor the Person from Team A will try to break,
* unless the person is the last Person on Team B, in which case the Person from Team A will try to break the link
*  between the last two Persons. For example,
Team A: Grant, Ray, Iris, Eric
Pick: Ray
Team B: Dantley, Kevin, Matt, Jacob
Pick: Matt
In this example, Ray will attempt to break the link between Matt and Jacob. The link is broken if the sum of Ray's
* strength and speed exceeds the sum of Matt and Jacob's strength. If the link is broken then Ray returns to his
*  original index on his team. The stronger Person associated with the link that was broken becomes a part of
*  Ray's team and is inserted after Ray. If the link is not broken then Ray becomes part of Team B and is
*  inserted between Matt and Jacob.
3. Team B then assumes Team A’s role, and vice versa.
4. Play continues until there is one person left on a team. At this point print
* out the name of the winning team and return to the menu.
If the user enters invalid input, re-prompt the user until correct input is provided.

*
*
Option 7-Auto Play
This option will simulate a game of Red Rover. Your program randomly selects a player to try to break a
* randomly selected link of the other team. Between each turn, print the names of Persons currently on Team A
*  and Team B. At the end of play, print out the name of the winning team, and return to the menu.
*
*
*
*
*
*
Option 8 – Quit
This option will terminate the program.

*
*
*
*
*
*
To receive full credit, your program must pass valgrind. You may run this through the terminal on the
* Linux machines. You must first navigate to your project folder and find your project’s executable file. If
* you do not have an executable file, you can make one through the terminal command:

g++ -o <name of executable file you want to create> *.h *.cpp
i.e.
g++ -o redRover *.h *.cpp

This will create an executable file with the name you entered within your project code folder. Now to run
* valgrind, the command is:

valgrind --tool=memcheck --leak-check=yes ./<name of executable>
i.e.
valgrind --tool=memcheck --leak-check=yes ./redRover

If the result of running this command says:

All heap blocks were freed -- no leaks are possible

Then you passed valgrind :)*/
