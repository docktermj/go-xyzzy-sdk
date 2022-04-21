package main

/*
#include <stdlib.h>
#include <stdio.h>
#include "libg2diagnostic.h"
#cgo CFLAGS: -g -Wall
#cgo LDFLAGS: -shared
*/
import "C"
import (
  "fmt"
//  "unsafe"
)

// Values updated via "go install -ldflags" parameters.

var moduleName string = "github.com/docktermj/go-xyzzy-sdk"
var buildVersion string = "0.0.5"
var buildIteration string = "0"

// ----------------------------------------------------------------------------
// libg2diagnostic.h
// ----------------------------------------------------------------------------

func G2Diagnostic_getPhysicalCoresX() int {
    result := C.G2Diagnostic_getPhysicalCores()
    return int(result)
}

// ----------------------------------------------------------------------------
// main
// ----------------------------------------------------------------------------


func main() {

  physicalCores := G2Diagnostic_getPhysicalCoresX()
  fmt.Println("Physical cores %d", physicalCores)

}
