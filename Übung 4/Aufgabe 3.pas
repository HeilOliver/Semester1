arrayequally(↓integer numbers0[],↓integer numbers1[], ↑bool equally)
  equally := true
  
  if (numbers0.size() != numbers1.size()) then
	equally := false
  else
	for(integer i = numbers0.size(); i >= 0 && equally == true; i-- ) do
		if ((numbers0 * numbers0) != (numbers1 * numbers1)) then
			if (numbers0 != 0 || numbers1 != 0) then
				equally := false
			end
		end
	end
  end
end