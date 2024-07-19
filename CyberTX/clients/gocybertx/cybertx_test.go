package gocybertx

import (
	"testing"
)

func TestCybertxClient(t *testing.T) {
	// Create a new CybertxClient instance
	client, err := NewCybertxClient("/dev/ttyUSB0", 9600)
	if err != nil {
		t.Fatalf("Failed to create CybertxClient: %v", err)
	}
	defer client.Close()

	// Test UpdateLine method
	err = client.UpdateLine(1, 2, 100)
	if err != nil {
		t.Errorf("UpdateLine failed: %v", err)
	}

	// Test UpdateAllLines method
	err = client.UpdateAllLines(1, []int32{100, 200, 300})
	if err != nil {
		t.Errorf("UpdateAllLines failed: %v", err)
	}

	// Add more test cases here...

}
