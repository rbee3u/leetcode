package main

import (
    "testing"
)

func TestCountSubstrings(t *testing.T) {
    if countSubstrings("abc") != 3 {
        t.Errorf("wrong answer")
    }
    if countSubstrings("aaa") != 6 {
        t.Errorf("wrong answer")
    }
}
