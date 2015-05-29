// knight moves soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

class LongestWord {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        char c = line[0];
        char n = line[1];

        List<string> moves = getMoves(c, n);
        List<string> formattedMoves = format(moves);
        Console.WriteLine(String.Join(" ", formattedMoves));
      }
    }
  }
}