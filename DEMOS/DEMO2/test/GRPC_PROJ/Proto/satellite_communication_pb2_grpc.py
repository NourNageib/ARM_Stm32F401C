# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
"""Client and server classes corresponding to protobuf-defined services."""
import grpc

import satellite_communication_pb2 as satellite__communication__pb2


class LEDControlStub(object):
    """Define the LED control service
    """

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.TurnOnLED = channel.unary_unary(
                '/satellitecommunication.LEDControl/TurnOnLED',
                request_serializer=satellite__communication__pb2.LEDRequest.SerializeToString,
                response_deserializer=satellite__communication__pb2.LEDResponse.FromString,
                )
        self.TurnOffLED = channel.unary_unary(
                '/satellitecommunication.LEDControl/TurnOffLED',
                request_serializer=satellite__communication__pb2.LEDRequest.SerializeToString,
                response_deserializer=satellite__communication__pb2.LEDResponse.FromString,
                )


class LEDControlServicer(object):
    """Define the LED control service
    """

    def TurnOnLED(self, request, context):
        """Command to turn the LED on
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def TurnOffLED(self, request, context):
        """Command to turn the LED off
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_LEDControlServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'TurnOnLED': grpc.unary_unary_rpc_method_handler(
                    servicer.TurnOnLED,
                    request_deserializer=satellite__communication__pb2.LEDRequest.FromString,
                    response_serializer=satellite__communication__pb2.LEDResponse.SerializeToString,
            ),
            'TurnOffLED': grpc.unary_unary_rpc_method_handler(
                    servicer.TurnOffLED,
                    request_deserializer=satellite__communication__pb2.LEDRequest.FromString,
                    response_serializer=satellite__communication__pb2.LEDResponse.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'satellitecommunication.LEDControl', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class LEDControl(object):
    """Define the LED control service
    """

    @staticmethod
    def TurnOnLED(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/satellitecommunication.LEDControl/TurnOnLED',
            satellite__communication__pb2.LEDRequest.SerializeToString,
            satellite__communication__pb2.LEDResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def TurnOffLED(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/satellitecommunication.LEDControl/TurnOffLED',
            satellite__communication__pb2.LEDRequest.SerializeToString,
            satellite__communication__pb2.LEDResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)
