///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Electronic Arts Inc. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// This file defines random number generation like the std C++ <random> header.
///////////////////////////////////////////////////////////////////////////////


#ifndef EASTL_RANDOM_H
#define EASTL_RANDOM_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#include <EASTL/internal/config.h>
#include <EASTL/numeric_limits.h>



///////////////////////////////////////////////////////////////////////////////
// min/max workaround
//
// MSVC++ has #defines for min/max which collide with the min/max algorithm
// declarations. The following may still not completely resolve some kinds of
// problems with MSVC++ #defines, though it deals with most cases in production
// game code.
//
#if EASTL_NOMINMAX
	#ifdef min
		#undef min
	#endif
	#ifdef max
		#undef max
	#endif
#endif


namespace std
{

	// Implements a uniform distribution of values generated by a Generator,
	// where Generator is typically a random or pseudo-random number generator.
	// Note that the min/max range for this class is inclusive, so if you want
	// random integers 0, 1, 2, and 3, then you need to init this class with (0, 3)
	// and not (0, 4).
	// See the C++11 Standard, section 26.5.1.6
	template<class IntType = int>
	class uniform_int_distribution
	{
		static_assert(std::is_integral<IntType>::value, "uniform_int_distribution: IntType must be integral.");

	public:
		typedef IntType result_type;

		// For uniform_int_distribution, param_type defines simply the min and max values of
		// the range returned by operator(). It may mean something else for other distribution types.
		struct param_type
		{
			explicit param_type(IntType a = 0, IntType b = std::numeric_limits<IntType>::max());

			result_type a() const;
			result_type b() const;

			bool operator==(const param_type& x) { return (x.mA == mA) && (x.mB == mB); }
			bool operator!=(const param_type& x) { return (x.mA != mA) || (x.mB != mB); }

		protected:
			IntType mA;
			IntType mB;
		};

		uniform_int_distribution(IntType a = 0, IntType b = std::numeric_limits<IntType>::max());
		uniform_int_distribution(const param_type& params);

		void reset();

		template<class Generator>
		result_type operator()(Generator& g);

		template<class Generator>
		result_type operator()(Generator& g, const param_type& params);

		result_type a() const;
		result_type b() const;

		param_type param() const;
		void param(const param_type& params);

		result_type min() const;
		result_type max() const;

		protected:
			param_type mParam;
	};



	///////////////////////////////////////////////////////////////////////
	// uniform_int_distribution
	///////////////////////////////////////////////////////////////////////

	template<class IntType>
	inline uniform_int_distribution<IntType>::param_type::param_type(IntType aValue, IntType bValue)
	  : mA(aValue), mB(bValue)
	{
		EASTL_ASSERT(aValue <= bValue);
	}

	template<class IntType>
	inline typename uniform_int_distribution<IntType>::result_type
	uniform_int_distribution<IntType>::param_type::a() const
	{
		return mA;
	}

	template<class IntType>
	inline typename uniform_int_distribution<IntType>::result_type
	uniform_int_distribution<IntType>::param_type::b() const
	{
		return mB;
	}



	template<class IntType>
	inline uniform_int_distribution<IntType>::uniform_int_distribution(IntType aValue, IntType bValue)
	  : mParam(aValue, bValue)
	{
		// Nothing more to do.
	}

	template<class IntType>
	inline uniform_int_distribution<IntType>::uniform_int_distribution(const param_type& params)
	  : mParam(params)
	{
		// Nothing more to do.
	}

	template<class IntType>
	void uniform_int_distribution<IntType>::reset()
	{
		// Nothing to do.
	}

	template<class IntType>
	template<class Generator>
	inline typename uniform_int_distribution<IntType>::result_type
	uniform_int_distribution<IntType>::operator()(Generator& g)
	{
		return operator()(g, mParam);
	}

	template<class IntType>
	template<class Generator>
	inline typename uniform_int_distribution<IntType>::result_type
	uniform_int_distribution<IntType>::operator()(Generator& g, const param_type& params)
	{
		// This is a tricky function to implement in a generic way for all integral types.
		// The solution will involve handling the case of signed types and 64 bit types,
		// probably in a way that uses template metaprogramming to deal with signed ranges.

		// Temporary solution while we research a full solution. It supports only uint8_t,
		// uint16_t, and uint32_t uniform_int_distribution types.
		static_assert(std::is_unsigned<result_type>::value && (sizeof(result_type) <= 4), "uniform_int_distribution currently supports only uint8_t, uint16_t, uint32_t.");

		result_type v = g();    // Generates a value in the range of (numeric_limits<result_type>::min(), numeric_limits<result_type>::max()).
		result_type r = (result_type)((v * (uint64_t)((params.b() - params.a()) + 1)) >> (sizeof(result_type) * 8)); // +1 because ranges are inclusive.
		return params.a() + r;
	}

	template<class IntType>
	inline typename uniform_int_distribution<IntType>::result_type
	uniform_int_distribution<IntType>::a() const
	{
		return mParam.mA;
	}

	template<class IntType>
	inline typename uniform_int_distribution<IntType>::result_type
	uniform_int_distribution<IntType>::b() const
	{
		return mParam.mB;
	}


	template<class IntType>
	inline typename uniform_int_distribution<IntType>::param_type
	uniform_int_distribution<IntType>::param() const
	{
		return mParam;
	}

	template<class IntType>
	inline void
	uniform_int_distribution<IntType>::param(const param_type& params)
	{
		mParam = params;
	}

	template<class IntType>
	inline typename uniform_int_distribution<IntType>::result_type
	uniform_int_distribution<IntType>::min() const
	{
		return mParam.mA;
	}

	template<class IntType>
	inline typename uniform_int_distribution<IntType>::result_type
	uniform_int_distribution<IntType>::max() const
	{
		return mParam.mB;
	}



	template<class ResultType>
	inline bool operator==(const uniform_int_distribution<ResultType>& lhs,
						   const uniform_int_distribution<ResultType>& rhs)
	{
		return (lhs.param() == rhs.param());
	}

	template<class ResultType>
	inline bool operator!=(const uniform_int_distribution<ResultType>& lhs,
						   const uniform_int_distribution<ResultType>& rhs)
	{
		return (lhs.param() != rhs.param());
	}


	// EASTL doesn't currently implement IO stream-related functionality.
	// It may be useful to forward declare these templates and let the user implement them in the meantime.
	//
	// template<class CharT, class Traits, class ResultType>
	// std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const uniform_int_distribution& uid);
	//
	// template<class CharT, class Traits, class ResultType>
	// std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>& is, uniform_int_distribution& uid);


} // namespace std


#endif // Header include guard







