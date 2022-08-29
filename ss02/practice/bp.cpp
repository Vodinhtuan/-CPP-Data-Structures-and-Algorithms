#include <iostream>
// fibonacci ssg
int bp(int n){
	if (n>0 && n<4)
	return n;
	else bp(n-2) + bp(n-1);
	}

