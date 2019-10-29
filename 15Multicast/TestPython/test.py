import socket

MCAST_GRP = '224.0.0.1'
MCAST_PORT = 2323
MULTICAST_TTL = 2
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, MULTICAST_TTL)