#pragma once
#include <iostream>
#include <type_traits>
#include <string>
#include <list>
#include <vector>
#include <tuple>

/**
 * Convert an UInt32 into an IP String 
 * String equivilant format: "xxx.xxx.xxx.xxx" 
 * public String UInt32ToIPAdd(UInt32 UIntIP) {
 *    return (UIntIP >> 24) + "." +              
 *          ((UIntIP >> 16) & 0xff) + "." +     
 *          ((UIntIP >> 8) & 0xff) + "." +       
 *          (UIntIP & 0xff);
 *  }
 */

///@file
 
 //integral type
/**
 * @brief   Адрес представлен в виде произвольного целочисленного типа.
 * 
 * @tparam  T - integral type)
 * @param   ip - IP aдрес 
 */

template <typename T>
typename std::enable_if_t<std::is_integral<T>::value> print_ip(const T& ip) {
  for (size_t sz = sizeof(T); sz != 0; --sz) {
    std::cout << ((ip >> (8 * (sz - 1))) & 0xff)
      << (sz != 1 ? "." : "");
  }
}

//std::string type
template <typename T>
struct is_string : std::false_type {};
template <>
struct is_string<std::string> : std::true_type {};

/**
 * @brief   Адрес представлен в виде строки
 * 
 * @tparam  T - std::string type
 * @param   ip - IP aдрес 
 */
template <typename T>
typename std::enable_if<is_string<T>::value>::type print_ip(const T& ip) {
  std::cout << ip;
}


template <typename T>
struct is_vector_or_list : std::false_type {};
//std::vector
template <typename... Args>
struct is_vector_or_list<std::vector<Args ...> > : std::true_type {};
//std::list
template <typename... Args>
struct is_vector_or_list<std::list<Args ...> > : std::true_type {};

/**
* @brief    Адрес представлен в виде контейнеров std::list/std::vector
*
* @tparam   T - std::list/std::vector type
* @param    ip - IP aдрес 
*/
template <typename T>
std::enable_if_t<is_vector_or_list<T>::value> print_ip(const T& ip) {
  for (const auto& it : ip) {
    std::cout << it;
    std::cout << (&it != &ip.back() ? "." : "");
  }
}

/**
* @brief    Адрес представлен в виде `std::tuple`
*
* @tparam   T - std::tuple
* @param    ip - IP aдрес 
*/


