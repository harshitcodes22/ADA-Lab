<h1>01- Activity Selection</h1>

<p> Aim:- To implement Activity selection technique </p>


<p>


The Activity Selection Problem is a classic algorithmic problem in which you have a set of activities, each with a start time and end time, and you want to find the maximum number of non-overlapping activities that can be performed. The goal is to select the largest possible set of activities that do not overlap with each other.
</p>

<h1>Psuedo Code </h1>

```cpp
ActivitySelection(start[], end[], n):
    Sort activities based on their end times in ascending order.
    
    selectedActivities = [0] * n  # Initialize an array to store selected activities
    
    # Select the first activity (activity with the earliest end time)
    selectedActivities[0] = true
    prevEnd = end[0]
    selectedCount = 1
    
    # Iterate through the sorted activities
    for i from 1 to n - 1:
        if start[i] >= prevEnd:  # If the current activity starts after the previous one ends
            selectedActivities[i] = true  # Select the current activity
            prevEnd = end[i]  # Update the previous end time
            selectedCount = selectedCount + 1  # Increment the count of selected activities
    
    return selectedCount, selectedActivities

```
<h1>Graph</h1>

![activity_selector](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/6852e066-47bd-4cbc-bcf1-be06cbdb61d1)

<h1>02- knapsack </h1>

<p> Aim:- To implement Knapsack technique </p>

##
The Knapsack Problem is a classic optimization problem where you are given a set of items, each with a weight and a value, and a knapsack with a maximum weight capacity. The goal is to select a combination of items that maximizes the total value while keeping the total weight within the capacity of the knapsack.
<h1>Psuedo Code </h1>

```cpp
Knapsack(weights[], values[], capacity, n):
    // Create a 2D array to store the maximum value that can be achieved for different subproblems.
    // dp[i][w] represents the maximum value that can be achieved using the first i items and a knapsack capacity of w.
    Let dp[n+1][capacity+1] be a 2D array
    
    // Initialize the first row and column of the dp table to 0
    for i from 0 to n:
        dp[i][0] = 0
    for w from 0 to capacity:
        dp[0][w] = 0
    
    // Fill the dp table using dynamic programming
    for i from 1 to n:
        for w from 1 to capacity:
            if weights[i-1] <= w:
                // If the weight of the current item is less than or equal to the knapsack capacity,
                // we have two choices: either include the item or exclude it.
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w])
            else:
                // If the weight of the current item is greater than the knapsack capacity,
                // we cannot include it in the knapsack.
                dp[i][w] = dp[i-1][w]
    
    // The maximum value that can be achieved is stored in dp[n][capacity]
    return dp[n][capacity]
```

<h1>Graph</h1>

![Knapsack](https://github.com/harshitcodes22/ADA-Lab/assets/110489265/2aa379af-445e-47eb-b57a-567793e9f0ce)
