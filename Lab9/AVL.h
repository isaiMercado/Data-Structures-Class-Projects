#include "NodeInterface.h"
#include "AVLInterface.h"
#include "Node.h"

using namespace std;

class AVL : public AVLInterface
{
public:
	AVL()
	{
		root = NULL;
	}

	~AVL()
	{
		clear();
	}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	 * Returns the root node for this tree
	 *
	 * @return the root node for this tree.
	 */
	virtual NodeInterface * getRootNode()
	{
		return root;
	}

	/*
	 * Attempts to add the given int to the AVL tree
	 * Rebalances the tree if data is successfully added
	 *
	 * @return true if added
	 * @return false if unsuccessful (i.e. the int is already in tree)
	 */
	virtual bool add(int data)
	{
		cout << "in add" << endl;

		bool rep = repetition(data, root);

		cout << "rep is " << rep << endl;

		if (rep == true)

		{

			cout << "repetition was found " << endl;

			return false;

		}

		if (rep == false)

		{

			cout << "repetition was not found " << endl;

			root = insert(root, data);

			return true;

		}

	}



	virtual bool remove(int data)
	{
		cout << "in remove" << endl;

		bool rep = repetition(data, root);

		cout << "rep is " << rep << endl;

		if (rep == true)

		{

			cout << "repetition was found " << endl;

			root = removing(root, data);

			return true;

		}

		if (rep == false)

		{

			cout << "repetition was not found " << endl;

			return false;

		}

	}



	Node* removing(Node *new_node, int data)

	{
		cout << "in removing" << endl;

		if (new_node != NULL) cout << " node is " << new_node->data << endl;

		if (new_node->up != NULL) cout << " node up is " << new_node->up->data << endl;

		if (data == new_node->getData())

		{

			new_node = removed(data);

			if (new_node != NULL)

				new_node = balance(new_node);

		}

		else if (data < new_node->getData())

		{

			Node* left = removing(new_node->getleft(), data);

			//new_node->setleft(left);

			if (new_node != NULL)///

				new_node = balance(new_node);//

		}

		else if (data >= new_node->getData())

		{

			Node* right = removing(new_node->getright(), data);

			//new_node->setright(right);

			if (new_node != NULL)

				new_node = balance(new_node);

		}

		return new_node;

	}


