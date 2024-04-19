#include<algorithm> //fine, if
#include<cctype> // isspace()
#include <string>
#include <iostream>
#include<vector>
#include <iterator>


using namespace std;

//인수가 공백일때는 true, 그렇지 않을때는 false


static bool space(char c) {
	return isspace(c);
}

//인수가 공백일때는 true, 그렇지 않을때는 false

static bool not_space(char c) {
	return !isspace(c);
}

static vector<string> split(const string&str){
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string>ret;

	while (i != str.end()) {
		cout << "String begin pos" << distance(str.begin(), i) << endl;

		i = find_if(i, str.end(), not_space);
		cout << "String find pos: " << distance(str.begin(), i) << endl;

		//다음 단어의 끝을 찾음
		iter j = find_if(i, str.end(), space);

		cout << "j pos: " << distance(str.begin(), j) << endl;

		//[i,j)범위의 문자를 복사
		if (i != str.end()) {
			ret.push_back(string(i, j));
		}
		i = j;
		cout << "i 이동 pos: " << distance(str.begin(), i) << endl;
	}

	return ret;
}

int main() {
	string s;

	//문자열을 한행씩 입력받아 분할
	while (getline(cin, s)) {
		vector <string>	v = split(s);

		//벡터 v에 저장한 단어를 각 각 출력	
		for (vector<string> ::size_type i = 0;
			i != v.size(); i++) {
			cout << v[i] << endl;
		}

	}
	return 0;
}