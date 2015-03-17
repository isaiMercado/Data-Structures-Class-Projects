/*
 * File:   QS.h
 * Author: misaie
 *
 * Created on June 9, 2014, 3:20 PM
 */

#ifndef QS_H
#define    QS_H

#include"QSInterface.h"
#include<iostream>
#include<sstream>

using namespace std;

class QS : public QSInterface
{
public:
	QS()
	{
		this->SIZE = 0;
		this->array = NULL;
		this->position = 0;
	}

	virtual ~QS()
	{
		clear();
	}

	/*
	 * sortAll()
	 *
	 * Sorts elements of the array.  After this method is called, every
	 * element in the array is less than or equal to the following element.
	 *
	 * Does nothing if the array is empty.
	 */
	virtual void sortAll()
	{
		cout << "In sortAll " << endl;
		recursion(0, SIZE - 1);
	}

	void recursion(int left, int right)
	{
		cout << " In recursion " << endl;
		cout << "Left: " << left << " Right: " << right << endl;

		if (left < right && left >= 0 && right <= SIZE)
		{

			int pivot = medianOfThree(left, right);
			cout << " Pivot is " << pivot << endl;
			int newpivot = partition(left, right, pivot);
			cout << "Newpivot is " << newpivot << endl;
			cout << "Next is the left side " << endl;
			recursion(left, newpivot - 1);
			cout << "Next is the right side " << endl;
			recursion(newpivot + 1, right);
		}
	}
	/*
	 * medianOfThree()
	 *
	 * Performs median-of-three pivot selection from among the values in
	 * the array between the two given indices. Median-of-three pivot
	 * selection will sort the first, middle, and last elements in a given
	 * array with respect to each other. After this method is called,
	 * data[first] <= data[middle] <= data[last], where middle =
	 * (first + last)/2.
	 *
	 * Returns -1 if the array is empty, if either of the given integers
	 * is out of bounds, or if the first integer is not less than the second
	 * integer.
	 *
	 * @param left
	 *         the left boundary for the subarray from which to find a pivot
	 * @param right
	 *         the right boundary for the subarray from which to find a pivot
	 * @return
	 *        the index of the pivot; -1 if provided with invalid input
	 */
	virtual int medianOfThree(int left, int right)
	{
		//cout << "In medianOfThree " << endl;
		//cout << "SIZE IS " << SIZE << endl;
		if (SIZE == 0) { return -1; }
		if (left < 0 || left >= SIZE) { return -1; }
		if (right < 0 || right >= SIZE) { return -1; }
		if (left >= right) { return -1; }
		int pivot;
		pivot = (left + right) / 2;
		return pivot;

	}


