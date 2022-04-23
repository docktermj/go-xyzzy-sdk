package main

/*
#include <stdlib.h>
#include <stdio.h>
*/
import (
	"context"
	"fmt"

	"github.com/docktermj/xyzzygoapi/g2diagnostic"
)

// Values updated via "go install -ldflags" parameters.

var moduleName string = "github.com/docktermj/go-xyzzy-sdk"
var buildVersion string = "0.0.5"
var buildIteration string = "0"

// ----------------------------------------------------------------------------
// main
// ----------------------------------------------------------------------------

func main() {

	// Get Xyzzy's G2diagnostic object.

	g2diagnostic := g2diagnostic.G2diagnosticImpl{}

	// Create context.

	ctx := context.TODO()

	// Call Xyzzy G2diagnostic methods.

	availableMemory, _ := g2diagnostic.GetAvailableMemory(ctx)
	logicalCores, _ := g2diagnostic.GetLogicalCores(ctx)
	physicalCores, _ := g2diagnostic.GetPhysicalCores(ctx)
	totalSystemMemory, _ := g2diagnostic.GetTotalSystemMemory(ctx)

	// Print results.

	fmt.Println("Available memory:", availableMemory)
	fmt.Println("    Total memory:", totalSystemMemory)
	fmt.Println("  Physical cores:", physicalCores)
	fmt.Println("   Logical cores:", logicalCores)

}
