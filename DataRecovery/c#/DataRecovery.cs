// data recovery soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class DataRecovery {
  public static int find_missing(List<int> indices, int length) {
    int sum = 0;
    foreach (int i in indices)
      sum += i;
    int expected_sum = length * (length + 1) / 2;
    return expected_sum - sum;
  }

  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] inputs = line.Trim().Split(';');
        string[] words = inputs[0].Split();
        List<int> indices = inputs[1].Split().Select(x => Int32.Parse(x)).ToList();
        indices.Add(find_missing(indices, words.Length));
        for (int i = 1; i < indices.Count + 1; i++)
          Console.Write(words[indices.IndexOf(i)] + " ");
        Console.WriteLine();
      }
    }
  }
}