#include <cstdlib>
#include <iostream>
#include <memory>
#include "session.h"
#include <utility>
#include <boost/asio.hpp>
#ifndef SERVER_H
#define SERVER_H
namespace virtdat{
	class server{
		void do_accept();
		boost::asio::ip::tcp::acceptor acceptor_;
		boost::asio::ip::tcp::socket socket_;
	    public:
		server(boost::asio::io_service& io_service,short port);
	};
}
#endif