	Node* removed(int data)
	{
		cout << "In removed " << endl;

		cout << "removing data " << data << endl;

		Node* found = finding(data, root);

		if (found == NULL) { return NULL; }

		cout << "in remove, found is " << found->getData() << endl;

		Node* pre = findPredecessor(data, found, found);

		cout << "predecessor is " << pre->getData() << endl;

		cout << "root is " << root->getData() << endl;




		if (root->getleft() == NULL && root->getright() == NULL) //1 node involved 'root'
		{
			cout << "inside 1 node 'root'" << endl;
			root->setup(NULL);
			root->setleft(NULL);
			root->setright(NULL);

			delete found;
			root = NULL;
			return NULL;


		}



		if (found->getleft() == NULL && found->getright() == NULL) //2 nodes involved 'leaf'
		{
			cout << "2 nodes involved 'leaf'" << endl;

			if (found == found->getup()->getleft())

			{

				Node* temporal = found->up;

				found->setup(NULL);
				found->setleft(NULL);
				found->setright(NULL);

				delete found;
				found = NULL;

				temporal->left = NULL;

				cout << "2 nodes involved returning" << endl;
				cout << "temporal is " << temporal->getData() << endl;
				return temporal;
			}

			if (found == found->getup()->getright())

			{

				Node* temporal = found->up;

				found->setup(NULL);
				found->setleft(NULL);
				found->setright(NULL);

				delete found;
				found = NULL;

				temporal->right = NULL;

				cout << "2 nodes involved returning" << endl;
				cout << "temporal is " << temporal->getData() << endl;
				return temporal;
			}

		}



		if (found->getright() != NULL && found->getleft() == NULL) //3 nodes involved
		{
			cout << "inside 3 node 'stick'" << endl;

			cout << "root " << root->getData() << endl;

			cout << "found " << found->getData() << endl;


			if (found == root)
			{
				if (found->getleft() == NULL)
				{
					cout << "quadrant 1" << endl;

					root = found->getright();
					found->getright()->setup(NULL);

					Node* temporal = found->getright();

					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;

					temporal->left = NULL;

					cout << "temporal is " << temporal->getData() << endl;

					return temporal;

				}
				if (found->getright() == NULL)
				{
					cout << "quadrant 2 " << endl;

					root = found->getleft();
					found->getleft()->setup(NULL);

					Node* temporal = found->getleft();

					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;

					temporal->right = NULL;

					cout << "temporal is " << temporal->getData() << endl;

					return temporal;
				}
			}

			if (found->getup()->getleft() == found)
			{
				if (found->getleft() == NULL && found->getright() != NULL)
				{
					cout << "quadrant 3" << endl;

					found->getup()->setleft(found->getright());
					found->getright()->setup(found->getup());

					Node* temporal = found->getright();

					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;

					temporal->left = NULL;

					cout << "temporal is " << temporal->getData() << endl;

					return temporal;

				}
				if (found->getleft() != NULL && found->getright() == NULL)
				{
					cout << "quadrant 4" << endl;

					found->getup()->setleft(found->getleft());
					found->getleft()->setup(found->getup());

					Node* temporal = found->getleft();

					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;

					temporal->right = NULL;

					cout << "temporal is " << temporal->getData() << endl;

					return temporal;
				}
			}
			if (found->getup()->getright() == found)
			{
				if (found->getleft() == NULL && found->getright() != NULL)
				{
					cout << "quadrant 5" << endl;

					found->getup()->setright(found->getright());
					found->getright()->setup(found->getup());

					Node* temporal = found->getright();

					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;

					temporal->left = NULL;

					cout << "temporal is " << temporal->getData() << endl;

					return temporal;
				}
				if (found->getleft() != NULL && found->getright() == NULL)
				{
					cout << "quadrant 6" << endl;

					found->getup()->setright(found->getleft());
					found->getleft()->setup(found->getup());

					Node* temporal = found->getleft();

					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;

					temporal->right = NULL;

					cout << "temporal is " << temporal->getData() << endl;

					return temporal;
				}

			}

		}
		//////////////////////////////////aqui me quede con temporal////////////////////////////////////


		if (found->getleft() == pre) //4 nodes involved
		{
			cout << "inside 4 node 'pre is found's left child'" << endl;

			//removing link of pre's parent
			pre->getup()->setleft(NULL); // setting pre's parent's left to NULL

			//Coping links of found into pre--except left
			pre->setright(found->getright()); // found's right copied into pre
			pre->setup(found->getup()); // found's up copied into pre

			//Putting links of nodes around found into pre--except left
			if (found->getright() != NULL)
			{
				//cout << "in 4 nodes 6" << endl;
				found->getright()->setup(pre); // the node on the right of found is set pre as parent
			}

			if (found->getup() != NULL)
			{
				//cout << "in 4 nodes 7" << endl;
				if (found->getup()->getright() == found) { found->getup()->setright(pre); } // the node on the up of found is set pre as right
				if (found->getup()->getleft() == found) { found->getup()->setleft(pre); } // the node on the up of found is set pre as left
			}

			if (root == found) { root = pre; } // setting pre as root

			//cout << "in 4 nodes 8" << endl;
			found->setleft(NULL);
			//cout << "in 4 nodes 9" << endl;
			found->setright(NULL);
			//cout << "in 4 nodes 10" << endl;

			//cout << "in 4 nodes 11" << endl;
			delete found;
			found = NULL;
			//cout << "in 4 nodes 12" << endl;
			return NULL;



			/*
			found->getup()->setright(found->getleft());

			found->getleft()->setright(found->getright());

			if (found->getright() != NULL)
			{
			found->getright()->setup(found->getleft());

			found->getleft()->setup(found->getup());

			}

			delete found;

			found = NULL;

			return true;*/
		}



		if (pre->getleft() == NULL) //5 nodes involved
		{
			cout << "in 5 nodes 'pre does not have children'" << endl;

			pre->getup()->setright(NULL); // the link of pre's parent is broken
			//cout << "in 5 nodes 1" << endl;
			pre->setleft(found->getleft()); // found left is copied to pre
			//cout << "in 5 nodes 2" << endl;
			pre->setright(found->getright()); // found's right is copied into pre
			// cout << "in 5 nodes 3" << endl;
			pre->setup(found->getup()); // found's up is copied into pre
			//cout << "in 5 nodes 4" << endl;
			if (found->getleft() != NULL)
			{
				//cout << "in 5 nodes 5" << endl;
				found->getleft()->setup(pre); // the node on the left of found is set pre as parent
			}

			if (found->getright() != NULL)
			{
				//cout << "in 5 nodes 6" << endl;
				found->getright()->setup(pre); // the node on the right of found is set pre as parent
			}

			if (found->getup() != NULL)
			{
				//cout << "in 5 nodes 7" << endl;
				if (found->getup()->getright() == found) { found->getup()->setright(pre); } // the node on the up of found is set pre as right
				if (found->getup()->getleft() == found) { found->getup()->setleft(pre); } // the node on the up of found is set pre as left
			}

			if (root == found) { root = pre; } // setting pre as root

			//cout << "in 5 nodes 8" << endl;
			found->setleft(NULL);
			//cout << "in 5 nodes 9" << endl;
			found->setright(NULL);
			//cout << "in 5 nodes 10" << endl;

			//cout << "in 5 nodes 11" << endl;
			delete found;
			found = NULL;
			//cout << "in 5 nodes 12" << endl;
			return NULL;



		}



		if (pre->getleft() != NULL) //6 nodes involved
		{
			cout << "inside 6 nodes" << endl;
			if (found == root)
			{
				pre->getup()->setright(pre->getleft());
				pre->getleft()->setup(pre->getup());


				pre->setleft(found->getleft());
				pre->setright(found->getright());
				pre->setup(found->getup());


				found->getleft()->setup(pre);
				found->getright()->setup(pre);

				root = pre;

				found->setleft(NULL);
				found->setright(NULL);

				delete found;
				found = NULL;
				return NULL;

			}



			if (found != root)
			{
				if (found->getup()->getleft() == found)
				{
					pre->getup()->setright(pre->getleft());
					pre->getleft()->setup(pre->getup());


					pre->setleft(found->getleft());
					pre->setright(found->getright());
					pre->setup(found->getup());


					found->getleft()->setup(pre);
					found->getright()->setup(pre);
					found->getup()->setleft(pre);


					found->setleft(NULL);
					found->setright(NULL);
					found->setup(NULL);

					delete found;
					found = NULL;
					return NULL;
				}



				if (found->getup()->getright() == found)
				{
					pre->getup()->setright(pre->getleft());
					pre->getleft()->setup(pre->getup());


					pre->setleft(found->getleft());
					pre->setright(found->getright());
					pre->setup(found->getup());


					found->getleft()->setup(pre);
					found->getright()->setup(pre);
					found->getup()->setright(pre);


					found->setleft(NULL);
					found->setright(NULL);
					found->setup(NULL);

					delete found;
					found = NULL;
					return NULL;

				}


			}

		}


	}


