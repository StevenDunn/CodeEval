// longest word soln in c# for code eval by steven a dunn

using System;
using System.IO;

class LongestWord {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] words = line.Split();
        int maxLength = 0; 
        string longestWord = "";
        foreach (string word in words)
          if (word.Length > maxLength) {
            maxLength = word.Length;
            longestWord = word;
          }
        Console.WriteLine(longestWord);
      }
    }
  }
}