package algoritmos_ordenacao

func merge(arr []int, left, middle, right int) {
	n1 := middle - left + 1
	n2 := right - middle

	L := make([]int, n1)
	R := make([]int, n2)

	for i := 0; i < n1; i++ {
		L[i] = arr[left+i]
	}
	for j := 0; j < n2; j++ {
		R[j] = arr[middle+1+j]
	}

	i, j := 0, 0
	k := left

	for i < n1 && j < n2 {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
		k++
	}

	for i < n1 {
		arr[k] = L[i]
		i++
		k++
	}

	for j < n2 {
		arr[k] = R[j]
		j++
		k++
	}
}

func mergeSortRecursive(arr []int, left, right int) {
	if left < right {
		middle := left + (right-left)/2

		mergeSortRecursive(arr, left, middle)
		mergeSortRecursive(arr, middle+1, right)

		merge(arr, left, middle, right)
	}
}

func MergeSort(arr []int) {
	if arr == nil || len(arr) <= 1 {
		return
	}
	mergeSortRecursive(arr, 0, len(arr)-1)
}