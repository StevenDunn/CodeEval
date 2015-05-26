// sum of digits soln in c# for code eval by steven a dunn

using System;
using System.IO;

class SumOfDigits {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;

				int sum = 0;
				foreach (char c in line) {
					sum += (int)char.GetNumericValue(c);
				}

				Console.WriteLine(sum);
			}
		}
	}
}