import matplotlib.pyplot as plt
import numpy as np

list_1 = [65500.40197372437, 65505.68985939026, 65756.76584243774, 67221.80485725403, 65298.23517799377]
list_2 = [33804.89897727966, 33998.3229637146, 33803.34091186523, 34882.49683380127, 33573.23694229126]
list_4 = [25008.5289478302, 25691.07699394226, 24659.77001190186, 24568.01390647888, 24448.56810569763]
list_8 = [24338.87410163879, 23238.05689811707, 19444.21410560608, 26068.14289093018, 25008.75306129456]
list_16 = [22542.87695884705, 23154.04105186462, 24747.83897399902, 25839.80798721313, 25240.26584625244]

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
