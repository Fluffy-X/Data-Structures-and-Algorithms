int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
	int i = 0;
	string dfs(int n, string& s) {
		string local;
		while( s[i] != ']' && i < s.size()) {
			if ( (int)s[i] >= 49 && (int)s[i] <= 57) {
                std::string::size_type sz;
                int n = std::stoi(s.substr(i,s.size()-i), &sz);
                i = i + sz + 1;
				local = local + dfs(n, s);
			}
			else {
				local += s[i];
				i++;
			}
		}
		if ( s[i] == ']') {
            string temp = local;
            for ( int j = 1; j < n; j++)
                local += temp;
            i++;
            return local;
        }
        return local;
	}
    string decodeString(string& s) {
  	 	return dfs(1,s);
    }
};
