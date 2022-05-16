#pragma once
#include <iostream>
#include <type_traits>
#include <string>
#include <list>
#include <vector>
#include <tuple>
 /// References: https://en.cppreference.com/w/cpp/utility/tuple/tuple
 /// References: https://en.cppreference.com/w/cpp/utility/tuple/tuple_cat
 /// References: https://stackoverflow.com/questions/6245735/pretty-print-stdtuple
 /// References: https://stackoverflow.com/questions/37236109/how-to-check-the-type-of-passed-arguments-to-variadic-function

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
 * @brief Адрес представлен в виде произвольного целочисленного типа.
 * 
 * @tparam T - integral type
 * @param ip - IP aдрес 
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
 * @brief Адрес представлен в виде строки
 * 
 * @tparam T - std::string type
 * @param ip - IP aдрес 
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
* @brief Адрес представлен в виде контейнеров std::list/std::vector
*
* @tparam T - std::list/std::vector type
* @param ip - IP aдрес 
*/
template <typename T>
std::enable_if_t<is_vector_or_list<T>::value> print_ip(const T& ip) {
  for (const auto& it : ip) {
    std::cout << it;
    std::cout << (&it != &ip.back() ? "." : "");
  }
}
/**
 * @brief Вспомогательный функции помогающие определить однотипность элементов в Tuple
 * 
 * @tparam Args — значения, используемые для инициализации каждого элемента кортежа
 */

template <typename ... Args>
struct all_same : public std::false_type {};

template <typename T>
struct all_same<T> : public std::true_type {};

template <typename T, typename ... Args>
struct all_same<T, T, Args...> : public all_same<T, Args ... > {};

/**
 * @brief Вспомогательный класс с вспомогательной функцией для печати Tuple любого размера 
 * 
 * @tparam T - std::tuple
 * @tparam N - размер std::tuple
 */

template<class Tuple, std::size_t N>
struct TuplePrinter {
	static void print(const Tuple& t) {
		TuplePrinter<Tuple, N - 1>::print(t);
		std::cout << "." << std::get<N - 1>(t);
	}
};
/**
 * @brief Вспомогательный класс с вспомогательной функцией для печати Tuple одного элемента  
 * 
 * @tparam T - std::tuple
 * @tparam N - размер std::tuple =1
 */

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
	static void print(const Tuple& t) {
		std::cout << std::get<0>(t);
	}
};
/**
 * @brief Вспомогательная функцией для печати Tuple одного элемента 
 * 
 * @tparam Args — значения, используемые для инициализации каждого элемента кортежа 
 */
template<class... Args>
void print(const std::tuple<Args...>& t) {
  //Код для проверки того, имеют ли переданные аргументы один и тот же тип
  static_assert(all_same<Args ...>::value, "Params must have same types");
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
}

