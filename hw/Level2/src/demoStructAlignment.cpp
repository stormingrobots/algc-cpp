// testx.cpp : Defines the entry point for the console application.
//

#include <string.h>

#define offset(type, x)  &(((type*)NULL)->x)
typedef struct {
	char c1[3];   // 0
	char c2[4];   // 1
} test0;

typedef struct {
	char ca1;   // 0, but 1-3 not used due to data packing
	int ia;     // 4-7
	char ca2;   // 8, but 9-11 not used
} test1;

typedef struct  {
	char c1;   // 0
	char c2;   // 1  
	int  i1;   // 4
	short c3;   // 8
} test2;

typedef struct {
	int ia;    // 0 
	char ca1;  // 4
	char ca2;  // 5, but 6-7 unsable
} test3;

typedef struct {
	int ia1;   // 0-3 
	char ca1;  // 4, but 5 not used
	short ia2; // 6-7
	char ca2;  // 8, but 9-11 not used
} test4;

typedef struct {
	int ia1;   // 0-3 
	char ca1;  // 4
	char ca2;  // 5
	char ia2; // 6
	char ia3; // 7  , 8 bytes
} test5;

typedef struct {
	int ia1;   // 0-3 
	char ca1;  // 4
	char ca2;  // 5
	char ca3;
	short ia2; // 6-7
	short ia3; // 8-9, but 10-11 not used
} test6;
/*
They internally get memory from malloc. However, if you requested:
N bytes : will need N+P+A 
    where P =  the size of a pointer (based on the CPU architecture)
	      A = the alignment required, expressed in power-of-2 number of bytes. For example, if I request for 100 bytes on a 64-bit CPU and require the memory to be aligned to a multiple of 32, then the wrapper will request for 140 bytes.
*/

void dataAlignInStruct() {
	char  c1;
	short i1;
	char c2;
	short i2;


	test0 tst; 
	
	printf("%d %d %d %d\n", &i1, &i2, &c1, &c2);

	return;

	printf("sizeof (test1) %d\n", sizeof(tst));
	printf(" %d;   %d;  \n",
		offset(test0, c1), offset(test0, c2));

	
	/*
	test0 s0;
	test1 s1;
	test2 s2;
	
	test2 s2;
	test3 s3;
	test4 s4;
	test5 s5;
	
	char  c1;
	short i1;
	char c2;
	short i2;
*/
	printf("i1: %d;  i2: %d\n", &i1, &i2);

/*	printf("s: %d;  s2: %d (size=%d), %d\n",
		offset(test0, ca1), offset(test0, ca2),
		sizeof(test0), &s0);



	printf("s: %d;  s2: %d;   s3: %d; (size=%d), %d\n",
		offset(test2, ca1), offset(test2, ca2), offset(test2, ca3),
		sizeof(test2), &s2);
*/
/*
	printf("s1: %d;  s2: %d; s3: %d (size=%d)\n",
		offset(test1, ca1), offset(test1, ia),
		offset(test1, ca2), sizeof(test1));
	printf("s1: %d;  s2: %d; s3: %d (size=%d)\n",
		offset(test2, ca1), offset(test2, ia),
		offset(test2, ca2), sizeof(test2));
	printf("s1: %d;  s2: %d; s3: %d(size=%d)\n",
		offset(test3, ca1), offset(test3, ia),
		offset(test3, ca2), sizeof(test3));
	printf("s1: %d;  s2: %d; s3: %d; s4: %d (size=%d)\n",
		offset(test4, ia1), offset(test4, ca1),
		offset(test4, ia2), offset(test4, ca2), sizeof(test4));
	printf("s1: %d;  s2: %d; s3: %d; s4: %d; s5: %d (size=%d)\n",
		offset(test5, ia1), offset(test5, ca1),
		offset(test5, ca2),
		offset(test5, ia2), 
		offset(test5, ia3),
		sizeof(test5));
	printf("s1: %d;  s2: %d; s3: %d; s4: %d; s5: %d; s6: %d (size=%d)\n",
		offset(test6, ia1), offset(test6, ca1),
		offset(test6, ca2), offset(test6, ca3),
		offset(test6, ia2),
		offset(test6, ia3),
		sizeof(test6));

	//printf("s1.ca1: %d;  s1.ca2: %d\n", &(s1.ca1), &(s1.ca2));

	//printf("s2.ca1: %d;  s2.ca2: %d\n", &(s2.ca1), &(s2.ca2));

	//printf("s3.ca1: %d;  s3.ca2: %d\n", &(s3.ca1), &(s3.ca2));

	printf("s4.ia1: %d; s4.ca1: %d s4.ia2: %d s4.ca2: %d\n",
		&(s4.ia1), &s4.ca1, &(s4.ia2), &s4.ca2);

	
	*/
	
}

void show3DAddr() {
	char clist[3][10];
	char *cp = (char *)clist;
	int ilist[3][10];
	int *ip = ilist[0];

	for (int i = 0; i < 3; i++) {
		printf("\ncp+%d  \n", cp+i);
		for (int j = 0; j < 10; j++) {
			printf("  ilist[%d][%d]:  %d", i, j,&ilist[i][i]);
		}
	}

}

int main(int argc, char **argv)
{

	dataAlignInStruct();
	//show3DAddr();
	return 0;
}

