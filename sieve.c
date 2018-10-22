#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sieve.h"

int sieve(int num) {
	int size = num  * log(num) * 1.15;
	char *nums = malloc (size * sizeof(char));
	int count = 1;
	int ret = 3;
	long i;
	while (1) {
		if (ret % 2 && !nums[ret]) {
			count++;
			if (count == num)
				break;
			for (i = (long) ret * ret; i <= size; i += ret)
				if (!nums[i])
					nums[i] = 1;
		}
		ret++;
	}
	free(nums);
	return ret;
}