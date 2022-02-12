#!/usr/bin/env python3

from typing import List, Union


class Pet:
    def __init__(self, t: int, x: int, y: int):
        self.t: int = t
        self.x: int = x
        self.y: int = y

    def __repr__(self):
        iam = "cow"
        if self.t == 2:
            iam = "pig"
        if self.t == 3:
            iam = "rabbit"
        if self.t == 4:
            iam = "dog"
        if self.t == 5:
            iam = "cat"
        return str(self.x).zfill(2)+"|"+str(self.y).zfill(2) + "|" + iam


class Act:
    def __init__(self, t: str, x: int, y: int, draw: str):
        self.t: str = t
        self.x: int = x  # t="MOVE"
        self.y: int = y  # t="MOVE"
        self.draw: str = draw  # t="DRAW"

    def __repr__(self):
        if self.t == "MOVE":
            return self.t+"("+str(self.x)+","+str(self.y)+")"
        elif self.t == "DRAW":
            return self.t+"("+self.draw+")"
        elif self.t == "WAITUNTIL":
            return self.t+"("+str(self.x)+")"
        else:
            return "ERR(SYNTAX)"


class Human:
    def __init__(self, x: int, y: int):
        self.x: int = x
        self.y: int = y
        self.actq: List[Act] = list()

    def __repr__(self):
        acts = ""
        for act in self.actq:
            acts += act.__repr__() + " "
        return str(self.x).zfill(2)+"|"+str(self.y).zfill(2) + " " + acts


class Partition:
    def __init__(self, x: int, y: int):
        self.x: int = x
        self.y: int = y

    def __repr__(self):
        return str(self.x).zfill(2)+"|"+str(self.y).zfill(2)


def say(s: str):
    ss = s.split("\n")
    for sss in ss:
        print("# " + sss)


