package xyzzy

/*
#cgo CFLAGS: -g -Wall
#include <stdlib.h>
#include <stdio.h>
#include "g2PluginInterface.h"
#include "libg2.h"
#include "libg2config.h"
#include "libg2configmgr.h"
#include "libg2diagnostic.h"
#include "libg2hasher.h"
#include "libg2product.h"
#include "libg2ssadm.h"
*/
import "C"
import (
	"fmt"
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

	regreet()
}
