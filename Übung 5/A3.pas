delnegativnumbers(Integer data[], Integer Newsize, Integer Newdata[])
	Integer validcounter = 0;
	for (Integer i = 0, n= 0; i< data.length(); i++) do
		if (data[i] >= 0) do
			data[n] = data[i];
			n++;
			validcounter++;
		end
	end
	Newsize = validcounter;
	Newdata = data
end