from socket import *

s = socket(AF_INET, SOCK_DGRAM)
host = "0.0.0.0"
port = 9999
buf = 1024
addr = (host, port)

s.sendto("6/example.txt", addr)

f = open("example.txt", "r")
data = f.read(buf)
while data:
    if s.sendto(data, addr):
        print("sending ...")
        data = f.read(buf)
s.close()
f.close()
