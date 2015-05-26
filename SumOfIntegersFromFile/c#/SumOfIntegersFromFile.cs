// sum of integers from file soln in c# for code eval by steven a dunn

using System;
using System.IO;

class SumOfIntegersFromFile {
	public static void Main(string[] args) {
		int sum = 0;
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;

				sum += Int32.Parse(line);
			}
		}

		Console.WriteLine(sum);
	}
}