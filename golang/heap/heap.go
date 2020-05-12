package heap

type Comparable interface {
	LessThan(j interface{}) bool
	EqualTo(j interface{}) bool
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

func heap_shift(heap []Comparable, idx int, heap_len int) {
	target := idx
	if left(idx) < heap_len && heap[left(idx)].LessThan(heap[target]) {
		target = left(idx)
	}
	if right(idx) < heap_len && heap[right(idx)].LessThan(heap[target]) {
		target = right(idx)
	}
	if target != idx {
		heap[idx], heap[target] = heap[target], heap[idx]
		heap_shift(heap, target, heap_len)
	}
}

func heap_make(heap []Comparable, heap_len int) {
	if last_node, ok := parent(heap_len); ok {
		for last_node >= 0 {
			heap_shift(heap, last_node, heap_len)
			last_node--
		}
	}
}

func heap_push(heap *[]Comparable, node Comparable) {
	*heap = append(*heap, node)
}

func heap_pop(heap []Comparable, heap_len int) Comparable {
	if heap_len == 0 {
		return nil
	}
	heap[0], heap[heap_len-1] = heap[heap_len-1], heap[0]
	heap_shift(heap, 0, heap_len-1)
	return heap[heap_len-1]
}
