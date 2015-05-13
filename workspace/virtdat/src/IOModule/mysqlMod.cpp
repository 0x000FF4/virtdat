/* Copyright 2008, 2010, Oracle and/or its affiliates. All rights reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

There are special exceptions to the terms and conditions of the GPL
as it is applied to this software. View the full text of the
exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
software distribution.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
 1 headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include <mysql/mysql.h>
#include <cstdio>
#include "mysql_connection.h"
#include "simpleSQL.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#define CPPCONN_TRACE_ENABLED
#define WE_HAVE_VARARGS_MACRO_SUPPORT
using namespace std;

virtdat::simpleSQL::simpleSQL(){
}
void virtdat::simpleSQL::connect(std::string host,std::string username,std::string password,std::string database){

 this->connection = mysql_init(NULL);
 mysql_options(this->connection,MYSQL_READ_DEFAULT_GROUP,"virtdat");  
 mysql_real_connect(this->connection,host.c_str(),username.c_str(),password.c_str(),database.c_str(),0,NULL,0);
}

std::vector<char**> virtdat::simpleSQL::select(std::vector<std::string> *columns,std::string table){
 string columnsQuery = "";
 MYSQL_RES *result;	
 MYSQL_ROW row;
 std::vector<char**> resultQuery;
 if(columns != NULL){
 	for(int i = 0;i < columns->size()-1;i++){
     		columnsQuery += columns[0][i] + ",";
 	 }
         if(columns->size()>0){
               columnsQuery += columns[0][columns->size()-1];
	}
 }else{
	columnsQuery = "*";
 }
  
 string query = "SELECT "+columnsQuery+" FROM "+table;
 
  mysql_query(this->connection,query.c_str());
  result = mysql_store_result(this->connection);
  
  int num_fields = mysql_field_count(this->connection);
  cout << endl;
  while((row =mysql_fetch_row(result))){
  resultQuery.push_back(row);
  }
return resultQuery;
}
std::vector<char**> virtdat::simpleSQL::rawQuery(std::string query){
 MYSQL_RES *result;	
 MYSQL_ROW row;
 std::vector<char**> resultQuery;
 
  mysql_query(this->connection,query.c_str());
  result = mysql_store_result(this->connection);
  
  int num_fields = mysql_field_count(this->connection);
  cout << endl;
   if(result == NULL){
}
  while((row =mysql_fetch_row(result))){
  resultQuery.push_back(row);
  }
return resultQuery;

}
void virtdat::simpleSQL::closeConnection(){
   mysql_close(this->connection);
}
