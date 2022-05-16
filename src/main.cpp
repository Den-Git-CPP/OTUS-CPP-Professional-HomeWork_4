#include <iostream>
#include "print_ip.h"

/// @file

 /**
 * @brief  Функция печати условного IP-адреса для различных входных параметров через механизма SFINAE.
 * @version	1
 * @date 15.05.2022 
 */

int main( )
{
  print_ip(char(-1)); 
  std::cout << '\n';

  print_ip(short(0));
  std::cout << '\n';

  print_ip(int(2130706433));
  std::cout << '\n';

  print_ip(long(8875824491850138409));
  std::cout << '\n';

  print_ip(std::string("192.168.1.1"));
  std::cout << '\n';

  print_ip(std::vector<std::string>{"192", "168", "1", "1"});
  std::cout << '\n';

  print_ip(std::list<unsigned int>{192, 168, 1, 1});
  std::cout << '\n';

  print_ip(std::make_tuple("192", "168", "1", "1"));
	std::cout << "\n";
 
 return 0; 
}