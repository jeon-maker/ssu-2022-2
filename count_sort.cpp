
// #include <>


void function(int array[] ,int size, int max ,int min, int m){ // n은 input의 최대값 - 최대값 +1 즉 count 배열의 길이 . m 은 출력 횟수
	int n = max - min + 1;
	int count [n];
	int val [n];
	int p = min;
	for (int i=0; i<n; i++){
		count[i] = 0;
		val[i] = p;
		p++;
	}
	for (int i=0; i<size; i++){
		// min 값은 count 0에 들어가야 하고 max 값은 count n에 들어가야 한다.
		int c = array[i] - min;
		count[c]++;}
	// count에 정렬되어 있음
	// count에서 가장 큰 숫자를 찾으면 count의 idx를 출력하기. 
	//출력하면 그 idx는 -999로 만들고, 동일 값일 경우 더 큰 idx 출력하기
	// 음수일경우 출력이 안되는구나!
	for (int i=0; i<m; i++){	
		int val_ = count[0];
		int idx = 0;
		for (int j=0; j<n;j++)
			if(count[j] >= val_){
				val_ = count[j];
				idx = j;
			}
		count[idx] = -99999;
		cout << val[idx] << " ";
	}
};
