/**
 * @file        queue.cpp
 * @description Implementation of the Queue class.
 *
 *              SUBMIT THIS FILE WITH YOUR MODIFICATIONS
 */

/**
 * Adds the parameter object to the back of the Queue.
 *
 * NOTE: This fuction should have O(1) behavior over n operations!
 *
 * @param item - object to be added to the Queue.
 */
template <class T>
void Queue<T>::Enqueue(T const& item)
{
	// complete your implementation below

	// push items onto stack_1
	stack_1.Push(item);

}

/**
 * Removes the object at the front of the Queue, and returns it to
 * the caller. You may assume that this function is only called
 * when the Queue is non-empty.
 *
 * NOTE: This function should have O(1) behavior over n operations!
 *
 * @return the item that used to be at the front of the Queue.
 */
template <class T>
T Queue<T>::Dequeue()
{
	// complete your implementation below

	// if stack_2 is empty, need to put items from stack_1 to stack_2 to reverse order
	if (stack_2.IsEmpty()) {
		while (!stack_1.IsEmpty()) {
			stack_2.Push(stack_1.Pop());
		}
	}
	// here, either stack_2 was not empty or we have reversed items in stack_1 onto stack_2
	T item = stack_2.Pop();
	return item;

	// T item = stack_2.Pop();
}

/**
 * Adds an element to the ordering structure.
 *
 * See OrderingStructure::Add()
 */
template <class T>
void Queue<T>::Add(const T& item)
{
	// complete your implementation below
	// Hint: this function should call a Queue
	//  function to add the element to the Queue.

	Enqueue(item);

}

/*
*  Removes an element from the ordering structure.
*
*  See OrderingStructure::Remove()
*/
template <class T>
T Queue<T>::Remove()
{
	// complete your implementation below
	// Hint: this function should call a Queue
	// function to remove an element from the Queue and return it. You will
	// need to replace the following lines.
  
	T item = Dequeue();
	return item;
}

/*
*  Finds the object at the front of the Queue, and returns it to
*  the caller. Unlike Dequeue(), this operation does (conceptually!) not alter the
*  Queue; however, you may need to alter the internal representation of the Queue.
*  You may assume that this function is only called when the
*  Queue is non-empty.
*
*  NOTE: This function should have O(1) behavior over n operations!
*
*  @return the item at the front of the queue.
*/
template <class T>
T Queue<T>::Peek()
{
	// complete your implementation below

	if (stack_2.IsEmpty()) {
		while (!stack_1.IsEmpty()) {
			stack_2.Push(stack_1.Pop());
		}
	}
  
	T item = stack_2.Peek();
	return item;
}

/*
*  Determines if the Queue is empty.
*
*  @return true if the stack is empty,
*          false otherwise.
* 
*  NOTE: This function must always run in O(1) time!
*/
template <class T>
bool Queue<T>::IsEmpty() const
{
	// complete your implementation below

	if (stack_1.IsEmpty() and stack_2.IsEmpty()) {
		return true;
	}
  
	return false; // REPLACE THIS STUB
}
