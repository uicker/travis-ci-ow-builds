///////////////////////////////////////////////////////////////////////////
// FILE: _algnmod.h (Definitions of non-modifying sequence operations)
//
// =========================================================================
//
//                          Open Watcom Project
//
// Copyright (c) 2004-2016 The Open Watcom Contributors. All Rights Reserved.
//
//    This file is automatically generated. Do not edit directly.
//
// =========================================================================
//
// Description: This header is part of the <algorithm> header.
///////////////////////////////////////////////////////////////////////////
#ifndef __ALGNMOD_H_INCLUDED
#define __ALGNMOD_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef _ALGORITHM_INCLUDED
 #error The header _algnmod.h requires algorithm.
#endif

#ifndef _ITERATOR_INCLUDED
 #include <iterator>
#endif

#ifndef _UTILITY_INCLUDED
 #include <utility>
#endif

namespace std {

    // all_of( InputIterator, InputIterator, Predicate )
    // *************************************************
    template< class InputIterator, class Predicate >
    bool all_of( InputIterator first, InputIterator last, Predicate pred )
    {
        while( first != last ) {
            if ( pred( *first ) == false ) return( false );
            ++first;
        }
        return( true );
    }

    // any_of( InputIterator, InputIterator, Predicate )
    // *************************************************
    template< class InputIterator, class Predicate >
    bool any_of( InputIterator first, InputIterator last, Predicate pred )
    {
        while( first != last ) {
            if ( pred( *first ) == true ) return( true );
            ++first;
        }
        return( false );
    }

    // none_of( InputIterator, InputIterator, Predicate )
    // **************************************************
    template< class InputIterator, class Predicate >
    bool none_of( InputIterator first, InputIterator last, Predicate pred )
    {
        while( first != last ) {
            if ( pred( *first ) == true ) return( false );
            ++first;
        }
        return( true );
    }

    // for_each( InputIterator, InputIterator, Function )
    // **************************************************
    template< class InputIterator, class Function >
    Function for_each( InputIterator first, InputIterator last, Function f )
    {
        while( first != last ) {
            f( *first );
            ++first;
        }
        return( f );
    }

    // find( InputIterator, InputIterator, const Type & )
    // **************************************************
    template< class InputIterator, class Type >
    InputIterator find( InputIterator first, InputIterator last, const Type &value )
    {
        while( first != last ) {
            if( *first == value ) return first;
            ++first;
        }
        return( first );
    }

    // find_if( InputIterator, InputIterator, Predicate )
    // **************************************************
    template< class InputIterator, class Predicate >
    InputIterator find_if( InputIterator first, InputIterator last, Predicate pred )
    {
        while( first != last ) {
            if( pred( *first ) != false ) return first;
            ++first;
        }
        return( first );
    }

    // find_end( Forward1, Forward1, Forward2, Forward2 )
    // **************************************************
    template< class ForwardIterator1, class ForwardIterator2 >
    ForwardIterator1 find_end( ForwardIterator1 first1,
                               ForwardIterator1 last1,
                               ForwardIterator2 first2,
                               ForwardIterator2 last2 )
    {
        ForwardIterator1 a;
        ForwardIterator2 b;
        ForwardIterator1 answer = last1;
        while( first1 != last1 ) {
            // Find first item that matches.
            while( !( *first1 == *first2 ) ) {
                ++first1;
                if( first1 == last1 ) return( answer );
            }
            // See if other items match.
            a = first1;
            b = first2;
            do {
                ++a;
                ++b;
                if( b == last2 ) {
                    answer = first1;
                    break;
                }
                if( a == last1 ) return( answer );
            } while( *a == *b );
            ++first1;
        }
        return( answer );
    }

