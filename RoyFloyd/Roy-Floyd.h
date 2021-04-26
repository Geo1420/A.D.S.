#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <conio.h>
#include <iostream>

#define Infinit 90000

void initial_cost(int cost[100][100], int& n, int& m);

void displayMatrix(int cost[100][100], int n);

void RoyFloyd(int cost[100][100], int n);

void print_path(int first, int last, int cost[100][100], int n);

void compute_path(int node1, int node2, int n, int cost[100][100]);

#endif;
