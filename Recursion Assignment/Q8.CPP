

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    
    unordered_map<char, char> sMap;
    unordered_map<char, char> tMap;
    
    for (int i = 0; i < s.length(); i++) {
        char sChar = s[i];
        char tChar = t[i];
        
        if (sMap.count(sChar) > 0 && sMap[sChar] != tChar) {
            return false;
        }
        
        if (tMap.count(tChar) > 0 && tMap[tChar] != sChar) {
            return false;
        }
        
        sMap[sChar] = tChar;
        tMap[tChar] = sChar;
    }
    
    return true;
}

