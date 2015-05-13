#ifndef SIMPLE_SQL_H
#define SIMPLE_SQL_H
#include <string>
#include <vector>
#include <mysql/mysql.h>
namespace virtdat{
	class mysqlMod{
                MYSQL *connection;
		public:
			mysqlMod();
			void connect(std::string host,std::string username,std::string password,std::string database);
	                std::vector<char**> select(std::vector<std::string> *columns, std::string table);
                        std::vector<char**> rawQuery(std::string query);
                        void closeConnection();
          };
}
#endif
