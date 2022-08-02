# Aqui importamos os módulos necessários para os testes
from pytest import fixture


@fixture(scope="module")
def listen_address():
    return '[::]:50051'


# Aqui criamos uma instância do servidor gRPC 
@fixture(scope="module")
def grpc_server(listen_address):
    from calculator_pb2_grpc import add_CalculatorServicer_to_server
    from calculator_server import Calculator

    from concurrent import futures

    from grpc import server

    grpc_server = server(futures.ThreadPoolExecutor(max_workers=10))

    add_CalculatorServicer_to_server(Calculator(), grpc_server)

    grpc_server.add_insecure_port(listen_address)
    grpc_server.start()

    yield

    grpc_server.stop(True)


@fixture(scope="module")
def channel(grpc_server, listen_address):
    from grpc import insecure_channel
    return insecure_channel(listen_address)


@fixture(scope="module")
def calculator_client(channel):
    from calculator_pb2_grpc import CalculatorStub
    return CalculatorStub(channel)


def test_sum(calculator_client):
    from calculator_pb2 import SumRequest

    # given
    a = 256.5
    b = 128.8

    expected = a + b

    # when
    result = calculator_client.Sum(SumRequest(a=a, b=b))

    # then
    assert result.s == expected
    
def test_multiply(calculator_client):
    from calculator_pb2 import MultiplyRequest
    
    # given
    c = 34.2
    d = 5.4
    
    expected = c * d
    
    # when
    result = calculator_client.Multiply(MultiplyRequest(c=c, d=d))
    
    # then
    assert result.m == expected
    
def test_largest(calculator_client):
    from calculator_pb2 import LargestRequest
    
    # given
    x = 1
    y = 2
    z = 3
    
    #nums = [x,y,z]
    #expected = max(nums)
        
    if (x >= y) and (x >= z):
        expected = x
    elif (y >= x) and (y >= z):
        expected = y
    else:
        expected = z
    
    # when
    result = calculator_client.Largest(LargestRequest(x=x, y=y, z=z))
    
    # then
    assert result.l == expected

def test_divide(calculator_client):
    from calculator_pb2 import DivideRequest
    
    # given
    d1 = 10
    d2 = 3
        
    expectedq = 3
    expectedr = 1
    
    #when
    result = calculator_client.Divide(DivideRequest(d1=d1, d2=d2))
    
    #then
    assert result.q == expectedq
    assert result.r == expectedr
    
