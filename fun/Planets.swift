for n in stride(from: 0, to: 9, by: 1) {
	print("\(Unicode.Scalar(0x263f+n)!)", terminator: " ")
}
print("")

