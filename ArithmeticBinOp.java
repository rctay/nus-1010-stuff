public class ArithmeticBinOp {

	// for some reason, if these classes are to be accessed in static methods,
	//they have to be static too
	private static class BinOpAdd implements BinOp {
		public String getName() { return "+"; }
		public int operate(int a, int b) { return a+b; }
	}

	private static class BinOpSubtract implements BinOp {
		public String getName() { return "-"; }
		public int operate(int a, int b) { return a-b; }
	}

	private static class BinOpMultiply implements BinOp {
		public String getName() { return "*"; }
		public int operate(int a, int b) { return a*b; }
	}

	private static class BinOpDivide implements BinOp {
		public String getName() { return "/"; }
		public int operate(int a, int b) { return a/b; }
	}

	public static BinOp get_op(String op) {
		BinOp inst;

		if (op.equals("+"))
			inst = new BinOpAdd();
		else if (op.equals("-"))
			inst = new BinOpSubtract();
		else if (op.equals("*"))
			inst = new BinOpMultiply();
		else if (op.equals("/"))
			inst = new BinOpDivide();
		else
			throw new UnknownBinOpException(op);

		// additional level of checking - to enable, run jre with -enableassertions
		assert inst.getName() != op;

		return inst;
	}

	public static int do_op(String op, int a, int b) {
		return get_op(op).operate(a, b);
	}
	
	public static boolean check_op(String op) {
		try {
			get_op(op);
			return true;
		} catch (UnknownBinOpException e) {
			return false;
		}
	}
}
