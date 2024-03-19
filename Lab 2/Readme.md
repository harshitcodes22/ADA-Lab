<h1>01-Finding Actual position</h1>

<p> Aim:- To implement code for finding actual position of number </p>

<h1>Psuedo Code</h1>
<p>
# Actual Position Algorithm

This algorithm (`actual_pst`) is designed to rearrange an array in such a way that elements lesser than a given element (`el`) are placed before it, elements greater than `el` are placed after it, and the element `el` itself is placed at its actual position in the sorted array.

## Algorithm Description

```c
int actual_pst(int * a, int n, int el) {
    int grt = 0;
    int sml = 0;
    int indx_pst;

    // Counting elements greater and smaller than 'el'
    for(int i = 0; i < n; i++) {
        if(a[i] < el) {
            sml++;
        }
        else if(a[i] > el) {
            grt++;
        }
        else {
            indx_pst = i;
        }
    }

    // Placing 'el' at its actual position
    int t = a[indx_pst];
    a[indx_pst] = a[sml];
    a[sml] = t;

    // Partitioning the array around 'el'
    int fst = 0;
    int last = n - 1;
    int i;
    int j;

    while(fst < last) {
        for(int i = fst; i < sml; i++) {
            if(a[i] > el) {
                fst = i;
                break;
            }
        }
        fst = i;

        for(int j = n - 1; j > sml; j--) {
            if(a[j] < el) {
                last = j;
                break;
            }
        }
        last = j;

        if(fst < last) {
            int t = a[fst];
            a[fst] = a[last];
            a[last] = t;
        }
    }
}
```

<h1>Graph</h1>

![Find_actual_position](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/6697a237-066a-4629-8849-9f6bea2a59d8)


<h1>02-Combining two sorted list</h1>

<p> Aim:- To implement code for combining two sorted List </p>

<h1>Psuedo Code</h1>

```cpp
// Sorted List Merge Algorithm

// Merges two sorted integer arrays into a single sorted array
void sorted_list_merge(int *list1, int *list2, int n, int m, int *result) {
    int x = 0; // Pointer for list1
    int y = 0; // Pointer for list2
    int z = 0; // Pointer for result array

    // Merge elements from both arrays into the result array
    while (y < m && x < n) {
        if (list1[x] < list2[y]) {
            result[z] = list1[x];
            x++;
        } else {
            result[z] = list2[y];
            y++;
        }
        z++;
    }

    // Append remaining elements from list1 to the result array
    while (x < n) {
        result[z] = list1[x];
        x++;
        z++;
    }

    // Append remaining elements from list2 to the result array
    while (y < m) {
        result[z] = list2[y];
        y++;
        z++;
    }
}
```

<h1>Graph</h1>

![comb_sorted_list](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/a0a55c9b-bea6-48a1-a485-d1228a08979e)


<h1>03-Finding Power of given number</h1>

<p> Aim:- To implement code for combining two sorted List </p>

<h1>Psuedo Code</h1>

## Power Function Algorithm

### Description:
This algorithm calculates the power of an integer `x` raised to the power of another integer `n`. It efficiently computes the result using iterative exponentiation.

### Algorithm:
```c
int power(int n, int x) {
    int power = 1;
    while (n != 0) {
        if (n % 2 == 0) {
            x = x * x;
            n = n / 2;
        } else {
            power = power * x;
            n = n - 1;
        }
    }
    return power;
}

```
<h1>Graph</h1>

![Power](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/6d854350-6591-42bd-ac48-5cbdcd463641)


