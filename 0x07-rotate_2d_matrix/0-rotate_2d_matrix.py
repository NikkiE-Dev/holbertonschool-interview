#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    row = len(matrix)
    col = len(matrix[0])
    for i in range(row):
        for j in range(i, col):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(row):
        matrix[i].reverse()
