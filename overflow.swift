
func addWithUnsignedByte() {
   print("Adding with unsigned bytes")
   let first: UInt8 = 79
   let second: UInt8 = 99
   let sum: UInt8 = first + second
   print("first: \(first) + second: \(second) == \(sum)")
}

func addWithSignedByte() {
   print("Adding with signed bytes")
   let first: Int8 = 79
   let second: Int8 = 99
   let sum: Int8 = first + second
   print("first: \(first) + second: \(second) == \(sum)")
}

func addWithSignedByteAndOverflow() {
   print("Adding with signed bytes")
   let first: Int8 = 79
   let second: Int8 = 99
   let sum: Int8 = first &+ second
   print("first: \(first) + second: \(second) == \(sum)")
}

print("Swift overflow handling...")
addWithUnsignedByte()
addWithSignedByte()
addWithSignedByteAndOverflow()
