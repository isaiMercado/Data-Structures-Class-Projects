/*
 * File:   Pathfinder.h
 * Author: misaie
 *
 * Created on May 20, 2014, 9:59 AM
 */

#ifndef PATHFINDER_H
#define	PATHFINDER_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;


class Pathfinder : public PathfinderInterface
{



public:



	Pathfinder()
	{
		srand(time(0));
		curr_maze[0][0][0] = "-1";
		curr_maze[4][4][4] = "-1";
	}



	virtual ~Pathfinder(){}




	virtual string getMaze()
	{
		//cout << "       in getMaze" << endl;


		if (curr_maze[0][0][0] == "-1")
		{
			string current;
			for (int z = 0; z < 5; z++)
			{
				for (int y = 0; y < 5; y++)
				{
					for (int x = 0; x < 5; x++)
					{
						curr_maze[x][y][z] = "1";
						current = current + "1";
						if (x < 4)
						{
							current = current + " ";
						}
					}

					if (current.length() < 250) { current = current + "\n"; }
				}
				if (current.length() < 250) { current = current + "\n"; }
			}
			//cout << "this maze from loop" << endl << current << endl;
			return current;
		}



		if (curr_maze[0][0][0] != "-1")
		{

			string current;
			for (int z = 0; z < 5; z++)
			{
				for (int y = 0; y < 5; y++)
				{
					for (int x = 0; x < 5; x++)
					{
						current = current + curr_maze[x][y][z];
						if (x < 4)
						{
							current = current + " ";
						}
					}
					if (current.length() < 250) { current = current + "\n"; }
				}
				if (current.length() < 250) { current = current + "\n"; }
			}
			//cout << "this maze from array" << endl << current << endl;
			return current;
		}




	}// function




