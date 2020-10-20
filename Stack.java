/*
 * Data Structures and Algorithms.
 * Copyright (C) 2016 Rafael Guterres Jeffman
 *
 * See the LICENSE file accompanying this source code, for
 * licensing restrictions that might apply.
 *
 */

package datastructures;

import java.util.EmptyStackException;

/**
 * Implements a LIFO protocol for data.
 */
public class Stack<T> {
	private Vector<T> data = new Vector<>();

	/**
	 * Add a new value to the stack.
	 * @param value The value to be on the top of the stack.
	 */
	public void push(T value) {
		this.data.append(value);
	}
	
	/**
	 * Remove the element on the top of the stack, returning it.
	 * @return The element at the top of the stack.
	 */
	public T pop() {
		if (isEmpty())
			throw new EmptyStackException();
		T result = peek();
		data.remove(data.size()-1);
		return result;
	}

	/**
	 * Retrieve the element at the top of the stack, without removing it
	 * from the stack.
	 * @return The element at the top of the stack, or null if it's empty.
	 */
	public T peek() {
		if (isEmpty())
			return null;
		return data.get(data.size()-1);
	}
	
	/**
	 * Check if the stack is empty.
	 * @return True if there's no element on the stack, false otherwise.
	 */
	public boolean isEmpty() {
		return data.size() == 0;
	}
	
	/**
	 * Return the number of elements on the stack currently stored.
	 * @return The number of elements stored.
	 */
	public int size() {
		return data.size();
	}
}
