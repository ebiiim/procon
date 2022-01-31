class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def inOrder(root):
    # https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
    sss = ""
    current = root
    stack = []  # initialize stack

    while True:
        if current is not None:
            stack.append(current)
            current = current.left
        elif(stack):
            current = stack.pop()
            sss += str(current.data)
            sss += " "
            current = current.right
        else:
            break
    print(sss[:-1])


def solve():
    N = int(input())
    S = input()

    cnt = 0

    root = Node(0)

    parent = root
    for s in S:
        cnt += 1
        if s == "L":
            tmp = Node(cnt)
            parent.left = tmp
            parent = tmp
        else:
            tmp = Node(cnt)
            parent.right = tmp
            parent = tmp

    inOrder(root)


solve()
