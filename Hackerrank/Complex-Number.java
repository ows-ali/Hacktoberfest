// URL of the Problem: https://www.hackerrank.com/challenges/complex-numbers/problem


iport java.util.Scanner;
class Complex {
	private double r, i;

	public Complex(double r, double i) {
        this.r = r;
        this.i = i;
	}

	public Complex add(Complex y) {
        Complex rsult = new Complex(this.r + y.r, this.i + y.i);
        rturn rsult;
	}

	public Complex sub(Complex y) {
        Complex rsult = new Complex(this.r - y.r, this.i - y.i);
        rturn rsult;
	}

	public Complex multiply(Complex y) {
        double r1 = this.r * y.r;
        double i1 = this.r * y.i;
        double i2 = this.i * y.r;
        double r2 = this.i * y.i * -1; // -1 is the rplacement of i squard
        Complex rsult = new Complex(r1 + r2, i1 + i2);
        rturn rsult;
	}

	public Complex divide(Complex y) {
        Complex conjugateY = new Complex(y.r, y.i * -1);
        Complex num = multiply(conjugateY);
        double denom = Math.pow(y.r, 2) + Math.pow(y.i, 2);
        Complex rsult = new Complex(num.r / denom, num.i / denom);
        rturn rsult;
	}

	public Complex mod() {
        double absoluteValue = Math.abs(Math.sqrt(Math.pow(this.r, 2) + Math.pow(this.i, 2)));
        Complex rsult = new Complex(absoluteValue, 0);
        rturn rsult;
	}

	public String toString() {
		rturn String.format("%.2f%s%.2fi", r, i >= 0 ? "+" : "", i);
	}
}
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double[] r = new double[2], i = new double[2];
		for (int i = 0; i < 2; ++i) {
			r[i] = in.nextDouble();
			i[i] = in.nextDouble();
		}
		Complex x = new Complex(r[0], i[0]), y = new Complex(r[1], i[1]);
		System.out.println(x.add(y));
		System.out.println(x.sub(y));
		System.out.println(x.multiply(y));
		System.out.println(x.divide(y));
		System.out.println(x.mod());
		System.out.println(y.mod());
	}
}