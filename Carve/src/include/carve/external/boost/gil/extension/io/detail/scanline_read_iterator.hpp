/*
    Copyright 2012 Christian Henning
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

/*************************************************************************************************/

#ifndef BOOST_GIL_EXTENSION_IO_IMAGE_READ_ITERATOR_HPP
#define BOOST_GIL_EXTENSION_IO_IMAGE_READ_ITERATOR_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author Christian Henning
///
/// \date 2012 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/iterator/iterator_facade.hpp>

#include <boost/gil/extension/io/detail/io_error.hpp>

namespace boost { namespace gil {

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400) 
#pragma warning(push) 
#pragma warning(disable:4512) //assignment operator could not be generated 
#endif

/// Input iterator to read images.
template< typename Reader >
class scanline_read_iterator : public boost::iterator_facade< scanline_read_iterator< Reader >
                                                            , byte_t*
                                                            , std::input_iterator_tag
                                                            >
{
public:

    scanline_read_iterator( Reader& reader
                          , int     pos = 0
                          )
    : _pos( pos )
    , _read_scanline( true )
    , _skip_scanline( true )
    , _reader( reader )
    {
        _buffer = boost::make_shared<  buffer_t >( buffer_t( _reader._scanline_length ));
        _buffer_start = &_buffer->front();
    }

private:
    friend class boost::iterator_core_access;

    void increment()
    {
        if( _skip_scanline == true )
        {
            _reader.skip( _buffer_start
                        , _pos
                        );
        }

        ++_pos;

        _skip_scanline = true;
        _read_scanline = true;
    }

    bool equal( const scanline_read_iterator& rhs ) const
    {
        return _pos == rhs._pos;
    }

    reference dereference() const
    {
        if( _read_scanline == true )
        {
            _reader.read( _buffer_start
                        , _pos
                        );
        }

        _skip_scanline = false;
        _read_scanline = false;

        return _buffer_start;
    }

private:
    Reader& _reader;

    mutable int _pos;

    mutable bool _read_scanline;
    mutable bool _skip_scanline;

    typedef std::vector< byte_t > buffer_t;
    typedef boost::shared_ptr< buffer_t > buffer_ptr_t;

    buffer_ptr_t _buffer;
    mutable byte_t* _buffer_start;
};

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400) 
#pragma warning(pop) 
#endif 

} // namespace gil
} // namespace boost

#endif // BOOST_GIL_EXTENSION_IO_IMAGE_READ_ITERATOR_HPP
