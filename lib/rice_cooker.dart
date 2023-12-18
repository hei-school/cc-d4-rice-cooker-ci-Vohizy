import 'dart:io';

class RiceCooker {
  late bool power;

  RiceCooker() {
    power = false;
  }

  bool checkPower() {
    return power;
  }

  void turnOn() {
    power = true;
    print("The rice cooker is turned on.");
  }

  void turnOff() {
    power = false;
    print("The rice cooker is turned off.");
  }

  void chooseFunction(int action, int? duration, int? temperature) {
    if (action == 1) {
      turnOn();
      try {
        switch (action) {
          case 1:
            if (duration == null || temperature == null) {
              throw ArgumentError("Duration and temperature must be provided.");
            }
            cook(duration, temperature);
            break;
          case 2:
            boil();
            break;
          default:
            print('Unrecognized action.');
        }
      } catch (error) {
        print('Error: $error');
      }
    } else if (action == 2) {
      turnOff();
    } else {
      print('Unrecognized command.');
    }
  }

  void cook(int duration, int temperature) {
    try {
      print('Cooking in progress for $duration minute(s) at $temperature°C...');
      sleep(Duration(minutes: duration));
      print('Cooking completed!');
    } catch (error) {
      print('Error: $error');
    }
  }

  void boil() {
    try {
      print('Boiling water in progress...');
      const boilingTime = 10; // Simulation duration (10 minutes, for example)
      int currentTemperature = 0;

      for (int i = 1; i <= boilingTime; i++) {
        currentTemperature += 10;
        sleep(Duration(minutes: 1)); // Simulate the time needed to increase the temperature
        print('Water temperature: $currentTemperature°C - Remaining time: ${boilingTime - i} minutes');
      }

      print('Water has reached 100°C. Automatic shutdown.');
    } catch (error) {
      print('Error: $error');
    }
  }
}

void main() {
  RiceCooker myRiceCooker = RiceCooker();

  stdout.write('Hello! You are using the rice cooker. Do you want to turn it on? (1 for yes / 2 for no): ');
  int userDecision = int.parse(stdin.readLineSync()!);

  if (userDecision == 1) {
    stdout.write('What do you want to do? (1 to cook / 2 to boil): ');
    int action = int.parse(stdin.readLineSync()!);

    if (action == 1) {
      stdout.write('How many minutes do you want to cook? ');
      int duration = int.parse(stdin.readLineSync()!);

      stdout.write('At what temperature do you want to cook? ');
      int temperature = int.parse(stdin.readLineSync()!);

      myRiceCooker.chooseFunction(action, duration, temperature);
    } else {
      myRiceCooker.chooseFunction(action, null, null);
    }
  } else {
    myRiceCooker.chooseFunction(2, null, null);
  }
}
