import socket

hostname = input("Please enter website address:\n")

# IP lookup from hostname
print(f'The {hostname} IP Address is {socket.gethostbyname(hostname)}')

print(socket.gethostbyaddr(hostname))
print(socket.gethostname())

# import socket
# hostname = input()
# x= socket.gethostbyname(hostname)
# print(x)