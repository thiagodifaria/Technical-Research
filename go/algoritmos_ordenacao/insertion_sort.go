package algoritmos_ordenacao

func InsertionSort(arr []int) {
	if arr == nil || len(arr) <= 1 {
		return
	}

	n := len(arr)
	for i := 1; i < n; i++ {
		key := arr[i]
		j := i - 1

		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j = j - 1
		}
		arr[j+1] = key
	}
}