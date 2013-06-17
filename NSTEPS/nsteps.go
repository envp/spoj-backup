package main

import "fmt"

func main() {
    var n int
	var x, y int
	fmt.Scanf("%d", &n)
	for ; n>0; n-- {
		fmt.Scanf("%d %d", &x, &y)
		if x-y==2 || x==y {
			fmt.Println(x+y-x%2-y%2+(x%2)*(y%2))
		} else {
			fmt.Println("No Number")
		}
	}
}



