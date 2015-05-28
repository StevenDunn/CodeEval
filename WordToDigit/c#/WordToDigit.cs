// word to digit soln in c# for code eval by steven a dunn

using System;
using System.IO;

class WordToDigit {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] inputs = line.Split(';');
        foreach (string s in inputs)
          Console.Write(convert(s));
        Console.WriteLine();
      }
    }
  }

  static int convert(string word) {
    if (word == "one") return 1;
    else if (word == "two") return 2;
    else if (word == "three") return 3;
    else if (word == "four") return 4;
    else if (word == "five") return 5;
    else if (word == "six") return 6;
    else if (word == "seven") return 7;
    else if (word == "eight") return 8;
    else if (word == "nine") return 9;
    else if (word == "zero") return 0;
    else return -1;
  }
}