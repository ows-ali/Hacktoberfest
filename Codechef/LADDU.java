import java.io.*;
import java.util.*;
class Laddu {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out, true);

		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");

			int numAct = Integer.parseInt(st.nextToken());
			int national = 0;

			if (st.nextToken().equals("INDIAN")) national = 1;

			int score = 0;
			while (numAct-- > 0) {
				score += laddus(br.readLine());
			}

			int perMonth = national == 0 ? 400 : 200;
			out.println((score - (score % perMonth)) / perMonth);
		}

		out.close();
	}
	public static int laddus(String str) {
		String[] arr = str.split(" ");

		if (arr.length == 1) {
			switch (arr[0]) {
			case "TOP_CONTRIBUTOR" :
				return 300;
			case "CONTEST_HOSTED" :
				return 50;
			default :
				return 0;
			}
		} else {
			switch (arr[0]) {
			case "BUG_FOUND" :
				return Integer.parseInt(arr[1]);
			case "CONTEST_WON" :
				if (Integer.parseInt(arr[1]) <= 20) {
					return 300 + 20 - Integer.parseInt(arr[1]);
				} else return 300;
			default :
				return 0;
			}
		}
	}
}
