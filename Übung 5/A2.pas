findlocalminmax(Integer data[], Integer minimas, Integer maximas)
	Integer local_minimas = 0
	Integer local_maximas = 0
	
	for (int i = 1; i < data.length()-1; i++) do
		if (data[i-1] > data[i] && data[i+1] > data[i])then
			local_minimas++
		end
		if (data[i-1] < data[i] && data[i+1] < data[i])then
			local_maximas++;
		end
	end
	minimas = local_minimas
	maximas = local_maximas
end