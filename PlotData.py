import matplotlib.pyplot as plt
import numpy as np

seeds = ["32984", "943342", "9275904917","13580"]

time_means = {
        "Mod Algorithm": [(0.194+0.206+0.196)/3, (4.479+4.45+4.54)/3, (10.906 + 10.741 + 11.062)/3, (4.306+4.116+4.353)/3],
        "DP Algorithm": [(14.740+14.746+14.332)/3, (3.962+4.313+4.323)/3, (25.554+25.645+26.064)/3, (24.075+23.781+24.032)/3],
        "Enhanced Mod" : [(0.012 + 0.002 +0.008)/3, (0.006+0.006+0.006)/3, (0.010+ 0.011+ 0.010)/3, (0.009+0.007+0.009)/3]
}

fig, ax = plt.subplots(layout = 'constrained')

x = np.arange(len(seeds))
multiplyer = 0
width = 0.25

for alg_type, time in time_means.items():
    offset = width*multiplyer
    rects = ax.bar(x + offset, time, width, label=alg_type)
    ax.bar_label(rects, padding=3)
    multiplyer += 1

ax.set_xlabel("Seed")
ax.set_xticks(x+width, seeds)
ax.set_ylabel("Time(s)")
ax.set_title("Time taken by Algorithm type")
ax.legend(loc="upper left")

plt.show()
