#ifndef SPROUT_RANGE_ALGORITHM_FIT_SET_SYMMETRIC_DIFFERENCE_HPP
#define SPROUT_RANGE_ALGORITHM_FIT_SET_SYMMETRIC_DIFFERENCE_HPP

#include <sprout/config.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/algorithm/fit/set_symmetric_difference.hpp>

namespace sprout {
	namespace range {
		namespace fit {
			//
			// set_symmetric_difference
			//
			template<typename Input1, typename Input2, typename Result, typename Compare>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			set_symmetric_difference(Input1 const& input1, Input2 const& input2, Result const& result, Compare comp) {
				return sprout::fit::set_symmetric_difference(sprout::begin(input1), sprout::end(input1), sprout::begin(input2), sprout::end(input2), result, comp);
			}
			template<typename Input1, typename Input2, typename Result>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			set_symmetric_difference(Input1 const& input1, Input2 const& input2, Result const& result) {
				return sprout::fit::set_symmetric_difference(sprout::begin(input1), sprout::end(input1), sprout::begin(input2), sprout::end(input2), result);
			}
		}	// namespace fit
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ALGORITHM_FIT_SET_SYMMETRIC_DIFFERENCE_HPP
