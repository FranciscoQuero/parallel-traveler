# parallel-traveler
 Travelling Salesman Problem parallelized through MPI and OMP libraries in C++
 
 It uses multiple classes:

 - City: Entity. It represents a city by its name, X coordinate and Y coordinate.
 - Routes: Entity. It represents multiple cities in order, so that it's a route to be followed.
 - Problem: An use case. It allows you to store the distance matrix among cities, calculate cost and retrieve certain cities.
 
 - Montecarlo Heuristic: It implements the Montecarlo heuristic. It shuffles the whole Route 
 
 TODO:
 - Refactor and move classes in order to follow Clean Code and Clean Architecture guidelines (e.g. entities, use cases; method with less than 16 lines, single responsibility...).
 - Better metrics such as Time tracking, results summary (e.g. # of cities, # of iterations, etc).
 
 FINAL GOAL:
 Parallelize by using MPI and OpenMP libraries.
