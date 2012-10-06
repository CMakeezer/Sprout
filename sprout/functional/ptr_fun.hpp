#ifndef SPROUT_FUNCTIONAL_PTR_FUN_HPP
#define SPROUT_FUNCTIONAL_PTR_FUN_HPP

#include <sprout/config.hpp>
#include <sprout/functional/base.hpp>

namespace sprout {
	// D.8.2.1 adaptors (deprecated)

	template<typename Arg, typename Result>
	class pointer_to_unary_function
		: public sprout::unary_function<Arg, Result>
	{
	protected:
		Result (*ptr_)(Arg);
	public:
		pointer_to_unary_function() = default;
		explicit SPROUT_CONSTEXPR pointer_to_unary_function(Result (*x)(Arg))
			: ptr_(x)
		{}
		SPROUT_CONSTEXPR Result operator()(Arg x) const {
			return ptr_(x);
		}
	};

	template<typename Arg, typename Result>
	inline SPROUT_CONSTEXPR sprout::pointer_to_unary_function<Arg, Result>
	ptr_fun(Result (*x)(Arg)) {
		return sprout::pointer_to_unary_function<Arg, Result>(x);
	}

	template<typename Arg1, typename Arg2, typename Result>
	class pointer_to_binary_function
		: public sprout::binary_function<Arg1, Arg2, Result>
	{
	protected:
		Result (*ptr_)(Arg1, Arg2);
	public:
		pointer_to_binary_function() = default;
		explicit SPROUT_CONSTEXPR pointer_to_binary_function(Result (*x)(Arg1, Arg2))
			: ptr_(x)
		{}
		SPROUT_CONSTEXPR Result operator()(Arg1 x, Arg2 y) const {
			return ptr_(x, y);
		}
	};

	template<typename Arg1, typename Arg2, typename Result>
	inline SPROUT_CONSTEXPR sprout::pointer_to_binary_function<Arg1, Arg2, Result>
	ptr_fun(Result (*x)(Arg1, Arg2)) {
		return sprout::pointer_to_binary_function<Arg1, Arg2, Result>(x);
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_FUNCTIONAL_PTR_FUN_HPP