	int level(Node* temp)

	{
		cout << "in level " << endl;
		//cout << "temp is " << temp->getData() << endl;

		int t_height = 0;

		if (temp != NULL)

		{

			int l_height = level(temp->left); cout << "in level 1" << endl;

			int r_height = level(temp->right); cout << "in level 2" << endl;

			int max_height = max(l_height, r_height); cout << "in level 3" << endl;

			t_height = max_height + 1; cout << "in level 4" << endl;

			cout << "Node is " << temp->getData() << " its height is " << t_height << endl;

		}



		return t_height;

	}



	int difference(Node *temp)
	{
		cout << "in difference " << endl;

		int l_height = level(temp->left);

		int r_height = level(temp->right);

		int factor = l_height - r_height;

		return factor;

	}


	Node* balance(Node* temp)

	{
		cout << "in balance" << endl;

		int first_factor = difference(temp);

		cout << " first factor is " << first_factor << endl;

		if (first_factor > 1)
		{
			int second_factor = difference(temp->getleft());

			cout << " second factor is " << second_factor << endl;

			if (second_factor > 0)

				temp = ll_rotation(temp);

			else

				temp = lr_rotation(temp);

		}

		else if (first_factor < -1)

		{
			int second_factor = difference(temp->getright());

			cout << " second factor is " << second_factor << endl;

			if (second_factor > 0)

				temp = rl_rotation(temp);

			else

				temp = rr_rotation(temp);

		}

		return temp;

	}



	Node* insert(Node *new_node, int data)

