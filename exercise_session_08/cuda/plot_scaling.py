import numpy as np
import matplotlib.pyplot as plt

blocks = []
threads = []
times = []

with open("output_scaling.txt") as f:
    lines = f.readlines()

for i in range(0, len(lines), 2):
    pi_line = lines[i].strip()
    bt_line = lines[i+1].strip()

    if not pi_line or not bt_line:
        continue

    time_sec = float(pi_line.split("computed in")[1].split("seconds")[0].strip())
    
    parts = bt_line.split()
    nb = int(parts[0].split('=')[1])
    nt = int(parts[1].split('=')[1])

    blocks.append(nb)
    threads.append(nt)
    times.append(time_sec)

blocks_unique = np.unique(blocks)
threads_unique = np.unique(threads)

time_grid = np.zeros((len(threads_unique), len(blocks_unique)))

for b, t, tt in zip(blocks, threads, times):
    i = np.where(threads_unique == t)[0][0]
    j = np.where(blocks_unique == b)[0][0]
    time_grid[i, j] = tt

plt.figure(figsize=(8,6))
X, Y = np.meshgrid(blocks_unique, threads_unique)
c = plt.pcolormesh(X, Y, time_grid, shading='auto', cmap='viridis')
plt.colorbar(c, label='Runtime [s]')
plt.xlabel('Number of blocks')
plt.ylabel('Threads per block')
plt.title('CUDA Runtime Scaling')
plt.savefig("scaling_plot.png")
plt.show()
