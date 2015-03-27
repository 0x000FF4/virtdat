/*
 * request.hpp
 *
 *  Created on: 27.03.2015 г.
 *      Author: x000ff4
 */

#ifndef INTERNETMODULE_REQUEST_HPP_
#define INTERNETMODULE_REQUEST_HPP_


#include <string>
#include <vector>
#include "header.hpp"

namespace http {
namespace server {

/// A request received from a client.
struct request
{
  std::string method;
  std::string uri;
  int http_version_major;
  int http_version_minor;
  std::vector<header> headers;
};

} // namespace server
} // namespace http



#endif /* INTERNETMODULE_REQUEST_HPP_ */
