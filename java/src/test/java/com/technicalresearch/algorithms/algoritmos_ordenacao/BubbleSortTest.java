package com.technicalresearch.algorithms.algoritmos_ordenacao;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;

import java.util.Arrays;
import java.util.Random;

class BubbleSortTest {

    private BubbleSort bubbleSort;

    @BeforeEach
    void setUp() {
        bubbleSort = new BubbleSort();
    }

    @Test
    void testNullArray() {
        int[] arr = null;
        assertDoesNotThrow(() -> bubbleSort.sort(arr));
    }

    @Test
    void testEmptyArray() {
        int[] arr = {};
        int[] expected = {};
        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array vazio deve permanecer vazio.");
    }

    @Test
    void testSingleElementArray() {
        int[] arr = {5};
        int[] expected = {5};
        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array com um único elemento deve permanecer inalterado.");
    }

    @Test
    void testSortedArray() {
        int[] arr = {1, 2, 3, 4, 5};
        int[] expected = {1, 2, 3, 4, 5};
        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array já ordenado deve permanecer ordenado.");
    }

    @Test
    void testReverseSortedArray() {
        int[] arr = {5, 4, 3, 2, 1};
        int[] expected = {1, 2, 3, 4, 5};
        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array em ordem reversa deve ser ordenado corretamente.");
    }

    @Test
    void testArrayWithDuplicates() {
        int[] arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        int[] expected = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array com elementos duplicados deve ser ordenado corretamente.");
    }

    @Test
    void testArrayWithNegativeNumbers() {
        int[] arr = {-3, 1, -4, 0, 5, -9, 2};
        int[] expected = {-9, -4, -3, 0, 1, 2, 5};
        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array com números negativos deve ser ordenado corretamente.");
    }

    @Test
    void testArrayAllSameElements() {
        int[] arr = {7, 7, 7, 7, 7};
        int[] expected = {7, 7, 7, 7, 7};
        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array com todos os elementos iguais deve permanecer inalterado.");
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

        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array aleatório pequeno deve ser ordenado corretamente.");
    }

    @Test
    void testRandomArrayModerate() {
        Random rand = new Random();
        int[] arr = new int[50];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(2001) - 1000;
        }
        int[] expected = Arrays.copyOf(arr, arr.length);
        Arrays.sort(expected);

        bubbleSort.sort(arr);
        assertArrayEquals(expected, arr, "Array aleatório moderado deve ser ordenado corretamente.");
    }
}