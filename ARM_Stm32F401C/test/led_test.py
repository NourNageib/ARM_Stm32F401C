# import unittest
# import ctypes
# import sys
# import os

# # Change the current working directory to the directory where the test script and LED.dll are located
# os.chdir('E:/NEW_DEM/test')

# # Load the shared library
# led_lib = ctypes.CDLL('E:/NEW_DEM/test/LED.dll')

# # Define function prototypes
# LED_On = led_lib.LED_On
# LED_On.restype = ctypes.c_int

# # Define LED status constants
# LED_ON_OK = 1

# class TestLEDFunction(unittest.TestCase):
#     def test_LED_On(self):
#         # Test if LED_On() turns the LED on successfully
#         result = LED_On()
#         self.assertEqual(result, LED_ON_OK, "LED_On did not return LED_ON_OK")

#     # Add more test cases as needed

# if __name__ == '__main__':
#     unittest.main()
import serial

# Open the serial port
ser = serial.Serial('COM7', baudrate=9600)

# Send data over the serial port
ser.write(b'Hello, world!\n')

# Close the serial port
ser.close()
