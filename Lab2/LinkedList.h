


#include <iostream>
#include <string>

using namespace std;

template<class T>

class LinkedList : public LinkedListInterface < T >
{
protected:

	struct Node
	{
		T data;

		Node* next;

		Node()
		{

			next = NULL;
		}

		Node(T dat)
		{
			data = dat;
			next = NULL;
		}

		Node* getnext(){
			return next;
		}

		void setnext(Node* newnode){
			// cout << "in setnext" << endl;
			next = newnode;
		}

		T getdata(){
			return data;
		}

		void setdata(T value){
			data = value;
		}
	};

	Node* head;



public:


	LinkedList(void)
	{
		head = NULL;

	}


	~LinkedList(void)
	{
		clear();
	}

	bool find_rep_func(T value)
	{
		bool found = false;
		Node* rep = head;

		while (rep != NULL)
		{
			if (rep->getdata() == value)
			{
				found = true;
				break;
			}
			rep = rep->getnext();
		}

		return found;
		/*cout << "   In repetition function " << endl;
		if (head == NULL)
		{
		//cout << "find_rep_func () head is NULL - return false" << endl;
		return false;
		}
		else if (head != NULL)
		{

		//cout << "rep() head is not null" << endl;

		if (head->getnext() == NULL)
		{
		//cout << "find_rep_func () head != NULL but head->next is NULL - return false" << endl;
		return false;
		}
		else if (head->getnext() != NULL)
		{
		// cout << " rep() head is not NULL and head->getnext is not NULL" << endl;
		Node* temporal = head;
		T comparing_data;
		//while (temporal->getnext() != NULL)
		while (temporal != NULL)
		{
		comparing_data = temporal->getdata();
		if ( value == comparing_data )
		{
		// cout << "find_rep_func () repetition found - return true" << endl;
		return true;
		}
		temporal = temporal->getnext();
		}
		// cout << "find_rep_func () after while - return false" << endl;
		return false;
		}
		}*/
	}

