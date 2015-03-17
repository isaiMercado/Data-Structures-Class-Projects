/*
 * File:   Node.h
 * Author: misaie
 *
 * Created on May 22, 2014, 8:40 AM
 */

#ifndef NODE_H
#define	NODE_H

#include"NodeInterface.h"

using namespace std;

class Node : public NodeInterface
{

public:

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
		up = NULL;
	}

	~Node()
	{
		data = NULL;
		left = NULL;
		right = NULL;
		up = NULL;
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

private:

	int data;
	Node* left;
	Node* right;
	Node* up;


};



#endif	/* NODE_H */

