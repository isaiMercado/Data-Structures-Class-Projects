//235 midterm 1 -- spring june 4
//isai mercado oliveros

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;


class LinkedList
{

protected:
	struct Node
	{

		string name;
		int strength;
		int speed;

		Node* next;
		Node* before;


		Node()
		{
			next = NULL;
			before = NULL;
		}


		Node(string name, int strength, int speed)
		{
			this->name = name;
			this->strength = strength;
			this->speed = speed;
			next = NULL;
			before = NULL;
		}

		Node* getnext()
		{
			return next;
		}


		Node* getbefore()
		{
			return before;
		}


		void setnext(Node* newnode)
		{
			// cout << "in setnext" << endl;
			next = newnode;
		}


		void setbefore(Node* newnode)
		{
			// cout << "in setnext" << endl;
			before = newnode;
		}


		string getname()
		{
			return name;
		}


		int getstrength()
		{
			return strength;
		}


		int getspeed()
		{
			return speed;
		}


		void setname(string value)
		{
			name = value;
		}


		void setstrength(int value)
		{
			strength = value;
		}


		void setspeed(int value)
		{
			speed = value;
		}



	};
	Node* head;

public:


	LinkedList(void)
	{
		srand(time(0));
		head = NULL;
	}


	~LinkedList(void)
	{
		clear();
	}


	void getlist()
	{
		Node* walking = head;
		int control = 0;

		while (walking != NULL)
		{
			control++;
			//cout << control << " " << walking->getname() << endl;
			cout << control << " " << walking->getname() << " " << walking->getstrength() << " " << walking->getspeed() << endl;
			walking = walking->getnext();
		}
	}

	bool find_rep_func(string value)
	{
		Node* rep = head;

		while (rep != NULL)
		{
			if (rep->getname() == value)
			{
				return true;
			}
			rep = rep->getnext();
		}

		return false;

	}

	Node* find_node_position(string value)
	{

		if (head == NULL)
		{
			//cout << " find position() there is no head so there is no position" << endl;
			return NULL;
		}
		else if (head != NULL && head->getnext() == NULL)
		{
			// cout << "find position() head is the only thing so head is returned" << endl;
			return head;
		}
		else if (head != NULL && head->getnext() != NULL)
		{
			Node* address = head;

			//while (address->getnext() != NULL)
			while (address != NULL)
			{
				if (value == address->getname())
				{
					//cout << "find position() an address is returned" << address << endl;
					return address;
				}
				address = address->getnext();

			}
			//cout << "find position() after while no address was found" << endl;
			return NULL;
		}



	}

	void put_new_link(Node* listnode, Node* entrynode)
	{
		if (head == NULL)
		{
			head = NULL;
		}
		else


			if (head != NULL && head->getnext() == NULL)
			{
				Node* temporal = head;
				entrynode->setnext(temporal);
				temporal->setbefore(entrynode);/////////////////////
				head = entrynode;
			}


		if (head != NULL && head->getnext() != NULL)
		{
			entrynode->setnext(listnode->getnext());
			listnode->getnext()->setbefore(entrynode);/////////////////////
			listnode->setnext(entrynode);
			entrynode->setbefore(listnode);//////////////////////
		}
	}

	Node* find_last_node()
	{
		Node* lastnode = head;
		//while (lastnode->getnext() != NULL)
		while (lastnode->getnext() != NULL)
		{
			lastnode = lastnode->getnext();
		}
		return lastnode;
	}

	int find_node_index(Node* searchable_node)
	{
		Node* temporal = head;

		int index = 0;

		while (temporal != searchable_node)
		{
			temporal = temporal->getnext();
			index = index + 1;
		}
		return index;
	}

	string getName(int index)
	{
		string in_at = at(index);
		Node* temp = find_node_position(in_at);
		return temp->getname();
	}

	int getStrength(int index)
	{
		string in_at = at(index);
		Node* temp = find_node_position(in_at);
		return temp->getstrength();
	}

