/////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Electronic Arts Inc. All rights reserved.
/////////////////////////////////////////////////////////////////////////////////


#ifndef EASTL_ATOMIC_INTERNAL_FLAG_STANDALONE_H
#define EASTL_ATOMIC_INTERNAL_FLAG_STANDALONE_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


namespace std
{


////////////////////////////////////////////////////////////////////////////////
//
// bool atomic_flag_test_and_set(std::atomic<T>*)
//
EASTL_FORCE_INLINE bool atomic_flag_test_and_set(std::atomic_flag* atomicObj) EA_NOEXCEPT
{
	return atomicObj->test_and_set();
}

template <typename Order>
EASTL_FORCE_INLINE bool atomic_flag_test_and_set_explicit(std::atomic_flag* atomicObj, Order order)
{
	return atomicObj->test_and_set(order);
}


////////////////////////////////////////////////////////////////////////////////
//
// bool atomic_flag_clear(std::atomic<T>*)
//
EASTL_FORCE_INLINE void atomic_flag_clear(std::atomic_flag* atomicObj)
{
	atomicObj->clear();
}

template <typename Order>
EASTL_FORCE_INLINE void atomic_flag_clear_explicit(std::atomic_flag* atomicObj, Order order)
{
	atomicObj->clear(order);
}


////////////////////////////////////////////////////////////////////////////////
//
// bool atomic_flag_test(std::atomic<T>*)
//
EASTL_FORCE_INLINE bool atomic_flag_test(std::atomic_flag* atomicObj)
{
	return atomicObj->test();
}

template <typename Order>
EASTL_FORCE_INLINE bool atomic_flag_test_explicit(std::atomic_flag* atomicObj, Order order)
{
	return atomicObj->test(order);
}


} // namespace std


#endif /* EASTL_ATOMIC_INTERNAL_FLAG_STANDALONE_H */
