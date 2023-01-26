import socket
import time
import keyboard

serverAddressPort   = ("192.168.1.102", 8005) #input the server address and port
bufferSize          =  1024
# Create a UDP socket at client side
UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
# Send to server using created UDP socket
def send(m):
    bytesToSend = str.encode(m)
    UDPClientSocket.sendto(bytesToSend, serverAddressPort)


while True():
    if keyboard.is_pressed("w"):
        send("w")
    elif keyboard.is_pressed("s"):
        send("s") 
    elif keyboard.is_pressed("e"):
        send("e") 
    elif keyboard.is_pressed("q"):
        send("q")
    elif keyboard.is_pressed("d"):
        send("d") 
    elif keyboard.is_pressed("a"):
        send("a") 
    elif keyboard.is_pressed("z"):
        send("z")
    elif keyboard.is_pressed("t"):
        send("t") 
    elif keyboard.is_pressed("y"):
        send("y") 
    elif keyboard.is_pressed("g"):
        send("g")
    elif keyboard.is_pressed("h"):
        send("h") 
    elif keyboard.is_pressed("r"):
        send("r") 
    else:
        pass     


   
