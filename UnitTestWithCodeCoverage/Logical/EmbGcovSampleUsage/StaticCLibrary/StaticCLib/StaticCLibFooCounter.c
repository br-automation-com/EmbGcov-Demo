



// Simple
int StaticCLibFooCounter( int a , int b ) 
{
	int c = a + b ;
	return c ;
}


// Call 2
int StaticCLibFooCounterRecursive( int a , int b , int n ) 
{
	int c = 0 ;
	
	if( n == 0 )
	{
		c = a + b ;
	}
	else
	{
		int an = a + 1 ;
		int bn = b + 1 ;
		int nn = n - 1 ;
		
		c =	StaticCLibFooCounterRecursive( an , bn , nn ) ;
	}
	
	return c ;
}

