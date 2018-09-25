howmuchdays(↓string date,↑integer result)
	string splitteddate[3] = {"","",""}
	integer date_length = date.length()
	integer i = 0
	integer n = 0
	
	while (i < date_length) do
		if (date[i] == ' ') then
			n := n + 1
		else
			splitteddate[n] = splitteddate[n] + date[i]
		end
		i = i + 1
	end
	
	if (numbercheck(splitteddate[1]) == true && numbercheck(splitteddate[3]) == true) then
		result := daycalc(atoi(splitteddate[1]),splitteddate[2],atoi(splitteddate[3]))
	else 
		result := -1
	end
end

daycalc(↓unsigned integer days,↓string month,↓unsigned integer year,↑integer days)
	const string month_str[12] = {"JAN","FEB","MAE","APR","MAI","JUN","JUL","AUG","SEP","OKT","NOV","DEZ"}
	integer month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31}
	integer numberofmonth := -1;
	integer sumofdays := 0;

	for (int i = 0; i < 12 && numberofmonth == -1; i++) do
		if (month == month_str[i]) then
			numberofmonth = i
			month_day[1] += leapyeardetermination(year)
		end
	end
	
	if (numberofmonth != -1 && days > 0 && days <= month_day[numberofmonth]) then
		for (integer i = 0; i < numberofmonth;i++) do
			sumofdays += month_day[i]
		end
		sumofdays += days
	else
		sumofdays := -1
	end
	days := sumofdays
end

leapyeardetermination(↓integer Year, ↑integer Result)
	Result := 1
	if (Year < 100) then
		Year = Year + 2000
	end
	if ((Year % 4) == 0) then
		if ((Jahr % 100) == 0)
			if ((Jahr % 100) == 0)
				Result := 0
			end
		end
	else
		Result := 0
	end
end

numbercheck(↓string number, ↑boolean result)
	const char numbers[10] = { '0','1','2','3','4','5','6','7','8','9'};
	boolean numberchecked = false
	result := true
	for (int i = number.length() -1; i >= 0; i--) do
		numberchecked := false
		for (int n = 0; n < 10; n++) do
			if (number[i] == numbers[n]) then
				numberchecked := true
			end
		end
		if (numberchecked == false) then
			result := false
		end
	end
end