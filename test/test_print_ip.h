#pragma once
#include <iostream>
#include <type_traits>
#include <string>
#include <list>
#include <vector>
#include <tuple>

template <typename T>
typename std::enable_if_t<std::is_integral<T>::value> print_ip(const T& ip) {
  for (size_t sz = sizeof(T); sz != 0; --sz) {
    std::cout << ((ip >> (8 * (sz - 1))) & 0xff)
      << (sz != 1 ? "." : "");
  }
}


template <typename T>
struct is_string : std::false_type {};
template <>
struct is_string<std::string> : std::true_type {};


template <typename T>
typename std::enable_if<is_string<T>::value>::type print_ip(const T& ip) {
  std::cout << ip;
}


template <typename T>
struct is_vector_or_list : std::false_type {};

template <typename... Args>
struct is_vector_or_list<std::vector<Args ...> > : std::true_type {};

template <typename... Args>
struct is_vector_or_list<std::list<Args ...> > : std::true_type {};


template <typename T>
std::enable_if_t<is_vector_or_list<T>::value> print_ip(const T& ip) {
  for (const auto& it : ip) {
    std::cout << it;
    std::cout << (&it != &ip.back() ? "." : "");
  }
}


template <typename ... Args>
struct all_same : public std::false_type {};

template <typename T>
struct all_same<T> : public std::true_type {};

template <typename T, typename ... Args>
struct all_same<T, T, Args...> : public all_same<T, Args ... > {};


template<class Tuple, std::size_t N>
struct TuplePrinter {
	static void print_ip(const Tuple& t) {
		TuplePrinter<Tuple, N - 1>::print_ip(t);
		std::cout << "." << std::get<N - 1>(t);
	}
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
	static void print_ip(const Tuple& t) {
		std::cout << std::get<0>(t);
	}
};

template<class... Args>
void print_ip(const std::tuple<Args...>& t) {
  static_assert(all_same<Args ...>::value, "Params must have same types");
	TuplePrinter<decltype(t), sizeof...(Args)>::print_ip(t);
}

