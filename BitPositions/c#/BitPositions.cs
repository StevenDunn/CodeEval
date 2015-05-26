// bit positions soln in c# for code eval by steven a dunn

using System;
using System.IO;

class BitPositions {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (line == null)
					continue;

				string[] input = line.Split(',');
				int n = Int32.Parse(input[0]);
				int pos1 = Int32.Parse(input[1]);
				int pos2 = Int32.Parse(input[2]);

				string binary = Convert.ToString(n, 2);
				if (binary[binary.Length-pos1] == binary[binary.Length-pos2])
					Console.WriteLine("true");
				else
					Console.WriteLine("false");
			}
		}
	}
}