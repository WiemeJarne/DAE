void TestContainer( )
{
	std::cout << "\n-- Container tests --\n";
	// Define a Container object
	const int cap{ 5 };
	std::cout << "Create container with capacity of " << cap << " elements\n";
	Container* pContainer{ new Container{cap} };
	PrintContainer( pContainer );

	// Add some values to the container
	int actNr{ 0 };
	std::cout << "\nPush back of " << ( cap - 1 ) << " elements\n";
	for ( int idx{ 1 }; idx < cap; ++idx )
	{
		pContainer->PushBack( rand( ) % 21 );
		++actNr;
	}
	PrintContainer( pContainer );

	std::cout << "\nChange the value of the elements (using Set)\n";
	for ( int idx{ 0 }; idx < actNr; ++idx )
	{
		pContainer->Set( idx, rand( ) % 21 );
	}
	PrintContainer( pContainer );

	std::cout << "\nPush back another " << ( cap - 1 ) << " elements\n";
	for ( int i{ 1 }; i < cap; ++i )
	{
		pContainer->PushBack( rand( ) % 21 );
		++actNr;
	}
	PrintContainer( pContainer );
	delete pContainer;
}

void PrintContainer( const Container *pContainer )
{
	std::cout << "-- Print container --\n";
	std::cout << "   Capacity: " << pContainer->Capacity( ) << std::endl;
	std::cout << "   Size: " << pContainer->Size( ) << std::endl;
	std::cout << "   Get the elements (using Get and Size)\n   ";
	for ( int idx{ 0 }; idx < pContainer->Size( ); ++idx )
	{
		std::cout << pContainer->Get( idx ) << " ";
	}
	std::cout << std::endl;
}