
wordcount(↓string text, ↓Integer n) {

	string W_str[100] = {}
	Integer W_str_length = 0
	Integer W_count[100] = {}
	Integer pos = 0
	
	
	while (pos < n) {
		findWordinArr(findWordinStr(text,pos), W_str_length,W_count,W_str)
	}

	for (--W_str_length; W_str_length > 0; --W_str_length) {
		printf("%s: %d",W_str[W_str_length],W_count[W_str_length])
	}
}

findWordinArr(↓string word, ↓↑Integer W_str_length, ↓↑Integer W_count, ↓↑string W_str ) {
	Integer i = 0
	Boolean found = false;
	
	while(found == false && i < W_str_length){
		if (word == W_str[i]) {
			found = true
		} else {
			++i
		}
	}
	if (found == true) {
		++W_count[i] 
	} else {
		W_str[W_str_length] = Word
		W_count[W_str_length] = 1
		++W_str_length 
	}
}


findWordinStr(↓string text, ↓↑Integer pos, ↑String word) {
	while(pos < text.length() && text[pos] != ',' && text[pos] != '.' && text[pos] != ' ') {
		word += text[pos]
		++pos
	}
	while(pos < text.length() && (text[pos] == ',' || text[pos] == '.' || text[pos] == ' ')) {
		++pos
	}
}