	{
		cout << "in insert " << endl;

		if (new_node == NULL)

		{

			new_node = new Node(data);

		}

		else if (data < new_node->getData())

		{

			Node* left = insert(new_node->getleft(), data);

			new_node->setleft(left);

			left->setup(new_node); /////

			cout << "left is " << left->getData() << endl;

			cout << "up is " << left->getup()->getData() << endl;

			new_node = balance(new_node);

		}

		else if (data >= new_node->getData())

		{

			Node* right = insert(new_node->getright(), data);

			new_node->setright(right);

			right->setup(new_node); /////

			cout << "left is " << right->getData() << endl;

			cout << "up is " << right->getup()->getData() << endl;

			new_node = balance(new_node);

		}

		return new_node;

	}


	Node* rr_rotation(Node* parent)

	{
		cout << "in rr rotation " << endl;

		Node* temp;

		Node* up;/////

		temp = parent->right; cout << "in rr rotation 1" << endl;

		up = parent->up; cout << "in rr rotation 3" << endl; /////

		parent->right = temp->left;

		temp->left = parent;

		temp->left->up = parent; cout << "in rr rotation 4" << endl; /////

		parent->up = temp; cout << "in rr rotation 5" << endl; //////

		temp->up = up; cout << "in rr rotation 6" << endl;//////

		return temp;

	}

	/*

	 * Left- Left Rotation

	 */

	Node* ll_rotation(Node* parent)

	{
		cout << "in ll rotation " << endl;

		Node* temp;

		Node* up;/////

		temp = parent->left;

		up = parent->up;//////

		parent->left = temp->right;

		temp->right = parent;

		temp->right->setup(parent);//////

		parent->setup(temp);//////

		temp->setup(up);/////

		return temp;

	}



	/*

	 * Left - Right Rotation

	 */

	Node* lr_rotation(Node* parent)

	{

		cout << "in lr rotation " << endl;

		Node* temp;

		temp = parent->left;

		parent->left = rr_rotation(temp);

		return ll_rotation(parent);

	}



	/*

	 * Right- Left Rotation

	 */

	Node* rl_rotation(Node* parent)

	{

		cout << "in rl rotation " << endl;

		Node* temp;

		temp = parent->right;

		parent->right = ll_rotation(temp);

		return rr_rotation(parent);

	}



	Node* finding(int data, Node* move)
	{
		cout << "in finding " << endl;
		Node* found = NULL;

		if (move != NULL)
		{
			if (data == move->getData() && found == NULL)
			{
				return move;
			}

			if (move->getleft() != NULL && found == NULL)
			{
				found = finding(data, move->getleft());
			}

			if (move->getright() != NULL && found == NULL)
			{
				found = finding(data, move->getright());
			}

			return found;
		}
		else


			if (move == NULL)
			{
				return NULL;
			}
	}


	Node* findPredecessor(int data, Node* found, Node* next)
	{
		cout << "In findPredecessor" << endl;

		if (found != NULL)
		{
			//cout << "In findPredecessor If != NULL" << endl;
			if (found == next && next->getleft() != NULL)
			{
				//cout << "In findPredecessor go left" << endl;
				next = findPredecessor(data, found, next->getleft());
			}
			else


				if (found != next && next->getright() != NULL)
				{
					//cout << "In findPredecessor go right" << endl;
					next = findPredecessor(data, found, next->getright());
				}
				else


					if (next->getright() == NULL)
					{
						//cout << "In findPredecessor return" << endl;
						return next;
					}
			//cout << "In findPredecessor return next from prev func calls" << endl;
			return next;
		}
		else
			if (found == NULL)
			{
				return NULL;
			}

	}


	void clear()
	{
		if (root != NULL)
		{
			erasing(root);
		}
	}

	void erasing(Node* move)
	{
		cout << "in erasing" << endl;
		if (move != NULL)
		{

			if (move->getleft() != NULL) { erasing(move->getleft()); }

			if (move->getright() != NULL) { erasing(move->getright()); }

			move->setright(NULL);
			move->setleft(NULL);
			move->setup(NULL);

			delete move;
			move = NULL;

		}

		if (move == NULL)
		{
			root = NULL;
		}

	}



	bool repetition(int data, Node* temp)
	{
		cout << "in repetition" << endl;

		bool rep = false;

		if (root != NULL)
		{

			if (temp->getleft() != NULL && rep != true)

			{
				rep = repetition(data, temp->getleft());

			}

			if (data == temp->getData() && rep != true)

			{

				cout << "data is " << data << " and temp is " << temp->getData() << endl;

				return true;

			}

			if (temp->getright() != NULL && rep != true)

			{

				rep = repetition(data, temp->getright());

			}

			//cout << "repetition bool is " << rep << endl;

			return rep;

		}

	}


	Node* root;
};
