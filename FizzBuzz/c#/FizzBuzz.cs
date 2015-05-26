// fizzbuzz soln in c# for code eval by steven a dunn

using System.IO;
using System.Collections.Generic;
using System;

class FizzBuzz {
    static void Main (string[] args) {
        using (StreamReader reader = File.OpenText(args[0]))
        while (!reader.EndOfStream) {
            string line = reader.ReadLine();
            if (null == line)
                continue;
            string[] input = line.Split(null);
            int a = Convert.ToInt32(input[0]);
            int b = Convert.ToInt32(input[1]);
            int n = Convert.ToInt32(input[2]);
            string output = "";

            for (int i = 1; i < n + 1; ++i)
            {
                int aMod = i % a;
                int bMod = i % b;
                if (aMod == 0 && bMod == 0)
                    output += "FB";
                else if (aMod == 0)
                    output += "F";
                else if (bMod == 0)
                    output += "B";
                else
                    output += Convert.ToString(i);
                output += " ";
            }
            Console.WriteLine(output);
        }
    }
}