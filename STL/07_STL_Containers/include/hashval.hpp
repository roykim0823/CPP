/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <functional>
#include <iostream>

// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html
template <typename T>
inline void hash_combine (std::size_t& seed, const T& val)
{
	//std::cout << "hash_combined" << std::endl;
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

// auxiliary generic functions to create a hash value using a seed
template <typename T>
inline void hash_val (std::size_t& seed, const T& val)
{
	//std::cout << "hash_val_v1" << std::endl;
    hash_combine(seed,val);
}

// Take a first arugement as a val 
template <typename T, typename... Types>
inline void hash_val (std::size_t& seed,
                      const T& val, const Types&... args)
{
	//std::cout << "hash_val_v2" << std::endl;
    hash_combine(seed,val);
    hash_val(seed,args...);
}

// auxiliary generic function to create a hash value out of a heterogeneous list of arguments
template <typename... Types>
inline std::size_t hash_val (const Types&... args)
{
	//std::cout << "hash_val (heter)" << std::endl;
    std::size_t seed = 0;
    hash_val (seed, args...);
    return seed;
}
