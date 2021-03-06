#include "server.h"

virtdat::server::server(boost::asio::io_service& io_service,short port)
		: acceptor_(io_service,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),port)),
			socket_(io_service){
		
		 	do_accept();
		 
		}
void virtdat::server::do_accept(){
	acceptor_.async_accept(socket_,[this](boost::system::error_code ec){
		if(!ec){
			std::make_shared<session>(std::move(socket_))->start();
		}
	});
}
