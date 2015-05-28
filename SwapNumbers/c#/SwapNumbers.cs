// swap numbers soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class SwapNumbers {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] words = line.Split();
        for (int i = 0; i < words.Length; i++) {
          string word = words[i];
          words[i] = word[word.Length-1] + word.Substring(1, word.Length-2) + word[0]; 
        }
        Console.WriteLine(String.Join(" ", words));
      }
    }
  }
}