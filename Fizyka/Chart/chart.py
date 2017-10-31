import numpy as np

import math
import os
#import texfig
import matplotlib.pyplot as plt
def getyoung(x,y,l,d):
    t = np.vstack([x, np.ones(len(x))]).T
    a, c = np.linalg.lstsq(t, y)[0]
    a/=1000; # w si
    g=9.811
    return 4*g*l/(a*math.pi*math.pow(d,2))

#Dane uzyskane z pomiarów
x = np.array([0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5]);
y = np.array([0.15, 0.2875, 0.415, 0.5225, 0.6175, 0.7225, 0.8225, 0.9325, 1.01]);
sx = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9])
sy=np.array([0.25, 0.45, 0.62, 0.75, 0.89, 1.02, 1.12, 1.27, 1.41]);

err=0.000508847
print(getyoung(x,y,1.076,0.77/1000))
print(getyoung(sx,sy,1.076,0.77/1000))
print(1000000000*100)

# #fig = texfig.figure()
# plt.xlabel('Masa obciążenia [Kg]')
# plt.ylabel('Wydłużenie drutu [mm]')
# plt.title('Drut stalowy')
# plt.plot(x, a * x + c, 'r', label='Fitted line', color="black")
# plt.plot(x, y, '.', color="black", label='Original data')
# plt.errorbar(x, y, 0.018,0,".",color="black")
#
# print(a, c);
# plt.grid(0.01);
# plt.show();


#texfig.savefig(os.path.join(os.environ["HOMEPATH"], "Desktop/plot2.pgf"));