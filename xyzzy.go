package xyzzy

import (
	"fmt"
)

// Values updated via "go install -ldflags" parameters.

var moduleName string = "github.com/docktermj/go-hello-world-module"
var buildVersion string = "0.0.5"
var buildIteration string = "0"
var helloName string = "world"

func Hello() string {
	return fmt.Sprintf("Hello, %s! from %s version %s-%s", helloName, moduleName, buildVersion, buildIteration)
}
