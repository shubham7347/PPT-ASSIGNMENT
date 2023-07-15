string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int n = s.length();
    int i = 0;
    
    for (int j = 0; j < n; j++) {
        if (s[j] == ' ') {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }
    
    reverse(s.begin() + i, s.end());
    
    // Remove leading, trailing, and extra spaces
    int k = 0;
    for (int j = 0; j < s.length(); j++) {
        if (s[j] != ' ' || (j > 0 && s[j-1] != ' ')) {
            s[k++] = s[j];
        }
    }
    
    return s.substr(0, k);
}
