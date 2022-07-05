
// That's my first brute force idea. Unfortunately, this solution would exceed time limitation.
int find(vector<string>words, string word)
{
	int count = -1;
	for (auto i : words)
	{
		count++;
		if (i == word)
			return count;
	}
	return -1;
}
vector<int> findSubstring(string s, vector<string>& words) {
	int n = words[0].length();
	vector<int> res;
	for (int i = 0; i < s.length(); i++)
	{
		vector<string> t = words;
		string s_t = s.substr(i);
		if (s_t.length() < n)
			break;
		while (1)
		{
			int loca = find(t, s_t.substr(0, n));
			if (loca != -1)
			{
				t.erase(t.begin() + loca);
				s_t = s_t.substr(n);
			}
			else
				break;
			if (t.size() == 0)
			{
				res.push_back(i); break;
			}
		}
	}
	return res;
}

// solution below is modified version
// two maps. One(record) for record how many times each word showing up in the vector(words)
// One(already) for record when word show up in s.
// if already[x] > record[x]
//		then it means we can not find solution when we start from s[i]. i++
// if all the test can be passed and when we test length i+m*n where m is the length of vector n is the length of each word
// then i is what we want.
vector<int> findSubstring(string s, vector<string>& words) {
	unordered_map<string, int> record;
	int n = words[0].length();
	int m = words.size();
	//initialize mapping all words in the list
	vector<int> res;
	for (auto word : words)
		record[word]++;
	for (int i = 0; i < s.length() - m * n + 1; i++)
	{
		unordered_map<string, int> already;
		int flag = 1;
		for (int j = i; j < i + m * n; j += n)
			if ((++already[s.substr(j, n)]) > record[s.substr(j, n)])
			{
				flag = 0; break;
			}
		if (flag)
			res.push_back(i);
	}
	return res;
}