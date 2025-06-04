package algoritmos_ordenacao

import (
	"math/rand"
	"reflect"
	"sort"
	"testing"
	"time"
)

func TestMergeSort(t *testing.T) {
	testCases := []struct {
		name     string
		input    []int
		expected []int
	}{
		{"nil slice", nil, nil},
		{"empty slice", []int{}, []int{}},
		{"single element", []int{5}, []int{5}},
		{"already sorted", []int{1, 2, 3, 4, 5}, []int{1, 2, 3, 4, 5}},
		{"reverse sorted", []int{5, 4, 3, 2, 1}, []int{1, 2, 3, 4, 5}},
		{"with duplicates", []int{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5}, []int{1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9}},
		{"with negative numbers", []int{-3, 1, -4, 0, 5, -9, 2}, []int{-9, -4, -3, 0, 1, 2, 5}},
		{"all same elements", []int{7, 7, 7, 7, 7}, []int{7, 7, 7, 7, 7}},
	}

	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {
			var inputCopy []int
			if tc.input != nil {
				inputCopy = make([]int, len(tc.input))
				copy(inputCopy, tc.input)
			}
			MergeSort(inputCopy)
			if !reflect.DeepEqual(inputCopy, tc.expected) {
				t.Errorf("MergeSort(%v) = %v, want %v", tc.input, inputCopy, tc.expected)
			}
		})
	}

	t.Run("random small", func(t *testing.T) {
		r := rand.New(rand.NewSource(time.Now().UnixNano()))
		input := make([]int, 10)
		for i := range input {
			input[i] = r.Intn(201) - 100
		}
		expected := make([]int, len(input))
		copy(expected, input)
		sort.Ints(expected)

		inputCopy := make([]int, len(input))
		copy(inputCopy, input)
		MergeSort(inputCopy)
		if !reflect.DeepEqual(inputCopy, expected) {
			t.Errorf("MergeSort(random small %v) = %v, want %v", input, inputCopy, expected)
		}
	})

	t.Run("random moderate", func(t *testing.T) {
		r := rand.New(rand.NewSource(time.Now().UnixNano()))
		input := make([]int, 100)
		for i := range input {
			input[i] = r.Intn(2001) - 1000
		}
		expected := make([]int, len(input))
		copy(expected, input)
		sort.Ints(expected)

		inputCopy := make([]int, len(input))
		copy(inputCopy, input)
		MergeSort(inputCopy)
		if !reflect.DeepEqual(inputCopy, expected) {
			t.Errorf("MergeSort(random moderate %v) = %v, want %v", input, inputCopy, expected)
		}
	})
}