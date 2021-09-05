using System;

namespace GuessTheNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Random r = new Random();

            int guessesLeft = 5;
            int wnum = r.Next(1, 20);
            bool won = false;

            do
            {
                Console.WriteLine("Guesses left: {0}", guessesLeft);
                Console.Write("Guess a number between 1 and 20: ");
                string gs = Console.ReadLine();

                int gi = int.Parse(gs);

                if(gi > wnum)
                {
                    Console.WriteLine("Nope! Gotta go lower!");
                    guessesLeft--;

                    if(guessesLeft == 0)
                    {
                        Console.WriteLine("You ran out of guesses! Game over!");
                    }
                }
                else if(gi < wnum)
                {
                    Console.WriteLine("Nope! Gotta go higher!");
                    guessesLeft--;

                    if (guessesLeft == 0)
                    {
                        Console.WriteLine("You ran out of guesses! Game over!");
                    }
                }
                else if(gi == wnum)
                {
                    Console.WriteLine("Oh hey, you guessed the number.");
                    won = true;
                }
            } while ((won == false) && (guessesLeft > 0));

            Console.WriteLine("Thanks for playing!");
            Console.Write("Press any key to exit.");
            Console.ReadKey(true);
        }
    }
}
