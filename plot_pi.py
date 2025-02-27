import matplotlib.pyplot as plt
import csv

iterations = []
pi_values = []

with open('pi_values.csv', 'r') as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        iterations.append(int(row[0]))
        pi_values.append(float(row[1]))

plt.figure(figsize=(10, 6))
plt.plot(iterations, pi_values, label="Pi Approximation", color='b')
plt.xlabel("Iteration")
plt.ylabel("Pi Value")
plt.title("Pi Approximation Over Iterations")
plt.grid(True)
plt.legend()

import matplotlib.pyplot as plt
import csv

iterations = []
time_taken = []

with open('pi_calculation_time.csv', 'r') as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        iterations.append(int(row[0]))
        time_taken.append(float(row[1]))

scaled_time_taken = [time * 1e6 if time > 0 else 1e-9 for time in time_taken]

plt.figure(figsize=(15, 10))

plt.plot(iterations[:50], scaled_time_taken[:50], label="Scaled Time Taken per Iteration", color='r')

plt.yscale('log')

plt.xlabel("Iteration")
plt.ylabel("Time Taken (microseconds)")
plt.title("Time Taken for Pi Approximation Over Iterations")
plt.grid(True)
plt.legend()

plt.show()