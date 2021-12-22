package hello

import (
	"fmt"
	"strings"
	"testing"
)

/*
 * The unit tests in this file simulate command line invocation.
 */

func TestHello(testing *testing.T) {
	want := fmt.Sprintf("Hello, %s!", helloName)
	if got := Hello(); !strings.HasPrefix(got, want) {
		testing.Errorf("Hello() = %q, want %q", got, want)
	}
}
