#import everything from socket library
from socket import *
#import regular expression
import re
#server ip goes here
serverName = '129.10.33.208'
#one of the ports open
serverPort = 12001
#define client socket
clientSocket = socket(AF_INET, SOCK_STREAM)
#connect to server
clientSocket.connect((serverName,serverPort))
#send a hello
clientSocket.send('ece[class] HELLO [ID withheld]')

#initialization out of the way, main body
#define expected BYE message
BYE_format = "ece[class] BYE \d*"
b = re.compile(BYE_format)

while True:
    processEQ = clientSocket.recv(1024)
    #Check for success message
    if b.match(processEQ):
        print 'FINAL: ' + processEQ
        break
    #split string
    usr, msge, num1s, opr, num2s = str.split(processEQ)
    #make num1s and num2s into ints
    num1 = int(num1s)
    num2 = int(num2s)
    if opr == '/':
        #declare an answer variable
        ans = num1 / num2
    elif opr == '*':
        ans = num1 * num2
    elif opr == '+':
        ans = num1 + num2
    elif opr == '-':
        ans = num1 - num2
    #send answer
    clientSocket.send(str(ans))
    print 'From Server: ' + "\t" + usr + "\t" + msge + "\t" + num1s + "\t" + opr + "\t" + num2s #debug output

#close connection
clientSocket.close()
#waits user to input something before exiting
wait = raw_input('Press enter to continue: ' )
