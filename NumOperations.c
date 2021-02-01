int NumOperations(int target,int* numbers,int numbersSize){

	for(int i=0;i<=numbersSize-1;i++) {
		if(check(target,numbers,numbersSize)) {
			return i-1;
		}
		if(numbersSize==1) return -1;

        // find index of min numbers
		int min1=numbers[0]>numbers[1], min2=numbers[1] <= numbers[0];

		for(int j=2;j<=numberSize-1;j++) {
			if(numbers[j]<a[min1]) {
				min1=j;min2=min1;
			} else {
				if(numbers[j]<numbers[min2]) {
					min2=j;
				}
			}
		}

	    // calculate lcm number
		int lcmNumber = lcm(numbers[min1],numbers[min2]);

	    // save lcm on numberSize-2
		numbers[min1]=numbers[numberSize-1];
		numbers[min2]=numbers[numberSize-2];
		numbers[numberSize-2] = lcmNumber;

	    // size-1 
		numberSize--;

	}

	return -1;

}

// greatest common divisor
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

// least common multiple
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int check(int target,int* numbers,int numbersSize){
	int i;
	for(i=0;i<numbersSize;i++){
		if(numbers[i]<target)return 0;
	}
	return 1;
}