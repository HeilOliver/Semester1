VowelOccurencies(↓string text, ↑integer freqA, ↑integer freqE, ↑integer freqI, ↑integer freqO, ↑integer freqU)

	integer i = 0
	integer textlength = text.length()
	integer Vowels[5] = {0,0,0,0,0}

	while (i < textlength) do
		if (text[i] == 'A' || text[i] == 'a') then
			Vowels[0] = Vowels[0] +1
		end
		if (text[i] == 'E' || text[i] == 'e') then
			Vowels[1] = Vowels[1] +1
		end
		if (text[i] == 'I' || text[i] == 'i') then
			Vowels[2] = Vowels[2] +1
		end
		if (text[i] == 'O' || text[i] == 'o') then
			Vowels[3] = Vowels[3] +1
		end	
		if (text[i] == 'U' || text[i] == 'u') then
			Vowels[4] = Vowels[4] +1
		end
		i = i + 1
	end

	freqA := (Vowels[0] * 100) / (textlength * 100)
	freqE := (Vowels[1] * 100) / (textlength * 100)
	freqI := (Vowels[2] * 100) / (textlength * 100)
	freqO := (Vowels[3] * 100) / (textlength * 100)
	freqU := (Vowels[4] * 100) / (textlength * 100)

end