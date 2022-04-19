package xyzzy

/*
#cgo CFLAGS: -g -Wall
#include <stdlib.h>
#include <stdio.h>
#include "libg2diagnostic.h"
*/
import "C"
import (
  "fmt"
  "unsafe"
)

// Values updated via "go install -ldflags" parameters.

var moduleName string = "github.com/docktermj/go-xyzzy-sdk"
var buildVersion string = "0.0.5"
var buildIteration string = "0"

// ----------------------------------------------------------------------------
// libg2diagnostic.h
// ----------------------------------------------------------------------------

func G2Diagnostic_getPhysicalCores() int {
    result := C.G2Diagnostic_getPhysicalCores()
    return result
}

// ----------------------------------------------------------------------------
// main
// ----------------------------------------------------------------------------


func main() {

  physicalCores := G2Diagnostic_getPhysicalCores()
  fmt.Println("Physical cores %d", physicalCores)

}
