#include <stdio.h>

void swapChar(char *a, char *b) {
	char t;
	t = *a;
	*a = *b;
	*b = t;
}

void swapInt(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void reverse(char *x, int i, int j) {
	for (; i < j; i++, j--) {
		swapChar(&x[i], &x[j]);
	}
}

// Alg 1: Rotate by reversal
void reverseRotate(char *x, int i, int n) {
	reverse(x, 0, i-1);		// (a^r)b
	reverse(x, i, n-1);    	// (a^r)(b^r)
	reverse(x, 0, n-1);     // ((a^r)(b^r))^r = ba, so ab->ba
}

// Alg 2: Juggling (dolphin) rotation
int gcd(int i, int j) {
	while(i != 0) {
		if( j>=i )
			j -= i;
		else {
			swapInt(&i, &j);
		}
	}
	return j;
}

int isogcd(int i, int j) {
	if (i==0) return j;
	if (j==0) return i;

	while( i != j) {
		if(i > j)
			i -= j;
		else
			j -= i;
	}
	return i;
}

void juggleRotate(char *x, int rotdist, int n) {
	int cycles, i, j, k, t;
	cycles = gcd(rotdist, n);
	for(i=0; i<cycles; i++) {
		// move i-th values of blocks
		t = x[i];
		j = i;
		for(;;) {
			k = j + rotdist;
			if( k >= n) 
				k -= n;
			if( k == i)
				break;
			x[j] = x[k];
			j = k;
		}
		x[j] = t;
	}
}

void juggleRotate2(char *x, int rotdist, int n) {
	int cycles, i, j, k, t;
	cycles = gcd(rotdist, n);
	for(i=0; i<cycles; i++) {
		// move i-th values of blocks
		t = x[i];
		j = i;
		for(;;) {
		/* Replace with mode below 
			k = j + rotdist;
			if( k >= n) 
				k -= n;
		*/
		k = (j+rotdist) % n;
			if( k == i)
				break;
			x[j] = x[k];
			j = k;
		}
		x[j] = t;
	}
}


// Alg 3: Recursive rotate (using gcd structure)

// swap x[i..i+k-1] with x[j..j+k-1]
void nSwap(char *x, int i, int j, int k) {
	while (k--) {  
		swapChar(&x[i], &x[j]);
		i++;
		j++;
	}
}

void gcdRotate(char *x, int rotdist, int n) {
	int i, j, p;
	if (rotdist == 0 || rotdist == n)
		return;
	i = p = rotdist;
	j = n - p;
	while( i != j) {
		/* invariant:
			x[0	.. p-i	] is in final position
			x[p-i..p-i	] = a (to be swapped with b)
			x[p	 ..p+j-1] = b (to be swapped with a)
			x[p+j..n-1	] in final position
		*/
		if(i>j) {
			nSwap(x, p-i, p, j);
			i -= j;
		} else {
			nSwap(x, p-i, p+j-i, i);
			j -= i;
		}
	}
	nSwap(x, p-i, p, i);
}

int main() {
	/* Example usage */
	char tst[] = "hello, world";
	//reverseRotate(tst, 9, 12);
	//juggleRotate(tst, 9, 12);
	//juggleRotate2(tst, 9, 12);
	gcdRotate(tst, 9, 12);
	printf("%s\n", tst); /* Expected: rldhello, wo */
	return 0;
}
