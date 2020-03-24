#pragma once

#define iParent(i) floor(((i)-1) / 2)
#define iLeftChild(i) 2*(i) + 1
#define iRightChild(i) 2*(i) + 2

template <typename Iter>
void make_heap(Iter begin, Iter end) {
      using _ValueType = typename iterator_traits<Iter>::value_type;
      using _DistanceType = typename iterator_traits<Iter>::difference_type;
      if (__last - __first < 2) {
          return;
      }
      const _DistanceType len = end - begin;
      _DistanceType __parent = (len - 2) / 2;

}