import socket
import json
import httplib2
import urllib
import redis
import time


class Log_Distance:
	r = redis.StrictRedis(host='localhost', port=6370, db=0, charset="utf-8", decode_responses=True, password="LoRaBD")
	edsIP = "192.168.1.244"
	edsPORT = 64000
	MESSAGE=bytes("M0\r\n", 'utf-8')
	srvsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	srvsock.settimeout(3)
	srvsock.connect((edsIP, edsPORT))
	delay_read = 1
	
	def read_post(self):
		while(1):
			time.sleep(Log_Distance.delay_read)
			Log_Distance.srvsock.sendall(Log_Distance.MESSAGE)
			data = Log_Distance.srvsock.recv(4096).decode("utf-8")
			a = float(data.split(',')[1]) / 1000.00
			#print("Distance :: ",data)
			print("Distance B = ", a)
			x = str(a)+"|"+str(time.time())
			print("This is X", x)
			#### Save To the Redis
			Log_Distance.r.set("Dest-time", x)
			### read From Redis
			print(Log_Distance.r.get("Dest-time"))
			http = httplib2.Http(".cache",  disable_ssl_certificate_validation=True)
			url_ = "http://192.168.1.75/php_code/receive_post_value.php"
			body = {'distance':x}
			content = http.request(url_, method="POST", headers={'Content-type': 'application/x-www-form-urlencoded'}, body=urllib.parse.urlencode(body) )[1]
			content = content.decode("utf-8")
			print("This is received From the server ==>", content)
		Log_Distance.srvsock.close()


if __name__ == '__main__':
	# Create the form with simple fields
	obj = Log_Distance()
	obj.read_post()


				  
