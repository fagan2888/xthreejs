#ifndef XTHREE_ARRAY_CAMERA_HPP
#define XTHREE_ARRAY_CAMERA_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xperspective_camera_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // array_camera declaration
    //

    template<class D>
    class xarray_camera : public xperspective_camera<D>
    {
    public:

        using base_type = xperspective_camera<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, type, "ArrayCamera");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xarray_camera();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using array_camera = xw::xmaterialize<xarray_camera>;

    using array_camera_generator = xw::xgenerator<xarray_camera>;

    //
    // array_camera implementation
    //


    template <class D>
    inline void xarray_camera<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xarray_camera<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xarray_camera<D>::xarray_camera()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xarray_camera<D>::set_defaults()
    {
        this->_model_name() = "ArrayCameraModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xarray_camera>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xarray_camera>;
        extern template xw::xmaterialize<xthree::xarray_camera>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xarray_camera>>;
        extern template class xw::xgenerator<xthree::xarray_camera>;
        extern template xw::xgenerator<xthree::xarray_camera>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xarray_camera>>;
    #endif
#endif

#endif