	int getSpeed(int index)
	{
		string in_at = at(index);
		Node* temp = find_node_position(in_at);
		return temp->getspeed();
	}


	void randomshuffle()
	{
		if (head == NULL)
		{
			cout << endl;
			cout << "Roster Empty. " << endl;
			cout << endl;
		}


		if (head != NULL && head->getnext() == NULL)
		{
			cout << endl;
			cout << "There is only one player, so it did not shuffle. " << endl;
			cout << endl;
		}


		if (head != NULL && head->getnext() != NULL)
		{
			cout << endl;
			cout << "Roster was shuffled. " << endl;
			cout << endl;

			int siz = size();
			for (int i = 0; i < siz; i++)
			{
				if (i == 0)
				{
					Node* temporal1 = head;
					Node* temporal2 = temporal1->getnext();

					if (head != NULL && head->getnext()->getnext() != NULL)
					{

						temporal2->getbefore()->setnext(temporal2->getnext());
						temporal2->getnext()->setbefore(temporal2->getbefore());

						temporal2->setnext(temporal1);
						temporal1->setbefore(temporal2);

						temporal2->setbefore(NULL);

						head = temporal2;

					}

					if (head != NULL && head->getnext()->getnext() == NULL)
					{
						temporal2->setnext(temporal1);
						temporal1->setbefore(temporal2);

						temporal1->setnext(NULL);
						temporal2->setbefore(NULL);

						head = temporal2;
					}

				}
				else


					if (i == (siz - 1) && size() != 2)
					{
						Node* last = find_last_node();
						Node* beflast = last->getbefore();

						beflast->getbefore()->setnext(last);
						last->setbefore(beflast->getbefore());

						last->setnext(beflast);
						beflast->setbefore(last);

						beflast->setnext(NULL);

					}
					else


						if (i != 0 && size() != 2)
						{
							int random = (rand() % (size() - 2)) + 1;

							string rand_str = at(random);
							Node* rand_node = find_node_position(rand_str);
							Node* temporal2 = rand_node;

							string for_str = at(i);
							Node* for_node = find_node_position(for_str);
							Node* temporal1 = for_node;


							if (temporal1 != temporal2 && temporal1->getnext() != temporal2 && temporal1->getbefore() != temporal2)
							{
								temporal1->getbefore()->setnext(temporal1->getnext());
								temporal1->getnext()->setbefore(temporal1->getbefore());

								temporal1->setnext(temporal2->getnext());
								temporal2->getnext()->setbefore(temporal1);

								temporal2->setnext(temporal1);
								temporal1->setbefore(temporal2);

							}


						}

			}
		}

	}

	void insertHead(string name1, int strength1, int speed1)
	{
		bool rep = find_rep_func(name1);

		if (head == NULL)
		{
			head = new Node(name1, strength1, speed1);
		}


		if (head != NULL && head->getnext() == NULL && rep == false)
		{
			Node* newhead = new Node(name1, strength1, speed1);
			Node* temporal = head;
			newhead->setnext(temporal);
			temporal->setbefore(newhead);
			head = newhead;
		}

	}


	void insertTail(string name1, int strength1, int speed1)
	{
		bool rep = find_rep_func(name1);

		if (head == NULL)
		{
			head = new Node(name1, strength1, speed1);
		}
		else


			if (head != NULL && head->getnext() == NULL && rep == false)
			{
				Node* new_node = new Node(name1, strength1, speed1);
				head->setnext(new_node);
				new_node->setbefore(head);
			}
			else


				if (head != NULL && head->getnext() != NULL && rep == false)
				{
					Node* newlastnode = new Node(name1, strength1, speed1);
					Node* lastnode = find_last_node();

					newlastnode->setbefore(lastnode);
					lastnode->setnext(newlastnode);
				}

	} // function



