package algoritmos_ordenacao

func BubbleSort(arr []int) {
	if arr == nil || len(arr) <= 1 {
		return
	}

	n := len(arr)
	var swapped bool
	for i := 0; i < n-1; i++ {
		swapped = false
		for j := 0; j < n-i-1; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
				swapped = true
			}
		}
		if !swapped {
			break
		}
	}
}