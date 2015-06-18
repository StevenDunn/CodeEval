// age distribution soln in c# for code eval by steven a dunn

using System;
using System.IO;

class AgeDistribution {

  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (line == null)
          continue;

        int val = Int32.Parse(line.Trim());
        if (val < 0)
          Console.WriteLine( "This program is for humans" );
        else if (val <= 2)
          Console.WriteLine( "Still in Mama's arms" );
        else if (val <= 4)
          Console.WriteLine( "Preschool Maniac" );
        else if (val <= 11)
          Console.WriteLine( "Elementary school" );
        else if (val <= 14)
          Console.WriteLine( "Middle school" );
        else if (val <= 18)
          Console.WriteLine( "High school" );
        else if (val <= 22)
          Console.WriteLine( "College" );
        else if (val <= 65)
          Console.WriteLine( "Working for the man" );
        else if (val <= 100)
          Console.WriteLine( "The Golden Years" );
        else
          Console.WriteLine( "This program is for humans" );
      }
    }
  }
}