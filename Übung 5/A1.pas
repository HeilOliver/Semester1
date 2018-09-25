
Searchformissingnumber(↓Integer numbers[], ↑Integer missingNum) 
	sumofnumbers = 0
	totalsum = 0
	Integer i = 0
	
	while (i < numbers.length()) do
		sumofnumbers = numbers[i]
		totalsum += i
		i++
	end	
	missingNum = (totalsum + i) - sumofnumbers
end
