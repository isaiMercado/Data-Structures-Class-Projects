#pragma once
#include<string>
#include "NodeInterface.h"
#include <iostream>

using namespace std;

class Node : public NodeInterface
{

public:
	Node(int D)
	{
		data = D;
		balance = 0;
		Nleft = -1;
		Nright = -1;
		left = NULL;
		right = NULL;
		up = NULL;
	}

	virtual ~Node()
	{

	}

	/*
	 * Returns the data that is stored in this node
	 *
	 * @return the data that is stored in this node.
	 */
	virtual int getData()
	{

		return data;
	}

	/*
	 * Returns the left child of this node or null if it doesn't have one.
	 *
	 * @return the left child of this node or null if it doesn't have one.
	 */
	virtual NodeInterface * getLeftChild()
	{
		return left;
	}

	/*
	 * Returns the right child of this node or null if it doesn't have one.
	 *
	 * @return the right child of this node or null if it doesn't have one.
	 */
	virtual NodeInterface * getRightChild()
	{
		return right;
	}

	/*
	 * Returns the height of this node. The height is the number of edges
	 * from this node to this nodes farthest child.
	 */
	virtual int getHeight()
	{
		cout << "inside get height" << endl;

		if (getLeftChild() == NULL)
		{
			cout << "inside left NULL" << endl;
			Nleft = -1;
		}
		else
			if (getLeftChild() != NULL)
			{
				cout << "inside left no NULL" << endl;
				Nleft = getLeftChild()->getHeight();
			}



		if (getRightChild() == NULL)
		{
			cout << "inside right NULL" << endl;
			Nright = -1;
		}
		else
			if (getRightChild() != NULL)
			{
				cout << "inside right no NULL" << endl;
				Nright = getRightChild()->getHeight();
			}



		if (Nleft >= Nright)
		{
			balance = Nleft + 1;
		}
		else

			if (Nright > Nleft)
			{
				balance = Nright + 1;
			}

		return balance;

	}



	void setleft(Node* l)
	{
		left = l;
	}

	void setright(Node* r)
	{
		right = r;
	}

	void setup(Node* u)
	{
		up = u;
	}

	Node* getleft()
	{
		return left;
	}

	Node* getright()
	{
		return right;
	}

	Node* getup()
	{
		return up;
	}

	int getbalance()
	{
		int a = getHeight();
		return a;
	}



	int data;
	int balance;
	int Nleft;
	int Nright;
	Node* left;
	Node* right;
	Node* up;


};
