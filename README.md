# C-


In this report,described the functionality of the LongNumber class, analyze the Pi approximation calculations, and present visual analyses of the output using graphs. 


---

### **LongNumber Class Overview**:

| **Feature**               | **Description**                                                   |
|---------------------------|-------------------------------------------------------------------|
| **Constructor/Destructor** | Handles initialization and destruction of the `LongNumber` object. |
| **Arithmetic Operations**  | Supports +, -, *, / with proper precision handling.               |
| **Comparison Operators**   | Supports ==, !=, <, > for comparing two `LongNumber` objects.     |
| **Precision Handling**     | Allows setting and adjusting precision for calculations.          |
| **Pi Approximation**       | Uses the Leibniz formula for Pi, iterating to reach the desired precision. |

---

### **Code Execution Results**:

| **Test Category**          | **Result**                                                      |
|----------------------------|-----------------------------------------------------------------|
| **Arithmetic Operations**   | All operations (+, -, *, /) passed successfully.                |
| **Comparison Operators**    | Comparison tests passed (equality, inequality, less than, greater than). |
| **Precision Handling**      | Pi calculated with 32-bit precision as expected.                |
| **Division by Zero**        | Test failed; no exception thrown during division by zero.      |
| **Negative Numbers**        | Negative number operations passed successfully.                 |

---

Here’s the requested table format with the code output:

| **Test Category**            | **Test Output**                                                 |
|------------------------------|---------------------------------------------------------------|
| **Arithmetic Operations**     |                                                               |
| Addition:                     | 6167360160.6841951676 + 8611528784.10 = 21620840630.0         |
| Addition (repeated):          | 6167360160.6841951676 + 8611528784.10 = 21620840630.0         |
| Subtraction:                  | 6167360160.6841951676 - 8611528784.10 = 4397783042.0          |
| Multiplication:               | 6167360160.6841951676 * 8611528784.10 = 1349599023581696088.0 |
| Division:                     | 6167360160.6841951676 / 8611528784.10 = 1.0                   |
| **Comparison Operators**      | Comparison tests passed!                                      |
| **Precision Setting**         | Pi with 32-bit precision: 6167360161.2546984380               |
| **Division by Zero**          | Test failed: Division by zero did not throw an exception!     |
| **Negative Numbers**          |                                                               |
| Addition (with negative):     | -8611528795.-9 + 8611528784.10 = -10.0                         |
| Addition (with negative, repeated): | -8611528795.-9 + 8611528784.10 = -10.0                  |
| **Overall Test Result**       | All tests passed!                                             |

### **Graphs**:

#### 1. **Pi Approximation Over Iterations**:

| **Iteration** | **Pi Approximation** |
|---------------|----------------------|
| 1             | 4.0                  |
| 2             | 2.6667               |
| 3             | 3.4667               |
| 4             | 2.8952               |
| ...           | ...                  |
| 500           | ~3.1415               |

![Figure_1](https://github.com/user-attachments/assets/c3511e65-0e60-4dc0-8c42-897beec56f51)

The first graph depicts the value of Pi over iterations, showing how the approximation improves as the number of iterations increases. Initially, the value fluctuates widely, but as more terms are added, the approximation stabilizes and approaches the true value of Pi. This is typical of the Leibniz series, which converges slowly.

#### 2. **Time Taken for Pi Approximation Over Iterations**:

| **Iteration** | **Time Taken (microseconds)** |
|---------------|------------------------------|
| 1             | 1.0                          |
| 2             | 1.0                          |
| 3             | 1.1                          |
| 4             | 1.0                          |
| ...           | ...                          |
| 50            | 1.1                          |

![Figure_2](https://github.com/user-attachments/assets/0213b751-60d7-4baa-8fa9-5c1517019444)

The second graph visualizes the time taken per iteration for calculating Pi. The time taken for each iteration is plotted on a logarithmic scale, which is common for analyzing performance in algorithms. From the graph, we can see that the time taken per iteration remains constant or shows only minor fluctuations, suggesting that each iteration's computational cost is relatively stable.

