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
    if keyboard.is_pressed("i"):
        send("i")
    elif keyboard.is_pressed("o"):
        send("o") 
    elif keyboard.is_pressed("p"):
        send("p") 
    elif keyboard.is_pressed("l"):
        send("l") 
    elif keyboard.is_pressed("n"):
        send("n") 
    
    else:
        pass     


   
