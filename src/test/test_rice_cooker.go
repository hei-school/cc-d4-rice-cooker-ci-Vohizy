package main

import (
	"fmt"
	"testing"
)

// TestTurnOn tests the TurnOn method of RiceCooker.
func TestTurnOn(t *testing.T) {
	rc := RiceCooker{}
	rc.TurnOn()

	if !rc.CheckPower() {
		t.Error("Expected power to be on, but it's off")
	}
}

// TestTurnOff tests the TurnOff method of RiceCooker.
func TestTurnOff(t *testing.T) {
	rc := RiceCooker{power: true}
	rc.TurnOff()

	if rc.CheckPower() {
		t.Error("Expected power to be off, but it's on")
	}
}

// TestChooseFunction tests the ChooseFunction method of RiceCooker.
func TestChooseFunction(t *testing.T) {
	rc := RiceCooker{power: true}

	// Mock user input
	mockUserInput := "1\n2\n" // User decides to turn on, then turn off

	// Redirect input
	oldStdin := stdin
	stdin = strings.NewReader(mockUserInput)
	defer func() { stdin = oldStdin }()

	// Redirect output
	oldStdout := stdout
	var output bytes.Buffer
	stdout = &output
	defer func() { stdout = oldStdout }()

	rc.ChooseFunction()

	// Check if the expected output is present in the captured stdout
	expectedOutput := "The rice cooker is turned on.\n" +
		"Le rice cooker n'est pas allumé.\n" +
		"The rice cooker is turned off.\n"
	if output.String() != expectedOutput {
		t.Errorf("Expected output:\n%s\nActual output:\n%s", expectedOutput, output.String())
	}
}


func TestGetValidNumber(t *testing.T) {
	rc := &RiceCooker{}

	// Test with valid input
	validInput := "5\n"
	expectedResult := 5
	result, err := rc.getValidNumber("Enter a number: ", nil)
	if err != nil {
		t.Errorf("Unexpected error: %v", err)
	}
	if result != expectedResult {
		t.Errorf("Expected %d, got %d", expectedResult, result)
	}

	// Test with invalid input
	invalidInput := "abc\n"
	_, err = rc.getValidNumber("Enter a number: ", nil)
	if err == nil {
		t.Error("Expected an error, but got none")
	}
}

func TestMain(m *testing.M) {
	fmt.Println("Setup before tests")
	code := m.Run()
	fmt.Println("Teardown after tests")
	os.Exit(code)
}
