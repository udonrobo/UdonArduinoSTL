/////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Electronic Arts Inc. All rights reserved.
/////////////////////////////////////////////////////////////////////////////////


#ifndef EASTL_ATOMIC_INTERNAL_STANDALONE_H
#define EASTL_ATOMIC_INTERNAL_STANDALONE_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


namespace std
{


////////////////////////////////////////////////////////////////////////////////
//
// bool atomic_compare_exchange_strong(std::atomic<T>*, T* expected, T desired)
//
template <typename T>
EASTL_FORCE_INLINE bool atomic_compare_exchange_strong(std::atomic<T>* atomicObj,
													   typename std::atomic<T>::value_type* expected,
													   typename std::atomic<T>::value_type desired) EA_NOEXCEPT
{
	return atomicObj->compare_exchange_strong(*expected, desired);
}

template <typename T, typename OrderSuccess, typename OrderFailure>
EASTL_FORCE_INLINE bool atomic_compare_exchange_strong_explicit(std::atomic<T>* atomicObj,
																typename std::atomic<T>::value_type* expected,
																typename std::atomic<T>::value_type desired,
																OrderSuccess orderSuccess, OrderFailure orderFailure) EA_NOEXCEPT
{
	return atomicObj->compare_exchange_strong(*expected, desired, orderSuccess, orderFailure);
}


////////////////////////////////////////////////////////////////////////////////
//
// bool atomic_compare_exchange_weak(std::atomic<T>*, T* expected, T desired)
//
template <typename T>
EASTL_FORCE_INLINE bool atomic_compare_exchange_weak(std::atomic<T>* atomicObj,
													 typename std::atomic<T>::value_type* expected,
													 typename std::atomic<T>::value_type desired) EA_NOEXCEPT
{
	return atomicObj->compare_exchange_weak(*expected, desired);
}

template <typename T, typename OrderSuccess, typename OrderFailure>
EASTL_FORCE_INLINE bool atomic_compare_exchange_weak_explicit(std::atomic<T>* atomicObj,
															  typename std::atomic<T>::value_type* expected,
															  typename std::atomic<T>::value_type desired,
															  OrderSuccess orderSuccess, OrderFailure orderFailure) EA_NOEXCEPT
{
	return atomicObj->compare_exchange_weak(*expected, desired, orderSuccess, orderFailure);
}


////////////////////////////////////////////////////////////////////////////////
//
// T atomic_fetch_xor(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_xor(std::atomic<T>* atomicObj,
																		  typename std::atomic<T>::value_type arg) EA_NOEXCEPT
{
	return atomicObj->fetch_xor(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_xor_explicit(std::atomic<T>* atomicObj,
																				   typename std::atomic<T>::value_type arg,
																				   Order order) EA_NOEXCEPT
{
	return atomicObj->fetch_xor(arg, order);
}


////////////////////////////////////////////////////////////////////////////////
//
// T atomic_xor_fetch(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_xor_fetch(std::atomic<T>* atomicObj,
																		  typename std::atomic<T>::value_type arg) EA_NOEXCEPT
{
	return atomicObj->xor_fetch(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_xor_fetch_explicit(std::atomic<T>* atomicObj,
																				   typename std::atomic<T>::value_type arg,
																				   Order order) EA_NOEXCEPT
{
	return atomicObj->xor_fetch(arg, order);
}


////////////////////////////////////////////////////////////////////////////////
//
// T atomic_fetch_or(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_or(std::atomic<T>* atomicObj,
																		 typename std::atomic<T>::value_type arg) EA_NOEXCEPT
{
	return atomicObj->fetch_or(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_or_explicit(std::atomic<T>* atomicObj,
																				  typename std::atomic<T>::value_type arg,
																				  Order order) EA_NOEXCEPT
{
	return atomicObj->fetch_or(arg, order);
}


////////////////////////////////////////////////////////////////////////////////
//
// T atomic_or_fetch(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_or_fetch(std::atomic<T>* atomicObj,
																		 typename std::atomic<T>::value_type arg) EA_NOEXCEPT
{
	return atomicObj->or_fetch(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_or_fetch_explicit(std::atomic<T>* atomicObj,
																				  typename std::atomic<T>::value_type arg,
																				  Order order) EA_NOEXCEPT
{
	return atomicObj->or_fetch(arg, order);
}


////////////////////////////////////////////////////////////////////////////////
//
// T atomic_fetch_and(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_and(std::atomic<T>* atomicObj,
																		  typename std::atomic<T>::value_type arg) EA_NOEXCEPT
{
	return atomicObj->fetch_and(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_and_explicit(std::atomic<T>* atomicObj,
																				   typename std::atomic<T>::value_type arg,
																				   Order order) EA_NOEXCEPT
{
	return atomicObj->fetch_and(arg, order);
}


////////////////////////////////////////////////////////////////////////////////
//
// T atomic_and_fetch(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_and_fetch(std::atomic<T>* atomicObj,
																		  typename std::atomic<T>::value_type arg) EA_NOEXCEPT
{
	return atomicObj->and_fetch(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_and_fetch_explicit(std::atomic<T>* atomicObj,
																				   typename std::atomic<T>::value_type arg,
																				   Order order) EA_NOEXCEPT
{
	return atomicObj->and_fetch(arg, order);
}


/////////////////////////////////////////////////////////////////////////////////
//
// T atomic_fetch_sub(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_sub(std::atomic<T>* atomicObj,
																		  typename std::atomic<T>::difference_type arg) EA_NOEXCEPT
{
	return atomicObj->fetch_sub(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_sub_explicit(std::atomic<T>* atomicObj,
																				   typename std::atomic<T>::difference_type arg,
																				   Order order) EA_NOEXCEPT
{
	return atomicObj->fetch_sub(arg, order);
}


/////////////////////////////////////////////////////////////////////////////////
//
// T atomic_sub_fetch(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_sub_fetch(std::atomic<T>* atomicObj,
																		  typename std::atomic<T>::difference_type arg) EA_NOEXCEPT
{
	return atomicObj->sub_fetch(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_sub_fetch_explicit(std::atomic<T>* atomicObj,
																				   typename std::atomic<T>::difference_type arg,
																				   Order order) EA_NOEXCEPT
{
	return atomicObj->sub_fetch(arg, order);
}


/////////////////////////////////////////////////////////////////////////////////
//
// T atomic_fetch_add(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_add(std::atomic<T>* atomicObj,
																		  typename std::atomic<T>::difference_type arg) EA_NOEXCEPT
{
	return atomicObj->fetch_add(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_fetch_add_explicit(std::atomic<T>* atomicObj,
																				   typename std::atomic<T>::difference_type arg,
																				   Order order) EA_NOEXCEPT
{
	return atomicObj->fetch_add(arg, order);
}


/////////////////////////////////////////////////////////////////////////////////
//
// T atomic_add_fetch(std::atomic<T>*, T arg)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_add_fetch(std::atomic<T>* atomicObj,
																		  typename std::atomic<T>::difference_type arg) EA_NOEXCEPT
{
	return atomicObj->add_fetch(arg);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_add_fetch_explicit(std::atomic<T>* atomicObj,
																				   typename std::atomic<T>::difference_type arg,
																				   Order order) EA_NOEXCEPT
{
	return atomicObj->add_fetch(arg, order);
}


/////////////////////////////////////////////////////////////////////////////////
//
// T atomic_exchange(std::atomic<T>*, T desired)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_exchange(std::atomic<T>* atomicObj,
																		 typename std::atomic<T>::value_type desired) EA_NOEXCEPT
{
	return atomicObj->exchange(desired);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_exchange_explicit(std::atomic<T>* atomicObj,
																				  typename std::atomic<T>::value_type desired,
																				  Order order) EA_NOEXCEPT
{
	return atomicObj->exchange(desired, order);
}


/////////////////////////////////////////////////////////////////////////////////
//
// T atomic_load(const std::atomic<T>*)
//
template <typename T>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_load(const std::atomic<T>* atomicObj) EA_NOEXCEPT
{
	return atomicObj->load();
}

template <typename T, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_load_explicit(const std::atomic<T>* atomicObj, Order order) EA_NOEXCEPT
{
	return atomicObj->load(order);
}


/////////////////////////////////////////////////////////////////////////////////
//
// T atomic_load_cond(const std::atomic<T>*)
//
template <typename T, typename Predicate>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_load_cond(const std::atomic<T>* atomicObj, Predicate pred) EA_NOEXCEPT
{
	for (;;)
	{
		typename std::atomic<T>::value_type ret = atomicObj->load();

		if (pred(ret))
		{
			return ret;
		}

		EASTL_ATOMIC_CPU_PAUSE();
	}
}

template <typename T, typename Predicate, typename Order>
EASTL_FORCE_INLINE typename std::atomic<T>::value_type atomic_load_cond_explicit(const std::atomic<T>* atomicObj, Predicate pred, Order order) EA_NOEXCEPT
{
	for (;;)
	{
		typename std::atomic<T>::value_type ret = atomicObj->load(order);

		if (pred(ret))
		{
			return ret;
		}

		EASTL_ATOMIC_CPU_PAUSE();
	}
}


/////////////////////////////////////////////////////////////////////////////////
//
// void atomic_store(std::atomic<T>*, T)
//
template <typename T>
EASTL_FORCE_INLINE void atomic_store(std::atomic<T>* atomicObj, typename std::atomic<T>::value_type desired) EA_NOEXCEPT
{
	atomicObj->store(desired);
}

template <typename T, typename Order>
EASTL_FORCE_INLINE void atomic_store_explicit(std::atomic<T>* atomicObj, typename std::atomic<T>::value_type desired, Order order) EA_NOEXCEPT
{
	atomicObj->store(desired, order);
}


/////////////////////////////////////////////////////////////////////////////////
//
// void std::atomic_thread_fence(Order)
//
template <typename Order>
EASTL_FORCE_INLINE void atomic_thread_fence(Order) EA_NOEXCEPT
{
	EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(Order);
}

EASTL_FORCE_INLINE void atomic_thread_fence(std::internal::memory_order_relaxed_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_THREAD_FENCE_RELAXED();
}

EASTL_FORCE_INLINE void atomic_thread_fence(std::internal::memory_order_acquire_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_THREAD_FENCE_ACQUIRE();
}

EASTL_FORCE_INLINE void atomic_thread_fence(std::internal::memory_order_release_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_THREAD_FENCE_RELEASE();
}

EASTL_FORCE_INLINE void atomic_thread_fence(std::internal::memory_order_acq_rel_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_THREAD_FENCE_ACQ_REL();
}

EASTL_FORCE_INLINE void atomic_thread_fence(std::internal::memory_order_seq_cst_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_THREAD_FENCE_SEQ_CST();
}


/////////////////////////////////////////////////////////////////////////////////
//
// void std::atomic_signal_fence(Order)
//
template <typename Order>
EASTL_FORCE_INLINE void atomic_signal_fence(Order) EA_NOEXCEPT
{
	EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(Order);
}

EASTL_FORCE_INLINE void atomic_signal_fence(std::internal::memory_order_relaxed_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_SIGNAL_FENCE_RELAXED();
}

EASTL_FORCE_INLINE void atomic_signal_fence(std::internal::memory_order_acquire_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_SIGNAL_FENCE_ACQUIRE();
}

EASTL_FORCE_INLINE void atomic_signal_fence(std::internal::memory_order_release_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_SIGNAL_FENCE_RELEASE();
}

EASTL_FORCE_INLINE void atomic_signal_fence(std::internal::memory_order_acq_rel_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_SIGNAL_FENCE_ACQ_REL();
}

EASTL_FORCE_INLINE void atomic_signal_fence(std::internal::memory_order_seq_cst_s) EA_NOEXCEPT
{
	EASTL_ATOMIC_SIGNAL_FENCE_SEQ_CST();
}


/////////////////////////////////////////////////////////////////////////////////
//
// void std::compiler_barrier()
//
EASTL_FORCE_INLINE void compiler_barrier() EA_NOEXCEPT
{
	EASTL_ATOMIC_COMPILER_BARRIER();
}


/////////////////////////////////////////////////////////////////////////////////
//
// void std::compiler_barrier_data_dependency(const T&)
//
template <typename T>
EASTL_FORCE_INLINE void compiler_barrier_data_dependency(const T& val) EA_NOEXCEPT
{
	EASTL_ATOMIC_COMPILER_BARRIER_DATA_DEPENDENCY(val, T);
}


/////////////////////////////////////////////////////////////////////////////////
//
// void std::cpu_pause()
//
EASTL_FORCE_INLINE void cpu_pause() EA_NOEXCEPT
{
	EASTL_ATOMIC_CPU_PAUSE();
}


/////////////////////////////////////////////////////////////////////////////////
//
// bool std::atomic_is_lock_free(std::atomic<T>*)
//
template <typename T>
EASTL_FORCE_INLINE bool atomic_is_lock_free(const std::atomic<T>* atomicObj) EA_NOEXCEPT
{
	return atomicObj->is_lock_free();
}


} // namespace std


#endif /* EASTL_ATOMIC_INTERNAL_STANDALONE_H */
