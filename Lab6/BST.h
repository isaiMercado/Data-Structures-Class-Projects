/*
 * File:   BST.h
 * Author: misaie
 *
 * Created on May 22, 2014, 8:40 AM
 */

#ifndef BST_H
#define	BST_H

#include "Node.h"
#include "BSTInterface.h"

using namespace std;

class BST : public BSTInterface
{
public:

	BST()
	{
		root = NULL;
	}

	virtual ~BST()
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
		if (root != NULL)
		{
			//cout << "In getRootNode ,and root is " << root->getData() << endl; 
			return root;
		}
		if (root == NULL)
		{
			//cout << "In getRootNode ,and root is NULL" << endl;
			return root;
		}

	}

	/*
	 * Attempts to add the given int to the BST tree
	 *
	 * @return true if added
	 * @return false if unsuccessful (i.e. the int is already in tree)
	 */
	virtual bool add(int data)
	{
		//cout << "In add " << endl;
		bool rep = repetition(data, root);
		if (rep == true) { return false; }
		//cout << "repetition sent false " << endl;
		bool add = adding(data, root);
		if (add == true) { return true; }
		return false;
	}

	/*
	 * Attempts to remove the given int from the BST tree
	 *
	 * @return true if successfully removed
	 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
	 */
	virtual bool remove(int data)
	{
		//cout << "In remove " << endl;

		//cout << "removing data " << data << endl;

		Node* found = finding(data, root);

		if (found == NULL) { return false; }

		//cout << "in remove, found is " << found->getData() << endl;         

		Node* pre = findPredecessor(data, found, found);

		//cout << "predecessor is " << pre->getData() << endl;

		//cout << "root is " << root->getData() << endl;



		if (root->getleft() == NULL && root->getright() == NULL) //1 node involved 'root'
		{
			//cout << "inside 1 node 'root'" << endl;
			root->setup(NULL);
			root->setleft(NULL);
			root->setright(NULL);

			delete found;
			root = NULL;
			return true;


		}



		if (found->getleft() == NULL && found->getright() == NULL) //2 nodes involved 'leaf'
		{
			//cout << "2 nodes involved 'leaf'" << endl;

			// remove link of pre' parent which is found's parent

			if (found->getup() != NULL)
			{
				// cout << "parent is " << found->getup()->getData() << endl;
				if (found->getup()->getleft() != NULL)
				{
					//cout << "parent's left is " << found->getup()->getleft()->getData() << endl;
					if (found->getup()->getleft()->getData() == found->getData())
					{
						// cout << "inside left" << endl;
						found->getup()->setleft(NULL);
						// cout << "inside left 'end'" << endl;
					}
				}
			}

			if (found->getup() != NULL)
			{
				//cout << "parent is " << found->getup()->getData() << endl;
				if (found->getup()->getright() != NULL)
				{
					//cout << "parent's right is " << found->getup()->getright()->getData() << endl;
					if (found->getup()->getright()->getData() == found->getData())
					{
						//cout << "inside right" << endl;
						found->getup()->setright(NULL);
					}
				}
			}


			//cout << "2 nodes involved 'leaf' 2" << endl;
			found->setup(NULL);
			found->setleft(NULL);
			//cout << "2 nodes involved 'leaf' 3" << endl;          
			found->setright(NULL);
			//cout << "2 nodes involved 'leaf' 4" << endl;           

			//cout << "2 nodes involved 'leaf' 5" << endl;            
			delete found;
			found = NULL;
			//cout << "2 nodes involved 'leaf' 6" << endl;         
			return true;
		}



		if (found->getright() != NULL && found->getleft() == NULL) //3 nodes involved 
		{
			//cout << "inside 3 node 'stick'" << endl;

			if (found->getup() != NULL)
			{
				//cout << "found's up is " << found->getup()->getData() << endl;
			}


			if (found->getleft() != NULL)
			{
				// cout << "found's left is " << found->getleft()->getData() << endl;
			}


			if (found->getright() != NULL)
			{
				//cout << "found's right is " << found->getright()->getData() << endl;
			}


			if (found != NULL)
			{
				//cout << "found is " << found->getData() << endl;
			}



			if (found == root)
			{
				if (found->getleft() == NULL)
				{
					root = found->getright();
					found->getright()->setup(NULL);
					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;
					return true;

				}
				if (found->getright() == NULL)
				{
					root = found->getleft();
					found->getleft()->setup(NULL);
					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;
					return true;
				}
			}

			if (found->getup()->getleft() == found)
			{
				if (found->getleft() == NULL && found->getright() != NULL)
				{
					found->getup()->setleft(found->getright());
					found->getright()->setup(found->getup());
					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;
					return true;

				}
				if (found->getleft() != NULL && found->getright() == NULL)
				{
					found->getup()->setleft(found->getleft());
					found->getleft()->setup(found->getup());
					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;
					return true;
				}
			}
			if (found->getup()->getright() == found)
			{
				if (found->getleft() == NULL && found->getright() != NULL)
				{
					found->getup()->setright(found->getright());
					found->getright()->setup(found->getup());
					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;
					return true;
				}
				if (found->getleft() != NULL && found->getright() == NULL)
				{
					found->getup()->setright(found->getleft());
					found->getleft()->setup(found->getup());
					found->setup(NULL);
					found->setleft(NULL);
					found->setright(NULL);

					delete found;
					found = NULL;
					return true;
				}

			}

		}



		if (found->getleft() == pre) //4 nodes involved
		{
			//cout << "inside 4 node 'pre is found's left child'" << endl;

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
			return true;



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
			//cout << "in 5 nodes 'pre does not have children'" << endl;

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
			return true;





			/*
		   cout << "inside 5 node " << endl;

		   pre->getup->setleft(NULL);

		   if (found->getup() != NULL) {found->getup()->setright(pre); cout << "After 1" << endl;}

		   if (pre->getright() != NULL && found->getright() != NULL) {pre->setright(found->getright()); cout << "After 2" << endl;}

		   if (pre->getright() != NULL ) found->getright()->setup(pre); cout << "After 3" << endl;

		   if (found->getright() != NULL)
		   {

		   pre->getup()->setleft(NULL); cout << "After 4" << endl;

		   pre->setup(found->getup()); cout << "After 5" << endl;

		   }

		   delete found;  cout << "After 6" << endl;

		   found = NULL;  cout << "After 7" << endl;

		   if ( pre == root ) {root = pre;}

		   return true;
		   */
		}



		if (pre->getleft() != NULL) //6 nodes involved
		{
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
				return true;

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
					return true;
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
					return true;

				}


			}
			/*
		   cout << "inside 6 node 'pre has a left child'" << endl;

		   pre->getup()->setright(pre->getright()); //cout << "after  " << endl;

		   pre->getleft()->setup(pre->getup());// cout << "inside 6 node " << endl;

		   found->getup()->setright(pre); //cout << "inside 6 node " << endl;

		   pre->setright(found->getright()); //cout << "inside 6 node " << endl;

		   if (found->getright() != NULL)
		   {

		   found->getright()->setup(pre); //cout << "inside 6 node " << endl;

		   pre->getup()->setleft(NULL); //cout << "inside 6 node " << endl;

		   pre->setup(found->getup()); //cout << "inside 6 node " << endl;

		   }

		   delete found;  //cout << "inside 6 node " << endl;

		   found = NULL;  //cout << "inside 6 node " << endl;

		   return true; */
		}


	}

	/*
	 * Removes all nodes from the tree, resulting in an empty tree.
	 */
	virtual void clear()
	{

		//cout << "In clear" << endl;
		if (root != NULL)
		{
			//cout << "root is " << root->getData() << " in clear " << endl;
			erasing(root);
		}
		if (root == NULL)
		{
			//cout << "root is null in clear " << endl;
		}
		//cout << "Out of clear" << endl;

	}

	bool repetition(int data, Node* temp)
	{
		//cout << "In repetition" << endl;
		//cout << "data is " << data << endl;

		if (root == NULL)
		{
			//cout << "return false" << endl; 
			return false;
		}

		if (temp != NULL)
		{
			//cout << "node is " << temp->getData() << endl;
		}

		bool rep;
		//cout << "passed if " << endl;
		if (temp->getleft() != NULL) { rep = repetition(data, temp->getleft()); }
		else
			if (data == temp->getData())
			{
				//cout << "true repetition was found for " << temp->getData() << endl;
				return true;
			}
			else
				if (temp->getright() != NULL) { rep = repetition(data, temp->getright()); }
		return false;
	}

	bool adding(int data, Node* temp)
	{
		//cout << "In adding and data is " << data << endl;

		if (temp == NULL)
		{
			root = new Node(data);
			// cout << "*****root was inserted " << root->getData() << endl; 
			return true;
		}

		bool add;

		if (data < temp->getData() && temp->getleft() != NULL)
		{
			//cout << "recorsioning to left" << endl; 
			add = adding(data, temp->getleft());
		}
		else


			if (data > temp->getData() && temp->getright() != NULL)
			{
				//cout << "recorsioning to right" << endl;
				add = adding(data, temp->getright());
			}
			else


				if (data < temp->getData())
				{
					Node* newNode = new Node(data);
					temp->setleft(newNode);
					newNode->setup(temp);
					//cout << "*****this " << newNode->getData() << " was inserted  on left of " << temp->getData() << endl; 
					return true;
				}
				else


					if (data > temp->getData())
					{
						Node* newNode = new Node(data);
						temp->setright(newNode);
						newNode->setup(temp);
						//cout << "*****this " << newNode->getData() << " was inserted  on right of " << temp->getData() << endl;
						return true;
					}

	}

	Node* finding(int data, Node* move)
	{

		//cout << "In finding" << endl;

		Node* found = NULL;

		if (move != NULL)
		{
			if (data == move->getData() && found == NULL)
			{
				//cout << "this is node found " << move->getData() << endl; 
				return move;
			}

			if (move->getleft() != NULL && found == NULL)
			{
				//cout << "In finding going left " << endl;
				found = finding(data, move->getleft());
			}

			if (move->getright() != NULL && found == NULL)
			{
				//cout << "In finding going right " << endl; 
				found = finding(data, move->getright());
			}

			return found;
		}

		if (move == NULL)
		{
			return NULL;
		}


		/* OLD CODE "WORKING JUST CHANGED BECAUSE IT WAS UGLY"
	   cout << "In finding" << endl;
	   if (temp == NULL) { return NULL;}
	   else
	   if ( temp->getleft() != NULL) { temp = finding(data, temp->getleft()); }
	   else
	   if ( data == temp->getData()) { cout << "this is node found " << temp->getData() << endl; return temp;}
	   else
	   if ( temp->getright() != NULL) { temp = finding(data, temp->getright());}
	   */
	}

	Node* findPredecessor(int data, Node* found, Node* next)
	{
		//cout << "In findPredecessor" << endl;

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

	void erasing(Node* move)
	{

		if (move != NULL)
		{
			//cout << "move is " << move->getData() << endl;

			if (move->getleft() != NULL) { erasing(move->getleft()); }

			if (move->getright() != NULL) { erasing(move->getright()); }

			//cout << "************deleted " << move->getData() << endl; 

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

		//OLD CODE 1

		// if (move->getup() != NULL) { cout << "moved up " << endl; erase = erasing(begin, move->getup()); }

		//if (move->getright() == NULL ) { cout << "**********deleted " << move->getData() << endl; delete move; move = NULL; return true;}

		// if (move->getleft() == NULL ) { cout << "************deleted " << move->getData() << endl; delete move; move = NULL; return true;}


		/*
		if ( root->getleft() == NULL && root->getright() == NULL )
		{
		cout << "root was erased " << move->getData() << endl;
		//move = NULL;
		delete move;
		move = NULL;

		}
		else
		{
		cout << "this was erased " << move->getData() << endl;
		//move = NULL;
		delete move;
		move = NULL;

		erasing(begin, prev, prev);
		}*/


		//OLD CODE 2 
		/*   cout << " before if " << endl;

		 if(move != NULL)
		 {
		 cout << "In erasing " << track << " times" << endl;

		 track++;

		 erasing(move->getleft());

		 erasing(move->getright());

		 cout << "deleting " << move->getData() << endl;

		 delete(move);

		 if(move->getleft() != NULL) {move->setleft(NULL);}

		 if(move->getright() != NULL) {move->setright(NULL);}

		 root=NULL;
		 }

		 cout << "In erasing when the node is NULL " << endl;
		 */








	}
private:
	Node* root;
	int track;
};
#endif	/* BST_H */

