<h1>01- Matrix Multiplication</h1>

<p> Aim:- To implement Matrix Multiplication </p>


<p>

Matrix multiplication using recursion is a technique where the process of multiplying two matrices is broken down into smaller subproblems, which are then solved recursively. This approach offers an elegant solution to matrix multiplication while also providing insight into divide-and-conquer strategies.
</p>
<h1>Graph</h1>

![Matrix_multiplication](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/ff007bca-080e-49a1-b618-23188bef25d6)


<h1>02- Max-Min </h1>

<p> Aim:- To write program to find maximum and minimum from array using recursion </p>

<p>The provided code is an implementation of a divide and conquer algorithm aimed at finding both the maximum and minimum elements in an array. The function MaxMin takes an array a, along with indices representing the range of elements to consider (low and high).
</p>

<h1>Psuedo Code </h1>

```cpp

Procedure MaxMin(a, low, high)
    if low equals high then
        max = a[low]
        min = a[low]
    else
        mid = (low + high) / 2
        MaxMin(a, low, mid)
        MaxMin(a, mid + 1, high)
        max1 = a[low]
        min1 = a[low]
        if low does not equal high then
            mid = (low + high) / 2
            MaxMin(a, mid + 1, high)
            if max < max1 then
                max = max1
            if min > min1 then
                min = min1
    Output "Max el" + max + " Min el" + min
End Procedure
```

<h1>Graph</h1>

![MaxMin](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/423125ac-6505-461e-a7cb-60657db7dc78)


<h1>03- Quick Sort </h1>

<p> Aim:- To write program to implement Quick Sort</p>

<p>
  
Quicksort is a highly efficient sorting algorithm that follows the divide-and-conquer strategy. It was developed by Tony Hoare in 1959 and is widely used due to its average-case time complexity of O(n log n) and relatively low overhead. Quicksort works by partitioning an array into two sub-arrays around a pivot element: elements smaller than the pivot are placed to its left, and elements greater than the pivot are placed to its right. This process is repeated recursively for each sub-array until the entire array is sorted.

</p>

<h1>Psuedo Code </h1>

```cpp

quicksort(arr, low, high):
    if low < high:
        # Partition the array and get the pivot index
        pivot_index = partition(arr, low, high)
        
        # Recursively call quicksort on the partitions
        quicksort(arr, low, pivot_index - 1)
        quicksort(arr, pivot_index + 1, high)

partition(arr, low, high):
    # Choose the pivot element (can be any element in the array)
    pivot = arr[high]
    # Index of smaller element
    i = low - 1
    
    for j = low to high - 1:
        # If current element is smaller than or equal to pivot
        if arr[j] <= pivot:
            # Increment index of smaller element
            i = i + 1
            # Swap arr[i] and arr[j]
            swap(arr[i], arr[j])
    
    # Swap arr[i + 1] and arr[high] (or pivot)
    swap(arr[i + 1], arr[high])
    return i + 1
```

<h1>Graph</h1>

![Quick_sort](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/e53f80ab-4636-434b-8587-5d11c9f73dfd)

<h1>04- Merge Sort </h1>

<p> Aim:- To write program to implement Merge Sort</p>

The Merge Sort algorithm follows the divide-and-conquer paradigm, consisting of two main operations: dividing the array into smaller sub-arrays and merging these sub-arrays into a sorted result.

<h1>Psuedo Code </h1>

```cpp

mergeSort(arr):
    if length of arr <= 1:
        return arr
    
    # Split the array into two halves
    mid = length of arr / 2
    left_half = arr[0:mid]
    right_half = arr[mid:]
    
    # Recursively sort each half
    mergeSort(left_half)
    mergeSort(right_half)
    
    # Merge the sorted halves
    merge(arr, left_half, right_half)

merge(arr, left_half, right_half):
    i = 0  # Index for left_half
    j = 0  # Index for right_half
    k = 0  # Index for arr (merged array)
    
    while i < length of left_half and j < length of right_half:
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i = i + 1
        else:
            arr[k] = right_half[j]
            j = j + 1
        k = k + 1
    
    # Copy remaining elements of left_half (if any)
    while i < length of left_half:
        arr[k] = left_half[i]
        i = i + 1
        k = k + 1
    
    # Copy remaining elements of right_half (if any)
    while j < length of right_half:
        arr[k] = right_half[j]
        j = j + 1
        k = k + 1
```

<h1>Graph </h1>

![Merge_sort](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/0bc6a8a8-a9c5-466a-ada4-65a7b68b3cc0)

<h1>05 - Strassens Matrix </h1>

<p> Aim:- To write program to implement Strassens Matrix multiplication</p>

<p>The key insight behind Strassen's Algorithm is to reduce the number of recursive multiplications by performing fewer matrix operations. Instead of the standard eight multiplications required to compute each element of the resulting matrix in the traditional method, Strassen's Algorithm performs only seven multiplications by cleverly partitioning the matrices and using a set of additions and subtractions to compute the elements of the resulting matrix.</p>

<h1>Psuedo Code </h1>

```cpp

Strassen's Algorithm for Matrix Multiplication:
Input: Two square matrices A and B of size n x n
Output: The product matrix C = A * B

function Strassen(A, B, n):
    if n = 1:
        return A[0][0] * B[0][0]
    
    // Partition matrices A and B into sub-matrices
    Partition A into A11, A12, A21, A22
    Partition B into B11, B12, B21, B22
    
    // Compute intermediate matrices using additions and subtractions
    P1 = Strassen(A11 + A22, B11 + B22, n/2)
    P2 = Strassen(A21 + A22, B11, n/2)
    P3 = Strassen(A11, B12 - B22, n/2)
    P4 = Strassen(A22, B21 - B11, n/2)
    P5 = Strassen(A11 + A12, B22, n/2)
    P6 = Strassen(A21 - A11, B11 + B12, n/2)
    P7 = Strassen(A12 - A22, B21 + B22, n/2)
    
    // Compute product matrices recursively using the intermediate matrices
    C11 = P1 + P4 - P5 + P7
    C12 = P3 + P5
    C21 = P2 + P4
    C22 = P1 - P2 + P3 + P6
    
    // Combine product matrices into the resulting matrix
    Construct C from C11, C12, C21, C22
    
    return C

```

<h1>Graph</h1>

![Strassens](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/c9844521-5ec6-47d8-bde7-86ff88e5f413)
