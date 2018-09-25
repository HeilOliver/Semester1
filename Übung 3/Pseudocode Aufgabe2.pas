Palindromtest(↓string word, ↑bool result)
	result := true	
	integer n = word.length() - 1
	integer i = 0

	while (result == true and i < n) do
		if(word[n] != word[i]) then
			result := false	
		end
		
		i := i+1
		n := n-1
	end
end 