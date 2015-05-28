// Beautiful Strings soln in c# for code eval by steven a dunn

using System;
using System.IO;

class BeautifulStrings {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        line = line.ToLower();

        int[] counts = getCounts(line);
        int beauty = getBeauty(counts);

        Console.WriteLine(beauty);
      }
    }
  }

  static int[] getCounts(string line) {
    int[] counts = new int[26];
    const int ASCII_ZERO = 97;

    foreach (char c in line) {
      int i = (int)c - ASCII_ZERO;
      if (i >= 0 && i < 26)
        counts[i]++;
    }
    return counts;
  }

  static int getBeauty(int[] counts) {
    int beauty = 0;
    int weight = 26;
 
    Array.Sort(counts);

    for (int i = counts.Length - 1; i >= 0; i--) {
      beauty += weight * counts[i];
      weight--;
    }

    return beauty;
  }
}