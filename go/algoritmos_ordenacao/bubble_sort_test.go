package algoritmos_ordenacao

import (
	"math/rand"
	"reflect"
	"sort"
	"testing"
	"time"
)

func TestBubbleSort(t *testing.T) {
	testCases := []struct {
		name     string
		input    []int
		expected []int
	}{
		{
			name:     "nil slice",
			input:    nil,
			expected: nil,
		},
		{
			name:     "empty slice",
			input:    []int{},
			expected: []int{},
		},
		{
			name:     "single element",
			input:    []int{5},
			expected: []int{5},
		},
		{
			name:     "already sorted",
			input:    []int{1, 2, 3, 4, 5},
			expected: []int{1, 2, 3, 4, 5},
		},
		{
			name:     "reverse sorted",
			input:    []int{5, 4, 3, 2, 1},
			expected: []int{1, 2, 3, 4, 5},
		},
		{
			name:     "with duplicates",
			input:    []int{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5},
			expected: []int{1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9},
		},
		{
			name:     "with negative numbers",
			input:    []int{-3, 1, -4, 0, 5, -9, 2},
			expected: []int{-9, -4, -3, 0, 1, 2, 5},
		},
		{
			name:     "all same elements",
			input:    []int{7, 7, 7, 7, 7},
			expected: []int{7, 7, 7, 7, 7},
		},
	}

	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {

			var inputCopy []int
			if tc.input != nil {
				inputCopy = make([]int, len(tc.input))
				copy(inputCopy, tc.input)
			}

			BubbleSort(inputCopy)

			if !reflect.DeepEqual(inputCopy, tc.expected) {
				t.Errorf("BubbleSort(%v) = %v, want %v", tc.input, inputCopy, tc.expected)
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
		BubbleSort(inputCopy)

		if !reflect.DeepEqual(inputCopy, expected) {
			t.Errorf("BubbleSort(random small %v) = %v, want %v", input, inputCopy, expected)
		}
	})

	t.Run("random moderate", func(t *testing.T) {
		r := rand.New(rand.NewSource(time.Now().UnixNano()))
		input := make([]int, 50)
		for i := range input {
			input[i] = r.Intn(2001) - 1000
		}

		expected := make([]int, len(input))
		copy(expected, input)
		sort.Ints(expected)

		inputCopy := make([]int, len(input))
		copy(inputCopy, input)
		BubbleSort(inputCopy)

		if !reflect.DeepEqual(inputCopy, expected) {
			t.Errorf("BubbleSort(random moderate %v) = %v, want %v", input, inputCopy, expected)
		}
	})
}