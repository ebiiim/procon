def solve():
    A, B = map(int, input().split())

    import numpy as np

    v1 = np.array([0, 0])
    v2 = np.array([A, B])
    v = v2 - v1
    rad = np.arctan2(v[0], v[1])

    # print("rad", rad)

    x2 = 0 + 1 * np.cos(rad)
    y2 = 0 + 1 * np.sin(rad)

    print('{0:.12f}'.format(y2), '{0:.12f}'.format(x2))


solve()
