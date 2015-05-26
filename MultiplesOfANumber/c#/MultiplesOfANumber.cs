// multiples of a number soln in c# for code eval by steven a dunn

using System;
using System.IO;

class MultiplesOfANumber {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;
					
				string[] input = line.Split(',');
				int x = Int32.Parse(input[0]);
				int n = Int32.Parse(input[1]);
				
				int multiple = 2;
				int multipleN = n;
				while (x >= multipleN) {
					multipleN = multiple * n;
					multiple += 1;
				}

				Console.WriteLine(multipleN);
			}
		}
	}
}