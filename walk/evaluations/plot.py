import csv
import matplotlib.pyplot as plt
import numpy as np
import pylab
import pandas as pd
import seaborn as sns

from matplotlib import cm
from matplotlib.colors import ListedColormap, LinearSegmentedColormap
from mpl_toolkits.mplot3d import Axes3D

sns.set(rc={'axes.facecolor':'black', 'figure.facecolor':'black'})

min_a = (-0.558, 1.442) # -146
min_b = (0.623, 0.028) # -108
min_c = (-0.05, 0.467) # -80

def plot_random_walk(random_walk):
    plt.figure(0, figsize=(20,20), dpi=100)
    plt.plot(random_walk['x'], random_walk['y'], color='orange')
    plt.savefig('random_walk')

def plot_n_dependence(n_dependence):
    plt.figure(3, figsize=(20,20), dpi=100)
    plt.plot(n_dependence['n'], n_dependence['d'], label='end-to-end distance')
    plt.plot([np.sqrt(n) for n in range(1, 100)], label='$\sqrt{n}$')
    plt.plot(n_dependence['n'], n_dependence['r'], label='radius of gyration')
    plt.plot([np.sqrt(n) / np.sqrt(6) for n in range(1, 100)], label='analytical solution for r') # Analytic Solution
    plt.xlabel('n')
    legend = plt.legend()
    plt.setp(legend.get_texts(), color='w')
    plt.savefig('dependence_on_n.png')


def plot_potential(energies):

    num_grid_points = (energies['x'].to_list()).count(energies['x'][0])
    print(np.array(energies['x'].to_list()))
    print(num_grid_points)
    print(len(energies['x'])/num_grid_points)

    x = np.reshape(np.array(energies['x'].to_list()), (num_grid_points, num_grid_points))
    y = np.reshape(np.array(energies['y'].to_list()), (num_grid_points, num_grid_points))
    E = np.reshape(np.array(energies['E'].to_list()), (num_grid_points, num_grid_points))

    fig = plt.figure(1, figsize=(10, 10), dpi=100)
    ax = fig.add_subplot(111)


    # Show Minima
    ax.scatter(min_a[0], min_a[1], c='red', s=50, marker='x')
    ax.scatter(min_b[0], min_b[1], c='red', s=50, marker='x')
    ax.scatter(min_c[0], min_c[1], c='red', s=50, marker='x')
    ax.contour(x, y, np.clip(E, a_min=-200, a_max=15), levels=50)

    ax.set_xlabel('x')
    ax.set_ylabel('y')

    plt.savefig('mueller-brown.png')

def plot_mmc(energies):
    fig = plt.figure(2, figsize=(10, 10), dpi=100)
    ax = fig.add_subplot(111)

    print(energies['x'])



    # Show Minima
    ax.scatter(min_a[0], min_a[1], c='red', s=50, marker='x')
    ax.scatter(min_b[0], min_b[1], c='red', s=50, marker='x')
    ax.scatter(min_c[0], min_c[1], c='red', s=50, marker='x')
    sc = ax.scatter(energies['x'].to_list(), energies['y'].to_list(), c = energies['E'], cmap = cm.get_cmap("Spectral") )
    cbar = plt.colorbar(sc,shrink=0.5)
    cbar.set_label('E / kJ/mol')

    ax.set_xlabel('x')
    ax.set_ylabel('y')

    plt.savefig('mmc.png')

mueller_brown = pd.read_csv('mueller-brown', sep= ' ')
plot_potential(mueller_brown)

mmc = pd.read_csv('mmc_energies', sep= ' ')
plot_mmc(mmc)

n_dependence = pd.read_csv('dependence_on_n', sep = ' ')
plot_n_dependence(n_dependence)

random_walk = pd.read_csv('random_walk', sep = ' ')
plot_random_walk(random_walk)
