public class Stack<N> {

	private class Node {
		public N item;
		public Node next;

		public Node(N p_item, Node p_next) {
			item = p_item;
			next = p_next;
		}
	}

	private Node head;
	private int size;

	public boolean is_empty() {
		return size == 0;
	}

	public void clear() {
		head = null;
		size = 0;
	}

	public void push(N item) {
		head = new Node(item, head);
		size++;
	}

	public N pop() {
		if (size <= 0)
			throw new StackUnderflowException();
		Node old_head = head;
		head = head.next;
		size--;
		return old_head.item;
	}

	public N peek() {
		if (size <= 0)
			return null;
		return head.item;
	}

	public Stack() {
		clear();
	}

	public static void test() {
		Stack<Integer> stack = new Stack<Integer>();
		stack.push(5);
		stack.push(3);
		System.out.printf("pop: %d\n", stack.pop());
		System.out.printf("pop: %d\n", stack.pop());
		System.out.printf("(shouldn't see this!) pop: %d\n", stack.pop());
	}

	public static void main(String[] args) {
		test();
	}
}