class Field:
    def __init__(self, p, h):
        self.pets: List[Pet] = p
        self.humans: List[Human] = h
        self.partitions: List[Partition] = list()
        self.field: List[List[List[Union[Pet, Human, Partition]]]] = list(
            list())

    def __repr__(self):
        _p = False
        _h = False
        _x = False
        _f = True
        s = ""

        if _p:
            s += "Pets\n"
            for idx, x in enumerate(self.pets):
                s += str(idx+1).zfill(2)+": " + x.__repr__()+"\n"
        if _h:
            s += "Humans\n"
            for idx, x in enumerate(self.humans):
                s += str(idx+1).zfill(2)+": " + x.__repr__()+"\n"
        if _x:
            s += "Partitions\n"
            for idx, x in enumerate(self.partitions):
                s += str(idx+1).zfill(2)+": " + x.__repr__()+"\n"
        if _f:
            s += "Field\n"
            s += "   0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3\n"
            s += "   1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0\n"
            for x in range(1, 31):
                s += str(x).zfill(2) + " "
                for y in range(1, 31):
                    f = self.field[x][y]
                    val = 0b00000000
                    for obj in f:
                        if type(obj) is Partition:
                            val |= 0b00000001
                        if type(obj) is Human:
                            val |= 0b00000010
                        if type(obj) is Pet:
                            if obj.t == 1:
                                val |= 0b00000100
                            if obj.t == 2:
                                val |= 0b00001000
                            if obj.t == 3:
                                val |= 0b00010000
                            if obj.t == 4:
                                val |= 0b00100000
                            if obj.t == 5:
                                val |= 0b01000000
                    if val == 0b00000000:  # empty
                        s += ". "
                    elif val == 0b00000001:  # partition
                        s += "+ "
                    elif val == 0b00000010:  # human
                        s += "X "
                    elif val == 0b00000100:  # cow
                        s += "c "
                    elif val == 0b00001000:  # pig
                        s += "p "
                    elif val == 0b00010000:  # rabbit
                        s += "r "
                    elif val == 0b00100000:  # dog
                        s += "d "
                    elif val == 0b01000000:  # cat
                        s += "m "
                    else:
                        s += str(val)+" "  # overlap
                s += "\n"

        return s

    def update(self):
        self.field = list(list())
        for _ in range(0, 31):
            self.field.append([list() for y in range(0, 31)])
        for o in self.pets:
            self.field[o.x][o.y].append(o)
        for o in self.humans:
            self.field[o.x][o.y].append(o)
        for o in self.partitions:
            self.field[o.x][o.y].append(o)

    def move(self, turnNum: int) -> str:
        if turnNum == 0:
            pass
            for (idx, h) in enumerate(self.humans):
                h.actq.append(Act("MOVE", (idx+1)*2-1, 1, ""))
                h.actq.append(Act("WAITUNTIL", 50, -1, ""))
                for y in range(1, 31):
                    h.actq.append(Act("MOVE", (idx+1)*2-1, y, ""))
                    h.actq.append(Act("DRAW", -1, -1, "d"))

        acts = ""
        for (_, h) in enumerate(self.humans):
            if len(h.actq) == 0:
                acts += "."
                continue
            todo = h.actq[0]
            if todo.t == "MOVE":
                act = "."
                # TODO: check mobability
                aX = h.x
                aY = h.y
                if h.x < todo.x:
                    act = "D"
                    aX += 1
                elif h.x > todo.x:
                    act = "U"
                    aX -= 1
                elif h.y < todo.y:
                    act = "R"
                    aY += 1
                elif h.y > todo.y:
                    act = "L"
                    aY -= 1
                if todo.x == aX and todo.y == aY:
                    h.actq.pop(0)
                acts += act
            elif todo.t == "DRAW":
                act = "."
                drawX = h.x
                drawY = h.y
                if todo.draw == "u":
                    drawX -= 1
                elif todo.draw == "d":
                    drawX += 1
                elif todo.draw == "l":
                    drawY -= 1
                elif todo.draw == "r":
                    drawY += 1
                # try draw
                drawable = True
                for obj in self.field[drawX][drawY]:
                    if type(obj) == Pet:
                        drawable = False
                for obj in self.field[min(drawX+1, 30)][drawY]:
                    if type(obj) == Pet:
                        drawable = False
                for obj in self.field[max(1, drawX-1)][drawY]:
                    if type(obj) == Pet:
                        drawable = False
                for obj in self.field[drawX][min(drawY+1, 30)]:
                    if type(obj) == Pet:
                        drawable = False
                for obj in self.field[drawX][max(1, drawY-1)]:
                    if type(obj) == Pet:
                        drawable = False
                if drawable:
                    pass
                    act = todo.draw
                    h.actq.pop(0)
                acts += act
            elif todo.t == "WAITUNTIL":
                act = "."
                if turnNum < todo.x:
                    pass
                if turnNum + 1 >= todo.x:
                    h.actq.pop(0)
                acts += act

        return acts

    def do(self, turnNum):
        # print field before move
        self.update()
        say("[INIT] TURN "+str(turnNum))
        say(self.__repr__())

        # set move
        say("vvv TURN " + str(turnNum) + " MOVE vvv")
        act = self.move(turnNum)
        print(act)
        say("^^^ TURN " + str(turnNum) + " MOVE ^^^")

        # move humans
        for idx, c in enumerate(act):
            if c == "u":
                self.partitions.append(
                    Partition(self.humans[idx].x-1, self.humans[idx].y))
            if c == "d":
                self.partitions.append(
                    Partition(self.humans[idx].x+1, self.humans[idx].y))
            if c == "l":
                self.partitions.append(
                    Partition(self.humans[idx].x, self.humans[idx].y-1))
            if c == "r":
                self.partitions.append(
                    Partition(self.humans[idx].x, self.humans[idx].y+1))
            if c == "U":
                self.humans[idx].x -= 1
            if c == "D":
                self.humans[idx].x += 1
            if c == "L":
                self.humans[idx].y -= 1
            if c == "R":
                self.humans[idx].y += 1

        # print field after move
        self.update()
        say("[MOVED] TURN "+str(turnNum))
        say(self.__repr__())
        say("----------")

        # get pet moves and move pets
        for idx, act in enumerate([acts for acts in input().split()]):
            for c in act:
                if c == "U":
                    self.pets[idx].x -= 1
                if c == "D":
                    self.pets[idx].x += 1
                if c == "L":
                    self.pets[idx].y -= 1
                if c == "R":
                    self.pets[idx].y += 1


def solve():
    N = int(input())
    P = list()
    for _ in range(N):
        px, py, pt = map(int, input().split())
        P.append(Pet(pt, px, py))
    M = int(input())
    H = list()
    for _ in range(M):
        hx, hy = map(int, input().split())
        H.append(Human(hx, hy))

    F = Field(P, H)
    turns = 300
    for idx in range(turns):
        F.do(idx)


solve()
