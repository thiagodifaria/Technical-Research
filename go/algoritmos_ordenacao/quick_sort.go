package algoritmos_ordenacao

func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1

	for j := low; j < high; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

func quickSortRecursive(arr []int, low, high int) {
	if low < high {
		partitionIndex := partition(arr, low, high)

		quickSortRecursive(arr, low, partitionIndex-1)
		quickSortRecursive(arr, partitionIndex+1, high)
	}
}

func QuickSort(arr []int) {
	if arr == nil || len(arr) <= 1 {
		return
	}
	quickSortRecursive(arr, 0, len(arr)-1)
}