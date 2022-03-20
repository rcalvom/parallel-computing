import matplotlib.pyplot as plt
from matplotlib.collections import EventCollection
import numpy as np

list_1 = [6340.088844299316, 6335.758924484253, 6425.503969192505, 6347.927808761597, 6348.183155059814]
list_2 = [3340.939998626709, 3318.953037261963, 3334.092855453491, 3271.924018859863, 3390.055894851685]
list_4 = [2853.395223617554, 2846.215009689331, 2873.318195343018, 2871.086120605469, 2775.845050811768]
list_8 = [2862.823009490967, 2869.314908981323, 2902.832984924316, 2963.523864746094, 2813.30418586731]
list_16 = [2906.139135360718, 2706.709146499634, 2587.829113006592, 2684.438943862915, 2896.565198898315]

time_1 = np.average(list_1)
time_2 = np.average(list_2)
time_4 = np.average(list_4)
time_8 = np.average(list_8)
time_16 = np.average(list_16)

threads = [1, 2, 4, 8, 16]
times = [time_1, time_2, time_4, time_8, time_16]

fig, ax = plt.subplots()
ax.plot(threads, times)

ax.set(xlabel='Número de Hilos', ylabel='Tiempo (ms)', title='Número de hilos vs Tiempo')
ax.grid()

fig.savefig("times.png")
