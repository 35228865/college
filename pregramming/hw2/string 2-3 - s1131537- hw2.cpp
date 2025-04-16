#include <iostream>
using std::cout;
using std::exit;

//#include <algorithm>
//using std::max;

#include "string 2-3.h" // include definition of class String

string::string()
   : bx(),
     mySize( 0 ),
     myRes( 15 )
{
}

string::string( const size_type count, const char ch )
   : bx(),
     mySize( count ),
     myRes( ( mySize / 16 ) * 16 + 15 )
{
    if (myRes > 15)
        bx.ptr = new value_type[myRes + 1];
    for (size_type i = 0;i < mySize;i++)
    {
        myPtr()[i] = ch;
    }
    myPtr()[mySize] = value_type();
}

string::~string()
{
   if( myRes > 15 )
      delete[] bx.ptr;
}

string::value_type* string::myPtr()
{
   if( myRes < 16 )
      return bx.buf;
   else
      return bx.ptr;
}

const string::value_type* string::myPtr() const
{
   if( myRes < 16 )
      return bx.buf;
   else
      return bx.ptr;
}

// insert ch at where
string::iterator string::insert(const_iterator where, const char ch)
{
    if (where >= myPtr() && where <= myPtr() + mySize)
    {
        size_type pos = where - myPtr();
        if (mySize == myRes)
        {
            size_type newMyRes;
            if (myRes == 15 || myRes == 31)
                newMyRes = myRes + 16;
            else
                newMyRes = myRes * 3 / 2;

            pointer newPtr = new value_type[newMyRes + 1];
            for (size_type i = 0; i < pos; ++i)
            {
                newPtr[i] = myPtr()[i];
            }
            newPtr[pos] = ch;
            for (size_type i = pos; i < mySize; ++i)
            {
                newPtr[i + 1] = myPtr()[i];
            }

            if (myRes > 15)
                delete[] bx.ptr;

            bx.ptr = newPtr;
            myRes = newMyRes;
        }
        else
        {
            for (size_type i = mySize; i > pos; --i)
            {
                myPtr()[i] = myPtr()[i - 1];
            }
            myPtr()[pos] = ch;
        }
        ++mySize;
        myPtr()[mySize] = '\0';
        return myPtr() + pos;
    }
    else
        return iterator(nullptr);
}

string::iterator string::erase( const_iterator where )
{
   if( where >= myPtr() && where < myPtr() + mySize )
   {
       for(size_type i =where-myPtr();i<mySize;i++)
       {
           myPtr()[i] = myPtr()[i + 1];
       }
       mySize--;
       return const_cast<iterator>(where);
   }
   else
      return iterator( nullptr );
}

string& string::erase( const size_type off, size_type count )
{
   if( off < mySize )
   {
       if (count > mySize - off)
           count = mySize - off;
       for (size_type i = off;i < mySize-count;i++)
       {
           myPtr()[i] = myPtr()[i + count];
       } 
       mySize -= count;
       myPtr()[mySize] = '\0';
   }

   return *this;
}

void string::clear()
{
   mySize = 0;
   myPtr()[ 0 ] = value_type();
}

string::iterator string::begin()
{
   return myPtr();
}

string::const_iterator string::begin() const
{
   return const_iterator( myPtr() );
}

string::iterator string::end()
{
   return myPtr() + static_cast< difference_type >( mySize );
}

string::const_iterator string::end() const
{
   return const_iterator( myPtr() + static_cast< difference_type >( mySize ) );
}

string::reference string::at( const size_type off )
{
   if( off > mySize )
   {
      cout << "string subscript out of range\n";
      exit( 1 );
   }

   return myPtr()[ off ];
}

string::const_reference string::at( const size_type off ) const
{
   if( off > mySize )
   {
      cout << "string subscript out of range\n";
      exit( 1 );
   }

   return myPtr()[ off ];
}

string::reference string::front()
{
   return myPtr()[ 0 ];
}

string::const_reference string::front() const
{
   return myPtr()[ 0 ];
}

string::reference string::back()
{
   return myPtr()[ mySize - 1 ];
}

string::const_reference string::back() const
{
   return myPtr()[ mySize - 1 ];
}

const char* string::c_str() const
{
   return myPtr();
}

string::size_type string::size() const
{
   return mySize;
}

string::size_type string::capacity() const
{
   return myRes;
}

bool string::empty() const
{
   return mySize == 0;
}