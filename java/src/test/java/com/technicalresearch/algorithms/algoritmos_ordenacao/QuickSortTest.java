package com.technicalresearch.algorithms.algoritmos_ordenacao;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;

import java.util.Arrays;
import java.util.Random;

class QuickSortTest {

    private QuickSort quickSort;

    @BeforeEach
    void setUp() {
        quickSort = new QuickSort();
    }

    @Test
    void testNullArray() {
        int[] arr = null;
        assertDoesNotThrow(() -> quickSort.sort(arr));
    }

    @Test
    void testEmptyArray() {
        int[] arr = {};
        int[] expected = {};
        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testSingleElementArray() {
        int[] arr = {5};
        int[] expected = {5};
        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testSortedArray() {
        int[] arr = {1, 2, 3, 4, 5};
        int[] expected = {1, 2, 3, 4, 5};
        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testReverseSortedArray() {
        int[] arr = {5, 4, 3, 2, 1};
        int[] expected = {1, 2, 3, 4, 5};
        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testArrayWithDuplicates() {
        int[] arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        int[] expected = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testArrayWithNegativeNumbers() {
        int[] arr = {-3, 1, -4, 0, 5, -9, 2};
        int[] expected = {-9, -4, -3, 0, 1, 2, 5};
        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testArrayAllSameElements() {
        int[] arr = {7, 7, 7, 7, 7};
        int[] expected = {7, 7, 7, 7, 7};
        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testRandomArraySmall() {
        Random rand = new Random();
        int[] arr = new int[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(201) - 100;
        }
        int[] expected = Arrays.copyOf(arr, arr.length);
        Arrays.sort(expected);

        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testRandomArrayModerate() {
        Random rand = new Random();
        int[] arr = new int[100];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(2001) - 1000;
        }
        int[] expected = Arrays.copyOf(arr, arr.length);
        Arrays.sort(expected);

        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }

    @Test
    void testRandomArrayLarge() {
        Random rand = new Random();
        int[] arr = new int[2000];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(20001) - 10000;
        }
        int[] expected = Arrays.copyOf(arr, arr.length);
        Arrays.sort(expected);

        quickSort.sort(arr);
        assertArrayEquals(expected, arr);
    }
}