print("This assignment decodes a class C IP address")

# input_ip = str(input("Enter the initial IP (192.B.C.D format):"))
input_ip_1 = "192.168.0.1"
sections = input_ip_1.split('.')
prelim_string = ".".join(sections[:3]) + "."


cidr = 0
while cidr > 32 or cidr < 24:
    cidr = int(input("Enter the CIDR bits (a number between 24 to 32):"))
last_bits = cidr - 24
temp = 0

for i in range(last_bits):
    temp = temp + 2 ** (7 - i)

print("\nSubnet mask in numeric format: 255.255.255." + str(temp))

network_num = temp & int(sections[3])
broadcast_num = (255 - temp) | int(sections[3])
print("Network address in numeric format: " + prelim_string + str(network_num))
print("Broadcast address in numeric format: " + prelim_string + str(broadcast_num))

if broadcast_num - network_num > 1:
    print("First address in numeric format: " + prelim_string + str(network_num + 1))
    print("Last address in numeric format: " + prelim_string + str(broadcast_num - 1))
else:
    print("No usable address in this subnet")

while True:
    input_ip_2 = str(input("\nEnter the some IP (192.B.C.D format) or exit(1):"))

    if input_ip_2 == '1':
        break
    sections2 = input_ip_2.split('.')
    prelim_string1 = ".".join(sections2[:3]) + "."

    if prelim_string != prelim_string1:
        print("Clients not in same network")
    else:
        if network_num <= int(sections2[3]) <= broadcast_num:
            if int(sections2[3]) == int(sections[3]):
                print("Same IP address entered twice")
            else:
                print("Clients are in same subnet! Connectivity can be established!")
        else:
            print("Clients are in same network but different subnets, connectivity cannot be established.")