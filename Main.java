import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	private static void calc_echo(String msg) {
		System.out.printf("calc said: '%s'!\n", msg);
	}
	
	public static void main(String[] args) {
		Calculator calc = new Calculator();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String token;
		
		while (true) {
			try {
				System.out.println("Enter operation to perform:");
				token = br.readLine().trim();
				
				if (token.equals("help")) {
					System.out.println("Accepted commands:");
					System.out.println("--");
					System.out.println("num\tPushes a number to the stack");
					System.out.println("num4eva\tEnters number input mode");
					System.out.println("op\tPerforms a binary operation through the stack");
					System.out.println("ans\tGet the top most number");
					System.out.println("clear\tClears the stack");
					System.out.println("help\tPrints this message");
					System.out.println("--");
				} else if (token.equals("num")) {
					System.out.println("Enter number:");
					calc_echo(
							calc.number_input(
									Integer.parseInt(
											br.readLine().trim())));
				} else if (token.equals("num4eva")) {
					System.out.println("(entering number input mode; enter a non-integer to quit)");
					while (true) {
						try {
							System.out.println("Enter number:");
        					calc_echo(
        							calc.number_input(
        									Integer.parseInt(
        											br.readLine().trim())));
						} catch (NumberFormatException e) {
							break;
						}
					}
					System.out.println("(quitting number input mode...)");
    					
				} else if (token.equals("op")) {
					System.out.println("Enter binary operation to perform on stack:");
					token = br.readLine().trim();
					
					try {
						calc_echo(
								calc.operation_input(token));
					} catch (UnknownBinOpException e) {
						System.err.println("Unknown binary operation!");
					}
				} else if (token.equals("ans")) {
					calc_echo(
							calc.answer());
				} else if (token.equals("clear")) {
					calc_echo(
							calc.clear());
				} else {
					System.err.println("Unknown operation!");
				}
			} catch (IOException e) {
				;
			}
		}
	}
}
