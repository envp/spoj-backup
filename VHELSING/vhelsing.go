package main

import "fmt"
import "math"

func main() {
    var i int
	var r float64
	fmt.Scanf("%d",&i)
	for ; i>0; i-- {
		fmt.Scanf("%f", &r)
		fmt.Printf("%.4f\n", 8*(2-math.Sqrt(2))*r*r*r)
	}
}