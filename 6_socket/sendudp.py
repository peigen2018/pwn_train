import socket  
  
UDP_IP = "127.0.0.1"  
UDP_PORT = 514  
MESSAGE = "Hello, World!"  
  
# 创建 UDP socket 对象  
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  
  
# 发送数据到目标 IP 和端口  
sock.sendto(MESSAGE.encode(), (UDP_IP, UDP_PORT))  
  
# 接收服务器响应数据，可以设置超时时间为秒  
# response, addr = sock.recvfrom(4096)  
# print(f"Received: {response}")  
  
# 关闭连接  
sock.close()