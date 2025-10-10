import matplotlib.pyplot as plt

# Read the results
threads = []
times = []
with open("speedup_results.txt") as f:
    next(f)  # skip header
    for line in f:
        t, time = line.strip().split(",")
        threads.append(int(t))
        times.append(float(time))

# Plot
plt.figure()
plt.plot(threads, times, marker='o')
plt.xlabel("Number of threads")
plt.ylabel("Execution time (s)")
plt.title("Speedup vs Threads")
plt.grid(True)
plt.savefig("speedup_plot.png")
plt.show()
