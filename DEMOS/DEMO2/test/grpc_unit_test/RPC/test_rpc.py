# test_rpc.py

import unittest
from RPC import RPCServer, RPCClient
import threading

class TestRPCMethods(unittest.TestCase):

    def setUp(self):
        # Initialize RPC server
        self.server = RPCServer()
        # Register methods to be tested
        self.server.registerMethod(self.method_to_test)
        # Start RPC server in a separate thread
        self.server_thread = threading.Thread(target=self.server.run)
        self.server_thread.start()

        # Initialize RPC client
        self.client = RPCClient()
        # Connect RPC client to server
        self.client.connect()

    def tearDown(self):
        # Disconnect RPC client
        self.client.disconnect()
        # Stop RPC server
        self.server_thread.join()

    # Method to be tested
    def method_to_test(self, arg1, arg2):
        # Some logic to be tested
        return arg1 + arg2

    # Test case for method_to_test
    def test_method_to_test(self):
        # Call the method via RPC client
        result = self.client.method_to_test(2, 3)
        # Assert the result
        self.assertEqual(result, 5)

if __name__ == '__main__':
    unittest.main()
