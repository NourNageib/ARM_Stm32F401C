import unittest
import serial

# Function to send command and receive response
def send_command(ser, command):
    ser.write(command.to_bytes(1, 'big'))
    return ser.read()

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
        self.assertEqual(response[0], 0x11, "LED_ON test failed")
        print("LED_ON test passed")
    
    # Test LED_OFF command
    def test_LED_OFF(self):
        # Send byte 0x04 to test LED_OFF
        response = send_command(self.ser, 0x04)
        self.assertEqual(response[0], 0x22, "LED_OFF test failed")
        print("LED_OFF test passed")

# Main function to run the tests
if __name__ == '__main__':
    unittest.main()
