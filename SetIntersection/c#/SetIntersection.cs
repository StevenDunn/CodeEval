// set intersection soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

class SetIntersection {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
				string line = reader.ReadLine();
				if (null == line)
					continue;

				string[] inputs = line.Split(';');
				HashSet<string> set1 = new HashSet<string>(inputs[0].Split(','));
				HashSet<string> set2 = new HashSet<string>(inputs[1].Split(','));

        set1.IntersectWith(set2);

        Console.WriteLine(String.Join(",", set1));
			}
		}
	}
}