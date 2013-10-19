TLS encryption for Client/Server IPv6/IPv4 communication
========================================================

What is ucspi-ssl?
------------------

sslserver and sslclient are command-line tools for building SSL client-server applications. They conform to the UNIX Client-Server Program Interface, UCSPI.

sslserver listens for IPv6 and/or IPv4 connections, and runs a program for each connection it accepts. The program environment includes variables that hold the local and remote host names, IP addresses, and port numbers. sslserver offers a concurrency limit on acceptance of new connections, and selective handling of connections based on client identity supporting CIDR IP address notation. sslserver supports STARTTLS and STLS.

sslclient requests a connection to either a IPv6 or IPv4 TCP sockets, and runs a program. The program environment includes the same variables as for sslserver.

http://www.fehcom.de/ipnet/ucspi-ssl.html
