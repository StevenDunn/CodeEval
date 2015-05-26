// rightmost char soln in c# for code eval by steven a dunn

using System;
using System.IO;

class RightmostChar {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;

				Console.WriteLine(rightmostChar(line));
			}
		}
	}

	static int rightmostChar(string line) {
		string[] input = line.Split(',');
		return input[0].LastIndexOf(input[1]);
	}
}