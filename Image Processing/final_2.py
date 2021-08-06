import numpy as np
import cv2
import matplotlib.pyplot as plt
import time #importing libraries
from pySerialTransfer import pySerialTransfer as txfer



if __name__ == '__main__':
    try:
        img = cv2.imread('dolphin.jpg')
        imgray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        ret, thresh = cv2.threshold(imgray, 127, 255, 0)
        contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)


        p=0
        q=0
        j=0
        r=0
        s=0
        x,y=[],[]


        for i in range(len(contours[1])):
            p=int(contours[1][i][0][0])
            q=int(contours[1][i][0][1] )
            x.append(p)
            y.append(q)

        list_,y1=[],[] 
        link = txfer.SerialTransfer('COM3')  #connect to the arduino
        
        link.open()   #open serial port
        time.sleep(2) # allow some time for the Arduino to completely reset
        
        while True:
            if(link.available()):
                a=link.rx_obj(obj_type=type(2.3),
                                     obj_byte_size=4)
                n=int(a)
                print(n)
                if(n<len(x)):
                    list_.clear()
                    y1.clear()  
                    if(n+30<len(contours[1])):                
                        for i in range(n,n+30):
                            r=float(x[i])
                            s=float(y[i])
                            list_.append(r)
                            y1.append(s)
                    else:
                        for i in range(n,len(contours[1])):
                            r=float(x[i])
                            s=float(y[i])
                            list_.append(r)
                            y1.append(s)
                    send_size = 0   #initialises the variable
                    #buffer: temporarily holds the data while it is being moved from one place to another
                    #packets:developers store data in packet and each packet contains a byte buffer
                    #TX stands for transmit and RX stands for receive
                    ###################################################################
                    # Send a list
                    ###################################################################

                    #tx_obj:Insert an arbitrary variable's value into the TX buffer starting at the specified index

                    # #defining the list
                    list_size = link.tx_obj(list_)  #insert the list to tx buffer starting at the zero index(as starting index is not defined) 
                    ########################################link.tx_obj(list_) returns the "index of the last byte of list in TX buffer + 1"        
                    send_size += list_size       #here send_size is 40 as there are 10 integers(1 integer =4 byte)
                    str_size = link.tx_obj(y1, send_size) - send_size #link.tx_obj(str_, send_size) insert the 'str' in tx buffer 
                    ######################################################starting at send_size index and return  last bye index + 1               
                    send_size += str_size
                    
                    ###################################################################
                    # Transmit all the data to send in a single packet
                    ###################################################################
                    link.send(send_size)  #send the specified number of bytes in packetized form
                    
                    ###################################################################
                    # Wait for a response and report any errors while receiving packets
                    ###################################################################
                    while not link.available():
                        if link.status < 0:
                            if link.status == txfer.CRC_ERROR:
                                print('ERROR: CRC_ERROR')
                            elif link.status == txfer.PAYLOAD_ERROR:
                                print('ERROR: PAYLOAD_ERROR')
                            elif link.status == txfer.STOP_BYTE_ERROR:
                                print('ERROR: STOP_BYTE_ERROR')
                            else:
                                print('ERROR: {}'.format(link.status))

                    ###################################################################
                    # Parse response list
                    ###################################################################
                    #rx_obj: Extract an arbitrary variable's value from the RX buffer starting at the specified index and
                    #######################################         return unpacked object from the RX buffer
                    rec_list_  = link.rx_obj(obj_type=type(list_),   #type of object to be extract from RX buffer. here it is list
                                            obj_byte_size=list_size,  #no. of bytes occupied by extracted object(here it is 40 )
                                            list_format='f')
                    
                    rec_str_   = link.rx_obj(obj_type=type(y1),     #type of extracted object is string
                                            obj_byte_size=str_size,   #no. of bytes occupied by extracted object
                                            start_pos=list_size,list_format='f')

                    ###################################################################
                    # Display the received data
                    ###################################################################
                    print('SENT: {}'.format(list_))
                    print('SENT: {}'.format(y1))
                    print('RCVD: {}'.format(rec_list_))
                    print('RCVD: {}'.format(rec_str_))
                    print(' ')
            
    
    except KeyboardInterrupt:
        try:
            link.close()
        except:
            pass
    
    except:
        import traceback
        traceback.print_exc()
        
        try:
            link.close()
        except:
            pass
