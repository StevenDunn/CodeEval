// find a writer soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class FindAWriter {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;
        
        string[] inputs = line.Split(new String[] {"| "}, StringSplitOptions.None);
        string text = inputs[0];

        int[] keys = inputs[1].Split(' ').Select(x => Int32.Parse(x)).ToArray();
        foreach (int i in keys)
          Console.Write(text[i-1]);
        Console.WriteLine();
      }
    }
  }

 
}