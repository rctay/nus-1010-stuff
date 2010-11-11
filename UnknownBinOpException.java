class UnknownBinOpException extends RuntimeException {
	String op;

	public UnknownBinOpException(String op) {
		this.op = op;
	}

	public String toString() {
		return "Unknown binary operation: "+op;
	}
}
