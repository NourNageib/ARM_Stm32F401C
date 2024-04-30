# server.py

from RPC import RPCServer

# Define your server methods
def add(a, b):
    return a + b

# Create an RPC server instance
server = RPCServer()

# Register methods
server.registerMethod(add)

# Start the server
server.run()
