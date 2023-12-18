import 'package:test/test.dart';
import 'package:Dart/lib/rice_cooker.dart';

void main() {
  group('RiceCooker', () {
    late RiceCooker riceCooker;

    setUp(() {
      riceCooker = RiceCooker();
    });

    test('Initially turned off', () {
      expect(riceCooker.checkPower(), isFalse);
    });

    test('Turn on', () {
      riceCooker.turnOn();
      expect(riceCooker.checkPower(), isTrue);
    });

    test('Turn off', () {
      riceCooker.turnOn();
      riceCooker.turnOff();
      expect(riceCooker.checkPower(), isFalse);
    });

    test('Choose function - unrecognized command', () {
      riceCooker.chooseFunction(3, null, null);
    });
  });
}
