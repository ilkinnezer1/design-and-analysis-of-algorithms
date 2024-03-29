#include<iostream>

#define SIZE 3	 // Number of unknowns

//DECLARATIONS

// function to reduce matrix to r.e.f. Returns a value to
// indicate whether matrix is singular or not
int forwardElim(double mat[SIZE][SIZE+1]);

// function to calculate the values of the unknowns
void backSub(double mat[SIZE][SIZE+1]);

// function to get matrix content
void gaussianElimination(double mat[SIZE][SIZE+1])
{
	/* reduction into r.e.f. */
	int singular_flag = forwardElim(mat);

	/* if matrix is singular */
	if (singular_flag != -1)
	{
		std::cout << "Singular Matrix" << std::endl;

		/* if the RHS of equation corresponding to
		zero row is 0, * system has infinitely
		many solutions, else inconsistent*/
		if (mat[singular_flag][SIZE])
			std::cout <<("Inconsistent System.");
		else
			std::cout << "May have infinitely many " << std::endl;
				std:: cout << "solutions.";

		return;
	}

	/* get solution to system and print it using
	backward substitution */
	backSub(mat);
}

// function for elementary operation of swapping two rows
void swap_row(double mat[SIZE][SIZE+1], int i, int j)
{
	//printf("Swapped rows %d and %d\n", i, j);

	for (int k=0; k<=SIZE; k++)
	{
		double temp = mat[i][k];
		mat[i][k] = mat[j][k];
		mat[j][k] = temp;
	}
}
// function to print matrix content at any stage
void print(double mat[SIZE][SIZE+1])
{
	for (int i=0; i<SIZE; i++, printf("\n"))
		for (int j=0; j<=SIZE; j++)
			printf("%lf ", mat[i][j]);

	std::cout <<"\n";
}

// function to reduce matrix to r.e.f.
int forwardElim(double mat[SIZE][SIZE+1])
{
	for (int k=0; k<SIZE; k++)
	{
		// Initialize maximum value and index for pivot
		int i_max = k;
		int v_max = mat[i_max][k];

		/* find greater amplitude for pivot if any */
		for (int i = k+1; i < SIZE; i++)
			if (abs(mat[i][k]) > v_max)
				v_max = mat[i][k], i_max = i;

	    // 	 if a principal diagonal element is zero,
	    //  it denotes that matrix is singular, and
	// 	will lead to a division-by-zero later. 
		if (!mat[k][i_max])
			return k; // Matrix is singular

		/* Swap the greatest value row with current row */
		if (i_max != k)
			swap_row(mat, k, i_max);


		for (int i=k+1; i<SIZE; i++)
		{
			/* factor f to set current row kth element to 0,
			* and subsequently remaining kth column to 0 */
			double f = mat[i][k]/mat[k][k];

			/* subtract fth multiple of corresponding kth
			row element*/
			for (int j=k+1; j<=SIZE; j++)
				mat[i][j] -= mat[k][j]*f;

			/* filling lower triangular matrix with zeros*/
			mat[i][k] = 0;
		}

		//print(mat);	 //for matrix state
	}
	//print(mat);		 //for matrix state
	return -1;
}

// function to calculate the values of the unknowns
void backSub(double mat[SIZE][SIZE+1])
{
	double x[SIZE]; // An array to store solution

	/* Start calculating from last equation up to the
	first */
	for (int i = SIZE-1; i >= 0; i--)
	{
		/* start with the RHS of the equation */
		x[i] = mat[i][SIZE];

		/* Initialize j to i+1 since matrix is upper
		triangular*/
		for (int j=i+1; j<SIZE; j++)
		{
			/* subtract all the lhs values
			* except the coefficient of the variable
			* whose value is being calculated */
			x[i] -= mat[i][j]*x[j];
		}

		/* divide the RHS by the coefficient of the
		unknown being calculated */
		x[i] = x[i]/mat[i][i];
	}

	std::cout<< "\nSolution for the system:\n";
	for (int i=0; i<SIZE; i++)
		std::cout <<  x[i] << std::endl;
}

// Driver program
int main()
{
	/* input matrix */
	double mat[SIZE][SIZE+1] = {{3.0, 2.0,-4.0, 3.0},
						{2.0, 3.0, 3.0, 15.0},
						{5.0, -3, 1.0, 14.0}
						};

	gaussianElimination(mat);
}
