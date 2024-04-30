import unittest
import serial
import time
from termcolor import colored  # Import colored function for coloring console output

# Function to send command and receive response
def send_command(ser, command):
    ser.write(command.to_bytes(1, 'big'))
    start_time = time.time()  # Record the start time
    while True:
        response = ser.read()
        if response:
            return response
        elif time.time() - start_time > 3:  # Wait for a maximum of 3 seconds
            return None

# Test class
class TestLEDCommands(unittest.TestCase):
    # Set up serial port before each test
    def setUp(self):
        self.ser = serial.Serial('COM4', baudrate=9600, timeout=3)
    
    # Tear down serial port after each test
    def tearDown(self):
        self.ser.close()
    
    # Test LED_ON command
    def test_LED_ON(self):
        # Send byte 0x03 to test LED_ON
        response = send_command(self.ser, 0x03)
        if response and response[0] == 0x11:
            print(colored("LED_ON test passed", 'green'))
        else:
            print(colored("LED_ON test failed", 'red'))
    
    # Test LED_OFF command
    def test_LED_OFF(self):
        # Send byte 0x04 to test LED_OFF
        response = send_command(self.ser, 0x04)
        if response and response[0] == 0x22:
            print(colored("LED_OFF test passed", 'green'))
        else:
            print(colored("LED_OFF test failed", 'red'))

# Main function to run the tests
if __name__ == '__main__':
    unittest.main()
