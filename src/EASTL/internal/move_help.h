/////////////////////////////////////////////////////////////////////////////
// Copyright (c) Electronic Arts Inc. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef EASTL_INTERNAL_MOVE_HELP_H
#define EASTL_INTERNAL_MOVE_HELP_H


#include <EABase/eabase.h>
#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif

#include <EASTL/internal/config.h>
#include <EASTL/type_traits.h>


// C++11's rvalue references aren't supported by earlier versions of C++.
// It turns out that in a number of cases under earlier C++ versions we can
// write code that uses rvalues similar to lvalues. We have macros below for
// such cases. For example, std::move (same as std::move) can be treated
// as a no-op under C++03, though with the consequence that move functionality
// isn't taken advantage of.


/// EASTL_MOVE
/// Acts like std::move when possible. Same as C++11 std::move.
///
/// EASTL_MOVE_INLINE
/// Acts like std::move but is implemented inline instead of a function call.
/// This allows code to be faster in debug builds in particular.
/// Depends on C++ compiler decltype support or a similar extension.
///
/// EASTL_FORWARD
/// Acts like std::forward when possible. Same as C++11 std::forward.
///
/// EASTL_FORWARD_INLINE
/// Acts like std::forward but is implemented inline instead of a function call.
/// This allows code to be faster in debug builds in particular.
///
#define EASTL_MOVE(x)              std::move(x)
#if !defined(EA_COMPILER_NO_DECLTYPE)
	#define EASTL_MOVE_INLINE(x)   static_cast<typename std::remove_reference<decltype(x)>::type&&>(x)
#elif defined(__GNUC__)
	#define EASTL_MOVE_INLINE(x)   static_cast<typename std::remove_reference<__typeof__(x)>::type&&>(x)
#else
	#define EASTL_MOVE_INLINE(x)   std::move(x)
#endif

#define EASTL_FORWARD(T, x)        std::forward<T>(x)
#define EASTL_FORWARD_INLINE(T, x) std::forward<T>(x)  // Need to investigate how to properly make a macro for this. (std::is_reference<T>::value ? static_cast<T&&>(static_cast<T&>(x)) : static_cast<T&&>(x))




/// EASTL_MOVE_RANGE
/// Acts like the std::move algorithm when possible. Same as C++11 std::move.
/// Note to be confused with the single argument move: (typename remove_reference<T>::type&& move(T&& x))
/// http://en.cppreference.com/w/cpp/algorithm/move
/// http://en.cppreference.com/w/cpp/algorithm/move_backward
///
#define EASTL_MOVE_RANGE(first, last, result)             std::move(first, last, result)
#define EASTL_MOVE_BACKWARD_RANGE(first, last, resultEnd) std::move_backward(first, last, resultEnd)


namespace std
{
	// forward
	//
	// forwards the argument to another function exactly as it was passed to the calling function.
	// Not to be confused with move, this is specifically for echoing templated argument types
	// to another function. move is specifically about making a type be an rvalue reference (i.e. movable) type.
	//
	// Example usage:
	//     template <class T>
	//     void WrapperFunction(T&& arg)
	//         { foo(std::forward<T>(arg)); }
	//
	//     template <class... Args>
	//     void WrapperFunction(Args&&... args)
	//         { foo(std::forward<Args>(args)...); }
	//
	// See the C++ Standard, section 20.2.3
	// http://en.cppreference.com/w/cpp/utility/forward
	//
	template <typename T>
	constexpr T&& forward(typename std::remove_reference<T>::type& x) EA_NOEXCEPT
	{
		return static_cast<T&&>(x);
	}


	template <typename T>
	constexpr T&& forward(typename std::remove_reference<T>::type&& x) EA_NOEXCEPT
	{
		static_assert(!is_lvalue_reference<T>::value, "forward T isn't lvalue reference");
		return static_cast<T&&>(x);
	}


	// move
	//
	// move obtains an rvalue reference to its argument and converts it to an xvalue.
	// Returns, by definition: static_cast<typename remove_reference<T>::type&&>(t).
	// The primary use of this is to pass a move'd type to a function which takes T&&,
	// and thus select that function instead of (e.g.) a function which takes T or T&.
	// See the C++ Standard, section 20.2.3
	// http://en.cppreference.com/w/cpp/utility/move
	//
	template <typename T>
	constexpr typename std::remove_reference<T>::type&&
	move(T&& x) EA_NOEXCEPT
	{
		return static_cast<typename std::remove_reference<T>::type&&>(x);
	}


	// move_if_noexcept
	//
	// Returns T&& if move-constructing T throws no exceptions. Instead returns const T& if
	// move-constructing T throws exceptions or has no accessible copy constructor.
	// The purpose of this is to use automatically use copy construction instead of move
	// construction when the move may possible throw an exception.
	// See the C++ Standard, section 20.2.3
	// http://en.cppreference.com/w/cpp/utility/move_if_noexcept
	//
	#if EASTL_EXCEPTIONS_ENABLED
		template <typename T>
		constexpr typename std::conditional<!std::is_nothrow_move_constructible<T>::value &&
														std::is_copy_constructible<T>::value, const T&, T&&>::type
		move_if_noexcept(T& x) EA_NOEXCEPT
		{
			return std::move(x);
		}
	#else
		template <typename T>
		constexpr T&&
		move_if_noexcept(T& x) EA_NOEXCEPT
		{
			return std::move(x);
		}
	#endif

} // namespace std

#endif // Header include guard















