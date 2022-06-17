let array = [1,2,3,4,6,7,8,9,10]
// let array = [1,2,4]

let showDetails = true // Change to true to see what happens
var result = 0
let maxNum = array.max()!

print("Array is \(array)")
print("First loop...")
for number in 1...maxNum {
   if showDetails { print("  \(pad(string: String(result, radix: 2), toSize: 8))") }
   if showDetails { print("^ \(pad(string: String(number, radix: 2), toSize: 8))") }
   result = result ^ number
   if showDetails { print("> \(pad(string: String(result, radix: 2), toSize: 8))") }
   if showDetails { print("---") }
}
print("Second loop...")
for number in array {
   if showDetails { print("  \(pad(string: String(result, radix: 2), toSize: 8))") }
   if showDetails { print("^ \(pad(string: String(number, radix: 2), toSize: 8))") }
   result = result ^ number
   if showDetails { print("> \(pad(string: String(result, radix: 2), toSize: 8))") }
   if showDetails { print("---") }
}

print("Missing number is \(result)")

// Helper function for printing out details
func pad(string : String, toSize: Int) -> String {
   var padded = string
   for _ in 0..<(toSize - string.count) {
      padded = "0" + padded
   }
   return padded
}

