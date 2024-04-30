import grpc
from concurrent import futures
import satellite_communication_pb2
import satellite_communication_pb2_grpc
import subprocess
#MCU
class SatelliteCommunicationServicer(satellite_communication_pb2_grpc.SatelliteCommunicationServicer):
    def TransmitData(self, request, context):
        if request.message == "LED_ON":
            # Execute script to turn LED on
            result = subprocess.run(["./led_on.sh"], capture_output=True)
            if result.returncode == 0:
                return satellite_communication_pb2.DataResponse(status="LED turned on successfully")
            else:
                return satellite_communication_pb2.DataResponse(status="Error turning on LED")
        elif request.message == "LED_OFF":
            # Execute script to turn LED off
            result = subprocess.run(["./led_off.sh"], capture_output=True)
            if result.returncode == 0:
                return satellite_communication_pb2.DataResponse(status="LED turned off successfully")
            else:
                return satellite_communication_pb2.DataResponse(status="Error turning off LED")
        else:
            return satellite_communication_pb2.DataResponse(status="Unknown command")

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    satellite_communication_pb2_grpc.add_SatelliteCommunicationServicer_to_server(SatelliteCommunicationServicer(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
