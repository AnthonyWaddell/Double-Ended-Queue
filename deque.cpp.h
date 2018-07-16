//-----------------------------------------------------------------------------
// Basic constructor: came with file
//-----------------------------------------------------------------------------
template <class Object>
Deque<Object>::Deque( ) 
{                         
  front = back = NULL;
}

//-----------------------------------------------------------------------------
// Copy constructor: came with file
//-----------------------------------------------------------------------------
template <class Object>
Deque<Object>::Deque( const Deque &rhs ) 
{        
  front = back = NULL;
  *this = rhs;
}

//-----------------------------------------------------------------------------
// Desctructor: came with file
//-----------------------------------------------------------------------------
template <class Object>
Deque<Object>::~Deque( )
{                        
  clear( );
}

//-----------------------------------------------------------------------------
// isEmpty: came with file
//-----------------------------------------------------------------------------
template <class Object>
bool Deque<Object>::isEmpty( ) const 
{         
  return front == NULL;
}

//-----------------------------------------------------------------------------
// get size: came with file
//-----------------------------------------------------------------------------
template <class Object>
int Deque<Object>::size( ) const 
{  
  int i = 0;
  for (DequeNode *ptr = front; ptr != NULL; ptr = ptr->next)
  {
	  ++i;
  }
  return i;
}

//-----------------------------------------------------------------------------
// get head item: came with file
//-----------------------------------------------------------------------------
template <class Object>
const Object &Deque<Object>::getFront( ) const 
{   // retrieve the front node
  if ( isEmpty( ) )
    throw "empty queue";
  return front->item;
}

//-----------------------------------------------------------------------------
// get back item: came with file
//-----------------------------------------------------------------------------
template <class Object>
const Object &Deque<Object>::getBack( ) const 
{
  if ( isEmpty( ) )
    throw "empty queue";
  return back->item;
}

//-----------------------------------------------------------------------------
// clear deque: came with file
//-----------------------------------------------------------------------------
template <class Object>
void Deque<Object>::clear( ) 
{ 
  while ( !isEmpty( ) )       
    removeFront( );
}

//-----------------------------------------------------------------------------
// Function:	template <class Object>
//				void Deque<Object>::addFront(const Object &obj)
// Title:		adds to front
// Description: Adds a node to the front of the deque
//
// Programmer:	Anthony Waddell
// Date:		12-5-17
// 
// History Log:	12-5-17 AW Completed Function
//-----------------------------------------------------------------------------
template <class Object>
void Deque<Object>::addFront( const Object &obj ) 
{
	// Create node to be added
	DequeNode * temp = new DequeNode;
	temp->item = obj;
	temp->next = NULL;

	// If deque is empty, add first node
	if (isEmpty())
	{
		front = back = temp;
		front->next = back;
		back->prev = front;
	}
	// If deque is not empty, add to front and change pointers
	else
	{
		temp->next = front;
		front->prev = temp;
		front = temp;
	}

}

//-----------------------------------------------------------------------------
// Function:	template <class Object>
//				void Deque<Object>::addBack(const Object &obj)
// Title:		adds to back
// Description: Adds a node to the back of the deque
//
// Programmer:	Anthony Waddell
// Date:		12-5-17
// 
// History Log:	12-5-17 AW Completed Function
//-----------------------------------------------------------------------------
template <class Object>
void Deque<Object>::addBack( const Object &obj ) 
{ 
	// Create node to be added
	DequeNode * temp = new DequeNode;
	temp->item = obj;
	temp->next = NULL;

	// If deque is empty add first node
	if (isEmpty())
	{
		front = back = temp;
		front->next = back;
		back->prev = front;
	}
	// If deque is not empty, add to end and change pointers
	else
	{
		back->next = temp;
		temp->prev = back;
		back = temp;
	}
}

//-----------------------------------------------------------------------------
// Function:	template <class Object>
//				Object Deque<Object>::removeFront()
// Title:		removes front node
// Description: removes front node of deque and returns it's data
//
// Programmer:	Anthony Waddell
// Date:		12-5-17
// 
// History Log:	12-5-17 AW Completed Function
//-----------------------------------------------------------------------------
template <class Object>
Object Deque<Object>::removeFront( ) 
{
	Object data;
	int one = 1;

	// If list is empty
	if (isEmpty())
	{
		cout << "Empty deque" << endl;
		front = NULL;
		back = NULL;
	}
	
	// If deque is not empty
	else
	{
		// Get data
		data = front->item;
		// If deque has one item; clean pointers
		if (size() == one)
		{
			delete front;
			front = NULL;
			back = NULL;
		}
		//If deque has multiple items; clean pointers
		else
		{
			DequeNode *temp = front->next;
			delete front;
			front = temp;
		}
	}
	return data;

}

//-----------------------------------------------------------------------------
// Function:	template <class Object>
//				Object Deque<Object>::removeBack()
// Title:		removes back node
// Description: removes end node of deque and returns it's data
//
// Programmer:	Anthony Waddell
// Date:		12-5-17
// 
// History Log:	12-5-17 AW Completed Function
//-----------------------------------------------------------------------------
template <class Object>
Object Deque<Object>::removeBack( ) 
{   
	Object data;
	int one = 1;

	// If deque is empty
	if (isEmpty())
	{
		cout << "Empty deque" << endl;
		front = NULL;
		back = NULL;
	}
	// If deque is not empty
	else
	{
		// Get data
		data = back->item;
		// If deque has one item; clean pointers
		if (size() == one)
		{
			delete back;
			front = NULL;
			back = NULL;
		}
		// If deque has more than one item; clean pointers
		else
		{
			DequeNode *temp = back->prev;
			delete back;
			back = temp;
			back->next = NULL;
		}
	}
	return data;
}

//-----------------------------------------------------------------------------
// operator: came with file
//-----------------------------------------------------------------------------
template <class Object>
const Deque<Object> &Deque<Object>::operator=( const Deque &rhs ) 
{ // assign
  if ( this != &rhs ) 
  { // avoid self assignment
    clear( );
	for (DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next)
	{
		addBack(rptr->item);
	}

  }
  return *this;
}