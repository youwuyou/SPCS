# Exercise 1.1: Polynomer Chains and Random Walks

# Exercise 1-1

<aside>
💡 Modelling sketch

- Coordinate system:
    - Cartesian coordinates

    ![equation (1).png](Markdown/Z2.png)

- Modelling object:
    - polymers

        ![equation (2).png](Markdown/equation_1.png)

        - each segment has the same length
- Constraints on the model

    ⇒ for simplification

    i). At each grid point a segment can be represented

    ![equation (3).png](Markdown/equation_2.png)

    ii). No interactions between the segments

    iii). Conformation of a polymer

    - X - a n-tuple

        ![equation (4).png](Markdown/equation_3.png)

    - described by a tuple consisting the gitter points which are visited

    ![Untitled](Markdown/RandomWalkDNA.png)

    ![Untitled](Markdown/RandomWalk2D.png)

</aside>

<aside>
💡 Algorithm:

- Random walk of length n in 2D
- math. representation

    ![equation (5).png](Markdown/equation_4.png)

    - subscript represented the time step

        ![equation (6).png](Markdown/equation_5.png)

    - uniform time steps in directions

    ⇒  4 directions possible ( ⬅️, ➡️, ⬆️, ⬇️)

    ![equation (7).png](Markdown/equation_6.png)


- Goal: Observation of the behaviours of a short-chained polymer
    - Not possible to list out all conformations

        ⇒ exponential growth of the possibilities

- Ideas of the algorithm
    - using short chain instead of a long chain
    - accidentally generated “Ensemble” as the typical example
</aside>
