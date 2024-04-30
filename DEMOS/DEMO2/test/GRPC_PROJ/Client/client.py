import grpc
import satellite_communication_pb2
import satellite_communication_pb2_grpc

# Function to send command to microcontroller server
def send_command_to_server(command):
    # Establish gRPC channel to microcontroller server
    channel = grpc.insecure_channel('microcontroller-address:50051')  # Replace 'microcontroller-address' with the actual IP address or hostname of your microcontroller
    
    # Create stub
    stub = satellite_communication_pb2_grpc.LEDControlStub(channel)
    
    # Create request message
    request = satellite_communication_pb2.CommandRequest(command=command)
    
    # Send request and get response
    response = stub.SendCommand(request)
    
    # Print response status
    print("Response from server:", response.status)

# Main function
def main():
    # Send LED_ON command to microcontroller server
    send_command_to_server("LED_ON")

if __name__ == "__main__":
    main()
