// penultimate word soln in c# for code eval by steven a dunn

using System;
using System.IO;

class PenultimateWord {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;
        
        string[] words = line.Split(' ');
        Console.WriteLine(words[words.Length - 2]);
      }
    }
  }

}