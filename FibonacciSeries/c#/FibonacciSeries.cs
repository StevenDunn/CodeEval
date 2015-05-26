// fibonacci series soln in c# for code eval by steven a dunn

using System;
using System.IO;

class FibonacciSeries {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;

				Console.WriteLine(fib(Int32.Parse(line)));
			}
		}
	}

	static int fib (int n) {
  		int buf1 = 1;
  		int buf2 = 1;
  		int temp = 0;

		if (n == 0) 
			return 0;

  		if (n == 1 || n == 2)
  			return 1;

  		for (int i = 3; i < n + 1; i++) {
  			temp = buf1;
  			buf1 = buf2;
  			buf2 = buf1 + temp;
  		}

		return buf2;
	}
}