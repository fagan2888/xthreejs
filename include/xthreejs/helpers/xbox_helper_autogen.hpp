#ifndef XTHREE_BOX_HELPER_HPP
#define XTHREE_BOX_HELPER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // box_helper declaration
    //

    template<class D>
    class xbox_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, object);
        XPROPERTY(xtl::xoptional<xw::html_color>, derived_type, color, "#ffffff");
        XPROPERTY(std::string, derived_type, type, "BoxHelper");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xbox_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using box_helper = xw::xmaterialize<xbox_helper>;

    using box_helper_generator = xw::xgenerator<xbox_helper>;

    //
    // box_helper implementation
    //


    template <class D>
    inline void xbox_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(object, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xbox_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(object, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xbox_helper<D>::xbox_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbox_helper<D>::set_defaults()
    {
        this->_model_name() = "BoxHelperModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xbox_helper>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xbox_helper>;
        extern template xw::xmaterialize<xthree::xbox_helper>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xbox_helper>>;
        extern template class xw::xgenerator<xthree::xbox_helper>;
        extern template xw::xgenerator<xthree::xbox_helper>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xbox_helper>>;
    #endif
#endif

#endif