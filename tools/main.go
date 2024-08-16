package main

import (
	"fmt"
	"gocv.io/x/gocv"
)

// rebuild on code change using https://stackoverflow.com/questions/78551229/how-can-i-use-gocv-in-go-with-cuda-support-on-windows-11
func main() {
	fmt.Print(gocv.OpenCVVersion())
}
