all: MainServer ServerModule ClientModule Commands WebInterface
MainServer:
	c++ MainServer.cpp -std=c++11 -c -I /home/x000ff4/Свалени/openssl-1.0.2/include
ServerModule:
	c++ ServerModule.cpp -std=c++11 -c -I /home/x000ff4/Свалени/openssl-1.0.2/include
ClientModule:
	c++ ClientModule.cpp -std=c++11 -c -I /home/x000ff4/Свалени/openssl-1.0.2/include
Commands:
	c++ Commands.cpp -std=c++11 -c
WebInterface:
	c++ WebInterface.cpp -std=c++11 -c
clean: 
	$(RM) MainServer.o ServerModule.o ClientModule.o Commands.o
