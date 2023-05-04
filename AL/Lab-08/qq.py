import subprocess
import matplotlib.pyplot as plt

sizes = [10, 100, 1000, 10000, 100000]
times = []
ops = []

for size in sizes:
    command = "./heap %d" % size
    output = subprocess.check_output(command, shell=True)
    output_lines = output.decode().split('\n')
    time = float(output_lines[-2].split()[-2])
    op = int(output_lines[-3].split()[-1])
    times.append(time)
    ops.append(op)

plt.plot(sizes, times, 'o-', label='Time taken')
plt.plot(sizes, ops, 'o-', label='Number of operations')
plt.xlabel('Input size')
plt.ylabel
