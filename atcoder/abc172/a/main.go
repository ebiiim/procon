package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	in := scanner.Text()
	v, _ := strconv.Atoi(in)
	fmt.Printf("%d", v+v*v+v*v*v)
}
