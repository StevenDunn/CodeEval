// lowercase soln in c# for code eval by steven a dunn

using System;
using System.IO;

class Lowercase {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;

				Console.WriteLine(line.ToLower());
			}
		}
	}
}