    // find_end( Forward1, Forward1, Forward2, Forward2, BinaryPredicate )
    // *********************************************************************
    template< class ForwardIterator1,
              class ForwardIterator2,
              class BinaryPredictate >
    ForwardIterator1 find_end( ForwardIterator1 first1,
                               ForwardIterator1 last1,
                               ForwardIterator2 first2,
                               ForwardIterator2 last2,
                               BinaryPredictate pred )
    {
        ForwardIterator1 a;
        ForwardIterator2 b;
        ForwardIterator1 answer = last1;
        while( first1 != last1 ) {
            // Find first item that matches.
            while( ! ( pred( *first1, *first2 ) ) ) {
                ++first1;
                if( first1 == last1 ) return( answer );
            }
            // See if other items match.
            a = first1;
            b = first2;
            do {
                ++a;
                ++b;
                if( b == last2 ) {
                    answer = first1;
                    break;
                }
                if( a == last1 ) return( answer );
            } while( pred( *a, *b ) );
            ++first1;
        }
        return( answer );
    }

    // find_first_of( Input, Input, Forward, Forward )
    // ***********************************************
    template< class InputIterator, class ForwardIterator >
    InputIterator find_first_of( InputIterator first1,
                                 InputIterator last1,
                                 ForwardIterator first2,
                                 ForwardIterator last2 )
    {
        ForwardIterator i;
        while( first1 != last1 ) {
            for( i = first2; i != last2; ++i ){
                if( *first1 == *i ) return( first1 );
            }
            ++first1;
        }
        return( last1 );
    }

    // find_first_of( Input, Input, Forward, Forward, BinaryPredicate )
    // ****************************************************************
    template< class InputIterator,
              class ForwardIterator, 
              class BinaryPredictate >
    InputIterator find_first_of( InputIterator first1,
                                 InputIterator last1,
                                 ForwardIterator first2,
                                 ForwardIterator last2,
                                 BinaryPredictate pred )
    {
        ForwardIterator i;
        while( first1 != last1 ) {
            for( i = first2; i != last2; ++i ){
                if( pred( *first1, *i ) ) return first1;
            }
            ++first1;
        }
        return( last1 );
    }

    // adjacent_find( ForwardIterator, ForwardIterator )
    // *************************************************
    template< class ForwardIterator >
    ForwardIterator adjacent_find( ForwardIterator first, ForwardIterator last )
    {
        if( first == last ) return( last );

        ForwardIterator current( first );
        ++current;
        while( current != last ) {
            if( *first == *current ) return( first );
            ++first;
            ++current;
        }
        return( last );
    }

    // adjacent_find( ForwardIterator, ForwardIterator, BinaryPredicate )
    // ******************************************************************
    template< class ForwardIterator, class BinaryPredicate >
    ForwardIterator adjacent_find( ForwardIterator first,
                                   ForwardIterator last,
                                   BinaryPredicate pred )
    {
        if( first == last ) return( last );

        ForwardIterator current( first );
        ++current;
        while( current != last ) {
            if( pred( *first, *current ) != false ) return( first );
            ++first;
            ++current;
        }
        return( last );
    }

    // count( InputIterator, InputIterator, const Type & )
    // ***************************************************
    template< class InputIterator, class Type >
    typename iterator_traits< InputIterator >::difference_type
        count( InputIterator first, InputIterator last, const Type &value )
    {
        typename iterator_traits< InputIterator >::difference_type number(0);
        while( first != last ) {
            if( *first == value ) ++number;
            ++first;
        }
        return( number );
    }

    // count_if( InputIterator, InputIterator, Predicate )
    // ***************************************************
    template< class InputIterator, class Predicate >
    typename iterator_traits< InputIterator >::difference_type
        count_if( InputIterator first, InputIterator last, Predicate pred )
    {
        typename iterator_traits< InputIterator >::difference_type number(0);
        while( first != last ) {
            if( pred( *first ) != false ) ++number;
            ++first;
        }
        return( number );
    }

    // mismatch( InputIterator1, InputIterator1, InputIterator2 )
    //***********************************************************
    template< class InputIterator1, class InputIterator2 >
    pair< InputIterator1, InputIterator2 >
        mismatch( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while( first1 != last1 && *first1 == *first2 ) {
            ++first1; ++first2;
        }
        return( pair< InputIterator1, InputIterator2 >( first1, first2 ) );
    } 

    // mismatch( InputIterator1, InputIterator1, InputIterator2, BinaryPredicate )
    //***************************************************************************
    template< class InputIterator1, class InputIterator2, class BinaryPredicate >
    pair< InputIterator1, InputIterator2 >
        mismatch( InputIterator1 first1,
                  InputIterator1 last1,
                  InputIterator2 first2,
                  BinaryPredicate pred )
    {
        while( first1 != last1 && pred( *first1, *first2 ) != false ) {
            ++first1; ++first2;
        }
        return( pair< InputIterator1, InputIterator2 >( first1, first2 ) );
    } 

