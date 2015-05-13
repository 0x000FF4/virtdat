
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include "mysqlMod.h"


virtdat::mysqlMod::mysqlMod(){
}
void virtdat::mysqlMod::connect(std::string host,std::string username,std::string password,std::string database){

 this->connection = mysql_init(NULL);
 mysql_options(this->connection,MYSQL_READ_DEFAULT_GROUP,"virtdat");  
 mysql_real_connect(this->connection,host.c_str(),username.c_str(),password.c_str(),database.c_str(),0,NULL,0);
}

std::vector<char**> virtdat::mysqlMod::select(std::vector<std::string> *columns,std::string table){
 std::string columnsQuery = "";
 MYSQL_RES *result;
 std::string query;	
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
  query = "SELECT "+columnsQuery+" FROM "+table;
  mysql_query(this->connection,query.c_str());
  result = mysql_store_result(this->connection);
  while((row =mysql_fetch_row(result))){
  resultQuery.push_back(row);
  }
return resultQuery;
}
std::vector<char**> virtdat::mysqlMod::rawQuery(std::string query){
 MYSQL_RES *result;	
 MYSQL_ROW row;
 std::vector<char**> resultQuery;
 
  mysql_query(this->connection,query.c_str());
  result = mysql_store_result(this->connection);
 
   if(result == NULL){
   return resultQuery;
   }
   while((row =mysql_fetch_row(result))){
  	resultQuery.push_back(row);
   }
return resultQuery;

}
void virtdat::mysqlMod::closeConnection(){
   mysql_close(this->connection);
}
