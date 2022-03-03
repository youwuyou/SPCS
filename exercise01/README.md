# Exercise 1.1: Polynomer-Ketten und Random Walks

# Exercise 1-1

<aside>
💡 Modelling sketch

- Coordinate system:
    - Cartesian coordinates $\Z^2$
- Modelling object:
    - polymers
        - $\# \text{Segements} = n, \,\, n\in \N$
        - each segment has the same length
- Constraints on the model

    ⇒ for simplification

    i). At each grid point a segment can be represented

    $$
    x_i= (x^0,x^1),\,\, x^0, x^1\in \Z
    $$

    ii). No interactions between the segments

    iii). Conformation of a polymer

    - $X-\text{a n-tuple}$

    $$
    X:=(x_0,x_1,...x_{n-1})
    $$

    - described by a tuple consisting the gitter points which are visited

    ![Untitled](Markdown/RandomWalk2D.png)

    ![Untitled](Markdown/SimulatingDNA.png)

</aside>

<aside>
💡 Algorithm:

- Random walk of length n in 2D
- math. representation
    - $i\in [n]$ - subscript represented the time step
    - uniform time steps in directions $\{ \pm e_x, \pm e_y\}$

    ⇒  4 directions possible ( ⬅️, ➡️, ⬆️, ⬇️)


$$
S_t=(x_0,x_1,...,x_{n-1})
$$

- Goal: Observation of the behaviours of a short-chained polymer
    - Not possible to list out all conformations

        ⇒ exponential growth of the possibilities

- Ideas of the algorithm
    - using short chain instead of a long chain
    - accidentally generated “Ensemble” as the typical example
</aside>
