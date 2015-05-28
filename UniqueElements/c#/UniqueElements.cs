// unique elements c# soln for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

class UniqueElements {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;

				string[] elements = line.Split(',');
				HashSet<string> unique = new HashSet<string>(elements);
				Console.WriteLine(String.Join(",", unique));
			}
		}
	}
}