func divByZero() {

	var countOfPersons = 0
	var ages = 0
	var proceed = true

	while proceed {
		print("Give your age please, zero quits > ")
		let input = readLine()!
  		guard let value = Int(input) else {
  			print("Age was not an integer")
  			return
  		}
  		if value == 0 {
  			proceed = false
  		} else {
  			ages += value
  			countOfPersons += 1
  		}
  	}
  	let averageAge = ages / countOfPersons
  	print("Average age is \(averageAge)")
}

  
divByZero()
