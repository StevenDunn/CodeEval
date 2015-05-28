// self describing numbers soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

class SelfDescribingNumbers {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        if (isSelfDescribing(line))
          Console.WriteLine(1);
        else
          Console.WriteLine(0);
      }
    }
  }

  static bool isSelfDescribing(string n) {
    int[] counts = new int[10];

    foreach (char c in n)
      counts[(int)char.GetNumericValue(c)] += 1;

    for (int i = 0; i < n.Length; i++) {
      int x = (int)char.GetNumericValue(n[i]);
      if(x != counts[i]) 
        return false;
    }

    return true;
  }
}