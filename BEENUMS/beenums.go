package main

import "fmt"

func main() {
	var a int
	for ; a != -1; fmt.Scanf("%d", &a) {
		if a == 1 {
			fmt.Println("Y")
		} else {
			i := 0
			u := 1
			for u < a {
				u += 6 * i
				i++
			}
			if u == a {
				fmt.Println("Y")
			} else {
				fmt.Println("N")
			}
		}
	}
}
