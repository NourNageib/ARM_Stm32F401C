# client.py

from RPC import RPCClient

# Create an RPC client instance
client = RPCClient()

# Connect to the server
client.connect()

# Call remote methods
result = client.add(2, 3)
print("Result:", result)

# Disconnect from the server
client.disconnect()
