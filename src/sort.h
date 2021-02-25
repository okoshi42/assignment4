//
//  sort.h
//  
//  Functions for bubble sort, selection sort, and insertion sort.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef sort_hpp
#define sort_hpp

#include <algorithm> // for swap()

using namespace std;

namespace csi281 {
    
    // Performs an in-place ascending sort of *array* of size *length*
    // using the bubble sort algorithm
    template <typename T>
    void bubbleSort(T array[], const int length) {
        // YOUR CODE HERE
        for (int x = 0; x < length - 1; x++)//shrinks search area by one each iteration
        {
            for (int y = 0; y < (length - x - 1); y++)//at each index y, compares against the index directly after y
                if (array[y] > array[y + 1]) //swaps if index y is greater than index y+1
                    swap(array[y], array[y + 1]);
        }

    }
    
    // Performs an in-place ascending sort of *array* of size *length*
    // using the selection sort algorithm
    template <typename T>
    void selectionSort(T array[], const int length) {
       
        // YOUR CODE HERE
        for (int x = 0; x < length - 1; x++)//pushes the swapping index up by one each iteration
        {
            int minVal = x; //index of lowest value, initialized at x;
            for (int y = x + 1; y < length; y++) {//at each index after x, compares current index against minVal
                if (array[y] < array[minVal])//updates minVal if current index is less than minVal
                    minVal = y;
            }
            swap(array[minVal], array[x]);//swaps x with the lowest value found in the unsorted section of the array
        }
    }
    
    // Performs an in-place ascending sort of *array* of size *length*
    // using the insertion sort algorithm
    template <typename T>
    void insertionSort(T array[], const int length) {
        // YOUR CODE HERE
        for (int x = 1; x < length; x++) {
            T targetVal = array[x]; //value to be compared against, initialized at index x
            //checks every value left of x
            int y = x - 1; 

            // 1 4 2 5 3
            while (y >= 0 && array[y] > targetVal) { //if the current index is larger than targetVal, the loop breaks
                //shifts each value to the right by one
                array[y + 1] = array[y]; 
                y--;
            }
            //inserts targetVal into index left of the last index shifted
            array[y + 1] = targetVal;
        }
    }
}


#endif /* sort_hpp */
