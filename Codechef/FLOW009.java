import java.io.*;
class FLOW009 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out, true);

		int t = Integer.parseInt(br.readLine().trim());

		while (t-- > 0) {
			String[] tok = br.readLine().split(" ");

			double quan = Double.parseDouble(tok[0]);
			double price = Double.parseDouble(tok[1]);

			double cost = quan * price;
			if (quan > 1000) cost -= ((quan * price) / 100 * 10);

			out.printf("%.6f\n", cost);
		}
	}
}
