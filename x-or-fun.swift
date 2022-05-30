let array = [1,2,3,4,6,7,8,9,10]
// let array = [1,2,4]

var result = 0
let maxNum = array.max()!

func pad(string : String, toSize: Int) -> String {
   var padded = string
   for _ in 0..<(toSize - string.count) {
      padded = "0" + padded
   }
   return padded
}

for number in 1...maxNum {
   print("  \(pad(string: String(result, radix: 2), toSize: 8))")
   print("^ \(pad(string: String(number, radix: 2), toSize: 8))")
   result = result ^ number
   print("> \(pad(string: String(result, radix: 2), toSize: 8))")
   print("---")
}
print("And then...")
for number in array {
   print("  \(pad(string: String(result, radix: 2), toSize: 8))")
   print("^ \(pad(string: String(number, radix: 2), toSize: 8))")
   result = result ^ number
   print("> \(pad(string: String(result, radix: 2), toSize: 8))")
   print("---")
}

print("Missing number is \(result)")