	void show(int left, int right)
	{
		for (left; left <= right; left++)
		{
			cout << array[left] << ",";
		}
		cout << endl;
	}
	/*
	 * Partitions a subarray around a pivot value selected according to
	 * median-of-three pivot selection.
	 *
	 * The values which are smaller than the pivot should be placed to the left
	 * of the pivot; the values which are larger than the pivot should be placed
	 * to the right of the pivot.
	 *
	 * Does nothing and returns -1 if the array is null, if either of the
	 * given integers is out of bounds, or if the first integer is not less than
	 * the second integer, or if the pivot is not between the two boundaries.
	 *
	 * @param left
	 *         the left boundary for the subarray to partition
	 * @param right
	 *         the right boundary for the subarray to partition
	 * @param pivotIndex
	 *         the index of the pivot in the subarray
	 * @return
	 *        the pivot's ending index after the partition completes; -1 if
	 *         provided with bad input
	 */
	virtual int partition(int left, int right, int pivotIndex)
	{

		//cout << "In partition " << endl;
		if (SIZE == 0) { return -1; }
		if (left < 0 || left >= SIZE) { return -1; }
		if (right < 0 || right >= SIZE) { return -1; }
		if (left >= right) { return -1; }
		if (pivotIndex < left || pivotIndex > right) { return -1; }
		int L = left;
		int G = left + 1;

		int pivot = array[pivotIndex];
		int temp = 0;
		bool next = false;


		//cout << " LEFT INDEX IS " << left << endl;
		//cout << " RIGHT INDEX IS " << right << endl;
		//cout << " PIVOT INDEX IS " << pivotIndex << endl;
		//cout << " LEFT IS " << array[left] << endl;
		//cout << " RIGHT IS " << array[right] << endl;
		//cout << " PIVOT IS " << array[pivotIndex] << endl;
		//show(left, right);


		if (pivotIndex != right) { temp = array[left]; array[left] = array[pivotIndex]; array[pivotIndex] = temp; pivotIndex = left; }

		//show(left, right);

		int i = left + 1;
		for (i; i <= right; i++)
		{
			if (array[i] < pivot)
			{
				temp = array[i];
				array[i] = array[G];
				array[G] = temp;
				if (G < SIZE - 1)
				{
					G = G + 1;
				}
				//show(left, right);
			}

		}

		temp = array[left];
		array[left] = array[G - 1];
		array[G - 1] = temp;
		pivotIndex = G - 1;

		//show(left, right);

		return pivotIndex;

		// int pivot = input[r];
		/*
			while ( i < j )
			{
			while ( array[i] < pivot )
			i++;

			while ( array[j] > pivot )
			j--;

			if ( array[i] == array[j] )
			i++;
			else if ( i < j )
			{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			}
			}

			return i; */

		/*  while(i != j)
		  {
		  cout << "pivot: " << pivotIndex << " i " << i << " j " << j << endl;
		  while(i != pivotIndex)
		  {
		  if (array[i] >= pivot){ break;}
		  i++;
		  }

		  while(j != pivotIndex)
		  {
		  if (array[j] <= pivot){ break;}
		  j--;
		  }
		  cout << array[i] << " " << pivot << " " << array[j] << endl;
		  temp = array[i];
		  array[i] = array[j];
		  array[j] = temp;
		  if (array[i] == pivot ) pivotIndex = i;
		  if (array[j] == pivot ) pivotIndex = j;
		  if (i != pivotIndex)i++;
		  if (j != pivotIndex)j--;
		  show(left,right);

		  }

		  return i;       */


		/*int c = 0;
	  for(c; last == false ; c++)
	  { //cout << "1" << endl;

	  if( c == 0)
	  {
	  cout << "inside pivot diferent array" << endl;
	  temp = array[pivotIndex];
	  array[pivotIndex] = array[right];
	  array[right] = temp; j--;
	  show(left,right);
	  }

	  for( i ; i != right ; i++)
	  {
	  cout << "i is: " << i << endl;
	  //if (i ==  right) { return i;}
	  if ( array[i] >= pivot)
	  {
	  break;
	  }
	  }

	  cout << array[i] << " IS GREATER THAN PIVOT " << pivot << endl;


	  for(j ; j != left; j--)
	  {
	  cout << "j is: " << j << endl;
	  if (array[j] <= pivot)
	  {
	  break;
	  }
	  }
	  if (i ==  left) { i = right;}
	  cout << array[j] << " IS SMALLER THAN PIVOT " << pivot << endl;

	  //if (array[i] < array[j])
	  //{
	  //return i;
	  //}


	  if(j<i)
	  {
	  temp = array[right];
	  array[right] = array[i];
	  array[i] = temp;
	  show(left,right);
	  return i;
	  }


	  temp = array[i];
	  array[i] = array[j];
	  array[j] = temp;
	  i++;
	  j--;
	  show(left,right);
	  //cout << "ij3  " << i << "   " << j<< endl;




	  }*/
		/*memory free
		 int c = 0;
		 for(c; last == false ; c++)
		 { //cout << "1" << endl;
		 //if( right == left+1)
		 //{
		 //  int greater = 0;
		 //   int g = 0 ;
		 //for( g; g < 2 ; g++)
		 //{
		 //if (greater < array[left + g])
		 //{
		 //greater = array[left + g];

		 //}
		 //}
		 //return left+g;
		 //


		 if( c == 0)
		 {
		 //cout << "inside pivot diferent array" << endl;
		 temp = array[pivotIndex];
		 array[pivotIndex] = array[right];
		 array[right] = temp; j--;
		 show(left,right);
		 }

		 for( i ; array[i] <= pivot ; i++){ if (i == right) {i = left; break;}}
		 cout << array[i] << " IS GREATER THAN PIVOT " << pivot << endl;
		 if (i == right){ last = true;}

		 for(j ;array[j] >= pivot ; j--){ if (j == left) {j = right; break;}}
		 cout << array[j] << " IS SMALLER THAN PIVOT " << pivot << endl;


		 if(j<i)
		 {
		 temp = array[right];
		 array[right] = array[i];
		 array[i] = temp; last = true;
		 show(left,right);
		 return i;
		 }

		 if(last == false)
		 {
		 temp = array[i];
		 array[i] = array[j];
		 array[j] = temp;
		 i++;
		 j--;
		 show(left,right);
		 //cout << "ij3  " << i << "   " << j<< endl;
		 }



		 }   */




		/*
						// working code were pivot moves around.
						while(i != j)
						{
						cout << "before i while" << endl;

						while ( array[i] <= pivot )
						{
						cout << " i while" << endl;
						if (array[i] == pivot) {break;}
						i++;
						}

						cout << array[i] << " IS GREATER THAN PIVOT " << pivot << endl;

						while (array[j] >= pivot)
						{
						cout << "j while" << endl;
						if (array[j] == pivot) {break;}
						j--;
						}

						cout << array[j] << " IS SMALLER THAN PIVOT " << pivot << endl;
						cout << "arriba i and j " << i << " " << j << endl;
						cout << getArray() << endl;
						cout << " array i and j " << array[i] << " " << array[j] << endl;
						if ( array[i] > array[j])
						{
						cout << "if   " << endl;
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
						cout << getArray() << endl;
						if (array[i] != pivot) {i++;}
						if (array[j] != pivot) {j--;}
						cout << " i and j " << i << " " << j << endl;
						}

						}*/

		/*int new_pivot;
		int b = 0;
		for(b ; b < SIZE ; b++)
		{
		if (pivot == array[b]) {  new_pivot = array[b]; break;}
		}

		cout << "b  " << b << endl;

		return b;
		//return 1;*/
	}
	/*
	 * Gets the array of values and puts them into a string. For example: if my array
	 * looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
	 * with no trailing comma.
	 *
	 * Does nothing and returns null, if the array is null or empty.
	 *
	 * @return
	 *        the string representation of the current array
	 */
	virtual string getArray()
	{
		//return "uu";
		//cout << "In getArray " << endl;
		stringstream all;
		//cout << "SIZE IS " << SIZE << endl;
		//cout << "position " << position << endl;
		for (int i = 0; i < position; i++)
		{
			//cout << i << ": " << array[i];
			all << array[i];
			if (i < position - 1)
			{
				//cout << endl;
				all << ",";
			}
		}
		string sarray = all.str();

		// cout << "srray " << sarray << endl;
		return sarray;
	}

