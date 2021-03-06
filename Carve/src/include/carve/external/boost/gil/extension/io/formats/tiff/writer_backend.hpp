/*
    Copyright 2012 Christian Henning
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

/*************************************************************************************************/

#ifndef BOOST_GIL_EXTENSION_IO_TIFF_IO_WRITER_BACKEND_HPP
#define BOOST_GIL_EXTENSION_IO_TIFF_IO_WRITER_BACKEND_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author Christian Henning \n
///
/// \date 2012 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <boost/gil/extension/io/tiff_tags.hpp>

namespace boost { namespace gil {

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400) 
#pragma warning(push) 
#pragma warning(disable:4512) //assignment operator could not be generated 
#endif

///
/// TIFF Writer Backend
///
template< typename Device >
struct writer_backend< Device
                     , tiff_tag
                     >
{
public:

    typedef tiff_tag format_tag_t;

public:

    writer_backend( const Device&                       io_dev
                  , const image_write_info< tiff_tag >& info
                  )
    : _io_dev( io_dev )
    , _info( info )
    {}

protected:

    template< typename View >
    void write_header( const View& view )
    {
        typedef typename View::value_type pixel_t;

        // get the type of the first channel (heterogeneous pixels might be broken for now!)
        typedef typename channel_traits< typename element_type< pixel_t >::type >::value_type channel_t;

        if( this->_info._photometric_interpretation_user_defined )
        {
            typedef typename color_space_type< View >::type color_space_t;

            // write photometric interpretion - Warning: This value is rather subjective.
            // The user should better set this value itself. There is no way to decide if
            // a image is PHOTOMETRIC_MINISWHITE or PHOTOMETRIC_MINISBLACK. This writer
            // will assume PHOTOMETRIC_MINISBLACK for gray_t images and PHOTOMETRIC_RGB
            // for rgb_t images.
            this->_info._photometric_interpretation = detail::photometric_interpretation< color_space_t >::value;
        }

        // write dimensions
        tiff_image_width::type  width  = (tiff_image_width::type)  view.width();
        tiff_image_height::type height = (tiff_image_height::type) view.height();

        this->_io_dev.template set_property< tiff_image_width  >( width  );
        this->_io_dev.template set_property< tiff_image_height >( height );

        // write planar configuration
        this->_io_dev.template set_property<tiff_planar_configuration>( this->_info._planar_configuration );

        // write samples per pixel
        tiff_samples_per_pixel::type samples_per_pixel = num_channels< pixel_t >::value;
        this->_io_dev.template set_property<tiff_samples_per_pixel>( samples_per_pixel );

        // write bits per sample
        // @todo: Settings this value usually requires to write for each sample the bit
        // value seperately in case they are different, like rgb556.
        tiff_bits_per_sample::type bits_per_sample = detail::unsigned_integral_num_bits< channel_t >::value;
        this->_io_dev.template set_property<tiff_bits_per_sample>( bits_per_sample );

        // write sample format
        tiff_sample_format::type sampl_format = detail::sample_format< channel_t >::type::value;
        this->_io_dev.template set_property<tiff_sample_format>( sampl_format );

        // write photometric format
        this->_io_dev.template set_property<tiff_photometric_interpretation>( this->_info._photometric_interpretation );

        // write compression
        this->_io_dev.template set_property<tiff_compression>( this->_info._compression );

        // write orientation
        this->_io_dev.template set_property<tiff_orientation>( this->_info._orientation );

        // write rows per strip
        this->_io_dev.template set_property<tiff_rows_per_strip>( this->_io_dev.get_default_strip_size() );

        // x, y resolution
        this->_io_dev.template set_property<tiff_x_resolution>( this->_info._x_resolution );
        this->_io_dev.template set_property<tiff_y_resolution>( this->_info._y_resolution );
    }


public:

    Device _io_dev;

    image_write_info< tiff_tag > _info;
};

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400) 
#pragma warning(pop) 
#endif 

} // namespace gil
} // namespace boost

#endif // BOOST_GIL_EXTENSION_IO_TIFF_IO_WRITER_BACKEND_HPP
