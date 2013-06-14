package main
import "fmt"

func main() {
    var i int
	for {
		fmt.Scanf("%d", &i)
		if i==42 {
			break
		} else {
			fmt.Printf("%d\n",i)
		}
	}
}