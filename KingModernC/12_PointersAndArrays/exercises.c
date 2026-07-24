// ================================================================================================
// Chapter 12 Exercises
// ================================================================================================

// ================================================================================================
// (1) Suppose that the following declarations are in effect:
// int a[] = { 5, 15, 34, 54, 14, 2, 52, 72 };
// int *p = &a[1], *q = &a[5];
//
// (a) What is the value of *(p + 3)?               14
// (b) What is the value of *(q - 3)?               34
// (c) What is the value of q - p?                  4
// (d) Is the condition P < q true or false?        true
// (e) Is the condition *p < *q true or false?      false
// ================================================================================================

// ================================================================================================
// (2) Suppose that high, low, and middle are all pointer variables of the same type, and that low
// and high point to elements of an array. Why is the following statement illegal, and how could it
// be fixed?
// middle = (low + high) / 2;
//
// Addition between two pointers like this is not allowed, the result could easily be out of bounds
// of the array, and therefore dividing by two would yield a completely meaningless result.
// The proper way to do this would be:
//  
// middle = low + (high - low) / 2;
// ================================================================================================

// ================================================================================================
// (3) What will be the contents of the array a after the following statements are executed?
// 
// #define N 10
//
// int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
// int *p = &a[0], *q = &a[N - 1], temp;
//
// while (p < q)
// {
//      temp = *p;
//      *p++ = *q;
//      *q-- = temp;
// }
//
// { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }
// ================================================================================================

// ================================================================================================
// (4) Rewrite the make_empty(), is_empty(), and is_full() functions of section 10.2 to use the
// pointer variable top_ptr instead of the integer variable top.
//
// From section 10.2 ->
//
// #define STACK_SIZE 100
//
// int contents[STACK_SIZE];
// int top = 0;
//
// void make_empty(void)
// {
//      top = 0;
// }
//
// bool is_empty(void)
// {
//      return top == 0;
// }
//
// bool is_full(void)
// {
//      return top == STACK_SIZE;
// }
//
// Rewritten...
//
// #define STACK_SIZE 100
//
// int contents[STACK_SIZE];
// int *top_ptr = contents;
//
// void make_empty(void)
// {
//      top_ptr = contents;
// }
//
// bool is_empty(void)
// {
//      return top_ptr == contents;
// }
//
// bool is_full(void)
// {
//      return top_ptr == &contents[STACK_SIZE];
// }
// ================================================================================================

// ================================================================================================
// (5) Suppose that a is a one-dimensional array and p is a pointer variable. Assuming that the
// assignment p = a has just been performed, which of the following expressions are illegal becasue
// of mismatched types? Of the remaining expressions, which are true (have a nonzero value)?
//
// (a) p == a[0];       <- illegal, comparison between pointer and integer, compiles w/ warning
// (b) p == &a[0];      <- legal, and true
// (c) *p == a[0];      <- legal, and true
// (d) p[0] == a[0];    <- legal, and true
// ================================================================================================

// ================================================================================================
// (6) Rewrite the following function to use pointer arithmetic intead of array subscripting. (In
// other words, eliminate the variable i and all uses of the [] operator.) Make as few changes as
// possible.
//
// int sum_array(const int a[], int n)
// {
//      int i, sum;
//
//      sum = 0;
//      for (i = 0; i < n; i++)
//          sum += a[i];
//
//      return sum;
// }
//
// int sum_array(const int *a, int n)
// {
//     int sum = 0;
//     const int *p;
//
//     for (p = a; p < a + n; p++)
//     {
//         sum += *p;
//     }
//     return sum;
// }
//
// ================================================================================================

// ================================================================================================
// (7) Write the following function:
// 
// bool search(const int[], int n, int key);
//
// a is an array to be searched, n is the number of elements in the array, and key is the search
// key. search() should return true if key matches some element of a, and false if it doesn't. Use
// pointer arithmetic, not subscripting, to visit array elements.
//
// bool search(const int *a, int n, int key)
// {
//     for (const int *p = a; p < a + n; p++)
//     {
//         if (*p == key) return true;
//     }
//     return false;
// }
// ================================================================================================

// ================================================================================================
// (8) Rewrite the following function to use pointer arithmetic instead of array subscripting. (In
// other words, eliminate the variable i and all uses of the [] operator.) Make as few changes as
// possible.
//
// void store_zeros(int a[], int n)
// {
//      int i;
//
//      for (i = 0; i < n; i++)
//          a[i] = 0;
// }
//
// void store_zeros(int *a, int n)
// {
//      for (int *p = a; p < a + n; p++)
//          *p = 0;
// }
// ================================================================================================

// ================================================================================================
// (9) Write the following function:
//
// double inner_product(const double *a, const double *b, int n);
//
// a and b both point to arrays of length n, The function should return:
// a[0] * b[0] + a[1] * b[1] + ... + a[n - 1] * b[n - 1]
// Use pointer arithmetic, not array subscripting, to visit array elements.
//
// double inner_product(const double *a, const double *b, int n)
// {
//     const double *ptr_a;
//     const double *ptr_b = b;
//     double ans;
//
//     for (ptr_a = a; ptr_a < a + n; ptr_a++)
//     {
//         ans += (*ptr_a) * (*ptr_b++);
//     }
//     return ans;
// }
// ================================================================================================

