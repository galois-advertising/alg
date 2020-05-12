package heap

import "sort"

type IItems interface {
	sort.Interface
	Push(x interface{})
	Pop() interface{}
}

func left(idx int) int {
	return idx*2 + 1
}

func right(idx int) int {
	return idx*2 + 2
}

func parent(idx int) (int, bool) {
	if idx > 0 {
		return (idx - 1) / 2, true
	}
	return 0, false
}

func shift_up(heap IItems, idx int) {
	if p, ok := parent(idx); ok {
		if heap.Less(idx, p) {
			heap.Swap(idx, p)
			shift_up(heap, p)
		}
	}
}

func shift_down(heap IItems, idx int) {
	target := idx
	if left(idx) < heap.Len() && heap.Less(left(idx), target) {
		target = left(idx)
	}
	if right(idx) < heap.Len() && heap.Less(right(idx), target) {
		target = right(idx)
	}
	if target != idx {
		heap.Swap(idx, target)
		shift_down(heap, target)
	}
}

func Init(heap IItems) {
	if last_node, ok := parent(heap.Len()); ok {
		for last_node >= 0 {
			shift_down(heap, last_node)
			last_node--
		}
	}
}

func Remove(heap IItems, i int) interface{} {
	if i < 0 || i >= heap.Len() {
		return nil
	}
	heap.Swap(i, heap.Len()-1)
	ret := heap.Pop()
	shift_down(heap, i)
	return ret
}

func Pop(heap IItems) interface{} {
	if heap.Len() > 0 {
		return Remove(heap, 0)
	}
	return nil
}

func Push(heap IItems, i interface{}) {
	heap.Push(i)
	shift_up(heap, heap.Len()-1)
}
