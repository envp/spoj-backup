import "fmt"

func main() {
    var n int
	var l,u,d,k int64
    fmt.Scan(&n)
	for ; n>0; n-- {
		fmt.Scan(&l)
		k=l/2
		u=l*(l+1)*(l+2)/6
		if l%2!=0 {
			d=(k*(k+1)*(4*k+5)/6)
		} else {
			d=(k*(k+1)*(4*k-1)/6)
		}
		fmt.Println(u+d)
	}
	
}