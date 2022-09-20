// Swift version of the x-or-fun.c.
// Build: swiftc -o xfun x-or-fun.swift
// Run: execute the xfun binary.

let array = [1,2,3,4,6,7,8,9,10]

let showDetails = true // Change to true to see what happens
var result = 0
let maxNum = array.max()!

print("\nThis tool finds a missing number from the array below,");
print("using XOR operator. The tool goes through two loops, first");
print("XORing the numbers from 1 to max value found in array,");
print("10 in this example). Then second loop XORs the actual values");
print("in the array. The result will then contain the missing value.\n");

print("Array is \(array)")
print("First loop...")
for number in 1...maxNum {
   if showDetails { print("    \(pad(string: String(result, radix: 2), toSize: 8))") }
   if showDetails { print("XOR \(pad(string: String(number, radix: 2), toSize: 8))") }
   result = result ^ number
   if showDetails { print("=   \(pad(string: String(result, radix: 2), toSize: 8))") }
   if showDetails { print("-----") }
}
print("Second loop...")
for number in array {
   if showDetails { print("    \(pad(string: String(result, radix: 2), toSize: 8))") }
   if showDetails { print("XOR \(pad(string: String(number, radix: 2), toSize: 8))") }
   result = result ^ number
   if showDetails { print("=   \(pad(string: String(result, radix: 2), toSize: 8))") }
   if showDetails { print("-----") }
}

print("Missing number is \(result), in binary: \(pad(string: String(result, radix: 2), toSize: 8))")

// Helper function for printing out details
func pad(string : String, toSize: Int) -> String {
   var padded = string
   for _ in 0..<(toSize - string.count) {
      padded = "0" + padded
   }
   return padded
}

