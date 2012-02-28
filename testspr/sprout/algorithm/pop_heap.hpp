#ifndef TESTSPR_SPROUT_ALGORITHM_POP_HEAP_HPP
#define TESTSPR_SPROUT_ALGORITHM_POP_HEAP_HPP

#include <sprout/algorithm/pop_heap.hpp>
#include <sprout/array.hpp>
#include <sprout/sub_array.hpp>
#include <sprout/fixed_container.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void algorithm_pop_heap_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 10>{{10, 8, 9, 6, 7, 5, 3, 1, 2, 4}};

			// �q�[�v����|�b�v
			{
				SPROUT_STATIC_CONSTEXPR auto heap = sprout::pop_heap(
					arr1
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					heap,
					array<int, 10>{{9, 8, 5, 6, 7, 4, 3, 1, 2, 10}}
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto heap = sprout::fit::pop_heap(
					arr1
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					heap,
					array<int, 9>{{9, 8, 5, 6, 7, 4, 3, 1, 2}}
					));
			}
			// �q�[�v����|�b�v
			// �͈͂̐؂�o��
			{
				SPROUT_STATIC_CONSTEXPR auto heap = sprout::pop_heap(
					sprout::sub(arr1, 2, 10)
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					heap,
					array<int, 8>{{7, 6, 4, 5, 3, 1, 2, 9}}
					));
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					sprout::get_fixed(heap),
					array<int, 10>{{10, 8, 7, 6, 4, 5, 3, 1, 2, 9}}
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto heap = sprout::fit::pop_heap(
					sprout::sub(arr1, 2, 10)
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					heap,
					array<int, 7>{{7, 6, 4, 5, 3, 1, 2}}
					));
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					sprout::get_fixed(heap),
					array<int, 10>{{10, 8, 7, 6, 4, 5, 3, 1, 2, 9}}
					));
			}
		}
	}
}	// namespace testspr

#endif	// #ifndef TESTSPR_SPROUT_ALGORITHM_POP_HEAP_HPP
