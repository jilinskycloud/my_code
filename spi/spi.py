import spidev

spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz = 5000 
spi.mode = 0b01

#to_send = [0x01, 0x02, 0x88]
#print(spi.xfer(to_send))
print(spi.readbytes(3))
x = spi.close()
#print(x)