    // equal( InputIterator1, InputIterator1, InputIterator2 )
    // *******************************************************
    template< class InputIterator1, class InputIterator2 >
    bool equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while( first1 != last1 ) {
            if( *first1 != *first2 ) return false;
            ++first1; ++first2;
        }
        return( true );
    }

    // equal( InputIterator1, InputIterator1, InputIterator2, BinaryPredicate )
    // ************************************************************************
    template< class InputIterator1, class InputIterator2, class BinaryPredicate >
    bool equal( InputIterator1 first1,
                InputIterator1 last1,
                InputIterator2 first2,
                BinaryPredicate pred )
    {
        while( first1 != last1 ) {
            if( pred( *first1, *first2 ) == false ) return false;
            ++first1; ++first2;
        }
        return( true );
    }

    // search( Forward1, Forward1, Forward2, Forward2 )
    // ************************************************
    template< class ForwardIterator1, class ForwardIterator2 >
    ForwardIterator1
      search( ForwardIterator1 first1,
              ForwardIterator1 last1,
              ForwardIterator2 first2,
              ForwardIterator2 last2 )
    {
        typedef typename iterator_traits< ForwardIterator1 >::value_type value_type1;
        typedef typename iterator_traits< ForwardIterator2 >::value_type value_type2;

        // std::equal_to can only compare items of the same type.
        struct equal_items {
            bool operator( )( const value_type1 &x, const value_type2 &y )
                { return( x == y ); }
        };
        return search( first1, last1, first2, last2, equal_items( ) );
    }

    // search( Forward1, Forward1, Forward2, Forward2, BinaryPredicate )
    // *****************************************************************
    template< class ForwardIterator1, class ForwardIterator2, class BinaryPredicate >
    ForwardIterator1
      search( ForwardIterator1 first1,
              ForwardIterator1 last1,
              ForwardIterator2 first2,
              ForwardIterator2 last2,
              BinaryPredicate pred )
    {
        ForwardIterator1 a;
        ForwardIterator2 b;
        while( first1 != last1 ) {
            // Find first item that matches
            while( pred( *first1, *first2 ) == false ) {
                ++first1;
                if( first1 == last1 ) return( last1 );
            }
            // See if other items match.
            a = first1;
            b = first2;
            do {
                ++a;
                ++b;
                if( b == last2 ) {
                    return( first1 );
                }
                if( a == last1 ) return( last1 );
            } while( pred(*a,*b) );
            ++first1;
        }
        return( last1 );
    }

    // search_n( ForwardIterator, ForwardIterator, Size, Type )
    // ********************************************************
    template< class ForwardIterator, class Size, class Type >
    ForwardIterator
      search_n( ForwardIterator first,
                ForwardIterator last,
                Size            count,
                const Type     &value )
    {
        typedef typename iterator_traits< ForwardIterator >::value_type value_type;

        // std::equal_to can only compare items of the same type.
        struct equal_items {
            bool operator( )( const value_type &x, const Type &y )
                { return( x == y ); }
        };
        return search_n( first, last, count, value, equal_items( ) );
    }

    // search_n( ForwardIterator, ForwardIterator, Size, Type, BinaryPredicate )
    // *************************************************************************
    template< class ForwardIterator, class Size, class Type, class BinaryPredicate >
    ForwardIterator
      search_n( ForwardIterator first,
                ForwardIterator last,
                Size            count,
                const Type     &value,
                BinaryPredicate pred )
    {
        while( first != last ) {
            // Find first item that matches.
            while( pred( *first, value) == false ) {
                ++first;
                if( first == last ) return( last );
            }
            // See if other items match.
            ForwardIterator a = first;
            Size cnt = count;
            do {
                ++a;
                if ( --cnt == 0 ) return( first );
                if ( a == last ) return( last );
            } while ( pred( *a, value ) );
            ++first;
        }
        return( last );
    }

} // namespace std

#endif
