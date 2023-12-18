using System;

class RiceCooker
{
    private bool power;

    public RiceCooker()
    {
        power = false;
    }

    public bool CheckPower()
    {
        return power;
    }

    public void TurnOn()
    {
        power = true;
        Console.WriteLine("The rice cooker is turned on.");
    }

    public void TurnOff()
    {
        power = false;
        Console.WriteLine("The rice cooker is turned off.");
    }

    public void ChooseFunction()
    {
        if (!power)
        {
            Console.WriteLine("The rice cooker is not turned on.");
            return;
        }

        int choice;
        while (true)
        {
            Console.Write("Choose a function (1 to cook rice, 2 to heat water, 3 to heat food, 4 to turn off): ");

            if (!int.TryParse(Console.ReadLine(), out choice))
            {
                Console.WriteLine("Error: Please enter an integer.");
                continue;
            }

            if (choice < 1 || choice > 4)
            {
                Console.WriteLine("Error: Invalid choice. Please choose a number between 1 and 4.");
                continue;
            }

            break;
        }

        switch (choice)
        {
            case 1:
                int time;
                while (true)
                {
                    Console.Write("Enter the cooking duration in minutes: ");
                    if (!int.TryParse(Console.ReadLine(), out time))
                    {
                        Console.WriteLine("Error: Please enter an integer.");
                        continue;
                    }

                    break;
                }
                CookRice(time);
                break;
            case 2:
                HeatWater();
                break;
            case 3:
                HeatFood();
                break;
            case 4:
                TurnOff();
                break;
            default:
                Console.WriteLine("Unrecognized choice.");
                break;
        }
    }

    public void CookRice(int time)
    {
        Console.WriteLine($"Cooking rice for {time} minute(s)...");
        Sleep(time);
        Console.WriteLine("The rice is ready!");
    }

    public void HeatWater()
    {
        Console.WriteLine("Heating water in progress...");
        int temperature = 0;
        while (temperature < 100)
        {
            temperature += 10;
            Sleep(1);
            Console.WriteLine($"Water temperature: {temperature}°C");
        }
        Console.WriteLine("Water has reached 100°C. Automatically turning off.");
    }

    public void HeatFood()
    {
        Console.WriteLine("Heating food in progress...");
        Console.WriteLine("The food is heated and ready to be consumed!");
    }

    public void Sleep(int minutes)
    {
        int milliseconds = minutes * 60 * 1000;
        DateTime startTime = DateTime.Now;
        while (DateTime.Now < startTime.AddMilliseconds(milliseconds)) ;
    }
}

class Program
{
    static void Main()
    {
        RiceCooker myRiceCooker = new RiceCooker();

        Console.Write("Hello! You are using the rice cooker. Do you want to turn it on? (1 for yes / 2 for no): ");
        int userDecision;

        while (true)
        {
            if (!int.TryParse(Console.ReadLine(), out userDecision))
            {
                Console.WriteLine("Error: Please enter an integer.");
                continue;
            }

            if (userDecision != 1 && userDecision != 2)
            {
                Console.WriteLine("Error: Invalid choice. Please choose 1 for yes or 2 for no.");
                continue;
            }

            break;
        }

        if (userDecision == 1)
        {
            myRiceCooker.TurnOn();
            while (myRiceCooker.CheckPower())
            {
                myRiceCooker.ChooseFunction();
            }
        }
        else
        {
            Console.WriteLine("Rice cooker remains off.");
        }
    }
}
