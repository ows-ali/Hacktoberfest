/*
 * Data Structures and Algorithms.
 * Copyright (C) 2016 Rafael Guterres Jeffman
 *
 * See the LICENSE file accompanying this source code, for
 * licensing restrictions that might apply.
 *
 */

package datastructures;

import java.util.Comparator;

import interfaces.BidirectionalIterator;
import interfaces.Iterator;
import interfaces.Sortable;

/**
 * A Double Linked List implementation, which can be iterated with a
 * bidirectional iterator, and have its elements sorted.
 */
public class LinkedList<T> implements Iterable<T>, Sortable<T> {

	class Node {
		T data;
		public Node previous;
		public Node next;
		
		Node(T data) {
			this.data = data;
		}		
		void insert(Node before, Node after) {
			this.previous = before;
			this.next = after;
			if (before != null)
				before.next = this;
			if (after != null)
				after.previous = this;
		}
		void remove() {
			if (previous != null)
				previous.next = next;
			if (next != null)
				next.previous = previous;
			next = null;
			previous = null;
		}
	}

	class ListaIterator implements BidirectionalIterator<T> {

		LinkedList<T> container;
		Node current;
		
		public ListaIterator(LinkedList<T> container) {
			this.container = container;
			this.current = container.head;
		}

		@Override
		public boolean hasNext() {
			return current != null;
		}

		@Override
		public boolean hasPrevious() {
			return current == null || current.previous != null;
		}

		@Override
		public T next() {
			T data = current.data;
			current = current.next;
			return data;
		}

		@Override
		public T previous() {
			if (current == null)
				current = container.tail;
			else
				current = current.previous;
			return current.data;
		}

		@Override
		public void insert(T data) {
			if (current == head)
				throw new IllegalStateException("Usage before next().");
			Node novo = new Node(data);
			Node old, prev;
			if (current == null) {
				old = tail;
				prev = tail.previous;
			} else {
				old = current.previous;
				prev = old.previous;
			}
			novo.insert(prev, old);
			if (prev == null)
				head = novo;
		}

		@Override
		public void append(T data) {
			if (head == null) {
				String error_msg = "Cannot use iterator on an empty list.";
				throw new IllegalStateException(error_msg);
			}
			Node novo = new Node(data);
			if (current == null) {
				current = tail;
			}
			if (current.next == null)
				tail = novo;
			novo.insert(current, current.next);
			current = novo;
		}

		@Override
		public void remove() {
			if (current == head)
				throw new IllegalStateException("Usage before next().");
			if (tail == head || current == null) {
				Node prev = tail.previous;
				tail.remove();
				if (tail == head)
					head = prev;
				tail = prev;
				return;
			}
			Node next = current;
			current = current.previous;
			if (current == head)
				head = current.next;
			current.remove();
			current = next;
		}
	}
	
	private Node head;
	private Node tail;
	
	/**
	 * Check if the container is empty.
	 * @return True if there are no elements stored, false otherwise.
	 */
	public boolean isEmpty() {
		return head == null;
	}
	
	/**
	 * Add a new element to the end of the structure.
	 * @param data The element to be added.
	 */
	public void append(T data) {
		Node novo = new Node(data);
		if (tail == null) {
			head = novo;
		} else {
			novo.previous = tail;
			tail.next = novo;
		}
		tail = novo;
	}
	
	/**
	 * Returns a bidirectional iterator to the LinkedList.
	 */
	@Override
	public Iterator<T> iterator() {
		return new ListaIterator(this);
	}

	/**
	 * Sort the elements in the container using insertion sort.
	 * @param cmp The comparator to be used to sort the elements.
	 */
	@Override
	public void sort(Comparator<T> cmp) {
		if (head == null) return;
		Node novo = head.next;
		while (novo != null) {
			Node current = novo.previous, next = novo.next;
			while (current!=null && cmp.compare(current.data, novo.data) > 0)
				current = current.previous;
			// swap nodes
			swapNodes(novo, current);
			novo = next;
		}
	}

	private void swapNodes(Node novo, Node current) {
		if (current != null && current.next == novo)
			return;
		Node previous = novo.previous;
		Node next = novo.next;
		previous.next = next;
		// remove novo
		if (novo == tail)
			tail = previous;
		novo.remove();
		// Insere depois do current.
		if (current != null) {
			novo.insert(current,current.next);
		} else {
			novo.insert(null,head);
			head = novo;
		}
	}
}
