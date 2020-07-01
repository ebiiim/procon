package main

import (
	"bufio"
	"fmt"
	"os"
)

var rdr = bufio.NewReaderSize(os.Stdin, 100000000)

func readLine() string {
	buf := make([]byte, 0, 100000000)
	for {
		l, p, e := rdr.ReadLine()
		if e != nil {
			panic(e)
		}
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
}

func main() {
	s := readLine()
	t := readLine()

	ss := []byte(s)
	tt := []byte(t)

	c := 0
	for idx, b := range ss {
		if b != tt[idx] {
			c++
		}
	}
	fmt.Printf("%d", c)
}
