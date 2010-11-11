public class Calculator {

	private Stack<Integer> stack = new Stack<Integer>();

	public String answer() {
		return (stack.is_empty()) ? "empty stack" : stack.peek().toString();
	}

	public String clear() {
		stack.clear();
		return "cleared";
	}

	public String number_input(int num) {
		stack.push(num);
		return "pushed";
	}

	private int do_op(String op, int current) {
		if (stack.is_empty()) {
			stack.push(current);
			return 0;
		}

		int val = ArithmeticBinOp.do_op(op, current, stack.pop());

		return do_op(op, val);
	}

	public String operation_input(String op) {
		if (stack.is_empty())
			return "Stack empty - nothing to operate on";

		do_op(op, stack.pop());
		return "pushed";
	}

	public static void main(String[] args) {
		Calculator calc = new Calculator();
		System.out.printf("calc says \"%s\": %s\n", calc.number_input(5), calc.answer());
		System.out.printf("calc says \"%s\": %s\n", calc.number_input(3), calc.answer());
		System.out.printf("calc says \"%s\": %s\n", calc.number_input(-1), calc.answer());
		System.out.printf("add all, calc says: \"%s\": %s\n", calc.operation_input("+"), calc.answer());
		System.out.printf("calc says \"%s\": %s\n", calc.number_input(3), calc.answer());
		System.out.printf("test unknown op, calc says: \"%s\": %s\n", calc.operation_input("&"), calc.answer());
	}
}
