package algoritmos_ordenacao

func heapify(arr []int, n int, i int) {
	largest := i
	leftChild := 2*i + 1
	rightChild := 2*i + 2

	if leftChild < n && arr[leftChild] > arr[largest] {
		largest = leftChild
	}

	if rightChild < n && arr[rightChild] > arr[largest] {
		largest = rightChild
	}

	if largest != i {
		arr[i], arr[largest] = arr[largest], arr[i]

		heapify(arr, n, largest)
	}
}

func HeapSort(arr []int) {
	if arr == nil || len(arr) <= 1 {
		return
	}

	n := len(arr)

	for i := n/2 - 1; i >= 0; i-- {
		heapify(arr, n, i)
	}

	for i := n - 1; i > 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]

		heapify(arr, i, 0)
	}
}