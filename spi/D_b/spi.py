import time
import spidev
spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz = 50000
spi.mode = 0b11
while True:
  to = [0x31]
  res = spi.xfer(to)
  if(res[0] != 0  and res[0] != 0xd):
    h1 = hex(res[0])
    h1 = h1.replace('0x', '')
    h1 = bytes.fromhex(h1).decode('utf-8')
    print(h1)
  #spi.writebytes(to)
  #re = spi.readbytes(1)
  #if(re[0] != 0):
  #print(re)
  #time.sleep(1)
spi.close()
