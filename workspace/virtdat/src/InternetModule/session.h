#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
namespace virtdat{
 class session : public std::enable_shared_from_this<session>{
	boost::asio::ip::tcp::socket socket_;
	enum {max_length = 1024};
	char data_[max_length];
	void do_read();
	void do_write(std::size_t length);
	public:
	session(boost::asio::ip::tcp::socket socket);
	void start();
	};
}