	virtual void createRandomMaze()
	{
		//cout << "       in createRandomMaze" << endl;


		int iran = 0;
		string sran;

		//cout << "*************************" << endl;

		for (int z = 0; z < 5; z++)
		{
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
					iran = rand() % 2;
					if (iran == 0) { sran = "0"; }
					if (iran == 1) { sran = "1"; }
					curr_maze[x][y][z] = sran;
					curr_maze[0][0][0] = "1";
					curr_maze[4][4][4] = "1";
					//cout << curr_maze[x][y][z] << " " ;
				}
				//cout << "\n";
			}
			//cout << "\n";
		}


		//string test = string getMaze();

		//cout << "length is " << x.length() << endl;
		//cout << " it loops " << test << endl;
		//cout << "this maze from ranloop" << endl << x << endl;
		//curr_maze = x;



		/*  int test = 0;
		  int iran = 0;
		  string x;
		  string sran;

		  for ( int b = 0 ; b < 5 ; b++)
		  {
		  for (int i = 0 ; i < 5 ; i++)
		  {
		  for (int a = 0 ; a < 5 ; a++)
		  {
		  test++;
		  iran = rand() % 2;
		  if (iran == 0) { sran = "0";}
		  if (iran == 1) { sran = "1";}

		  if (x.length() == 0)   { x = "1";}
		  else if (x.length() == 252) { x = x + "1";}
		  else { x = x + sran; }

		  if (a < 4)
		  {
		  x = x + " ";
		  }
		  }
		  if (x.length() < 250) {x = x + "\n";}
		  }
		  if (x.length() < 250) {x = x + "\n";}
		  }
		  //cout << "length is " << x.length() << endl;
		  //cout << " it loops " << test << endl;
		  //cout << "this maze from ranloop" << endl << x << endl;
		  curr_maze = x;*/
	}

	virtual bool importMaze(string file_name)
	{
		// cout << "       in importMaze" << endl;
		//cout << "file opened " << file_name << endl;

		string current;
		string read;

		ifstream file;
		file.open(file_name.c_str());


		while (file >> read)
		{
			current = current + read;
		}

		// cout  << "This is current " << current <<  endl;

		if (current[0] != '1')
		{
			//cout << "false 1" << endl;
			return false;
		}

		if (current.length() > 125)
		{
			//cout << "false 2" << endl;
			return false;
		}

		if (current[124] != '1')
		{
			//cout << "false 3" << endl;
			return false;
		}

		for (int i = 0; i < current.length(); i++)
		{
			if (current[i] != '1' && current[i] != '0')
			{
				//cout << "false 4" << endl;
				return false;
			}
		}

		int spin = 0;
		for (int z = 0; z < 5; z++)
		{
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
					curr_maze[x][y][z] = current[spin];
					spin++;
				}
			}
		}

		return true;

		//string get = getMaze();
		//cout << "get " << get << endl;



		//===================================================================================//
		// string fileaddress = "/Home/misaie/NetBeansProjects/Lab5/To\\ Students/Mazes/" + file_name;
		/*//cout << fileaddress << endl;
		//cout << fileaddress.c_str() << endl;

		//stringstream all;


		string infile;
		while(file >> infile)
		{

		all << infile;
		//cout << infile << endl;
		//x = x + infile;
		//cout << x << endl << "------------------" << endl;

		}

		string current = all.str();
		*/

	}// function




	virtual vector<string> solveMaze()
	{
		//cout << "       in solveMaze" << endl;

		for (int z = 0; z < 5; z++)
		{
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
					curr_maze_bool[x][y][z] = true;

				}
			}
		}

		int x1 = 0;
		int y1 = 0;
		int z1 = 0;

		vector<string> coor_backwards = recursion(x1, y1, z1);
		vector<string> coordinates;

		int back = coor_backwards.size() - 1;
		for (int i = 0; i < coor_backwards.size(); i++)
		{
			coordinates.push_back(coor_backwards[back]);
			//cout << coordinates[i] << endl;
			back--;
		}

		return coordinates;
	}

	vector<string> recursion(int x, int y, int z)
	{
		//cout << "\n\nrecursion" << endl;
		//cout << "x " << x << " y " << y << " z " << z << endl;

		string maze = getMaze();

		//cout << maze << endl;

		ostringstream x1;
		string x_str;
		x1 << x;
		x_str = x1.str();

		ostringstream y1;
		string y_str;
		y1 << y;
		y_str = y1.str();

		ostringstream z1;
		string z_str;
		z1 << z;
		z_str = z1.str();

		string coor_stri = "(" + x_str + ", " + y_str + ", " + z_str + ")";

		//coor_stri = "( " + x + " , " + y + " , " + z + " )";

		bool edges = true;
		vector<string> coor_vect;


		/////There are 8 CORNERS with 3 options


		if (x == 0 && y == 0 && z == 0 && coor_vect.size() == 0) // 1
		{
			//cout << "corner 1" << endl;
			//cout << "x " << x << " y " << y << " z " << z << endl;

			curr_maze_bool[0][0][0] = false;

			if (curr_maze[1][0][0] == "1" && coor_vect.size() == 0 && curr_maze_bool[1][0][0] == true){ curr_maze_bool[1][0][0] = false; coor_vect = recursion(1, 0, 0); }
			if (curr_maze[0][1][0] == "1" && coor_vect.size() == 0 && curr_maze_bool[0][1][0] == true){ curr_maze_bool[0][1][0] = false; coor_vect = recursion(0, 1, 0); }
			if (curr_maze[0][0][1] == "1" && coor_vect.size() == 0 && curr_maze_bool[0][0][1] == true){ curr_maze_bool[0][0][1] = false; coor_vect = recursion(0, 0, 1); }

		}
		else


			if (x == 0 && y == 4 && z == 0 && coor_vect.size() == 0) //2
			{
				//cout << "corner 2" << endl;
				//cout << "x " << x << " y " << y << " z " << z << endl;
				if (curr_maze[1][4][0] == "1" && coor_vect.size() == 0 && curr_maze_bool[1][4][0] == true){ curr_maze_bool[1][4][0] = false; coor_vect = recursion(1, 4, 0); }
				if (curr_maze[0][3][0] == "1" && coor_vect.size() == 0 && curr_maze_bool[0][3][0] == true){ curr_maze_bool[0][3][0] = false; coor_vect = recursion(0, 3, 0); }
				if (curr_maze[0][4][1] == "1" && coor_vect.size() == 0 && curr_maze_bool[0][4][1] == true){ curr_maze_bool[0][4][1] = false; coor_vect = recursion(0, 4, 1); }

			}
			else


				if (x == 4 && y == 0 && z == 0 && coor_vect.size() == 0) //3
				{
					//cout << "corner 3" << endl;
					//cout << "x " << x << " y " << y << " z " << z << endl;
					if (curr_maze[4][1][0] == "1" && coor_vect.size() == 0 && curr_maze_bool[4][1][0] == true){ curr_maze_bool[4][1][0] = false; coor_vect = recursion(4, 1, 0); }
					if (curr_maze[3][0][0] == "1" && coor_vect.size() == 0 && curr_maze_bool[3][0][0] == true){ curr_maze_bool[3][0][0] = false; coor_vect = recursion(3, 0, 0); }
					if (curr_maze[4][0][1] == "1" && coor_vect.size() == 0 && curr_maze_bool[4][0][1] == true){ curr_maze_bool[4][0][1] = false; coor_vect = recursion(4, 0, 1); }

				}
				else


					if (x == 4 && y == 4 && z == 0 && coor_vect.size() == 0) //4
					{
						//cout << "corner 4" << endl;
						//cout << "x " << x << " y " << y << " z " << z << endl;
						if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[3][4][0] = false; coor_vect = recursion(3, 4, 0); }
						if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[4][3][0] = false; coor_vect = recursion(4, 3, 0); }
						if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[4][4][1] = false; coor_vect = recursion(4, 4, 1); }

					}
					else


						if (x == 4 && y == 0 && z == 4 && coor_vect.size() == 0) //5
						{
							//cout << "corner 5" << endl;
							//cout << "x " << x << " y " << y << " z " << z << endl;
							if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[3][0][4] = false; coor_vect = recursion(3, 0, 4); }
							if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[4][0][3] = false; coor_vect = recursion(4, 0, 3); }
							if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[4][1][4] = false; coor_vect = recursion(4, 0, 4); }

						}
						else


							if (x == 4 && y == 4 && z == 4 && coor_vect.size() == 0) //6
							{
								//cout << "corner 4,4,4" << endl;
								//cout << "x " << x << " y " << y << " z " << z << endl;
								coor_vect.push_back(coor_stri);
								return coor_vect;
							}
							else


								if (x == 0 && y == 4 && z == 4 && coor_vect.size() == 0) //7
								{
									//cout << "corner 7" << endl;
									//cout << "x " << x << " y " << y << " z " << z << endl;
									if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[1][4][4] = false; coor_vect = recursion(1, 4, 4); }
									if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[0][4][3] = false; coor_vect = recursion(0, 4, 3); }
									if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[0][3][4] = false; coor_vect = recursion(0, 3, 4); }

								}
								else


									if (x == 0 && y == 0 && z == 4 && coor_vect.size() == 0) //8
									{
										//cout << "corner 8" << endl;
										//cout << "x " << x << " y " << y << " z " << z << endl;
										if (curr_maze[0][1][4] == "1" && coor_vect.size() == 0 && curr_maze_bool[0][1][4] == true){ curr_maze_bool[0][1][4] = false; coor_vect = recursion(0, 1, 4); }
										if (curr_maze[0][0][3] == "1" && coor_vect.size() == 0 && curr_maze_bool[0][0][3] == true){ curr_maze_bool[0][0][3] = false; coor_vect = recursion(0, 0, 3); }
										if (curr_maze[1][0][4] == "1" && coor_vect.size() == 0 && curr_maze_bool[1][0][4] == true){ curr_maze_bool[1][0][4] = false; coor_vect = recursion(1, 0, 4); }

									}
									else


										/////There are 12 EDGES with 4 options



										if (x == 0 && z == 0 && coor_vect.size() == 0) //1
										{
											//cout << "edge 1" << endl;
											//cout << "x " << x << " y " << y << " z " << z << endl;
											if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
											if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
											if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
											if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }

										}
										else


											if (x == 4 && z == 0 && coor_vect.size() == 0) //2
											{
												//cout << "edge 2" << endl;
												//cout << "x " << x << " y " << y << " z " << z << endl;
												if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
												if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
												if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
												if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }

											}
											else


												if (y == 0 && z == 0 && coor_vect.size() == 0) //3
												{
													//cout << "edge 3" << endl;
													//cout << "x " << x << " y " << y << " z " << z << endl;
													if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
													if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
													if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
													if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }

												}
												else


													if (y == 4 && z == 0 && coor_vect.size() == 0) //4
													{
														//cout << "edge 4" << endl;
														//cout << "x " << x << " y " << y << " z " << z << endl;
														if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
														if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
														if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
														if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }

													}
													else


														if (x == 0 && z == 4 && coor_vect.size() == 0) //5
														{
															//cout << "edge 5" << endl;
															//cout << "x " << x << " y " << y << " z " << z << endl;
															if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
															if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
															if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
															if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }

														}
														else


															if (x == 4 && z == 4 && coor_vect.size() == 0) //6
															{
																//cout << "edge 6" << endl;
																//cout << "x " << x << " y " << y << " z " << z << endl;
																if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
																if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
																if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }

															}
															else


																if (y == 0 && z == 4 && coor_vect.size() == 0) //7
																{
																	//cout << "edge 7" << endl;
																	//cout << "x " << x << " y " << y << " z " << z << endl;
																	if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																	if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																	if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
																	if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }

																}
																else


																	if (y == 4 && z == 4 && coor_vect.size() == 0) //8
																	{
																		//cout << "edge 8" << endl;
																		//cout << "x " << x << " y " << y << " z " << z << endl;
																		if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																		if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																		if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
																		if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }

																	}
																	else


																		if (x == 0 && y == 0 && coor_vect.size() == 0) //9
																		{
																			//cout << "edge 9" << endl;
																			//cout << "x " << x << " y " << y << " z " << z << endl;
																			if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }
																			if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																			if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																			if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }

																		}
																		else


																			if (x == 4 && y == 0 && coor_vect.size() == 0) //10
																			{
																				//cout << "edge 10" << endl;
																				//cout << "x " << x << " y " << y << " z " << z << endl;
																				if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }
																				if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																				if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																				if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y, z + 1); }

																			}
																			else


																				if (x == 0 && y == 4 && coor_vect.size() == 0) //11
																				{
																					//cout << "edge 11" << endl;
																					//cout << "x " << x << " y " << y << " z " << z << endl;
																					if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }
																					if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																					if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																					if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }

																				}
																				else


																					if (x == 4 && y == 4 && coor_vect.size() == 0) //12
																					{
																						//cout << "edge 12" << endl;
																						//cout << "x " << x << " y " << y << " z " << z << endl;
																						if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }
																						if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																						if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																						if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }

																					}
																					else


																						/////There are 6 FACES with 5 options

																						if (x == 0 && coor_vect.size() == 0) //1
																						{
																							//cout << "face 1" << endl;
																							//cout << "x " << x << " y " << y << " z " << z << endl;
																							if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }
																							if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																							if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
																							if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
																							if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }

																						}
																						else

																							if (x == 4 && coor_vect.size() == 0) //2
																							{
																								// cout << "face 2" << endl;
																								//cout << "x " << x << " y " << y << " z " << z << endl;
																								if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }
																								if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																								if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
																								if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
																								if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }

																							}
																							else


																								if (y == 0 && coor_vect.size() == 0) //3
																								{
																									//cout << "face 3" << endl;
																									//cout << "x " << x << " y " << y << " z " << z << endl;
																									if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }
																									if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																									if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																									if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																									if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }

																								}
																								else


																									if (y == 4 && coor_vect.size() == 0) //4
																									{
																										//cout << "face 4" << endl;
																										//cout << "x " << x << " y " << y << " z " << z << endl;
																										if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }
																										if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																										if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																										if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																										if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }

																									}
																									else


																										if (z == 0 && coor_vect.size() == 0) //5
																										{
																											// cout << "face 5" << endl;
																											//cout << "x " << x << " y " << y << " z " << z << endl;
																											if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
																											if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
																											if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																											if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																											if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }

																										}
																										else


																											if (z == 4 && coor_vect.size() == 0) //6
																											{
																												//cout << "face 6" << endl;
																												//cout << "x " << x << " y " << y << " z " << z << endl;
																												if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
																												if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
																												if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																												if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																												if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }

																											}
																											else


																												/////There is only one BLOCK with 6 options


																												if (coor_vect.size() == 0)
																												{
																													//cout << "bloque" << endl;
																													//cout << "x " << x << " y " << y << " z " << z << endl;
																													if (curr_maze[x - 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x - 1][y][z] == true){ curr_maze_bool[x - 1][y][z] = false; coor_vect = recursion(x - 1, y, z); }
																													if (curr_maze[x + 1][y][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x + 1][y][z] == true){ curr_maze_bool[x + 1][y][z] = false; coor_vect = recursion(x + 1, y, z); }
																													if (curr_maze[x][y - 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y - 1][z] == true){ curr_maze_bool[x][y - 1][z] = false; coor_vect = recursion(x, y - 1, z); }
																													if (curr_maze[x][y + 1][z] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y + 1][z] == true){ curr_maze_bool[x][y + 1][z] = false; coor_vect = recursion(x, y + 1, z); }
																													if (curr_maze[x][y][z - 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z - 1] == true){ curr_maze_bool[x][y][z - 1] = false; coor_vect = recursion(x, y, z - 1); }
																													if (curr_maze[x][y][z + 1] == "1" && coor_vect.size() == 0 && curr_maze_bool[x][y][z + 1] == true){ curr_maze_bool[x][y][z + 1] = false; coor_vect = recursion(x, y, z + 1); }


																												}


		if (coor_vect.size() != 0)
		{
			//cout << "vector != 0" << endl;
			coor_vect.push_back(coor_stri);
			return coor_vect;
		}




		return coor_vect;



	}// function

private:

	string curr_maze[5][5][5];
	bool curr_maze_bool[5][5][5];



};

#endif	/* PATHFINDER_H */

