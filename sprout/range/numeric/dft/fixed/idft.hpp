#ifndef SPROUT_RANGE_NUMERIC_DFT_FIXED_IDFT_HPP
#define SPROUT_RANGE_NUMERIC_DFT_FIXED_IDFT_HPP

#include <sprout/config.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fixed/result_of.hpp>
#include <sprout/numeric/dft/fixed/idft.hpp>

namespace sprout {
	namespace range {
		namespace fixed {
			//
			// idft
			//
			template<typename Input, typename Result>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			idft(Input const& input, Result const& result) {
				return sprout::fixed::idft(sprout::begin(input), sprout::end(input), result);
			}
		}	// namespace fixed

		using sprout::range::fixed::idft;
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_NUMERIC_DFT_FIXED_IDFT_HPP
