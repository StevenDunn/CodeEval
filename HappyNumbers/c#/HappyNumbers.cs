// happy numbers soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

class HappyNumbers {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;

				int n = Int32.Parse(line);
				List<int> visited = new List<int>();

				if (isHappy(line, visited))
					Console.WriteLine(1);
				else
					Console.WriteLine(0);
			}
		}
	}

	static bool isHappy(string n, List<int> visited) {
		int sum = 0;
		foreach (char c in n) {
			int x = (int)char.GetNumericValue(c);
			sum += x * x;
		}

		if (sum == 1)
			return true;
		if (visited.Contains(sum))
			return false;
		visited.Add(sum);

		if (isHappy(sum.ToString(), visited))
			return true;
  		return false;
	}
}