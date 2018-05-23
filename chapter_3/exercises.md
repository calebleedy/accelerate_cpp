# Exercises

*3-0* Compile, execute, and test the programs in this chapter.

See [mean_grades.cpp](./mean_grades.cpp) and [median_grades.cpp](./median_grades.cpp).

*3-1* Suppose we wish to find the median of a collection of values. Assume that
we have read some of the values so far, and that we have no idea how many values
remain to be read. Prove that we cannot afford to discard any of the values that
we have read.

To prove that we cannot throw out any of the values that we have read, we must
show that there is a case where discarding a single value will result in the 
wrong answer. 

Consider the case where the collection from which one is drawing is such that
the true median is unique. That is there is either one or zero elements in the 
set that are equal to the actual median. Since we do not know the data
generating process of the collection this could certainly be the case. Consider
remove a single element from the collection. If this element, x, is less than
the median, the new median will decrease because the median is unique. By 
symmetry this will happen if x is greater than the median. If x is the median
then the new median will likely be different. (However, it could be the case
that the new median is the same. This does not matter because we must only 
show that the median differs in some cases.)

*3-2* Write a program to compute and print the quartiles of a set of integers.

See [ex_2.cpp](./ex_2.cpp). This was actually quite difficult because I had to
work with trucated integers. In the end I basically used the fact that the
modulo operator can partition data into a preset number of bins.

*3-3* Write a program to count how many times each distinct word appears in its
input.

See [ex_3.cpp](./ex_3.cpp).

*3-4* Write a program to report the length of the longest and shortest `string`
in its input.

See [ex_4.cpp](./ex_4.cpp).

*3-5* Write a program that will keep track of grades for several students at
once. The program could keep two `vectors` in sync: The first should hold the 
student's names, and the second the final grades that can be computed as input
is read. For now, you should assume a fixed number of homework grades. 

See [ex_5.cpp](./ex_5.cpp).
