/*
 * stl.h -- a wrapper around STL containers.
 *
 * Copyright (c) 2007-2010, Dmitry Prokoptsev <dprokoptsev@gmail.com>,
 *                          Alexander Gololobov <agololobov@gmail.com>
 *
 * This file is part of Pire, the Perl Incompatible
 * Regular Expressions library.
 *
 * Pire is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Pire is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 * You should have received a copy of the GNU Lesser Public License
 * along with Pire.  If not, see <http://www.gnu.org/licenses>.
 */


/*
 * This file is autogenerated; do not edit.
 * Modify tools/mkstl.pl and regenerate the file if you need to.
 */
#ifndef PIRE_COMPAT_H_INCLUDED
#define PIRE_COMPAT_H_INCLUDED

#include "../defs.h"
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <utility>
#include <memory>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <functional>
#include <assert.h>

#ifdef PIRE_CHECKED
#define YASSERT(e) assert(e)
#else
#define YASSERT(e) do {} while (0)
#endif

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace Pire {
	template< class T, class A = std::allocator<T> >
	class yvector: public std::vector<T, A> {
	public:
		yvector(): std::vector<T, A>() {}

		template<class Arg1>
		yvector(Arg1 arg1): std::vector<T, A>(arg1) {}

		template<class Arg1, class Arg2>
		yvector(Arg1 arg1, Arg2 arg2): std::vector<T, A>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		yvector(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::vector<T, A>(arg1, arg2, arg3) {}
	};

	template< class T, class A = std::allocator<T> >
	class ydeque: public std::deque<T, A> {
	public:
		ydeque(): std::deque<T, A>() {}

		template<class Arg1>
		ydeque(Arg1 arg1): std::deque<T, A>(arg1) {}

		template<class Arg1, class Arg2>
		ydeque(Arg1 arg1, Arg2 arg2): std::deque<T, A>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		ydeque(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::deque<T, A>(arg1, arg2, arg3) {}
	};

	template< class T, class A = std::allocator<T> >
	class ylist: public std::list<T, A> {
	public:
		ylist(): std::list<T, A>() {}

		template<class Arg1>
		ylist(Arg1 arg1): std::list<T, A>(arg1) {}

		template<class Arg1, class Arg2>
		ylist(Arg1 arg1, Arg2 arg2): std::list<T, A>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		ylist(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::list<T, A>(arg1, arg2, arg3) {}
	};

	template< class K, class V, class C = std::less<K>, class A = std::allocator< std::pair<const K, V> > >
	class ymap: public std::map<K, V, C, A> {
	public:
		ymap(): std::map<K, V, C, A>() {}

		template<class Arg1>
		ymap(Arg1 arg1): std::map<K, V, C, A>(arg1) {}

		template<class Arg1, class Arg2>
		ymap(Arg1 arg1, Arg2 arg2): std::map<K, V, C, A>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		ymap(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::map<K, V, C, A>(arg1, arg2, arg3) {}
	};

	template< class T, class C = std::less<T>, class A = std::allocator<T> >
	class yset: public std::set<T, C, A> {
	public:
		yset(): std::set<T, C, A>() {}

		template<class Arg1>
		yset(Arg1 arg1): std::set<T, C, A>(arg1) {}

		template<class Arg1, class Arg2>
		yset(Arg1 arg1, Arg2 arg2): std::set<T, C, A>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		yset(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::set<T, C, A>(arg1, arg2, arg3) {}
	};

	template< class T >
	class yauto_ptr: public std::auto_ptr<T> {
	public:
		yauto_ptr(): std::auto_ptr<T>() {}

		template<class Arg1>
		yauto_ptr(Arg1 arg1): std::auto_ptr<T>(arg1) {}

		template<class Arg1, class Arg2>
		yauto_ptr(Arg1 arg1, Arg2 arg2): std::auto_ptr<T>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		yauto_ptr(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::auto_ptr<T>(arg1, arg2, arg3) {}
	};

	template< size_t N >
	class ybitset: public std::bitset<N> {
	public:
		ybitset(): std::bitset<N>() {}

		template<class Arg1>
		ybitset(Arg1 arg1): std::bitset<N>(arg1) {}

		template<class Arg1, class Arg2>
		ybitset(Arg1 arg1, Arg2 arg2): std::bitset<N>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		ybitset(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::bitset<N>(arg1, arg2, arg3) {}
	};

	template< class A, class B >
	class ypair: public std::pair<A, B> {
	public:
		ypair(): std::pair<A, B>() {}

		template<class Arg1>
		ypair(Arg1 arg1): std::pair<A, B>(arg1) {}

		template<class Arg1, class Arg2>
		ypair(Arg1 arg1, Arg2 arg2): std::pair<A, B>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		ypair(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::pair<A, B>(arg1, arg2, arg3) {}
	};

	template< class A, class B, class R >
	class ybinary_function: public std::binary_function<A, B, R> {
	public:
		ybinary_function(): std::binary_function<A, B, R>() {}

		template<class Arg1>
		ybinary_function(Arg1 arg1): std::binary_function<A, B, R>(arg1) {}

		template<class Arg1, class Arg2>
		ybinary_function(Arg1 arg1, Arg2 arg2): std::binary_function<A, B, R>(arg1, arg2) {}

		template<class Arg1, class Arg2, class Arg3>
		ybinary_function(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::binary_function<A, B, R>(arg1, arg2, arg3) {}
	};

	typedef std::string ystring;
	typedef std::istream yistream;
	typedef std::ostream yostream;

	template<class A, class B>
	inline ypair<A, B> ymake_pair(A a, B b) { return ypair<A, B>(a, b); }

	template<class T>
	inline const T& ymin(const T& a, const T& b) { return std::min(a, b); }

	template<class T>
	inline const T& ymax(const T& a, const T& b) { return std::max(a, b); }

	PIRE_IFDEBUG(static std::ostream& Cdbg = std::clog);

	inline yostream& Endl(yostream& s) { return std::endl(s); }

	template<class T>
	static inline void DoSwap(T& a, T& b) { std::swap(a, b); }

	template<class Iter, class T>
	static inline void Fill(Iter begin, Iter end, T t) { std::fill(begin, end, t); }
	
	template <class I, class T, class C>
	static inline I LowerBound(I f, I l, const T& v, C c) {
		return std::lower_bound(f, l, v, c);
	}

	class Error: public std::runtime_error {
	public:
		Error(const char* msg): std::runtime_error(msg) {}
		Error(const ystring& msg): std::runtime_error(msg) {}
	};

	template <class T1, class T2, class Stream>
	Stream& operator << (Stream& stream, const ypair<T1, T2>& val)
	{
		stream << "[" << val.first << ", " << val.second << "]";
		return stream;
	}

}

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif

#endif