	Node* find_node_position(T value)
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
				if (value == address->getdata())
				{
					//cout << "find position() an address is returned" << address << endl;
					return address;
				}
				address = address->getnext();

			}
			//cout << "find position() after while no address was found" << endl;
			return NULL;
		}


		/*Node* address = head->getnext();

	   while (address->getnext() != NULL)
	   {
	   if (value != address->getdata())
	   {
	   address = address->getnext();
	   }
	   else if (value == address->getdata())
	   {
	   return address;
	   }
	   }
	   delete address;
	   return NULL;*/
	}

	void put_new_link(Node* listnode, Node* entrynode)
	{
		if (head == NULL)
		{
			head = NULL;
		}
		else if (head != NULL && head->getnext() == NULL)
		{
			Node* temporal = head;
			entrynode->setnext(temporal);
			head = entrynode;
		}
		if (head != NULL && head->getnext() != NULL)
		{
			entrynode->setnext(listnode->getnext());
			listnode->setnext(entrynode);
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

	/*void showing_linkedlist()
	{
	cout << "in showing list function" << endl;
	Node* temporal = head;
	T test = temporal->getdata();
	cout << test << " ";
	cout << "hola";
	while (temporal->getnext() != NULL)
	{
	test = temporal->getdata();
	cout << test << ",";
	temporal = temporal->getnext();
	}

	}*/



	/*A node with the given value should be inserted at the beginning of the list.
	Do not allow duplicate values in the list.*/
	virtual void insertHead(T value)
	{
		//cout << "   In insert head function" << endl;
		if (head == NULL)
		{
			//cout << " in inserthead() made it" << endl;
			head = new Node(value);
		}
		else if (head->getnext() == NULL)
		{
			// cout << "second time around" << endl;
			bool rep = false;

			rep = find_rep_func(value);

			if (rep == false)
			{
				Node* second = new Node(value);
				Node* temporal = head;
				second->setnext(temporal);
				head = second;
			}
		}
		else if (head->getnext() != NULL)
		{
			bool rep = false;

			rep = find_rep_func(value);

			if (rep == false)
			{
				//cout << "inserHead() more than 3 nodes" << endl;
				Node* second = new Node(value);
				Node* temporal = head;
				second->setnext(temporal);
				head = second;

				//Node* test=head;
				//int s=size();
				// cout << s << " in inserthead()size" << endl;
				//for(int i=0; i<s; i++)
				//{
				//cout << "in inserthead() this is the data "test->getdata() << endl;
				//test=test->getnext();
				//}

			}
		}
	}




	/*A node with the given value should be inserted at the end of the list.
	Do not allow duplicate values in the list.*/
	virtual void insertTail(T value)
	{ // function
		//cout << "   in insert tail function" << endl;

		bool rep = find_rep_func(value);

		if (head == NULL)
		{
			head = new Node(value);
		}
		else if (head != NULL && head->getnext() == NULL && rep == false)
		{
			Node* new_node = new Node(value);
			head->setnext(new_node);
		}
		else if (head != NULL && head->getnext() != NULL && rep == false)
		{
			Node* newnode = new Node(value);
			//cout << "insertTail () : head != NULL and re == false " << endl;
			Node* lastnode = find_last_node();
			lastnode->setnext(newnode);
		}
	} // function




	/*A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.
	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.*/
	virtual void insertAfter(T value, T insertionNode)
	{
		//cout << "   In insert after function " << endl;

		bool found = false;
		bool rep = false;
		Node* foundNode = head;



		while (foundNode != NULL)
		{
			if (foundNode->getdata() == insertionNode)
			{
				found = true;
				//cout << "   bool is true" << endl;
				break;
			}
			foundNode = foundNode->getnext();
		}

		rep = find_rep_func(value);

		if (found == true && rep == false && foundNode->getnext() == NULL && foundNode != head)
		{
			Node* inserted = new Node(value);
			foundNode->setnext(inserted);
			//cout << inserted->getdata() << " was inserted after the last node " << foundNode->getdata() << endl;
		}
		else



			if (found == true && rep == false && foundNode->getnext() != NULL)
			{
				Node* inserted = new Node(value);
				inserted->setnext(foundNode->getnext());
				foundNode->setnext(inserted);

				//cout << inserted->getdata() << " was inserted after the middle node " << foundNode->getdata() << endl;
			}
			else



				if (found == true && rep == false && foundNode->getnext() == NULL && foundNode == head)
				{
					Node* inserted = new Node(value);
					foundNode->setnext(inserted);
					//cout << inserted->getdata() << " was inserted after head " << foundNode->getdata() << endl;
				}





		/*bool rep = find_rep_func(value);

		if (head == NULL)
		{
		//cout << "insertafter() head is null so value was set as head" << endl;
		head = new Node(value);
		}
		else if ( head != NULL && head->getnext() == NULL && rep == false)
		{
		//cout << "insertafter() head no NULL, head.next NULL so value was put as head.next" << endl;
		Node* new_node = new Node(value);

		head->setnext(new_node);
		}
		else if ( head != NULL && head->getnext() != NULL && rep == false)
		{

		Node* found_node = find_node_position(insertionNode);

		if (found_node == NULL)
		{
		//cout << " insertAfter() node was not added because node was not found" << endl;
		}
		else if (found_node != NULL && found_node->getnext() == NULL)
		{
		//cout << " insertAfter() found node is the last one " << endl;
		Node* new_node = new Node(value);

		found_node->setnext(new_node);
		}
		else if (found_node != NULL && found_node->getnext() != NULL)
		{
		//cout << " insertAfter() found node is in the middle" << endl;
		Node* new_node = new Node(value);

		put_new_link(found_node, new_node);

		//cout << "insertAfter() the node was inserted" << endl;
		}
		}  */
	}//function



	/*remove The node with the given value should be removed from the list.
	The list may or may not include a node with the given value.*/
	virtual void remove(T value)
	{
		//cout << "   In remove function " << endl;
		bool found = false;
		Node* deleted = head;
		Node* before;



		while (deleted != NULL)
		{
			if (deleted->getdata() == value)
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
				if (before->getnext()->getdata() == deleted->getdata())
				{
					break;
				}
				before = before->getnext();
			}
			deleted->setnext(NULL);
			delete deleted;
			deleted = NULL;
			before->setnext(NULL);
			//cout << "   passed last node test" << endl;
		}
		else



			if (found == true && deleted->getnext() != NULL)
			{
				Node* afterdeleted = deleted->getnext();
				deleted->setdata(afterdeleted->getdata());
				deleted->setnext(afterdeleted->getnext());

				delete afterdeleted;
				afterdeleted = NULL;
				//cout << "   passed middle node test" << endl;
			}
			else



				if (found == true && deleted->getnext() == NULL && deleted == head)
				{
					delete head;
					head = NULL;
				}




	}// function



	/*clear Remove all nodes from the list.*/
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



	/*at Returns the value of the node at the given index. The list begins at
	index 0. If the given index is out of range of the list, return NULL;*/
	virtual T at(int index)
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
					return head->getdata();
				}
				else if (index > 0)
				{
					//cout << "in at function : not head" << endl;
					Node* address = head;

					for (int i = 0; i < index; i++)
					{
						address = address->getnext();
					}
					return address->getdata();
				}
			}
			else
			{
				//cout << "index is less or bigger than size() so size is 0" << endl;
				return 0;
			}
		}
	}



	/* size Returns the number of nodes in the list.*/
	virtual int size()
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
