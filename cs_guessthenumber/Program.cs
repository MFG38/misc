using System;

namespace GuessTheNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Random r = new Random();

            int wnum = r.Next(1, 20);
            bool won = false;

            do
            {
                Console.Write("Guess a nomber between 1 and 20: ");
                string gs = Console.ReadLine();

                int gi = int.Parse(gs);

                if(gi > wnum)
                {
                    Console.WriteLine("Nope! Gotta go lower!");
                }
                else if(gi < wnum)
                {
                    Console.WriteLine("Nope! Gotta go higher!");
                }
                else if(gi == wnum)
                {
                    Console.WriteLine("Oh hey, you guessed the number.");
                    won = true;
                }
            } while (won == false);

            Console.WriteLine("Thanks for playing!");
            Console.Write("Press any key to exit.");
            Console.ReadKey(true);
        }
    }
}
