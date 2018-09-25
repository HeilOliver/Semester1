checksum(↓integer numbers[], ↑integer cksm)
  integer sum = 0
  
  for (i=numbers.size-1; i>=0; i--)do
		sum += numbers[i]
  end
  cksm = sum % 256
 end