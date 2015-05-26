// multiplication tables soln in c# for code eval by steven a dunn

using System;

class MultiplicationTables {
	public static void Main(string[] args) {
		for (int i = 1; i < 13; i++) {
			for (int j = 1; j < 13; j++) {
				if (j == 1) 
					Console.Write("{0,2}", i * j);
				else
					Console.Write("{0,4}", i * j);
			}	
			Console.WriteLine();
		}
	}
}