#pragma once

#include "test_print_ip.h"

TEST(print_ip, type_char) { 
  std::stringstream buffer,strm;
  strm<<"255";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(char(-1)); 
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

TEST(print_ip, type_chort) { 
  std::stringstream buffer,strm;
  strm<<"0.0";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(short(0));
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

TEST(print_ip, type_int) { 
  std::stringstream buffer,strm;
  strm<<"127.0.0.1";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(int(2130706433));
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

TEST(print_ip, type_long) { 
  std::stringstream buffer,strm;
  strm<<"101.112.131.41";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(long(8875824491850138409));
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

TEST(print_ip, type_string) { 
  std::stringstream buffer,strm;
  strm<<"192.168.1.1";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(std::string("192.168.1.1"));
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

TEST(print_ip, type_vector_string) { 
  std::stringstream buffer,strm;
  strm<<"192.168.1.2";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(std::vector<std::string>{"192", "168", "1", "2"});
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

 TEST(print_ip, type_list_nsigned_int) { 
  std::stringstream buffer,strm;
  strm<<"192.168.1.3";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(std::list<unsigned int>{192, 168, 1, 3});
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

  TEST(print_ip, type_make_tuple_string) { 
  std::stringstream buffer,strm;
  strm<<"192.168.1.4";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(std::make_tuple("192", "168", "1", "4"));
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

   TEST(print_ip, type_make_tuple_int) { 
  std::stringstream buffer,strm;
  strm<<"192.168.1.4";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  print_ip(std::make_tuple(192, 168, 1, 4));
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }