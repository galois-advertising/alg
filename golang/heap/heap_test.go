package heap

import (
	goheap "container/heap"
	"fmt"
	"testing"
)

type HeapItems []uint32

func (vec HeapItems) Less(i, j int) bool {
	return vec[i] < vec[j]
}

func (vec HeapItems) Len() int {
	return len(vec)
}

func (vec HeapItems) Swap(i, j int) {
	vec[i], vec[j] = vec[j], vec[i]
}

func (vec *HeapItems) Push(x interface{}) {
	*vec = append(*vec, x.(uint32))
}

func (vec *HeapItems) Pop() interface{} {
	old := *vec
	n := len(old)
	x := old[n-1]
	*vec = old[0 : n-1]
	return x
}

func Test_goheap(t *testing.T) {
	heap := HeapItems{9, 8, 7, 6, 5, 4}
	goheap.Init(&heap)
	goheap.Push(&heap, uint32(2))
	goheap.Push(&heap, uint32(1))
	fmt.Println(goheap.Pop(&heap))
}

func Test_myheap(t *testing.T) {
	heap := HeapItems{9, 8, 7, 6, 5, 4}
	Init(&heap)
	Push(&heap, uint32(2))
	Push(&heap, uint32(1))
	fmt.Println(Pop(&heap))
}