	void insertAfter(string name1, int strength1, int speed1, string insertionNode)
	{
		//cout << "   In insert after function " << endl;

		bool found = false;
		bool rep = false;
		Node* foundNode = head;



		while (foundNode != NULL)
		{
			if (foundNode->getname() == insertionNode)
			{
				found = true;
				//cout << "   bool is true" << endl;
				break;
			}
			foundNode = foundNode->getnext();
		}


		rep = find_rep_func(name1);


		if (found == true && rep == false && foundNode->getnext() == NULL && foundNode != head)
		{
			Node* inserted = new Node(name1, strength1, speed1);
			foundNode->setnext(inserted);
			inserted->setbefore(foundNode);
			//cout << inserted->getdata() << " was inserted after the last node " << foundNode->getdata() << endl;
		}
		else



			if (found == true && rep == false && foundNode->getnext() != NULL)
			{
				Node* inserted = new Node(name1, strength1, speed1);
				inserted->setnext(foundNode->getnext());
				foundNode->getnext()->setbefore(inserted);
				foundNode->setnext(inserted);
				inserted->setbefore(foundNode);
				//cout << inserted->getdata() << " was inserted after the middle node " << foundNode->getdata() << endl;
			}
			else



				if (found == true && rep == false && foundNode->getnext() == NULL && foundNode == head)
				{
					Node* inserted = new Node(name1, strength1, speed1);
					foundNode->setnext(inserted);
					inserted->setbefore(foundNode);
				}

	}//function



	void remove(string name1)
	{
		//cout << "   In remove function " << endl;
		bool found = false;
		Node* deleted = head;
		Node* before;



		while (deleted != NULL)
		{
			if (deleted->getname() == name1)
			{
				found = true;
				//cout << "   bool is true" << endl;
				break;
			}
			deleted = deleted->getnext();
		}



		if (found == true && deleted->getnext() == NULL && deleted != head)
		{
			Node* before = head;
			while (before != NULL)
			{
				if (before->getnext()->getname() == deleted->getname())
				{
					break;
				}
				before = before->getnext();
			}
			deleted->setnext(NULL);
			before->setnext(NULL);/////////////////
			delete deleted;
			deleted = NULL;

			//cout << "   passed last node test" << endl;
		}
		else



			if (found == true && deleted->getnext() != NULL)
			{
				Node* afterdeleted = deleted->getnext();
				deleted->setname(afterdeleted->getname());
				deleted->setstrength(afterdeleted->getstrength());
				deleted->setspeed(afterdeleted->getspeed());
				deleted->setnext(afterdeleted->getnext());
				deleted->setbefore(afterdeleted->getbefore());

				delete afterdeleted;
				afterdeleted = NULL;

				/*Node* afterdeleted = deleted->getnext();
				deleted->setname(afterdeleted->getname());
				deleted->setnext(afterdeleted->getnext());

				delete afterdeleted;
				afterdeleted = NULL;
				//cout << "   passed middle node test" << endl;*/
			}
			else



				if (found == true && deleted->getnext() == NULL && deleted == head)
				{
					delete head;
					head = NULL;
				}




	}// function


	virtual void clear()
	{
		//cout << "   in clear function" << endl;

		Node* current = head;

		while (current != NULL)
		{
			head = head->next;
			delete(current);
			current = head;
		}
		head = NULL;
	}


	string at(int index)
	{
		//cout << "   in at function" << endl;
		if (head == NULL)
		{
			return NULL;
		}
		else if (head != NULL)
		{
			if (0 <= index && index < size())
			{
				if (index == 0)
				{
					//cout << "in at function : head worked" << endl;
					//cout << head->getdata() << endl;
					return head->getname();
				}
				else if (index > 0)
				{
					//cout << "in at function : not head" << endl;
					Node* address = head;

					for (int i = 0; i < index; i++)
					{
						address = address->getnext();
					}
					return address->getname();
				}
			}
			else
			{
				//cout << "index is less or bigger than size() so size is 0" << endl;
				return NULL;
			}
		}
	}



	int size()
	{
		//cout << "   in size function" << endl;
		int size = 0;
		Node* temporal = head;

		while (temporal != NULL)
		{
			size = size + 1;
			temporal = temporal->getnext();
		}
		return size;
	}


};


#endif	
