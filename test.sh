#!/bin/bash
assert() {
  expected="$1"
  input="$2"

#   ./chibicc "$input" > tmp.s
#   gcc -static -o tmp tmp.s
#   ./tmp
#   actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}