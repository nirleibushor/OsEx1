import matplotlib.pyplot as plt
import numpy as np
import matplotlib.patches as mpatches

x = np.arange(6)

# these values where taken from the program's output in the host, and VM, accordingly
times = [1.320, 4.071, 1056.907]
virtual_times = [6.579, 88.674, 1242.079]

y = np.array(times + virtual_times)
y = np.log(y)

bars = plt.bar(x, y, color=['r', 'r', 'r', 'b', 'b', 'b'])
plt.xticks(x, ('simple op', 'func call', 'syscall', 'simple op', 'func call', 'syscall'))

red_patch = mpatches.Patch(color='r', label='host')
blue_patch = mpatches.Patch(color='b', label='vm')
plt.legend(handles=[red_patch, blue_patch])

plt.xlabel('Timed actions')
plt.ylabel('Timing, natural logarithm scale')

for bar in bars:
        height = bar.get_height()
        plt.text(bar.get_x() + bar.get_width()/2., 1.05*height,
                '%f' % float(height),
                ha='center', va='bottom')

plt.show()
