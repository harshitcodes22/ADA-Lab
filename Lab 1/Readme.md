<h1>01-Horner Series</h1>

<p> Aim:- To implement Horner series </p>

<h1>Psuedo Code</h1>
<p>
  
## Horner's Algorithm

### Introduction
Horner's algorithm is a method for efficiently evaluating polynomials by recursively computing each term based on the previous one. This algorithm reduces the number of multiplications required to evaluate a polynomial compared to the straightforward method.

### Algorithm Description
The Horner's algorithm takes an array of coefficients representing a polynomial, the degree of the polynomial `n`, the index of the current term `m`, and the value of `x` for which the polynomial needs to be evaluated.

```c
int Horner(int a[], int n, int m, int x) {
    if (n == m) {
        // Base case: return the coefficient of the highest degree term
        return a[m];
    } else {
        // Recursive case: compute the value of the polynomial term by term
        return (a[n] + x * Horner(a, n + 1, m, x));
    }
}

```

</p>
<h1>Graph</h1>

![horner](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/ec383910-d937-46a1-b62e-354202291d8d)

<h1>02-Boolean Series</h1>

<p> Aim:- To implement Boolean series </p>

<h1>Psuedo Code</h1>
<p>
  ## Truth Table Generator

This function generates all possible combinations of the characters 'T' and 'F' of length `n`.

### Algorithm:

```cpp
void TT(char x[], int k, int n) {
    if (k == n + 1) {
        for (int i = 0; i < n; i++) {
            cout << x[i];
        }
        cout << endl;
    } else {
        x[k] = 'T';
        TT(x, k + 1, n);
        x[k] = 'F';
        TT(x, k + 1, n);
    }
}

```
<h1>Graph</h1>

![Boolean](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/343011b4-fea9-48a4-b13a-5a1ca5899795)

<h1>03-Selection Sort</h1>

<p> Aim:- To implement Selection Sort </p>


# Selection Sort Algorithm

This algorithm sorts an array of integers in ascending order using the selection sort technique.

## Algorithm Description

1. For each element in the array:
    - Set the current element as the minimum.
    - Compare this minimum element with the rest of the elements in the array.
    - If any element is found to be smaller than the current minimum, update the minimum to the index of that element.
2. Swap the minimum element found with the current element.
3. Repeat the process for each subsequent element until the array is sorted.

## Pseudocode

```cpp
void selection_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
        {
            if (a[k] < a[j])
            {
                j = k;
            }
        }
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}

```

  
<h1>Graph</h1>

![selection_sort](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/1ee63920-56a7-4055-b208-928577ebeb5f)

<h1>04-Sum of N series</h1>

<p> Aim:- To Find sum of N series using Recursion </p>

<h1>Psuedo Code</h1>

 ```cpp

int sum(int a[], int k) {
    if (k == 1) 
        return a[0];
    else 
        return (a[k - 1] + sum(a, k - 1));
}

```
<h1>Graph</h1>

![sum_of_n_no](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/f8447357-57ea-43db-ae6c-c72af456afcc)


<h1>05 Tower of Hanoi</h1>

<p> Aim:- To implement tower of hanoi </p>


# Tower of Hanoi Algorithm

This algorithm demonstrates the Tower of Hanoi problem, a classic problem in computer science and mathematics.

## Overview

The Tower of Hanoi problem consists of three rods and a number of disks of different sizes which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, with the smallest disk at the top, thus making a conical shape.

The objective of the puzzle is to move the entire stack to another rod, obeying the following rules:
1. Only one disk can be moved at a time.
2. Each move consists of taking the top disk from one of the stacks and placing it on top of another stack.
3. No disk may be placed on top of a smaller disk.

## Algorithm

The Tower of Hanoi algorithm can be recursively defined as follows:

<h1>Psuedo Code</h1>

```cpp
void towerOfHanoi(int n, char source, char destination, char spare) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, spare, destination);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    towerOfHanoi(n - 1, spare, destination, source);
}
```
<h1>Graph</h1>

![Tower_of_hanoi](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/7f8e0019-1292-4e97-beb2-5d1c0369f726)

