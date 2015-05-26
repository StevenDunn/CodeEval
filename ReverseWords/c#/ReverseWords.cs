// reverse words soln in c# for code eval by steven a dunn

using System;
using System.IO;

class ReverseWords {
	public static void Main(string[] args) {
		using (StreamReader reader = new StreamReader(args[0])) {
			while (!reader.EndOfStream) {
       			string line = reader.ReadLine();
            	if (null == line)
                	continue;
                string[] words = line.Split(null);
                for (int i = words.Length - 1; i >= 0; i--)
                    Console.Write(words[i] + " ");
                Console.WriteLine();
            }
        }
	}
}