	/*
	 * Gets the current size of the current array.
	 *
	 * @return
	 *         the current size
	 */
	virtual int getSize()
	{
		//cout << "In getSize " << endl;
		return SIZE;
	}

	/*
	 * Adds the given value to the array.
	 */
	virtual void addToArray(int value)
	{
		//cout << "In addToArray " << endl;
		//cout << "VALUE IS " << value << endl;
		//cout << "POSITION IS " << position << endl;
		if (SIZE > 0)
		{
			array[position] = value;
			//cout << " ARRAY[i] IS " << array[position] << endl;
			position++;
		}
	}

	/*
	 * Creates an array of with the given size.
	 *
	 * Returns false if the given value is non-positive, true otherwise.
	 *
	 * @param
	 *        size of array
	 * @return
	 *        true if the array was created, false otherwise
	 */
	virtual bool createArray(int size)
	{
		//cout << "In createArray " << endl;
		//cout << " SIZE IS " << size << endl;
		if (size <= 0) { return false; }
		if (size > 0)
		{
			//cout << " INSIDE IF " << endl;
			SIZE = size;
			array = new int[SIZE];
			position = 0;
			return true;
		}
		//return true;
	}

	/*
	 * Clears the array.
	 */
	virtual void clear()
	{
		//cout << "In clear " << endl;
		delete[] array;
		array = NULL;
		SIZE = 0;
		position = 0;
	}

protected:

	int SIZE;
	int* array;
	int position;


};


#endif    /* QS_H */