// ================================================================================================
// (10) Modify the find_middle() function of section 11.5 so that it uses pointer arithmetic to
// calculate the return value.
//
// From seciton 11.5 ->
//
// int *find_middle(int a[], int n)
// {
//      return &a[n / 2];
// }
//
// int *find_middle(int *a, int n)
// {
//      return a + n / 2;
// }
//
// ================================================================================================

// ================================================================================================
// (11) Modify the find_largest() function so that it uses pointer arithmetic.
//
// int find_largest(int *a, int n)
// {
//     int *p, largest = *a;
//
//     for (p = a + 1; p < a + n; p++)
//     {
//         if (*p > largest)
//             largest = *p;
//     }
//     return largest;
// }
//
// ================================================================================================

// ================================================================================================
// (12) Write the following function:
//
// void find_two_largest(const int *a, int n, int *largest, int *second_largest);
//
// a points to an array of length n. The function searches the array for its largest and second
// largest elements, storing them in the variables pointed to by largest and second_largest,
// respectively. Use pointer arithmetic.
//
//
// void find_two_largest(const int *a, int n, int *largest, int *second_largest)
// {
//     int i = 1;
//     *largest = *a;
//     *second_largest = *a;
//
//     while (i < n)
//     {
//         if (*(a + i) > *largest)
//         {
//             *second_largest = *largest;
//             *largest = *(a + i);
//
//         }
//         else if (*(a + i) > *second_largest && *(a + i) != *largest)
//         {
//             *second_largest = *(a + i);
//         }
//         i++;
//     }
// }
//
// ================================================================================================

// ================================================================================================
// (13) Section 8.2 had a program fragment in which two nested for loops initialized the array
// ident for use as an identity matrix. Rewrite the code, using a single pointer to step through
// the array one element at a time. Hint: the first element of the array should be 1...
//
// #define N 10
//
// double id_matrix[N][N];
// int i = 0;
//
// for (double *aptr = &id_matrix[0][0]; aptr < &id_matrix[0][0] + N * N; aptr++)
// {
//     if (aptr == id_matrix[i] + i)
//     {
//         *aptr = 1.0;
//         i++;
//     }
//     else 
//     {
//         *aptr = 0.0;
//     }
// }
//
// ================================================================================================

// ================================================================================================
// (14) Assume that the following array contains a week's worth of hourly temperature readings,
// with each row containing the readings for one day:
// int temperatures[7][24];
// Write a statement that uses the search function from exercise 7 to search the entire
// temperatures array for the value 32.
<<<<<<< HEAD
// 
// void print_array_twod(int *a, int rows, int cols)
// {
//     int i  = 0;
//     for (int *p = a; p < a + rows * cols; p++)
//     {
//         printf("%2d ", *p);
//         if (++i % cols == 0) puts("");
//     }
//
//     puts("");
// }
//
// void rfill_array(int *a, int n, int mod)
// {
//     srand((unsigned) time(NULL));
//
//     for (int *p = a; p < a + n; p++)
//     {
//         *p = (rand() % mod);
//     }
//
// }
//
// bool search(const int *a, int n, int key)
// {
//     for (const int *p = a; p < a + n; p++)
//     {
//         if (*p == key) return true;
//     }
//     return false;
// }
// if (search(temperatures[0], DAYS * HOURS, 30))
// {
//     puts("true");
// }
// else
// {
//     puts("false");
// }
=======
//
// for (int i = 0; i < 7; i++)
//     if (search(temeratures, 24, 32)) 
//         printf("Found\n");
//
>>>>>>> ec3bd4e18a7c853e614d83e49368a5ec39e4edb5
// ================================================================================================

// ================================================================================================
// (15) Write a loop that prints all temperature readings stored in row i of the temperatures array
// from exercise 14. Use a pointer to visit each element of the row.
//
// void print_array_twod(int *a, int rows, int cols)
// {
//     int i  = 0;
//     for (int *p = a; p < a + rows * cols; p++)
//     {
//         printf("%2d ", *p);
//         if (++i % cols == 0) puts("");
//     }
//
//     puts("");
// }
//
// ================================================================================================

// ================================================================================================
// (16) Write a loop that prints the highest temperature in the temperature array from exercise 14
// for each day of the week. The loop body should call the find_largest() function, passing it one
// row of the array at a time.
//
// for (int *p = temperatures[0]; p < temperatures[0] + DAYS * HOURS; p += HOURS)
// {
//     printf("Hottest day: %d\n", find_largest(p, HOURS));
// }
// ================================================================================================

// ================================================================================================
// (17) Rewrite the following function to use pointer arithmetic instead of array subscripting. Use
// a single loop instad of nested loops.
//
// int sum_two_dimen_array(const int a[][LEN], int n)
// {
//      int i, j, sum = 0;
//
//      for (i = 0; i < n; i++)
//          for (j = 0; j < LEN; j++)
//              sum += a[i][j];
//
//      return sum;
// }
//
// int sum_twod_array(const int a[][LEN], int n)
// {
//     int sum = 0;
//
//     for (int *p = a[0]; p < a[0] + LEN * n; p++)
//     {
//         sum += *p;
//     }
//     return sum;
// }
//
// ================================================================================================

// ================================================================================================
// (18) Write the evaluate_position() function from exercise 13 in chapter 9 using pointer
// arithmetic, and a single loop instead of nested loops.
// ================================================================================================
